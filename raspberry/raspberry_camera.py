
import RPi.GPIO as GPIO
import serial
import signal

from osc4py3.as_eventloop import *
from osc4py3 import oscbuildparse
from picamera.array import PiRGBArray # Generates a 3D RGB array
from picamera import PiCamera # Provides a Python interface for the RPi Camera Module
import time # Provides time-related functions
import cv2 # OpenCV library
import numpy as np



osc_startup()
osc_udp_client("127.0.0.1", 5005, "raspberry")

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
contrast=int (reglage_lines[1])
thresh=int(reglage_lines[2])
reverse=int(reglage_lines[3])
print("brightness:" ,brightness, "/contrast: ",contrast,"tresh: ",thresh,"reverse: ",reverse)





ser = serial.Serial(
    port='/dev/ttyAMA0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0.01
)

image=0


signal.signal(signal.SIGINT, handler)


# Initialize the camera
camera = PiCamera()

# Set the camera resolution
camera.resolution = (640, 480)

# Set the number of frames per second
camera.framerate = 25
time.sleep(2)

camera.exposure_mode = 'off'
print(camera.analog_gain, camera.digital_gain)

camera.awb_mode= 'off'

# Generates a 3D RGB array and stores it in rawCapture

camera.hflip = True
camera.vflip = True
raw_capture = PiRGBArray(camera, size=(640, 480))
font = cv2.FONT_HERSHEY_SIMPLEX

# Wait a certain number of seconds to allow the camera time to warmup
time.sleep(0.1)

