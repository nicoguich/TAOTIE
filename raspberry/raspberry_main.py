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
GPIO.output(22, GPIO.LOW)


time.sleep(2)
GPIO.output(10, GPIO.HIGH)
GPIO.output(27, GPIO.HIGH)
GPIO.output(22, GPIO.HIGH)
time.sleep(1)
GPIO.output(10, GPIO.LOW)
GPIO.output(27, GPIO.LOW)
GPIO.output(22, GPIO.LOW)
time.sleep(1)
GPIO.output(10, GPIO.HIGH)
GPIO.output(27, GPIO.HIGH)
GPIO.output(22, GPIO.HIGH)
time.sleep(1)
GPIO.output(10, GPIO.LOW)
GPIO.output(27, GPIO.LOW)
GPIO.output(22, GPIO.LOW)


osc_startup()
arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ip="127.0.0.1"
port=5005
osc_udp_server(ip, port, "raspberry")



dir=0
step=0
speed=1000
speed_control=1000
speed_temp=1000
dir_temp=0
home_temp = 0
rec_temp=0
compteur_play=0
lines = []
arrive=0
led_ir_temp=0
led_fat_temp=0
etape_perdu=0
speed_perdu=400
play=0
start_released=0
led_ir_released=0
led_fat_released=0

on_ligne_H=0
on_ligne_V=0
dir_ligne=0
check_croix=0
check_bord=0

sensor=[0,0,0,0,0,0,0,0,0,0,0,0]
dataMotor=[0,0,0,0,0,0]
coordX=-1
coordY=-1




###############################################################""
def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global compteur_play
    global home_temp
    global on_ligne_H
    global dir_ligne

    print("etape_perdu: ", etape_perdu)
    if etape_perdu == 0 :
        led_ir_control(1)
        etape_perdu=1
    if etape_perdu==1:
        speed=speed_perdu
        dir=17
        if sensor[7]==1 and sensor[6]==0 :
            dir=19
        if sensor[7]==0 and sensor[6]==1:
            dir=20
        if sensor[7]==1 and sensor[6]==1 and sensor[0]==0 and sensor[1]==0 and sensor[2]==0 :
            etape_perdu=2
            dir=17

    if etape_perdu==2:
        speed=speed_perdu
        dir=17
        if sensor[11]>0 and sensor[11]<45:
            dir=20

        if sensor[11]>45 :
            dir=19

        if sensor[11]==0 or sensor[11]==90:
            print("home_ok")
            #led_ir_control(0)
            etape_perdu=3
            home_temp=0
            dir=0
            on_ligne_H=1
            dir_ligne=0


    if etape_perdu==4:

        if on_ligne_H==1:
            dir_ligne=14
            home_temp=0





###########################################################################






###############################################################
def coordonate():

    global coordX
    global coordY












###########################################################################





