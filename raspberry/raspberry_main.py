import RPi.GPIO as GPIO
from osc4py3.as_eventloop import *
from osc4py3 import oscmethod as osm
from osc4py3 import oscbuildparse
import time
import random
import netifaces


osc_startup()
#ip="127.0.0.1"
addrs = netifaces.ifaddresses('wlan0')
ip = addrs[netifaces.AF_INET][0]['addr']
print(ip)

osc_udp_server(ip, 5005, "raspberry")
osc_udp_client(ip, 5007, "chataigne")

osc_udp_client("192.168.50.10", 5009, "tablette")


id=-1
id_osc=[-1]
dir=0
play=0
bot_state=1
speed=600
speed_control=700
speed_temp=600
dir_temp=0
home_temp = 0
lines = []
etape_perdu=0
speed_perdu=400
verin=0
nb_table=0
table_random=0
table_random_temp=0

nb_table_interdite=0
nb_ligne_interdite=1
new_coordonate=[0,0]


on_ligne_H=0
on_ligne_V=0
dir_ligne=0
check_croix=0
check_bord=0

sensor=[0,0,0,0,0,0,0,0,0,0,0,0]

dataMotor=[0,0,0,0,0,0]
coordX=-1
coordY=-1
coordonate_bot =[-1,-1]
go_to=0
go_toX=-1
go_toY=-1
max_X=1
max_Y=1

valid_ping=[1]




coordonate_table_lines = []
coordonate_table = [[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1]]
coordonate_table_osc = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
taille_grille_osc=[0,0,0]
with open("/home/pi/Desktop/coordonate_table.txt") as f:
    coordonate_table_lines = f.readlines()


for x in range (0 , len(coordonate_table_lines)):
    temp_coordonate="".join(coordonate_table_lines[x])
    temp_coordonate_list = temp_coordonate.split(' ')
    coordonate_table[x][0]=int(temp_coordonate_list[0])
    coordonate_table[x][1]=int(temp_coordonate_list[1])
    print("table",x," ",coordonate_table[x][0]," ",coordonate_table[x][1])
    coordonate_table_osc[x*2] =coordonate_table[x][0]
    coordonate_table_osc[(x*2)+1] =coordonate_table[x][1]
    


coordonate_pos_interdite_lines = []
coordonate_pos_interdite = [[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1],[-1,-1]]
coordonate_pos_interdite_osc = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]

with open("/home/pi/Desktop/coordonate_pos_interdite.txt") as f:
    coordonate_pos_interdite_lines = f.readlines()


for x in range (0 , len(coordonate_pos_interdite_lines)):
    temp_pos_interdite="".join(coordonate_pos_interdite_lines[x])
    temp_pos_interdite_list = temp_pos_interdite.split(' ')
    coordonate_pos_interdite[x][0]=int(temp_pos_interdite_list[0])
    coordonate_pos_interdite[x][1]=int(temp_pos_interdite_list[1])
    coordonate_pos_interdite_osc[x*2] =coordonate_pos_interdite[x][0]
    coordonate_pos_interdite_osc[(x*2)+1] =coordonate_pos_interdite[x][1]


msg = oscbuildparse.OSCMessage("/coord_table", None, coordonate_table_osc)
osc_send(msg, "tablette")

msg1 = oscbuildparse.OSCMessage("/coordonate_pos_interdite", None, coordonate_pos_interdite_osc)
osc_send(msg1, "tablette")
temps=time.time()





