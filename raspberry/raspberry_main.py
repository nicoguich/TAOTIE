from pythonosc import dispatcher
from pythonosc import osc_server
import serial
import time

arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ip="127.0.0.1"
port=5005



dataMotor=[0,0,0,0,0]

data_motor=[0,0]

step=0
speed=1000
speed_temp=1000
dir=0
dir_temp=0

data=[0,0]

sensor=[0,0,0,0,0,0,0,0]


def sensor_osc(address, *args):
    global sensor
    sensor=args
    

def controller_osc(address, *args):
    global dir_temp
    global speed_temp

    arduino_serial.flush()

    dir=args[0]
    speed=args[1]
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
        print(dir)


dispatcher = dispatcher.Dispatcher()
dispatcher.map("/sensor", sensor_osc)
dispatcher.map("/controller", controller_osc)
server = osc_server.ThreadingOSCUDPServer((ip, port), dispatcher)
server.serve_forever()  # Blocks forever
