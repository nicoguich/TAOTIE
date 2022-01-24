import RPi.GPIO as GPIO
from osc4py3.as_eventloop import *
from osc4py3 import oscmethod as osm
import serial
import time


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(10, GPIO.OUT)
GPIO.output(10, GPIO.LOW)
GPIO.setup(27, GPIO.OUT)
GPIO.output(27, GPIO.LOW)
GPIO.setup(22, GPIO.OUT)
GPIO.output(22, GPIO.HIGH)


osc_startup()
arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ip="127.0.0.1"
port=5005
osc_udp_server(ip, port, "raspberry")



dir=0
step=0
speed=1000
speed_temp=1000
dir_temp=0
home_temp = 0
rec_temp=0
compteur_play=0
lines = []
arrive=0
led_ir_temp=0
etape_perdu=0
speed_perdu=600
play=0
start_released=0

sensor=[0,0,0,0,0,0,0,0]
dataMotor=[0,0,0,0,0]




###############################################################""
def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global compteur_play


    if etape_perdu == 0 :
        speed=speed_perdu
        dir=17
        if sensor[7]==1 and sensor[6]==0 :
            dir=19
        if sensor[7]==0 and sensor[6]==1:
            dir=20
        if sensor[7]==1 and sensor[6]==1 and sensor[3]==0 and sensor[5]==0:
            etape_perdu=1
            dir=14

    if etape_perdu==1:
        speed=speed_perdu
        dir=14
        if sensor[0]==1:
            dir=20
        if sensor[3]==1:
            dir=19
        if sensor[0]==1 and sensor[6]==1 and sensor[3]==1:
            dir =14
        if sensor[3]==1 and sensor[4]==1 and sensor[5]==1:
            dir =17
        if sensor[0]==1 and sensor[1]==1 and sensor[2]==1:
            dir =12
        if sensor[1]==1 and sensor[4]==1 and sensor[0]==0 and sensor[3]==0 :
            etape_perdu=2
            dir=0
            print("home_ok")
            if play==1:
                compteur_play+=1
###########################################################################



##########################################################################
def command(*args):
    global rec_temp
    global home_temp
    global speed

    data_step= args[1]
    data_dir= args[0]

    if rec_temp==1 and home_temp==0:
        print ("commande : ",data_dir,"  step : ", data_step,"  speed : ", speed)
        chemin.write(str(data_dir)+" "+str(data_step)+" "+str(speed)+"\n")
#################################################################################


#################################
def sensor_osc(*args):
    global sensor
    sensor=args
#######################################


###################################
def check_arrive(*args):
    global compteur_play
    print("arrive")
    compteur_play+=1
##################################

##########################################################
def controller(*args):
    global dir
    global dir_temp
    global speed
    global select
    global home_temp
    global etape_perdu
    global led_ir_temp
    global rec_temp
    global chemin
    global play
    global lines
    global start_released




    speed=args[1]
    select=args[2]
    home=args[3]
    start=args[4]
    led_ir=args[5]

    if select== 1 :
        dir=args[0]

    if home==1 and home_temp==0:
        print("process home....")
        home_temp=1
        etape_perdu=0
        if rec_temp==1:
            print ("commande : 255 255 255")
            chemin.write("255 255 255\n")
    if home_temp==1 and etape_perdu==2 :
        home_temp=0

    if led_ir==1 and led_ir_temp==0:
        led_ir_temp=1
        GPIO.output(22, GPIO.HIGH)
        dataMotor[0] = 0;
        dataMotor[1] = 0;
        dataMotor[2] = 255;
        dataMotor[3] = 0;
        dataMotor[4] = 150;
        for x in range (0,5):

        	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
        arduino_serial.write(b'\n')
    if led_ir==0 and led_ir_temp==1:
        led_ir_temp=0
        GPIO.output(22, GPIO.LOW)
        dataMotor[0] = 0;
        dataMotor[1] = 0;
        dataMotor[2] = 255;
        dataMotor[3] = 0;
        dataMotor[4] = 0;
        for x in range (0,5):

        	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
        arduino_serial.write(b'\n')

    if start==1 and rec_temp==1 and select==1 and start_released==0:
        start_released=1
        chemin.close()
        rec_temp=0
        print("rec off")
        GPIO.output(27, GPIO.LOW)
    if start==1 and rec_temp==0 and select==1 and start_released==0:
        start_released=1
        rec_temp=1
        print("rec on")
        GPIO.output(27, GPIO.HIGH)
        chemin = open("/home/pi/Desktop/chemin.txt","w")
    if start==1 and select==0 and play==0 and start_released==0:
        start_released=1
        play=1
        etape_perdu=0
        home_temp=1
        lines = []
        with open("/home/pi/Desktop/chemin.txt") as f:
            lines = f.readlines()
        print(lines)
        compteur_play=0
        print("play and process home....")
    if start==1 and select==0 and play==1 and start_released==0:
        print("pause")
        start_released=1
        play=2
    if start==1 and select==0 and play==2 and start_released==0:
        print("resume")
        start_released=1
        play=1
    if select==1:
        GPIO.output(10, GPIO.HIGH)
        play=0
    else:
        GPIO.output(10, GPIO.LOW)
    if start==0:
        start_released=0


#################################################################




########################################################################
def send_serial(dir,step,speed):
    global dir_temp
    global speed_temp

    if (dir_temp != dir or speed_temp != speed) and dir>=0 :

        print("dir:", dir)

        step_temp=step
        dir_temp=dir
        speed_temp=speed
        dataMotor[0] = step >> 8;
        dataMotor[1] = step - ((step >> 8) * 256);
        dataMotor[2] = dir;
        dataMotor[3] = speed >> 8;
        dataMotor[4] = speed - ((speed >> 8) * 256);
        for x in range (0,5):

        	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
        arduino_serial.write(b'\n')
################################################################################


######################################################################
def lecture():
    global compteur_play
    global lines
    global dir
    global step
    global speed
    global etape_perdu
    global home_temp

    home_temp=0

    if compteur_play < len(lines):
        data=lines[compteur_play].split()

        if int(data[0])!= 255 :
            speed=int(data[2])
            step=int(data[1])
            dir=int(data[0])-10
        else:
            etape_perdu=0
            dir=-1
            home_temp=1
        if dir==-10:
            compteur_play+=1
            dir=-1


    else:
        compteur_play=0
        etape_perdu=0
        home_temp=1
        print("fin")




osc_method("/controller", controller)
osc_method("/sensor", sensor_osc)
osc_method("/command", command)
osc_method("/arrive", check_arrive)

###########################################################
#############################################################
#################################################################
while True:

    osc_process()
    if home_temp==1:
        alignement()
    if etape_perdu==2 and play==1:
        lecture()
    send_serial(dir,step,speed)

osc_terminate()