###############################################################""
def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global home_temp
    global on_ligne_H
    global dir_ligne
    global verin
    
    #print("etape_perdu: ", etape_perdu)
    if etape_perdu == 0 :
        etape_perdu=1
    if etape_perdu==1:
        speed=speed_control
        dir=7
        if sensor[7]==1 and sensor[6]==0 :
            dir=10
        if sensor[7]==0 and sensor[6]==1:
            dir=9
        if sensor[7]==1 and sensor[6]==1 and sensor[0]==0 and sensor[1]==0 and sensor[2]==0 :
            etape_perdu=2
            dir=7

    if etape_perdu==2:
        speed=speed_control
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
    global home
    global home_temp
    global new_coordonate




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
                bot_state=1
            elif bot_state==1:
                verin=1
                bot_state=2
            elif bot_state==2:

                coordonate_table[table_random][0]=coordX
                coordonate_table[table_random][1]=coordY
                verin=0
                for x in range (nb_table):
                    coordonate_table_osc[x*2] =coordonate_table[x][0]
                    coordonate_table_osc[(x*2)+1] =coordonate_table[x][1]

                msg1 = oscbuildparse.OSCMessage("/coord_table", None, coordonate_table_osc)
                osc_send(msg1, "tablette")

                if (coordY==max_Y-1):
                    if coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0] :
                        go_to=1
                        go_toX=coordX
                        go_toY=coordonate_pos_interdite[0][1]
                        bot_state=0
                    else:
                        go_to=1
                        go_toX=coordX
                        go_toY=0
                        bot_state=0
                else :
                    bot_state=random.randint(0,1)
                    if bot_state==0:
                        if coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0] :
                            go_to=1
                            go_toX=coordX
                            go_toY=coordonate_pos_interdite[0][1]
                            bot_state=0
                        else:
                            go_to=1
                            go_toX=coordX
                            go_toY=0
                            bot_state=0
            elif bot_state == 3:
                go_to=1
                bot_state=1
                go_toX=coordonate_table[table_random][0]
                go_toY=coordonate_table[table_random][1]
                print ("new go_toX :", go_toX)
            print ("new go_toY :", go_toY)
            new_coordonate=[go_toX,go_toY]
            msg0 = oscbuildparse.OSCMessage("/new_coordonate", None, new_coordonate)
            osc_send(msg0, "tablette")
                


    elif play==1:

        go_to=1

        if bot_state==0:

            if coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0] :
                go_toX=coordX
                go_toY=coordonate_pos_interdite[0][1]
            else:
                go_toX=coordX
                go_toY=0
                


        elif bot_state==1:
            while table_random==table_random_temp :
                table_random= random.randint(0,nb_table-1-nb_table_interdite)


            table_random_temp=table_random
            if (coordX<= coordonate_pos_interdite[0][0] and coordonate_table[table_random][0] > coordonate_pos_interdite[0][0] and coordY< coordonate_pos_interdite[0][1]) or (coordX>= coordonate_pos_interdite[1][0] and coordonate_table[table_random][0]< coordonate_pos_interdite[1][0] and coordY< coordonate_pos_interdite[0][1]) :
                go_toX=coordX
                go_toY=coordonate_pos_interdite[0][1]
                bot_state=3
            else :
                go_toX=coordonate_table[table_random][0]
                go_toY=coordonate_table[table_random][1]
            print ("table choisie : ",table_random," ///// max : ", nb_table)

        elif bot_state==2:
            coordonate_exist=0
            bloque=0
            coordX_temp=coordX
            coordY_temp=coordY

            if coordX==0 or coordX==max_X-1:
                bloque+=1
                print("bloque X")
            if coordY==nb_ligne_interdite :
                bloque+=1
                print("bloque minY")
            if coordY==max_Y-1:
                bloque+=1
                print("bloque maxY")
            if coordX==coordonate_pos_interdite[0][0] and coordY<coordonate_pos_interdite[0][1] :
                bloque+=1
            if coordX==coordonate_pos_interdite[1][0] and coordY<coordonate_pos_interdite[0][1] :
                bloque+=1
            if coordY==coordonate_pos_interdite[0][1] and coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0] :
                bloque+=1




            for x in range (nb_table):

                if (coordonate_table[x][0]==coordX-1 and coordonate_table[x][1]==coordY):
                    bloque+=1
                    print("bloque table X-1")
                if (coordonate_table[x][0]==coordX+1 and coordonate_table[x][1]==coordY):
                    bloque+=1
                    print("bloque table X+1")
                if (coordonate_table[x][0]==coordX and coordonate_table[x][1]==coordY-1):
                    bloque+=1
                    print("bloque table Y-1")
                if (coordonate_table[x][0]==coordX and coordonate_table[x][1]==coordY+1):
                    bloque+=1
                    print("bloque table Y+1")
            print ("bloque : ", bloque)
            print ("coord : ", coordX, coordY)
            if bloque<4:
                while coordonate_exist<nb_table :
                    coordonate_exist=0
                    go_toX=coordX_temp
                    go_toY=coordY_temp
                   # print ("coord : ", coordX, coordY)

                    random_axe = random.randint(0,1)
                    if random_axe==0 :
                        go_toX=random.randint(coordX-1,coordX + 1)
                        if (go_toX>max_X-1):
                            go_toX=max_X-1
                        if (go_toX<0):
                            go_toX=0
                        if (go_toX>coordonate_pos_interdite[0][0] and coordY<coordonate_pos_interdite[0][1] and coordX==coordonate_pos_interdite[0][0]) :
                            go_toX=coordonate_pos_interdite[0][0]
                        if (go_toX<coordonate_pos_interdite[1][0] and coordY<coordonate_pos_interdite[0][1]and coordX== coordonate_pos_interdite[1][0]) :
                            go_toX = coordonate_pos_interdite[1][0]
                    else:
                        go_toY=random.randint(coordY-1,coordY + 1)
                        if (go_toY>max_Y-1):
                            go_toY=max_Y-1
                        if (go_toY<nb_ligne_interdite):
                            go_toY=nb_ligne_interdite
                        if (go_toY<coordonate_pos_interdite[0][1] and coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0]) : 
                            go_toY=coordonate_pos_interdite[0][1]
                   # print ("goto random: ", go_toX, go_toY)

                    for x in range (nb_table):

                        if (coordonate_table[x][0]==go_toX and coordonate_table[x][1]==go_toY) or (go_toX==coordX and go_toY==coordY):
                            coordonate_exist=0
                          #  print ("same coordonate table", x)


                        else:
                           # print ("ok", x)
                            coordonate_exist+=1
            else :
                verin=0
                dir=0
                go_to=0
                bot_state=0

            






        print ("new go_toX :", go_toX)
        print ("new go_toY :", go_toY)
        new_coordonate=[go_toX,go_toY]
        msg0 = oscbuildparse.OSCMessage("/new_coordonate", None, new_coordonate)
        osc_send(msg0, "tablette")
        print("bot_state: ", bot_state)

        for x in range (nb_table):
            coordonate_table_osc[x*2] =coordonate_table[x][0]
            coordonate_table_osc[(x*2)+1] =coordonate_table[x][1]

        msg1 = oscbuildparse.OSCMessage("/coord_table", None, coordonate_table_osc)
        osc_send(msg1, "tablette")
        coordonate_bot[0]=coordX
        coordonate_bot[1]=coordY
        msg2 = oscbuildparse.OSCMessage("/coord_bot", None, coordonate_bot)
        osc_send(msg2, "tablette")
        osc_process()










    speed=speed_control






    if (on_ligne_H==1 and (dir_ligne==4 or dir_ligne==5)):
        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45  and sensor[10]==0:
            speed=speed_perdu-100
            dir=9

        if sensor[11]>45 and sensor[11]<99  and sensor[10]==0:
            speed=speed_perdu-100
            dir=10

        if sensor[9]<210 and dir_ligne==4 and (sensor[10]==0 or sensor[10]==2):
            speed=speed_perdu
            dir=2
        if sensor[9]<210 and dir_ligne==5 and  (sensor[10]==0 or sensor[10]==2):
            speed=speed_perdu
            dir=2

        if sensor[9]>270  and dir_ligne==4 and  (sensor[10]==0 or sensor[10]==2):
            speed=speed_perdu
            dir=7

        if sensor[9]>270 and dir_ligne==5 and  (sensor[10]==0 or sensor[10]==2):
            speed=speed_perdu

            dir=7
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
           # time.sleep(2)

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
           # time.sleep(2)




        if sensor[0]==0 and sensor[3]==0 and sensor[6]==0 and sensor[7]==1 and dir_ligne==4 and sensor[10]==3 and check_bord==0 and check_croix==0:

            
            if coordX< coordonate_pos_interdite[1][0]:
                coordX = 0
                print("T OUEST")
            else :
                coordX = coordonate_pos_interdite[1][0]
                print("T OUEST U")

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
            

            if coordX>coordonate_pos_interdite[0][0]:
                coordX = max_X-1
                print("T EST")
            else :
                coordX = coordonate_pos_interdite[0][0]
                print("T EST U")       
                
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)



        if sensor[1]==1 and sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0 and check_croix==0 :

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1
            if etape_perdu != 4:
                dir=0
                dir_ligne=0
                
            if coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0]:
                coordY=coordonate_pos_interdite[0][1] 
                print("T SUD U")
            else:
                print("T SUD")
                coordY=0

            check_bord=1
            on_ligne_V=0
            on_ligne_H=1
            
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[4]==1 and (dir_ligne==4 or dir_ligne==5) and sensor[10]==3 and check_bord==0 and check_croix==0 :

            if (dir_ligne==4):
                coordX += -1
            else:
                coordX += 1

            dir=0
            coordY=max_Y-1
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            print("T NORD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if  sensor[4]==1 and sensor[3]==0 and sensor[6]==0  and dir_ligne==4  and sensor[10]==4 and check_bord==0 and check_croix==0 and (coordY== max_Y-1 or coordY==-1):
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=1
            on_ligne_H=0
            coordX=0
            coordY= max_Y-1
            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[0]==0 and sensor[6]==0 and sensor[3]==0 and sensor[1]==1 and dir_ligne==4  and sensor[10]==4 and check_bord==0 and check_croix==0 and (coordY== 0 or coordY==-1):
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=1
            on_ligne_H=0
            
            if coordX>= coordonate_pos_interdite[1][0] and coordX!=-1:
                coordX= coordonate_pos_interdite[1][0]
                print("COIN SUD OUEST U")
            else:
                coordX=0
                print("COIN SUD OUEST")
            coordY= 0
            etape_perdu=5
            play=1
            home_temp=0
            
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[4]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0 and check_croix==0 and (coordY== max_Y-1 or coordY==-1):
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=1
            on_ligne_H=0
            coordX = max_X-1
            coordY= max_Y-1
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[2]==0 and sensor[7]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==5  and sensor[10]==4 and check_bord==0 and check_croix==0 and coordY==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=1
            on_ligne_H=0
            
            if coordX<=coordonate_pos_interdite[0][0] :
                coordX=coordonate_pos_interdite[0][0]
                print("COIN SUD EST U")
            else:
                coordX =max_X-1
                print("COIN SUD EST")

            coordY = 0
            
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)




    if (on_ligne_V==1 and (dir_ligne==2 or dir_ligne==7)):




        dir = dir_ligne
        if sensor[11]>1 and sensor[11]<45  and sensor[10]==1:
            speed=speed_perdu-100
            dir=9

        if sensor[11]>45 and sensor[11]<99  and sensor[10]==1:
            speed=speed_perdu-100
            dir=10

        if sensor[8] <290 and dir_ligne==2 and (sensor[10]==1 or sensor[10]==2):
            speed=speed_perdu
            dir=4
        if sensor[8] <290 and dir_ligne==7 and (sensor[10]==1 or sensor[10]==2):
            speed=speed_perdu
            dir=4
        if sensor[8] >350 and dir_ligne==2 and (sensor[10]==1 or sensor[10]==2):
            speed=speed_perdu
            dir=5
        if sensor[8] >350 and dir_ligne==7 and (sensor[10]==1 or sensor[10]==2):
            speed=speed_perdu
            dir=5
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
            #time.sleep(2)

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
           # time.sleep(2)
            print ("check croix 0")

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[1]==1 and dir_ligne==7 and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=1
            on_ligne_V=0
            on_ligne_H=1

            if coordX>coordonate_pos_interdite[0][0] and coordX<coordonate_pos_interdite[1][0]:
                coordY=coordonate_pos_interdite[0][1] 
                print("T SUD U")
            else:
                print("T SUD")
                coordY=0

            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)
        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[4]==1 and dir_ligne==2 and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=2
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y-1
            print("T NORD")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)


        if sensor[0]==0  and sensor[3]==0  and sensor[6]==0  and sensor[7]==1  and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0 :

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1
            dir=0
            dir_ligne=0
            check_bord=3
            on_ligne_V=1
            on_ligne_H=0
 
            if coordX< coordonate_pos_interdite[1][0]:
                coordX = 0
                print("T OUEST")
            else :
                coordX = coordonate_pos_interdite[1][0]
                print("T OUEST U")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[2]==0 and sensor[5]==0 and sensor[7]==0 and sensor[6]==1 and (dir_ligne==2 or dir_ligne==7) and sensor[10]==3 and check_bord==0 and etape_perdu!=4 and check_croix==0 :

            if (dir_ligne==7):
                coordY += -1
            else:
                coordY += 1

            dir=0
            dir_ligne=0
            check_bord=4
            on_ligne_V=1
            on_ligne_H=0
            if coordX>coordonate_pos_interdite[0][0]:
                coordX = max_X-1
                print("T EST")
            else :
                coordX = coordonate_pos_interdite[0][0]
                print("T EST U") 
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[6]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0 and check_croix==0 and coordX ==max_X-1 :
            dir=0
            dir_ligne=0
            check_bord=7
            on_ligne_V=0
            on_ligne_H=1
            
            coordY =max_Y-1
            coordX = max_X-1
            print("COIN NORD EST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[6]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=8
            on_ligne_V=0
            on_ligne_H=1
            

            if coordX<=coordonate_pos_interdite[0][0] :
                coordX=coordonate_pos_interdite[0][0]
                print("COIN SUD EST U")
            else:
                coordX =max_X-1
                print("COIN SUD EST")           
            coordY=0


            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[7]==1 and dir_ligne==2  and sensor[10]==4 and check_bord==0 and check_croix==0 and coordX==0:
            dir=0
            dir_ligne=0
            check_bord=5
            on_ligne_V=0
            on_ligne_H=1
            coordY = max_Y-1
            coordX= 0

            home_temp=0

            print("COIN NORD OUEST")
            print("gotoX:",go_toX," /gotoY:",go_toY," /X:",coordX," /Y:",coordY)

        if sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[7]==1 and dir_ligne==7  and sensor[10]==4 and check_bord==0 and check_croix==0:
            dir=0
            dir_ligne=0
            check_bord=6
            on_ligne_V=0
            on_ligne_H=1
            etape_perdu=5
            play=1
            
            if coordX>= coordonate_pos_interdite[1][0] :
                coordX= coordonate_pos_interdite[1][0]
                print("COIN SUD OUEST U")
            else:
                coordX=0
                print("COIN SUD OUEST")
            coordY= 0

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




    if (sensor[0]==0 and sensor[1]==0 and sensor[2]==0 and sensor[3]==0 and sensor[4]==0 and sensor[5]==0 and sensor[6]==0 and sensor[7]==0 ):
        home_temp=0
        home=0
        verin=0
        etape_perdu=0
        on_ligne_H=0
        on_ligne_V=0
        play=0
        coordX=-1
        coordY=-1
        go_to=0
        go_toX=-1
        go_toY=-1
        dir = 0
        dir_ligne = 0
        print("mode manuel")
        rec_coordonate = open("/home/pi/Desktop/coordonate_table.txt","w")
        print("rec table...")
        for x in range (0 , len(coordonate_table)):

            rec_coordonate.write(str(int(coordonate_table[x][0]))+" "+str(int(coordonate_table[x][1]))+"\n")

        rec_coordonate.close()

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


#################################
def void_id(*args):
    global id
    global id_osc

    id=args[0]
    id_osc[0]=args[0]

    print("id: ",id)


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
    global dir
    global coordX
    global coordY
    global bot_state
    global coordonate_table


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
        dir = 0
        print("mode manuel")
        bot_state=0
        rec_coordonate = open("/home/pi/Desktop/coordonate_table.txt","w")
        print("rec table...")
        for x in range (0 , len(coordonate_table)):

            rec_coordonate.write(str(int(coordonate_table[x][0]))+" "+str(int(coordonate_table[x][1]))+"\n")

        rec_coordonate.close()


    if play==1:
        print("mode auto")



    if home==1 and home_temp==0 :

        print("process home ligne....")
        home_temp=1
        etape_perdu=0
        on_ligne_H=0
        on_ligne_V=0
        coordX=-1
        coordY=-1
        bot_state=0



###########################################################



#######################################
def reset_table(*args):
    global coordonate_table


    with open("/home/pi/Desktop/reset_table.txt") as f:
        coordonate_table_lines = f.readlines()


    for x in range (0 , len(coordonate_table_lines)):
        temp_coordonate="".join(coordonate_table_lines[x])
        temp_coordonate_list = temp_coordonate.split(' ')
        coordonate_table[x][0]=int(temp_coordonate_list[0])
        coordonate_table[x][1]=int(temp_coordonate_list[1])
        coordonate_table_osc[x*2] =coordonate_table[x][0]
        coordonate_table_osc[(x*2)+1] =coordonate_table[x][1]


    msg = oscbuildparse.OSCMessage("/coord_table", None, coordonate_table_osc)
    osc_send(msg, "tablette")

    rec_coordonate = open("/home/pi/Desktop/coordonate_table.txt","w")
    print("rec table...")
    for x in range (0 , len(coordonate_table)):

        rec_coordonate.write(str(int(coordonate_table[x][0]))+" "+str(int(coordonate_table[x][1]))+"\n")

    rec_coordonate.close()



#############################################################
#################################################################


osc_method("/coordonate", coordonate)
osc_method("/game_pad", game_pad)
osc_method("/sensor", sensor_osc)

osc_method("/grille", grille)
osc_method("/reset_table", reset_table)
osc_method("/id", void_id)




while True:




    if verin != 2 :
        print("verin", verin)
        verin_osc=[verin]
        msgverin = oscbuildparse.OSCMessage("/verin", None, verin_osc)
        osc_send(msgverin, "chataigne")

        for x in range(0,50):
            osc_process()
            time.sleep(0.1)

        #time.sleep(5)
        verin=2
        print("verin", verin)


    if home_temp==1:
        alignement()
    if on_ligne_H==1 or on_ligne_V==1:
        reste_sur_ligne()



    if dir != dir_temp  :
        speed_osc=[speed]
        msgspeed = oscbuildparse.OSCMessage("/speed", None, speed_osc)
        osc_send(msgspeed,"chataigne")
        
        dir_osc=[dir]
        msgdir = oscbuildparse.OSCMessage("/dir", None, dir_osc)
        osc_send(msgdir, "chataigne")
        dir_temp=dir




    if time.time()-temps > 1 :
        msg0 = oscbuildparse.OSCMessage("/coord_table", None, coordonate_table_osc)
        osc_send(msg0, "tablette")
        coordonate_bot[0]=coordX
        coordonate_bot[1]=coordY
        msg1 = oscbuildparse.OSCMessage("/coord_bot", None, coordonate_bot)
        osc_send(msg1, "tablette")
        msg2 = oscbuildparse.OSCMessage("/ping_main", None, '1')
        osc_send(msg2, "chataigne")
        msg3 = oscbuildparse.OSCMessage("/ping_main", None, '0')
        osc_send(msg3, "chataigne")
        taille_grille_osc[0]=max_X
        taille_grille_osc[1]=max_Y
        taille_grille_osc[2]=nb_table

        msg4 = oscbuildparse.OSCMessage("/grille", None, taille_grille_osc)
        osc_send(msg4, "tablette")
        msg5 = oscbuildparse.OSCMessage("/id",None , id_osc)
        osc_send(msg5, "tablette")
        osc_send(msg5, "chataigne")
        msg6 = oscbuildparse.OSCMessage("/ping_main", None, valid_ping)
        osc_send(msg6, "tablette")
        
        msg7 = oscbuildparse.OSCMessage("/coordonate_pos_interdite", None, coordonate_pos_interdite_osc)
        osc_send(msg7, "tablette")
        
        msg8 = oscbuildparse.OSCMessage("/new_coordonate", None, new_coordonate)
        osc_send(msg8, "tablette")
        


        temps=time.time()


    osc_process()

osc_terminate()
