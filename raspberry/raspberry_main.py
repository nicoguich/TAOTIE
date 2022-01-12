from pythonosc import dispatcher
from pythonosc import osc_server
import serial
import time




arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ip="127.0.0.1"
port=5005


step=0
speed=1000
speed_temp=1000
dir=0
dir_temp=0
select=0
home=0
home_temp=0
rec=0
rec_temp=0
compteur_play=0
lines = []




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
    global rec
    global chemin
    global compteur_play
    global lines
    global step



    if select==0:


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
                dir =0
                etape_perdu=2
                time.sleep(2)
        if etape_perdu==2:
            if compteur_play < len(lines):
                print(lines[compteur_play])
                step=int(lines[compteur_play][2:])
                dir=int(lines[compteur_play][:2])-10

            else:
                compteur_play=0
                etape_perdu=-1
                print("fin")


        send_serial(0,step,dir,speed,select,home,rec)

def command(address, *args):
    global rec
    global chemin

    if rec==1 :
        print ("commande : ",args[0],"  step : ", args[1])
        chemin.write(str(args[0])+" "+str(args[1])+"\n")



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

    arduino_serial.flush()
    step=args[0]
    dir=args[1]
    speed=args[2]
    select=args[3]
    home=args[4]
    rec=args[5]

    if home==1 and home_temp==0:
        print("play")
        etape_perdu=0
        home_temp=1
        lines = []
        with open("chemin.txt") as f:
            lines = f.readlines()
        print(lines)
        compteur_play=0
    if home==0 and home_temp==1:
        home_temp=0


    if rec==0 and rec_temp==1:
        chemin.close()
        rec_temp=0
        print("rec off")
    if rec==1 and rec_temp==0:
        rec_temp=1
        print("rec on")
        chemin = open("chemin.txt","w")

    if dir_temp != dir or speed_temp != speed:
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





dispatcher = dispatcher.Dispatcher()
dispatcher.map("/sensor", sensor_osc)
dispatcher.map("/controller", send_serial)
dispatcher.map("/command", command)
dispatcher.map("/arrive", check_arrive)
server = osc_server.ThreadingOSCUDPServer((ip, port), dispatcher)
server.serve_forever()
