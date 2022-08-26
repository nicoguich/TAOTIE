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
osc_udp_client("192.168.100.117", 5008, "all")



dir=0
play=0
bot_state=1
speed=1000
speed_control=1000
speed_temp=1000
dir_temp=0
home_temp = 0
lines = []
etape_perdu=0
speed_perdu=400
verin=0
verin_temp=0
nb_table=6
table_random=0
table_random_temp=0



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
max_X=6
max_Y=4



coordonate_table_lines = []
coordonate_table = [[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1]]

with open("/home/pi/Desktop/coordonate_table.txt") as f:
    coordonate_table_lines = f.readlines()


for x in range (0 , len(coordonate_table_lines)):
    temp_coordonate="".join(coordonate_table_lines[x])
    temp_coordonate_list = temp_coordonate.split(' ')
    coordonate_table[x][0]=int(temp_coordonate_list[0])
    coordonate_table[x][1]=int(temp_coordonate_list[1])






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
            etape_perdu=4
            #home_temp=0
            dir=0
            on_ligne_H=1
            dir_ligne=0


    if etape_perdu==4:

        if on_ligne_H==1:
            dir_ligne=4
            #home_temp=0





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
    global bot_state
    global coordonate_table
    global table_random
    global table_random_temp
    global verin




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
            if bot_state==0:
                time.sleep(2)
                bot_state=1
            elif bot_state==1:
                verin=1
                bot_state=2
            elif bot_state==2:

                coordonate_table[table_random][0]=coordX
                coordonate_table[table_random][1]=coordY
                rec_coordonate = open("/home/pi/Desktop/coordonate_table.txt","w")
                print("rec table...")
                for x in range (0 , len(coordonate_table)):

                    rec_coordonate.write(str(int(coordonate_table[x][0]))+" "+str(int(coordonate_table[x][1]))+"\n")

                rec_coordonate.close()
                verin=0
                bot_state=1

    elif play==1:

        go_to=1

        if bot_state==0:
            go_toX=random.randint(0, max_X)
            go_toY=random.randint(0,max_Y)

        elif bot_state==1:
            while table_random==table_random_temp :
                table_random= random.randint(0,nb_table)
            table_random_temp=table_random
            go_toX=coordonate_table[table_random][0]
            go_toY=coordonate_table[table_random][1]
            print ("table choisie : ",table_random," ///// max : ", nb_table)

        elif bot_state==2:
            coordonate_exist=0
            bloque=0
            coordX_temp=coordX
            coordY_temp=coordY

            for x in range (0,nb_table+1):
                if (coordonate_table[x][0]==coordX-1 and coordonate_table[x][1]==coordY):
                    bloque+=1
                if (coordonate_table[x][0]==coordX+1 and coordonate_table[x][1]==coordY):
                    bloque+=1
                if (coordonate_table[x][0]==coordX and coordonate_table[x][1]==coordY-1):
                    bloque+=1
                if (coordonate_table[x][0]==coordX and coordonate_table[x][1]==coordY+1):
                    bloque+=1
            print ("bloque : ", bloque)
            if bloque<4:
                while coordonate_exist<nb_table :
                    coordonate_exist=0
                    go_toX=coordX_temp
                    go_toY=coordY_temp
                    print ("coord : ", coordX, coordY)

                    random_axe = random.randint(0,1)
                    if random_axe==0:
                        go_toX=random.randint(coordX-1,coordX + 1)
                        if (go_toX>max_X):
                            go_toX=max_X
                        if (go_toX<0):
                            go_toX=0
                    else:
                        go_toY=random.randint(coordY-1,coordY + 1)
                        if (go_toY>max_Y):
                            go_toY=max_Y
                        if (go_toY<0):
                            go_toY=0
                    print ("goto random: ", go_toX, go_toY)
                    for x in range (0 , nb_table+1):

                        if (coordonate_table[x][0]==go_toX and coordonate_table[x][1]==go_toY) or (go_toX==coordX and go_toY==coordY):
                            coordonate_exist=0
                            print ("same coordonate table", x)


                        else:
                            print ("ok", x)
                            coordonate_exist+=1
            else :
                bot_state=2







        print ("new go_toX :", go_toX)
        print ("new go_toY :", go_toY)
        new_coordonate=[go_toX,go_toY]
        msg = oscbuildparse.OSCMessage("/new_coordonate", None, new_coordonate)
        osc_send(msg, "all")
        print("bot_state: ", bot_state)






    speed=speed_control

    if (on_ligne_H==1 and (dir_ligne==4 or dir_ligne==5)):
        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45  and sensor[10]==0:
            speed=speed_perdu
            dir=9

        if sensor[11]>45 and sensor[11]<99  and sensor[10]==0:
            speed=speed_perdu
            dir=10

        if sensor[9]<200 and dir_ligne==4 and sensor[10]==0:
            speed=speed_perdu
            dir=1
        if sensor[9]<200 and dir_ligne==5 and sensor[10]==0:
            speed=speed_perdu
            dir=3

        if sensor[9]>250  and dir_ligne==4 and sensor[10]==0:
            speed=speed_perdu
            dir=6


        if sensor[9]>250 and dir_ligne==5 and sensor[10]==0:
            speed=speed_perdu

            dir=8
        if dir_ligne==4 and (sensor[0]==0 or sensor[3]==0) and sensor[1]==1 and sensor[4]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!= 4:

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("croix")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if check_croix==1 and (sensor[10]==0 or sensor[10]==1):
            check_croix=0
            print ("check croix 0")
            time.sleep(1)

        if dir_ligne==5 and (sensor[2]==0 or sensor[5]==0) and sensor[1]==1 and sensor[4]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!= 4:

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("croix")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if check_croix==1 and (sensor[10]==0 or sensor[10]==1):
            check_croix=0
            print ("check croix 0")
            time.sleep(1)




        if sensor[0]==0 and sensor[3]==0 and sensor[6]==0 and sensor[7]==1 and dir_ligne==4 and sensor[10]==3 and check_bord==0 and check_croix==0:

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
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[6]==1 and  dir_ligne==5 and sensor[10]==3 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X
            print("T EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)



        if sensor[1]==1 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0 and check_croix==0 and coordY==0:

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
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[4]==1 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0 and check_croix==0 and coordY==max_Y:

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
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if  sensor[4]==1 and sensor[3]==0 and sensor[6]==0  and dir_ligne==4  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            coordY= max_Y
            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[1]==1 and dir_ligne==4  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            coordY= 0
            etape_perdu=5
            home_temp=0
            print("COIN SUD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[4]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X
            coordY= max_Y
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=1
            on_ligne_H=0
            coordX =max_X
            coordY = 0
            print("COIN SUD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)




    if (on_ligne_V==1 and (dir_ligne==2 or dir_ligne==7)):




        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45  and sensor[10]==1:
            speed=speed_perdu
            dir=9

        if sensor[11]>45 and sensor[11]<99  and sensor[10]==1:
            speed=speed_perdu
            dir=10

        if sensor[8] <280 and dir_ligne==2 and sensor[10]==1:
            speed=speed_perdu
            dir=1
        if sensor[8] <280 and dir_ligne==7 and sensor[10]==1:
            speed=speed_perdu
            dir=6
        if sensor[8] >360 and dir_ligne==2 and sensor[10]==1:
            speed=speed_perdu
            dir=3
        if sensor[8] >360 and dir_ligne==7 and sensor[10]==1:
            speed=speed_perdu
            dir=8
        if  dir_ligne==2 and (sensor[0]==0 or sensor[2]==0) and sensor[6]==1 and sensor[7]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!=4 :
            print("croix")

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if check_croix==1 and (sensor[10]==0 or sensor[10]==1):
            check_croix=0
            print ("check croix 0")
            time.sleep(1)

        if  dir_ligne==7 and (sensor[3]==0 or sensor[5]==0) and sensor[6]==1 and sensor[7]==1 and sensor[10]==2 and check_croix==0 and etape_perdu!=4 :
            print("croix")

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1
            dir=0
            dir_ligne=0
            check_croix=1
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if check_croix==1 and (sensor[10]==0 or sensor[10]==1):
            check_croix=0
            time.sleep(1)
            print ("check croix 0")

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==7 and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            print("T SUD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[4]==1 and dir_ligne==2 and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y
            print("T NORD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)


        if sensor[7]==1  and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0 and coordX==0:

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
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[6]==1 and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0 and coordX==max_X:

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
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[6]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=0
            on_ligne_H=1
            coordY =max_Y
            coordX = max_X
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[6]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=0
            on_ligne_H=1
            coordY=0
            coordX = max_X
            print("COIN SUD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[7]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y
            coordX= 0
            etape_perdu=5
            home_temp=0

            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[7]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=0
            on_ligne_H=1
            etape_perdu=3
            coordX=0
            coordY=0
            print("COIN SUD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)



    if check_bord!=0 and (sensor[10]==0 or sensor[10]==1):
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


#######################################






#################################
def grille(*args):
    global max_X
    global max_Y
    global nb_table

    max_X=args[0]
    max_Y=args[1]
    nb_table=args[2]
    print("max_X : ", max_X, "max_Y : ", max_Y)


#######################################


def demarrage_cam(*args):
    print( "demarrage camera...")



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



    if home==1 and home_temp==0 :

        print("process home ligne....")
        home_temp=1
        etape_perdu=0
        on_ligne_H=0
        on_ligne_V=0







###########################################################
#############################################################
#################################################################


osc_method("/coordonate", coordonate)
osc_method("/game_pad", game_pad)
osc_method("/sensor", sensor_osc)

osc_method("/grille", grille)
osc_method("/demarrage", demarrage_cam)




while True:
    osc_process()
    if home_temp==1:
        alignement()
    if on_ligne_H==1 or on_ligne_V==1:
        reste_sur_ligne()
    if dir != dir_temp :

        dir_osc=[dir]
        msg = oscbuildparse.OSCMessage("/dir", None, dir_osc)
        osc_send(msg, "chataigne")
        dir_temp=dir

    if verin != 2 :
        print("verin", verin)
        verin_osc=[verin]
        msg = oscbuildparse.OSCMessage("/verin", None, verin_osc)
        osc_send(msg, "chataigne")
        osc_process()
        time.sleep(5)
        verin=2

osc_terminate()