# Capture frames continuously from the camera
for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):
    camera.contrast = contrast
    camera.brightness = brightness

    value_sensor=[0,0,0,0,0,0,0,0]
    # Grab the raw NumPy array representing the image
    img = frame.array

    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    (thresh, blackAndWhiteImage) = cv2.threshold(gray, thresh, 255, cv2.THRESH_BINARY)
    color = cv2.cvtColor(blackAndWhiteImage,cv2.COLOR_GRAY2BGR)

    if reverse==1:
        color=(255-color)

    array=np.array(color)


    sensor_1 = array[ 80:110,160:190]
    result_1 = np.all((sensor_1 == 0))

    sensor_2 = array[ 80:110,305:335]
    result_2 = np.all((sensor_2 == 0))

    sensor_3 = array[ 80:110,450:480]
    result_3 = np.all((sensor_3 == 0))

    sensor_4 = array[ 370:400,160:190]
    result_4 = np.all((sensor_4 == 0))

    sensor_5 = array[ 370:400,305:335]
    result_5 = np.all((sensor_5 == 0))

    sensor_6 = array[ 370:400,450:480]
    result_6 = np.all((sensor_6 == 0))

    sensor_7 = array[ 225:255,160:190]
    result_7 = np.all((sensor_7 == 0))

    sensor_8 = array[ 225:255,450:480]
    result_8 = np.all((sensor_8 == 0))



    if result_1:
        cv2.rectangle(color,(160,80),(190,110),(0,255,0),1)
        cv2.putText(color,"0",(160,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[0]=1

    else:
        cv2.rectangle(color,(160,80),(190,110),(0,0,255),1)
        cv2.putText(color,"0",(160,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_2:
        cv2.rectangle(color,(305,80),(335,110),(0,255,0),1)
        cv2.putText(color,"1",(305,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[1]=1
    else:
        cv2.rectangle(color,(305,80),(335,110),(0,0,255),1)
        cv2.putText(color,"1",(305,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_3:
        cv2.rectangle(color,(450,80),(480,110),(0,255,0),1)
        cv2.putText(color,"2",(450,110),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[2]=1
    else:
        cv2.rectangle(color,(450,80),(480,110),(0,0,255),1)
        cv2.putText(color,"2",(450,110),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_4:
        cv2.rectangle(color,(160,370),(190,400),(0,255,0),1)
        cv2.putText(color,"3",(160,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[3]=1
    else:
        cv2.rectangle(color,(160,370),(190,400),(0,0,255),1)
        cv2.putText(color,"3",(160,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_5:
        cv2.rectangle(color,(305,370),(335,400),(0,255,0),1)
        cv2.putText(color,"4",(305,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[4]=1
    else:
        cv2.rectangle(color,(305,370),(335,400),(0,0,255),1)
        cv2.putText(color,"4",(305,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_6:
        cv2.rectangle(color,(450,370),(480,400),(0,255,0),1)
        cv2.putText(color,"5",(450,400),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[5]=1
    else:
        cv2.rectangle(color,(450,370),(480,400),(0,0,255),1)
        cv2.putText(color,"5",(450,400),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_7:
        cv2.rectangle(color,(160,225),(190,255),(0,255,0),1)
        cv2.putText(color,"6",(160,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[6]=1
    else:
        cv2.rectangle(color,(160,225),(190,255),(0,0,255),1)
        cv2.putText(color,"6",(160,255),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_8:
        cv2.rectangle(color,(450,225),(480,255),(0,255,0),1)
        cv2.putText(color,"7",(450,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[7]=1
    else:
        cv2.rectangle(color,(450,225),(480,255),(0,0,255),1)
        cv2.putText(color,"7",(450,255),font,1,(0,0,255),2,cv2.LINE_AA)


    if image==0:
        cv2.imshow('frame', color)
    if image==1:
        cv2.imshow('frame', gray)


    # Wait for keyPress for 1 millisecond
    key = cv2.waitKey(10)
    if key==81:
        contrast-=1
        if contrast<=-100:
            contrast=-100
        print("contrast:",contrast)
    if key==83:
        contrast+=1
        if contrast>=100:
            contrast=100
        print("contrast:",contrast)

    if key==82:
        if image==1:
            brightness+=1
            if brightness>=100:
                brightness=100
            print("brightness",brightness)


        else:
            thresh+=1
            if thresh>=255:
                thresh=255
            print("thresh:",thresh)
    if key==84:
        if image==1:
            brightness-=1
            if brightness<=0:
                brightness=0
            print("brightness",brightness)

        else:
            thresh-=1
            if thresh<=0:
                thresh=0
            print("thresh:",thresh)
    if key==105:
        image=abs(image-1)
    if key==114:
        reverse=abs(reverse-1)
    if key==13:
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

    #if key!=-1:
        #print(key)

    # Clear the stream in preparation for the next frame
    raw_capture.truncate(0)
    msg = oscbuildparse.OSCMessage("/sensor", None, value_sensor)
    osc_send(msg, "raspberry")
    osc_process()
    ligne = ser.readline().rstrip()
    try:
        if ligne.decode("utf-8").isnumeric()==True :
            ligne=str(int(ligne))

            if len(ligne)>2:
                mode=int(ligne[0])


                if mode==3:
                    msg = oscbuildparse.OSCMessage("/arrive", None, data)
                    osc_send(msg, "raspberry")
                    osc_process()
                    print("arrive")

                if mode==2:
                    batterie=(int(ligne[1:])*100)/1023
                    print ("batterie : ",int( batterie),"%")
                    #print("")
                    if int( batterie)<60 :
                        GPIO.output(17, GPIO.HIGH)
                    else:
                        GPIO.output(17, GPIO.LOW)
                if mode==1:
                    if int(ligne[1:3])!= 0 :
                        data=[int(ligne[1:3]),int(ligne[3:])]
                    else:
                        data=[0,0]
                    print(data)
                    msg = oscbuildparse.OSCMessage("/command", None, data)
                    osc_send(msg, "raspberry")
                    osc_process()
                    #print ("commande : ",ligne[1:3],"  step : ", ligne[3:])
                    #print("")
    except (UnicodeDecodeError,ValueError):
        pass
osc_terminate()
