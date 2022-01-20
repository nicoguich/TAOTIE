from pythonosc import dispatcher
from pythonosc import osc_server
import serial
import time




arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ip="127.0.0.1"
port=5005


step=0
step_temp=0
speed=1000
speed_temp=1000
dir=0
dir_temp=0
select=0
home=0
home_temp = 0
rec=0
rec_temp=0
compteur_play=0
lines = []
data_step=0
data_dir=0
arrive=0





sensor=[0,0,0,0,0,0,0,0]
dataMotor=[0,0,0,0,0]


etape_perdu=-1
speed_perdu=800

def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global select
    global home
    global home_temp
    global rec_temp
    global chemin
    global compteur_play
    global lines
    global step
    global arrive
    global data_dir
    global data_step



    if select==0 or rec_temp==1:


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


                if rec_temp==1:
                    etape_perdu=-1
                    dir=0
        if etape_perdu==2 :
            if compteur_play < len(lines):


                data=lines[compteur_play].split()
                if int(data[0])!= 255 :
                    speed=int(data[2])
                    step=int(data[1])
                    dir=int(data[0])-10
                else:
                    etape_perdu=0
                    dir=-1

            else:
                compteur_play=0
                etape_perdu=0
                print("fin")
        if etape_perdu==-1:

            home_temp=0


        if dir>=0:
            #print ("dir: ",dir," step: ",step)
            send_serial(0,step,dir,speed,select,home,rec)
        else:
            compteur_play+=1

        if arrive==1 and home_temp==0 and rec_temp==1:
            arrive=0
            print ("commande : ",data_dir,"  step : ", data_step,"  speed : ", speed)
            chemin.write(str(data_dir)+" "+str(data_step)+" "+str(speed)+"\n")
        else:
            data_dir=0
            data_step=0

def command(address, *args):
    global rec_temp
    global home_temp
    global chemin
    global speed
    global data_step
    global data_dir
    global arrive


    if rec_temp==1:
        data_step= args[1]
        data_dir= args[0]
        arrive =1








def sensor_osc(address, *args):
    global sensor
    sensor=args
    alignement()

def check_arrive(address, *args):
    global compteur_play
    print("arrive")
    compteur_play+=1



def send_serial(address, *args):


    global step
    global dir
    global speed
    global dir_temp
    global speed_temp
    global dataMotor
    global select
    global home
    global home_temp
    global rec
    global rec_temp
    global chemin
    global compteur_play
    global lines
    global etape_perdu
    global step_temp

    arduino_serial.flush()
    step=args[0]
    dir=args[1]
    speed=args[2]
    select=args[3]
    home=args[4]
    rec=args[5]




    if home==1 and home_temp==0:

        if rec==0 and rec_temp==0:
            print("play")
            etape_perdu=0
            lines = []
            with open("chemin.txt") as f:
                lines = f.readlines()
            print(lines)
            compteur_play=0
        if rec_temp==1:
            print("home")
            chemin.write("255 255 255\n")
            etape_perdu=0
        home_temp=1




    if rec==0 and rec_temp==1:
        chemin.close()
        rec_temp=0
        print("rec off")
    if rec==1 and rec_temp==0:
        rec_temp=1
        etape_perdu=-1
        print("rec on")
        chemin = open("chemin.txt","w")

    if select==1:
        home=0
        compteur_play=0
        #etape_perdu=-1

    if dir_temp != dir or speed_temp != speed :

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


def poubelle(address, *args):
    print("poubelle")



dispatcher = dispatcher.Dispatcher()
dispatcher.map("/sensor", sensor_osc)
dispatcher.map("/controller", send_serial)
dispatcher.map("/command", command)
dispatcher.map("/arrive", check_arrive)
server = osc_server.ThreadingOSCUDPServer((ip, port), dispatcher)

server.serve_forever()
