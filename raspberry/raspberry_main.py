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
rec=0


sensor=[0,0,0,0,0,0,0,0]
dataMotor=[0,0,0,0,0]


etape_perdu=0
speed_perdu=800

def alignement():
    global etape_perdu
    global sensor
    global speed
    global dir
    global select
    global home
    data=[0,0]

    if select==0:
        if home==1:
            etape_perdu=0

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

        data=[dir,speed]
        send_serial(0,dir,speed,select,home)




def sensor_osc(address, *args):
    global sensor
    sensor=args
    alignement()


def send_serial(address, *args):


    global step
    global dir
    global speed
    global dir_temp
    global speed_temp
    global dataMotor
    global select
    global home
    global rec

    arduino_serial.flush()

    dir=args[0]
    speed=args[1]
    select=args[2]
    home=args[3]
    rec=args[4]

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
server = osc_server.ThreadingOSCUDPServer((ip, port), dispatcher)
server.serve_forever()
