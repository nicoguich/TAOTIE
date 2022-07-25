
import RPi.GPIO as GPIO

import signal



from matplotlib import pyplot as plt
from osc4py3.as_eventloop import *
from osc4py3 import oscbuildparse
from osc4py3 import oscmethod as osm
from picamera.array import PiRGBArray # Generates a 3D RGB array
from picamera import PiCamera # Provides a Python interface for the RPi Camera Module
import time # Provides time-related functions
import cv2 # OpenCV library
import numpy as np
from set_picamera_gain import set_analog_gain, set_digital_gain

sel_control=1
control_value=0
batterie=50
brightness_osc=[0]
contrast_osc=[0]
thresh_osc=[0]
reverse_osc=[0]


temps= time.time()


osc_startup()
osc_udp_client("192.168.100.180", 5005, "raspberry")
osc_udp_server("192.168.100.180", 5006, "camera")
osc_udp_client("192.168.100.180", 5007, "chataigne")

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)

def handler(signum, frame):
    print("prout")
    GPIO.output(17, GPIO.LOW)

    exit(1)


reglage_lines = []

with open("/home/pi/Desktop/reglage_camera.txt") as f:
    reglage_lines = f.readlines()
brightness=int (reglage_lines[0])
brightness_osc[0]=int (reglage_lines[0])
contrast=int (reglage_lines[1])
contrast_osc[0]=int (reglage_lines[1])
thresh=int(reglage_lines[2])
thresh_osc[0]=int (reglage_lines[2])
reverse=int(reglage_lines[3])
reverse_osc[0]=int (reglage_lines[3])
print("brightness:" ,brightness, "/contrast: ",contrast,"tresh: ",thresh,"reverse: ",reverse)
msg0 = oscbuildparse.OSCMessage("/brightness", None, brightness_osc)
msg1 = oscbuildparse.OSCMessage("/contrast", None, contrast_osc)
msg2 = oscbuildparse.OSCMessage("/thresh", None, thresh_osc)
msg3 = oscbuildparse.OSCMessage("/reverse", None, reverse_osc)

osc_send(msg0, "chataigne")
osc_send(msg1, "chataigne")
osc_send(msg2, "chataigne")
osc_send(msg3, "chataigne")


def control_image(*args):
    global sel_control
    global brightness
    global contrast
    global thresh
    global reverse
    global image
    sel_control=args[0]


    brightness=args[1]
    contrast=args[2]
    thresh=args[3]
    reverse = args[4]
    image = args[5]
    save = args[6]
    camera.contrast = contrast
    camera.brightness = brightness
    if (save==1) :
        print("enregistrement reglage camera...")
        reglage_camera = open("/home/pi/Desktop/reglage_camera.txt","w")
        print("...")
        reglage_camera.write(str(int(brightness))+"\n")
        print("...")
        reglage_camera.write(str(int(contrast))+"\n")
        print("...")
        reglage_camera.write(str(int(thresh))+"\n")
        print("...")
        reglage_camera.write(str(int(reverse))+"\n")
        reglage_camera.close()
        print("reglage enregistré")

image=0

# Initialize the camera
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
camera.start_preview(fullscreen=False)
camera.contrast = contrast
camera.brightness = brightness
time.sleep(2)

# fix the auto white balance gains at their current values
g = camera.awb_gains
camera.awb_mode = "off"
camera.awb_gains = g

# fix the shutter speed
camera.shutter_speed = camera.exposure_speed

print("Current a/d gains: {}, {}".format(camera.analog_gain, camera.digital_gain))

print("Attempting to set analogue gain to 1")
set_analog_gain(camera, 1)
print("Attempting to set digital gain to 1")
set_digital_gain(camera, 1)

camera.hflip = False
camera.vflip = True
raw_capture = PiRGBArray(camera, size=(640, 480))
font = cv2.FONT_HERSHEY_SIMPLEX

# Wait a certain number of seconds to allow the camera time to warmup
time.sleep(1)



osc_method("/image", control_image)


