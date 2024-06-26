
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

import netifaces


sel_control=1
control_value=0
batterie=50
brightness_osc=[0]
contrast_osc=[0]
thresh_osc=[0]
reverse_osc=[0]
taille_grille_X_osc=[0]
taille_grille_Y_osc=[0]
nb_table_osc=[0]
id_osc=[0]
main_osc=[0,0,0]
value_sensor_temp=[1,1,1,1,1,1,1,1,1,1,1,1] # [1 for i in range(10)]


temps= time.time()

addrs = netifaces.ifaddresses('wlan0')
ip = addrs[netifaces.AF_INET][0]['addr']
osc_startup()
osc_udp_client(ip, 5005, "raspberry")
osc_udp_server(ip, 5006, "camera")
osc_udp_client(ip, 5007, "chataigne")


#GPIO.setwarnings(False)
#GPIO.setmode(GPIO.BCM)
#GPIO.setup(10, GPIO.OUT)


def handler(signum, frame):
    print("prout")
#    GPIO.output(10, GPIO.LOW)

    exit(1)
    
#def fct(params):
# 
# return val1, val2, val3


#...
# a, b, c = fct(parametres)


reglage_lines = []

with open("/home/pi/Desktop/reglage_camera.txt") as f:
    reglage_lines = f.readlines()
brightness=int (reglage_lines[0])
brightness_osc[0]=int (reglage_lines[0]) # brightness_osc = [int (reglage_lines[0])]
contrast=int (reglage_lines[1])
contrast_osc[0]=int (reglage_lines[1])
thresh=int(reglage_lines[2])
thresh_osc[0]=int (reglage_lines[2])
reverse=int(reglage_lines[3])
reverse_osc[0]=int (reglage_lines[3])
taille_grille_X_osc[0]= int (reglage_lines[4])
taille_grille_Y_osc[0]= int (reglage_lines[5])
nb_table_osc[0]= int (reglage_lines[6])
id_osc[0]=int (reglage_lines[7])
main_osc[0]=int (reglage_lines[4])
main_osc[1]=int (reglage_lines[5])
main_osc[2]=int (reglage_lines[6])


print("brightness:" ,brightness, "/contrast: ",contrast,"tresh: ",thresh,"reverse: ",reverse, "id: ",id_osc)
msg0 = oscbuildparse.OSCMessage("/brightness", None, brightness_osc)
msg1 = oscbuildparse.OSCMessage("/contrast", None, contrast_osc)
msg2 = oscbuildparse.OSCMessage("/thresh", None, thresh_osc)
msg3 = oscbuildparse.OSCMessage("/reverse", None, reverse_osc)
msg4 = oscbuildparse.OSCMessage("/taille_grille_X", None, taille_grille_X_osc)
msg5 = oscbuildparse.OSCMessage("/taille_grille_Y", None, taille_grille_Y_osc)
msg6 = oscbuildparse.OSCMessage("/nb_table", None, nb_table_osc)
msg7 = oscbuildparse.OSCMessage("/grille", None, main_osc)
msg8 = oscbuildparse.OSCMessage("/id",None, id_osc)

osc_send(msg0, "chataigne")
osc_send(msg1, "chataigne")
osc_send(msg2, "chataigne")
osc_send(msg3, "chataigne")
osc_send(msg4, "chataigne")
osc_send(msg5, "chataigne")
osc_send(msg6, "chataigne")
osc_send(msg7, "raspberry")
osc_send(msg8, "raspberry")


def control_image(*args):
    global sel_control
    global brightness
    global contrast
    global thresh
    global reverse
    global image
    global id
    

    sel_control=args[0]
    brightness=args[1]
    contrast=args[2]
    thresh=args[3]
    reverse = args[4]
    image = args[5]
    save = args[6]
    taille_grille_X= args[7]
    taille_grille_Y= args[8]
    nb_table= args[9]
    id = args[10]
    camera.contrast = contrast
    camera.brightness = brightness

    print("enregistrement reglage camera...")
    reglage_camera = open("/home/pi/Desktop/reglage_camera.txt","w")
    print("...")
    reglage_camera.write(str(int(brightness))+"\n")
    print("...bright")
    reglage_camera.write(str(int(contrast))+"\n")
    print("...cont")
    reglage_camera.write(str(int(thresh))+"\n")
    print("...thresh")
    reglage_camera.write(str(int(reverse))+"\n")
    print("...reserse")
    reglage_camera.write(str(int(taille_grille_X))+"\n")
    print("...taille grille X")
    reglage_camera.write(str(int(taille_grille_Y))+"\n")
    print("...taille grille Y")
    reglage_camera.write(str(int(nb_table))+"\n")
    print("...nb table")
    reglage_camera.write(str(int(id))+"\n")
    print("...id")
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