###############################################################""
def reste_sur_ligne():
    global dir
    global dir_ligne
    global on_ligne_H
    global on_ligne_V
    global sensor
    global speed
    global speed_control
    global check_croix
    global check_bord
    global etape_perdu
    global coordX
    global coordY

    print(coordX, coordY)



    speed=speed_control

    if (on_ligne_H==1 and (dir_ligne==14 or dir_ligne==15)):
        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45:
            speed=speed_perdu
            dir=20

        if sensor[11]>45 and sensor[11]<99:
            speed=speed_perdu
            dir=19

        if sensor[0]==1 and sensor[1]==1 and sensor[2]==1:
            speed=speed_perdu
            dir=12
        if sensor[3]==1 and sensor[4]==1 and sensor[5]==1:
            speed=speed_perdu
            dir=17
        if sensor[1]==1 and sensor[4]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!= 4:
            dir=0
            dir_ligne=0
            check_croix=1
            if (dir_ligne==14):
                coordX += -1
            else:
                coordX += 1
        if sensor[10]!=2:
            check_croix=0



        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and dir_ligne==14 and sensor[10]==3 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=3
            on_ligne_V=1
            on_ligne_H=0
            print("T OUEST")
            coordX = 0
            if etape_perdu==4:
                dir=17
                dir_ligne=17

        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and dir_ligne==15 and sensor[10]==3 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            coordX += 1
            print("T EST")

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[1]==1 and (dir_ligne==14 or dir_ligne==15) and sensor[10]==3 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            if (dir_ligne==14):
                coordX += -1
            else:
                coordX += 1
            print("T SUD")

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[4]==1 and (dir_ligne==14 or dir_ligne==15) and sensor[10]==3 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            if (dir_ligne==14):
                coordX += -1
            else:
                coordX += 1
            print("T NORD")

        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[4]==1 and dir_ligne==14  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            print("COIN NORD OUEST")

        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[1]==1 and dir_ligne==14  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            print("COIN SUD OUEST")

        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[4]==1 and dir_ligne==15  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=1
            on_ligne_H=0
            coordX += 1
            print("COIN NORD EST")

        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==15  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=1
            on_ligne_H=0
            coordX += 1
            print("COIN SUD EST")





    if (on_ligne_V==1 and (dir_ligne==12 or dir_ligne==17)):


        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45:
            speed=speed_perdu
            dir=20

        if sensor[11]>45 and sensor[11]<99:
            speed=speed_perdu
            dir=19

        if sensor[0]==1 and sensor[6]==1 and sensor[3]==1:
            speed=speed_perdu
            dir=14
        if sensor[2]==1 and sensor[7]==1 and sensor[5]==1:
            speed=speed_perdu
            dir=15
        if sensor[6]==1 and sensor[7]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_croix=1
            if (dir_ligne==17):
                coordY += -1
            else:
                coordY += 1


        if sensor[10]!=2:
            check_croix=0

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and dir_ligne==17 and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            print("T SUD")
        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and dir_ligne==12 and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            coordY += 1
            print("T NORD")


        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[7]==1 and  (dir_ligne==12 or dir_ligne==17) and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=3
            on_ligne_V=1
            on_ligne_H=0
            if (dir_ligne==17):
                coordY += -1
            else:
                coordY += 1

            print("T OUEST")

        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[6]==1 and  (dir_ligne==12 or dir_ligne==17) and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            if (dir_ligne==17):
                coordY += -1
            else:
                coordY += 1
            print("T EST")

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[6]==1 and dir_ligne==12  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=0
            on_ligne_H=1
            coordY +=1
            print("COIN NORD EST")

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[6]==1 and dir_ligne==17  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            print("COIN SUD EST")

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[7]==1 and dir_ligne==12  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=0
            on_ligne_H=1
            coordY += 1

            print("COIN NORD OUEST")

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[7]==1 and dir_ligne==17  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=0
            on_ligne_H=1
            etape_perdu=3
            coordX=0
            coordY=0
            print("COIN SUD OUEST")



    if sensor[10]!=3 and sensor[10]!=4:
        check_bord=0



    if (check_croix==1 and (dir_ligne==17 or dir_ligne==12)):

        on_ligne_V=1
        on_ligne_H=0
    if (check_croix==1 and (dir_ligne==14 or dir_ligne==15)):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==1 and dir_ligne==12):

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==5 or check_bord== 7) and dir_ligne==17:

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==6 or check_bord== 8) and dir_ligne==12:

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==7 or check_bord== 8) and dir_ligne==14:

        on_ligne_V=0
        on_ligne_H=1

    if (check_bord==5 or check_bord== 6) and dir_ligne==15:

        on_ligne_V=0
        on_ligne_H=1



    if (check_bord==2 and dir_ligne==17):

        on_ligne_V=1
        on_ligne_H=0
    if (check_bord==1 or check_bord==2) and (dir_ligne==14 or dir_ligne==15):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==3 and dir_ligne==15):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==4 and dir_ligne==14):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==3 or check_bord==4) and (dir_ligne==12 or dir_ligne==17):

        on_ligne_V=1
        on_ligne_H=0




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
def led_ir_control(state):
    global led_ir_temp
    global led_ir

    if state!=led_ir_temp :
        if state==1:
            led_ir_temp=1
            GPIO.output(22, GPIO.HIGH)
            dataMotor[0] = 0;
            dataMotor[1] = 0;
            dataMotor[2] = 0;
            dataMotor[3] = 255;
            dataMotor[4] = 0;
            dataMotor[5] = 255;
            for x in range (0,6):

            	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
            arduino_serial.write(b'\n')
            time.sleep(0.5)
        # else:
        #     led_ir_temp=0
        #     GPIO.output(22, GPIO.LOW)
        #     dataMotor[0] = 0;
        #     dataMotor[1] = 0;
        #     dataMotor[2] = 0;
        #     dataMotor[3] = 255;
        #     dataMotor[4] = 0;
        #     dataMotor[5] = 0;
        #     for x in range (0,6):
        #
        #     	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
        #     arduino_serial.write(b'\n')