for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):
    osc_process()

    if camera.digital_gain!=1:
        set_digital_gain(camera, 1)
        set_analog_gain(camera, 1)

    img = frame.array
    img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    (thresh, blackAndWhiteImage) = cv2.threshold(img,thresh, 255, cv2.THRESH_BINARY)

    blackAndWhiteImage = cv2.rectangle(blackAndWhiteImage, (0, 0), (640, 480), (255), 3)
    if reverse==1:
        blackAndWhiteImage=(255-blackAndWhiteImage)


    contours, hierarchy = cv2.findContours( blackAndWhiteImage, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    blackAndWhiteImage = cv2.cvtColor(blackAndWhiteImage,cv2.COLOR_GRAY2BGR)

    value_sensor=[1,1,1,1,1,1,1,1,1,1,1,1]
    array=np.array(blackAndWhiteImage)
    sensor_1 = array[ 80:110,160:190]
    result_1 = np.all((sensor_1 == 255))

    sensor_2 = array[ 80:110,305:335]
    result_2 = np.all((sensor_2 == 255))

    sensor_3 = array[ 80:110,450:480]
    result_3 = np.all((sensor_3 == 255))

    sensor_4 = array[ 370:400,160:190]
    result_4 = np.all((sensor_4 == 255))

    sensor_5 = array[ 370:400,305:335]
    result_5 = np.all((sensor_5 == 255))

    sensor_6 = array[ 370:400,450:480]
    result_6 = np.all((sensor_6 == 255))

    sensor_7 = array[ 225:255,160:190]
    result_7 = np.all((sensor_7 == 255))

    sensor_8 = array[ 225:255,450:480]
    result_8 = np.all((sensor_8 == 255))



    if result_1:
        cv2.rectangle(blackAndWhiteImage,(160,80),(190,110),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"0",(160,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[0]=0

    else:
        cv2.rectangle(blackAndWhiteImage,(160,80),(190,110),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"0",(160,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_2:
        cv2.rectangle(blackAndWhiteImage,(305,80),(335,110),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"1",(305,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[1]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(305,80),(335,110),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"1",(305,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_3:
        cv2.rectangle(blackAndWhiteImage,(450,80),(480,110),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"2",(450,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[2]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(450,80),(480,110),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"2",(450,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_4:
        cv2.rectangle(blackAndWhiteImage,(160,370),(190,400),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"3",(160,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[3]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(160,370),(190,400),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"3",(160,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_5:
        cv2.rectangle(blackAndWhiteImage,(305,370),(335,400),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"4",(305,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[4]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(305,370),(335,400),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"4",(305,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_6:
        cv2.rectangle(blackAndWhiteImage,(450,370),(480,400),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"5",(450,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[5]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(450,370),(480,400),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"5",(450,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_7:
        cv2.rectangle(blackAndWhiteImage,(160,225),(190,255),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"6",(160,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[6]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(160,225),(190,255),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"6",(160,255),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_8:
        cv2.rectangle(blackAndWhiteImage,(450,225),(480,255),(0,255,0),1)
        cv2.putText(blackAndWhiteImage,"7",(450,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[7]=0
    else:
        cv2.rectangle(blackAndWhiteImage,(450,225),(480,255),(0,0,255),1)
        cv2.putText(blackAndWhiteImage,"7",(450,255),font,1,(0,0,255),2,cv2.LINE_AA)



    i=0
    for contour in contours:
        epsilon = 0.01*cv2.arcLength(contour,True)
        approx = cv2.approxPolyDP(contour,epsilon,True)
        area = cv2.contourArea(approx)
        rect = cv2.minAreaRect(contour)
        box = cv2.boxPoints(rect)
        box = np.int0(box)


    # finding center point of shape
        M = cv2.moments(contour)
        if M['m00'] != 0.0:
            x = int(M['m10']/M['m00'])
            y = int(M['m01']/M['m00'])



        #if area >100:
        if i == 0 or area < 200:
            i = 1
            continue
        if len(approx) == 4 :

            (width, height)= rect[1]
            if ((width > height) and (rect[2]>0) and (rect[2]<45)):
                cv2.putText(blackAndWhiteImage, 'ligne_H', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=0
            if ((width > height) and (rect[2]>45) and (rect[2]<90)):
                cv2.putText(blackAndWhiteImage, 'ligne_V', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=1
            if ((width < height) and (rect[2]>0) and (rect[2]<45)):
                cv2.putText(blackAndWhiteImage, 'ligne_V', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=1
            if ((width < height) and (rect[2]>45) and (rect[2]<90)):
                cv2.putText(blackAndWhiteImage, 'ligne_H', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=0

            cv2.drawContours(blackAndWhiteImage,[box],0,(0,0,255),2)
            cv2.putText(blackAndWhiteImage, str(int(rect[2])), (x, y+20),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            value_sensor[8]=x
            value_sensor[9]=y
            value_sensor[11]=int(rect[2])

        if len(approx) == 6 :
            cv2.putText(blackAndWhiteImage, 'coin', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=4
        if len(approx) == 8 :
            cv2.putText(blackAndWhiteImage, 'T', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=3
            if (value_sensor[0]==0  and value_sensor[3]==0 and value_sensor[6]==0 and value_sensor[7]==1 ) :
                cv2.putText(blackAndWhiteImage, 'est', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[1]==1 and value_sensor[3]==0 and value_sensor[4]==0 and value_sensor[5]==0):
                cv2.putText(blackAndWhiteImage, 'sud', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[2]==0 and value_sensor[5]==0 and value_sensor[6]==1 and value_sensor[7]==0):
                cv2.putText(blackAndWhiteImage, 'ouest', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[0]==0 and value_sensor[1]==0 and value_sensor[2]==0 and value_sensor[4]==1):
                cv2.putText(blackAndWhiteImage, 'nord', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

        if len(approx) == 12 :
            cv2.putText(blackAndWhiteImage, 'croix', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=2


        cv2.drawContours(blackAndWhiteImage, [approx], -1,(0,255,0) , 2)



    if image==0:
        cv2.imshow('opencv', blackAndWhiteImage)
    if image==1:
        cv2.imshow('opencv', img)


    cv2.moveWindow("opencv", 800, 10)


    raw_capture.truncate(0)
    key = cv2.waitKey(1)



    msg = oscbuildparse.OSCMessage("/sensor", None, value_sensor)
    osc_send(msg, "raspberry")


    # if time.time()-temps > 1 :
    #     msg2 = oscbuildparse.OSCMessage("/ping", None, '0')
    #     osc_send(msg2, "chataigne")
    #     msg3 = oscbuildparse.OSCMessage("/ping", None, '1')
    #     osc_send(msg3, "chataigne")
    #     temps=time.time()

    osc_process()

osc_terminate()