camera.hflip = True
camera.vflip = True
raw_capture = PiRGBArray(camera, size=(640, 480))
font = cv2.FONT_HERSHEY_SIMPLEX

# Wait a certain number of seconds to allow the camera time to warmup
time.sleep(1)



osc_method("/image", control_image)
#GPIO.output(10, GPIO.HIGH)


for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):
    osc_process()

    if camera.digital_gain!=1:
        set_digital_gain(camera, 1)
        set_analog_gain(camera, 1)

    img = frame.array
    img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    (thresh, blackAndWhiteImage) = cv2.threshold(img,thresh, 255, cv2.THRESH_BINARY)


    if reverse==1:
        blackAndWhiteImage=(255-blackAndWhiteImage)


    blackAndWhiteImage = cv2.rectangle(blackAndWhiteImage, (0, 0), (640, 480), (255), 3)
    contours, hierarchy = cv2.findContours( blackAndWhiteImage, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    blackAndWhiteImage = cv2.cvtColor(blackAndWhiteImage,cv2.COLOR_GRAY2BGR)

    
    i=0
    value_sensor=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
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
        if i == 0 or area < 3000:
            i = 1
            continue
        blackAndWhiteImage[:] = (255, 255, 255)
        cv2.fillPoly(blackAndWhiteImage, [approx],(0,0,0),8,0 )
        


        array=np.array(blackAndWhiteImage)
        sensor_1 = array[ 50:80,130:160]
        result_1w = np.all((sensor_1 == 255))
        result_1b = np.all((sensor_1 == 0))


        sensor_2 = array[ 50:80,305:335]
        result_2w = np.all((sensor_2 == 255))
        result_2b = np.all((sensor_2 == 0))


        sensor_3 = array[ 50:80,480:510]
        result_3w = np.all((sensor_3 == 255))
        result_3b = np.all((sensor_3 == 0))


        sensor_4 = array[ 400:430,130:160]
        result_4w = np.all((sensor_4 == 255))
        result_4b = np.all((sensor_4 == 0))


        sensor_5 = array[ 400:430,305:335]
        result_5w = np.all((sensor_5 ==255))
        result_5b = np.all((sensor_5 ==0))


        sensor_6 = array[ 400:430,480:510]
        result_6w = np.all((sensor_6 ==255))
        result_6b = np.all((sensor_6 ==0))


        sensor_7 = array[ 225:255,130:160]
        result_7w = np.all((sensor_7 == 255))
        result_7b = np.all((sensor_7 == 0))


        sensor_8 = array[ 225:255,480:510]
        result_8w = np.all((sensor_8 == 255))
        result_8b = np.all((sensor_8 == 0))




        if result_1w:
            cv2.rectangle(blackAndWhiteImage,(130,50),(160,80),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"0",(130,80),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[0]=0

        if result_1b:
            cv2.rectangle(blackAndWhiteImage,(130,50),(160,80),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"0",(130,80),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[0]=1

        if result_2w:
            cv2.rectangle(blackAndWhiteImage,(305,50),(335,80),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"1",(305,80),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[1]=0
        if result_2b:
            cv2.rectangle(blackAndWhiteImage,(305,50),(335,80),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"1",(305,80),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[1]=1

        if result_3w:
            cv2.rectangle(blackAndWhiteImage,(480,50),(510,80),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"2",(480,80),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[2]=0
        if result_3b:
            cv2.rectangle(blackAndWhiteImage,(480,50),(510,80),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"2",(480,80),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[2]=1

        if result_4w:
            cv2.rectangle(blackAndWhiteImage,(130,400),(160,430),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"3",(130,430),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[3]=0
        if result_4b:
            cv2.rectangle(blackAndWhiteImage,(130,400),(160,400),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"3",(130,430),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[3]=1


        if result_5w:
            cv2.rectangle(blackAndWhiteImage,(305,400),(335,430),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"4",(305,430),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[4]=0
        if result_5b:
            cv2.rectangle(blackAndWhiteImage,(305,400),(335,400),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"4",(305,430),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[4]=1


        if result_6w:
            cv2.rectangle(blackAndWhiteImage,(480,400),(510,430),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"5",(480,430),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[5]=0
        if result_6b:
            cv2.rectangle(blackAndWhiteImage,(480,400),(510,430),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"5",(480,430),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[5]=1


        if result_7w:
            cv2.rectangle(blackAndWhiteImage,(130,225),(160,255),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"6",(130,255),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[6]=0
        if result_7b:
            cv2.rectangle(blackAndWhiteImage,(130,225),(160,255),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"6",(130,255),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[6]=1

        if result_8w:
            cv2.rectangle(blackAndWhiteImage,(480,225),(510,255),(0,255,0),1)
            cv2.putText(blackAndWhiteImage,"7",(480,255),font,1,(0,255,0),2,cv2.LINE_AA)
            value_sensor[7]=0
        if result_8b:
            cv2.rectangle(blackAndWhiteImage,(480,225),(510,255),(0,0,255),1)
            cv2.putText(blackAndWhiteImage,"7",(480,255),font,1,(0,0,255),2,cv2.LINE_AA)
            value_sensor[7]=1









        
        value_sensor[8]=x
        value_sensor[9]=y
        value_sensor[11]=int(rect[2])

        if len(approx) == 4 :


            (width, height)= rect[1]
            if ((width > height) and (rect[2]>=0) and (rect[2]<45)):
                cv2.putText(blackAndWhiteImage, 'ligne_H', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                cv2.putText(blackAndWhiteImage, str(int(rect[0][1])), (x, y+20),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                
                value_sensor[10]=0
            if ((width > height) and (rect[2]>45) and (rect[2]<=90)):
                cv2.putText(blackAndWhiteImage, 'ligne_V', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                cv2.putText(blackAndWhiteImage, str(int(rect[0][0])), (x, y+20),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=1
            if ((width < height) and (rect[2]>=0) and (rect[2]<45)):
                cv2.putText(blackAndWhiteImage, 'ligne_V', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                cv2.putText(blackAndWhiteImage, str(int(rect[0][0])), (x, y+20),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=1
            if ((width < height) and (rect[2]>45) and (rect[2]<=90)):
                cv2.putText(blackAndWhiteImage, 'ligne_H', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                cv2.putText(blackAndWhiteImage, str(int(rect[0][1])), (x, y+20),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
                value_sensor[10]=0
            cv2.putText(blackAndWhiteImage, str(float(rect[2])), (x, y+40),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
           # cv2.drawContours(blackAndWhiteImage,[box],0,(0,0,255),2)
            



        if len(approx) == 6 :
            cv2.putText(blackAndWhiteImage, 'coin', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=4
        if len(approx) == 8 :
            cv2.putText(blackAndWhiteImage, 'T', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=3
            if (value_sensor[0]==0  and value_sensor[3]==0 and value_sensor[6]==0 and value_sensor[7]==1 ) :
                cv2.putText(blackAndWhiteImage, 'ouest', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[1]==1 and value_sensor[3]==0 and value_sensor[4]==0 and value_sensor[5]==0):
                cv2.putText(blackAndWhiteImage, 'sud', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[2]==0 and value_sensor[5]==0 and value_sensor[6]==1 and value_sensor[7]==0):
                cv2.putText(blackAndWhiteImage, 'est', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            if ( value_sensor[0]==0 and value_sensor[1]==0 and value_sensor[2]==0 and value_sensor[4]==1):
                cv2.putText(blackAndWhiteImage, 'nord', (x, y+15),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

        if len(approx) == 12 :
            cv2.putText(blackAndWhiteImage, 'croix', (x, y),cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            value_sensor[10]=2


       # cv2.drawContours(blackAndWhiteImage, [approx], -1,(0,255,0) , 2)
        


    if image==0:
        cv2.imshow('opencv', blackAndWhiteImage)
    if image==1:
        cv2.imshow('opencv', img)


   # cv2.moveWindow("opencv", 700, 100)


    raw_capture.truncate(0)
    key = cv2.waitKey(1)



    if value_sensor != value_sensor_temp:
        msg = oscbuildparse.OSCMessage("/sensor", None, value_sensor)
        osc_send(msg, "raspberry")
        value_sensor_temp = value_sensor




    if time.time()-temps > 1 :
        msg2 = oscbuildparse.OSCMessage("/ping_cam", None, '1')
        osc_send(msg2, "chataigne")
        msg3 = oscbuildparse.OSCMessage("/ping_cam", None, '0')
        osc_send(msg3, "chataigne")
        temps=time.time()

    osc_process()

osc_terminate()
