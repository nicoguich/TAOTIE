import RPi.GPIO as GPIO
from osc4py3.as_eventloop import *
from osc4py3 import oscmethod as osm
from osc4py3 import oscbuildparse
import time
import random


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
ip="192.168.100.180"
port=5005
osc_udp_server(ip, port, "raspberry")
osc_udp_client("192.168.100.180", 5007, "chataigne")



dir=0
play=0
speed=1000
speed_control=1000
speed_temp=1000
dir_temp=0
home_temp = 0
lines = []
etape_perdu=0
speed_perdu=400


on_ligne_H=0
on_ligne_V=0
dir_ligne=0
check_croix=0
check_bord=0

sensor=[0,0,0,0,0,0,0,0,0,0,0,0]
dataMotor=[0,0,0,0,0,0]
coordX=-1
coordY=-1
go_to=0
go_toX=-1
go_toY=-1
max_X=3
max_Y=3




###############################################################""
def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global home_temp
    global on_ligne_H
    global dir_ligne

    #print("etape_perdu: ", etape_perdu)
    if etape_perdu == 0 :
        etape_perdu=1
    if etape_perdu==1:
        speed=speed_perdu
        dir=7
        if sensor[7]==1 and sensor[6]==0 :
            dir=10
        if sensor[7]==0 and sensor[6]==1:
            dir=9
        if sensor[7]==1 and sensor[6]==1 and sensor[0]==0 and sensor[1]==0 and sensor[2]==0 :
            etape_perdu=2
            dir=7

    if etape_perdu==2:
        speed=speed_perdu
        dir=7
        if sensor[11]>0 and sensor[11]<45:
            dir=9

        if sensor[11]>45 :
            dir=10

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
            dir_ligne=4
            home_temp=0





###########################################################################






