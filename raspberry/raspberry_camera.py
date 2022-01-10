
import RPi.GPIO as GPIO
import serial
import signal

from pythonosc import udp_client
from picamera.array import PiRGBArray # Generates a 3D RGB array
from picamera import PiCamera # Provides a Python interface for the RPi Camera Module
import time # Provides time-related functions
import cv2 # OpenCV library
import numpy as np



client = udp_client.SimpleUDPClient("127.0.0.1", 5005)
ligne_temp=701
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)

def handler(signum, frame):
    print("prout")
    GPIO.output(17, GPIO.LOW)
    GPIO.output(22, GPIO.LOW)
    exit(1)



GPIO.output(22, GPIO.HIGH)

ser = serial.Serial(
    port='/dev/ttyAMA0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0.01
)


signal.signal(signal.SIGINT, handler)


# Initialize the camera
camera = PiCamera()

# Set the camera resolution
camera.resolution = (640, 480)

# Set the number of frames per second
camera.framerate = 25

camera.exposure_mode = 'off'
camera.brightness = 50

# Generates a 3D RGB array and stores it in rawCapture

camera.hflip = True
camera.vflip = True
raw_capture = PiRGBArray(camera, size=(640, 480))
font = cv2.FONT_HERSHEY_SIMPLEX

# Wait a certain number of seconds to allow the camera time to warmup
time.sleep(0.1)

# Capture frames continuously from the camera
for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):
    value_sensor=[0,0,0,0,0,0,0,0]
    # Grab the raw NumPy array representing the image
    img = frame.array

    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    (thresh, blackAndWhiteImage) = cv2.threshold(gray, 220, 255, cv2.THRESH_BINARY)
    color = cv2.cvtColor(blackAndWhiteImage,cv2.COLOR_GRAY2BGR)
    array=np.array(color)
    sensor_1 = array[ 30:60,130:160]
    result_1 = np.all((sensor_1 == 0))

    sensor_2 = array[ 30:60,305:335]
    result_2 = np.all((sensor_2 == 0))

    sensor_3 = array[ 30:60,480:510]
    result_3 = np.all((sensor_3 == 0))

    sensor_4 = array[ 420:450,130:160]
    result_4 = np.all((sensor_4 == 0))

    sensor_5 = array[ 420:450,305:335]
    result_5 = np.all((sensor_5 == 0))

    sensor_6 = array[ 420:450,480:510]
    result_6 = np.all((sensor_6 == 0))

    sensor_7 = array[ 225:255,130:160]
    result_7 = np.all((sensor_7 == 0))

    sensor_8 = array[ 225:255,480:510]
    result_8 = np.all((sensor_8 == 0))



    if result_1:
        cv2.rectangle(color,(130,30),(160,60),(0,255,0),1)
        cv2.putText(color,"1",(130,60),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[0]=1

    else:
        cv2.rectangle(color,(130,30),(160,60),(0,0,255),1)
        cv2.putText(color,"1",(130,60),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_2:
        cv2.rectangle(color,(305,30),(335,60),(0,255,0),1)
        cv2.putText(color,"2",(305,60),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[1]=1
    else:
        cv2.rectangle(color,(305,30),(335,60),(0,0,255),1)
        cv2.putText(color,"2",(305,60),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_3:
        cv2.rectangle(color,(480,30),(510,60),(0,255,0),1)
        cv2.putText(color,"3",(480,60),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[2]=1
    else:
        cv2.rectangle(color,(480,30),(510,60),(0,0,255),1)
        cv2.putText(color,"3",(480,60),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_4:
        cv2.rectangle(color,(130,420),(160,450),(0,255,0),1)
        cv2.putText(color,"4",(130,450),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[3]=1
    else:
        cv2.rectangle(color,(130,420),(160,450),(0,0,255),1)
        cv2.putText(color,"4",(130,450),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_5:
        cv2.rectangle(color,(305,420),(335,450),(0,255,0),1)
        cv2.putText(color,"5",(305,450),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[4]=1
    else:
        cv2.rectangle(color,(305,420),(335,450),(0,0,255),1)
        cv2.putText(color,"5",(305,450),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_6:
        cv2.rectangle(color,(480,420),(510,450),(0,255,0),1)
        cv2.putText(color,"6",(480,450),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[5]=1
    else:
        cv2.rectangle(color,(480,420),(510,450),(0,0,255),1)
        cv2.putText(color,"6",(480,450),font,1,(0,0,255),2,cv2.LINE_AA)


    if result_7:
        cv2.rectangle(color,(130,225),(160,255),(0,255,0),1)
        cv2.putText(color,"7",(130,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[6]=1
    else:
        cv2.rectangle(color,(130,225),(160,255),(0,0,255),1)
        cv2.putText(color,"7",(130,255),font,1,(0,0,255),2,cv2.LINE_AA)

    if result_8:
        cv2.rectangle(color,(480,225),(510,255),(0,255,0),1)
        cv2.putText(color,"8",(480,255),font,1,(0,255,0),2,cv2.LINE_AA)
        value_sensor[7]=1
    else:
        cv2.rectangle(color,(480,225),(510,255),(0,0,255),1)
        cv2.putText(color,"8",(480,255),font,1,(0,0,255),2,cv2.LINE_AA)








    cv2.imshow('frame', color)
    #client.send_message("/filter", x)

    # Wait for keyPress for 1 millisecond
    key = cv2.waitKey(1) & 0xFF

    # Clear the stream in preparation for the next frame
    raw_capture.truncate(0)
    client.send_message("/sensor",value_sensor)
    ligne = ser.readline().rstrip()
    if not ligne:
        continue
    if ligne.decode("utf-8").isnumeric()==True :
        ligne = int(ligne)
        ligne_temp=ligne
    else:
        ligne=ligne_temp


    if ligne<700 :
        GPIO.output(17, GPIO.HIGH)
    else:
        GPIO.output(17, GPIO.LOW)

    print ("niveau batterie" , ligne)