##########################################################

def led_fat_control(state):
    global led_fat_temp
    global led_fat

    #print(state)
    if state!=led_fat_temp :
        if state==1:
            led_fat_temp=1
            dataMotor[0] = 0;
            dataMotor[1] = 0;
            dataMotor[2] = 0;
            dataMotor[3] = 200;
            dataMotor[4] = 0;
            dataMotor[5] = 200;
            for x in range (0,6):

            	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
            arduino_serial.write(b'\n')
        else:
            led_fat_temp=0
            dataMotor[0] = 0;
            dataMotor[1] = 0;
            dataMotor[2] = 0;
            dataMotor[3] = 200;
            dataMotor[4] = 0;
            dataMotor[5] = 0;
            for x in range (0,6):

            	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
            arduino_serial.write(b'\n')


##########################################################




def controller(*args):
    global dir
    global dir_temp
    global speed
    global select
    global home_temp
    global etape_perdu
    global led_ir_temp
    global led_fat_temp
    global rec_temp
    global chemin
    global play
    global lines
    global start_released
    global led_ir_released
    global led_fat_released
    global compteur_play
    global dir_ligne
    global on_ligne_H
    global speed_control


    speed=args[1]
    speed_control=speed
    select=args[2]
    home=args[3]
    start=args[4]
    led_ir=args[5]
    led_fat=args[6]
    stop=args[7]




    if select== 1 :
        if args[8]!=0:
            dir_ligne=args[8]

        dir=args[0]

        if dir!=0:
            on_ligne_H=0
            home_temp=0
            etape_perdu=0

    if home==1 and home_temp==0 and etape_perdu==0:

        print("process home....")
        home_temp=1
        etape_perdu=0
        on_ligne_H=0
        if rec_temp==1:
            print ("commande : 255 255 255")
            chemin.write("255 255 255\n")

    if home==1 and home_temp==0 and etape_perdu==3:

        print("process home coordonate....")
        home_temp=1
        etape_perdu=4




    if led_ir==1 and led_ir_temp==0 and led_ir_released==0 :
        led_ir_released=1
        led_ir_control(1)

    if led_ir==1 and led_ir_temp==1 and led_ir_released==0:
        led_ir_released=1
        led_ir_control(0)


    if led_fat==1 and led_fat_temp==0 and led_fat_released==0 :
        led_fat_released=1
        led_fat_control(1)

    if led_fat==1 and led_fat_temp==1 and led_fat_released==0:
        led_fat_released=1
        led_fat_control(0)

    if start==1 and rec_temp==1 and select==1 and start_released==0:
        start_released=1
        chemin.close()
        rec_temp=0
        compteur_play=0
        print("rec off")

    if start==1 and rec_temp==0 and select==1 and start_released==0:
        start_released=1
        rec_temp=1
        print("rec on")

        chemin = open("/home/pi/Desktop/chemin.txt","w")
    if start==1 and select==0 and play==0 and start_released==0 :
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
    if led_ir==0:
        led_ir_released=0
    if led_fat==0:
        led_fat_released=0
    if play==1 or rec_temp==1:
        GPIO.output(27, GPIO.HIGH)
    else:
        GPIO.output(27, GPIO.LOW)
    if stop==1:
        led_fat_temp=0
        dataMotor[0] = 0;
        dataMotor[1] = 0;
        dataMotor[2] = 0;
        dataMotor[3] = 201;
        dataMotor[4] = 0;
        dataMotor[5] = 0;
        for x in range (0,6):

            arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
        arduino_serial.write(b'\n')


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
        step_byte=step.to_bytes(3,byteorder='big')
        print("step :",step,"/ bytes: ", step_byte)
        dataMotor[0] = step_byte[0];
        dataMotor[1] = step_byte[1];
        dataMotor[2] = step_byte[2];
        dataMotor[3] = dir;
        dataMotor[4] = speed >> 8;
        dataMotor[5] = speed - ((speed >> 8) * 256);
        for x in range (0,6):

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
led_ir_control(1)
while True:
    osc_process()
    if home_temp==1:
        alignement()
    if on_ligne_H==1 or on_ligne_V==1:
        reste_sur_ligne()

    send_serial(dir,step,speed)

osc_terminate()