###############################################################
def coordonate(*args):

    global go_toX
    global go_toY
    global go_to
    global coordX
    global coordY

    go_toX = args[0]
    go_toY = args[1]

    if ((go_toX!=coordX) or(go_toY!=coordY)):
        go_to = 1
    else :
        go_to=0

    print(go_toX,go_toY)

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
    global go_to
    global go_toX
    global go_toY
    global play
    global max_X
    global max_Y


    if (go_to==1):
        if (go_toX != coordX):
            if (go_toX<coordX):
                dir_ligne=4
            else:
                dir_ligne=5

        else :
            if (go_toY<coordY):
                dir_ligne=7
            else:
                dir_ligne=2

        if (go_toX==coordX and go_toY==coordY):
            go_to=0
            dir_ligne=0
            dir=0



    elif play==1:
        time.sleep(2)
        go_to=1
        go_toX=random.randint(0, max_X)
        go_toY=random.randint(0,max_Y)
        print ("new go_toX :", go_toX)
        print ("new go_toY :", go_toY)


    speed=speed_control

    if (on_ligne_H==1 and (dir_ligne==4 or dir_ligne==5)):
        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45:
            speed=speed_perdu
            dir=9

        if sensor[11]>45 and sensor[11]<99:
            speed=speed_perdu
            dir=10

        if (sensor[0]==1 or sensor[1]==1 or sensor[2]==1) and dir_ligne==4 and sensor[10]==0:
            speed=speed_perdu
            dir=1
        if (sensor[0]==1 or sensor[1]==1 or sensor[2]==1) and dir_ligne==5 and sensor[10]==0:
            speed=speed_perdu
            dir=3
        if (sensor[3]==1 or sensor[4]==1 or sensor[5]==1)  and dir_ligne==4 and sensor[10]==0:
            speed=speed_perdu
            dir=6
        if (sensor[3]==1 or sensor[4]==1 or sensor[5]==1)  and dir_ligne==4 and sensor[10]==0:
            speed=speed_perdu
            dir=8
        if sensor[1]==1 and sensor[4]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!= 4:

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("croix")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[10]!=2:
            check_croix=0



        if sensor[0]==0 and sensor[3]==0 and sensor[6]==0 and dir_ligne==4 and sensor[10]==3 and check_bord==0:

            print("T OUEST")
            coordX = 0

            dir=0
            dir_ligne=0
            check_bord=3
            on_ligne_V=1
            on_ligne_H=0
            if etape_perdu==4:
                dir=7
                dir_ligne=7
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and  dir_ligne==5 and sensor[10]==3 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X
            print("T EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[1]==1 and sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0:

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1
            if etape_perdu != 4:
                dir=0
                dir_ligne=0
            coordY=0

            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            print("T SUD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[4]==1 and sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0:

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1

            dir=0
            coordY=max_Y
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            print("T NORD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if  sensor[4]==1 and dir_ligne==4  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            coordY= max_Y
            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[1]==1 and dir_ligne==4  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            coordY= 0
            print("COIN SUD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[4]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X
            coordY= max_Y
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=1
            on_ligne_H=0
            coordX =max_X
            coordY = 0
            print("COIN SUD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)




    if (on_ligne_V==1 and (dir_ligne==2 or dir_ligne==7)):


        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45:
            speed=speed_perdu
            dir=9

        if sensor[11]>45 and sensor[11]<99:
            speed=speed_perdu
            dir=10

        if (sensor[0]==1 or sensor[6]==1 or sensor[3]==1) and dir_ligne==2 and sensor[10]==1:
            speed=speed_perdu
            dir=1
        if (sensor[0]==1 or sensor[6]==1 or sensor[3]==1) and dir_ligne==7 and sensor[10]==1:
            speed=speed_perdu
            dir=6
        if (sensor[2]==1 or sensor[7]==1 or sensor[5]==1)and dir_ligne==2 and sensor[10]==1:
            speed=speed_perdu
            dir=3
        if (sensor[2]==1 or sensor[7]==1 or sensor[5]==1) and dir_ligne==7 and sensor[10]==1:
            speed=speed_perdu
            dir=8
        if sensor[6]==1 and sensor[7]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!=4:
            print("croix")

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[10]!=2:
            check_croix=0

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and dir_ligne==7 and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            print("T SUD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)
        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and dir_ligne==2 and sensor[10]==3 and check_bord==0 and etape_perdu!=4:
            dir=0
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y
            print("T NORD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)


        if sensor[7]==1 and sensor[0]==0 and sensor[3]==0 and sensor[6]==0 and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4:

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1
            dir=0
            dir_ligne=0
            check_bord=3
            on_ligne_V=1
            on_ligne_H=0
            coordX = 0

            print("T OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[6]==1 and sensor[2]==0 and sensor[5]==0 and sensor[7]==0 and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4:

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1

            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X
            print("T EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[6]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=0
            on_ligne_H=1
            coordY =max_Y
            coordX = max_X
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[6]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            coordX = max_X
            print("COIN SUD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[7]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y
            coordX= 0

            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[7]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=0
            on_ligne_H=1
            etape_perdu=3
            coordX=0
            coordY=0
            print("COIN SUD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /X:",coordY)



    if sensor[10]!=3 and sensor[10]!=4:
        check_bord=0



    if (check_croix==1 and (dir_ligne==7 or dir_ligne==2)):

        on_ligne_V=1
        on_ligne_H=0
    if (check_croix==1 and (dir_ligne==4 or dir_ligne==5)):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==1 and dir_ligne==2):

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==5 or check_bord== 7) and dir_ligne==7:

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==6 or check_bord== 8) and dir_ligne==2:

        on_ligne_V=1
        on_ligne_H=0

    if (check_bord==7 or check_bord== 8) and dir_ligne==4:

        on_ligne_V=0
        on_ligne_H=1

    if (check_bord==5 or check_bord== 6) and dir_ligne==5:

        on_ligne_V=0
        on_ligne_H=1



    if (check_bord==2 and dir_ligne==7):

        on_ligne_V=1
        on_ligne_H=0
    if (check_bord==1 or check_bord==2) and (dir_ligne==4 or dir_ligne==5):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==3 and dir_ligne==5):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==4 and dir_ligne==4):

        on_ligne_V=0
        on_ligne_H=1
    if (check_bord==3 or check_bord==4) and (dir_ligne==2 or dir_ligne==7):

        on_ligne_V=1
        on_ligne_H=0




##########################################################################


#################################
def sensor_osc(*args):
    global sensor
    sensor=args
    print (sensor)

#######################################



#######################################
def game_pad(*args):

    global home_temp
    global etape_perdu
    global on_ligne_H
    global on_ligne_V
    global play
    global go_to
    global go_toX
    global go_toY


    home=args[0]
    play=args[1]
    if home==0:
        home_temp=0
        etape_perdu=0
        on_ligne_H=0
        on_ligne_V=0
        play=0
        coordX=-1
        coordY=-1
        go_to=0
        go_toX=-1
        go_toY=-1
        print("mode manuel")


    if play==1:
        print("mode auto")



    if home==1 and home_temp==0 and etape_perdu!=3:

        print("process home ligne....")
        home_temp=1
        etape_perdu=0
        on_ligne_H=0


    if home==1 and home_temp==0 and etape_perdu==3:

        home_temp=1
        etape_perdu=4
        print("process home coin....")



#################################################################

#################################################################
def send_osc_chataigne(*args):
    msg = oscbuildparse.OSCMessage("/dir", None, args)

    osc_send(msg, "chataigne")



###########################################################
#############################################################
#################################################################


osc_method("/coordonate", coordonate)
osc_method("/game_pad", game_pad)
osc_method("/sensor", sensor_osc)



while True:
    osc_process()
    if home_temp==1:
        alignement()
    if on_ligne_H==1 or on_ligne_V==1:
        reste_sur_ligne()
    if dir != dir_temp :
        send_osc_chataigne(dir)
        dir_temp=dir

osc_terminate()
