
import RPi.GPIO as GPIO
import inputs
from osc4py3.as_eventloop import *
from osc4py3 import oscbuildparse
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
osc_udp_client("127.0.0.1", 5005, "raspberry")


data=[0,0]
axe_X=0
axe_Y=0
axe_RX=0
axe_RY=0
triangle=0
carre=0
rond=0
croix=0
dir=0
speed=1000
select=0
start=0
home=0
led_ir=1


msg = oscbuildparse.OSCMessage("/controller", None, data)
osc_send(msg, "raspberry")
osc_process()









while True :
    events = inputs.get_gamepad()

    for event in events:
        if event.code=="ABS_HAT0Y" and event.state==1:
            led_ir =abs(led_ir-1)
            if led_ir==1:
                GPIO.output(22, GPIO.HIGH)
            else:
                GPIO.output(22, GPIO.LOW)


        if event.code == "BTN_MODE":
            home=event.state

        if event.code=="BTN_START" and event.state==1:

                start =abs(start-1)
                if select==1:
                    if start==1:
                        GPIO.output(27, GPIO.HIGH)
                    else:
                        GPIO.output(27, GPIO.LOW)

        if event.code=="BTN_SELECT" and event.state==1:

            select =abs(select-1)
            if select==1:
                GPIO.output(10, GPIO.HIGH)
            else:
                GPIO.output(27, GPIO.LOW)
                GPIO.output(10, GPIO.LOW)
                start=0
        if event.code == "ABS_Y" and event.state < -10000 :
            axe_Y=-1

        elif event.code == "ABS_Y" and event.state > 10000 :
            axe_Y=1
        elif event.code == "ABS_Y" and event.state < 10000 and event.state > -10000:
            axe_Y=0

        if event.code == "ABS_X" and event.state < -10000 :
            axe_X=-1
        elif event.code == "ABS_X" and event.state > 10000 :
            axe_X=1
        elif event.code == "ABS_X" and event.state < 10000 and event.state > -10000:
            axe_X=0

        if event.code == "ABS_RY" and event.state < -10000 :
            axe_RY=-1
        elif event.code == "ABS_RY" and event.state > 10000 :
            axe_RY=1
        elif event.code == "ABS_RY" and event.state < 10000 and event.state > -10000:
            axe_RY=0

        if event.code == "ABS_RX" and event.state < -10000 :
            axe_RX=-1
        elif event.code == "ABS_RX" and event.state > 10000 :
            axe_RX=1
        elif event.code == "ABS_RX" and event.state < 10000 and event.state > -10000:
            axe_RX=0

        if event.code == "BTN_WEST":
            triangle= event.state

        if event.code == "BTN_EAST":
            rond= event.state
        if event.code == "BTN_SOUTH":
            croix= event.state
        if event.code == "BTN_NORTH":
            carre= event.state



        if event.code =="BTN_TR" and event.state == 1 :
            speed = speed + 100
        if event.code =="BTN_TL" and event.state == 1 :
            speed = speed - 100


        if axe_X == 0 and axe_Y== 0 :
            dir=0

        if axe_Y == -1 and axe_RY== 1 :
            dir=20

        if axe_Y == 1 and axe_RY== -1 :
            dir=19


        if axe_Y== -1 and triangle == 1 :
            dir=12


        if axe_Y== -1 and rond == 1 :
            dir=13

        if axe_Y== -1 and carre == 1 :
            dir=11

        if axe_Y== 1 and croix == 1 :
            dir=17

        if axe_Y== 1 and rond == 1 :
            dir=18

        if axe_Y== 1 and carre == 1 :
            dir=16



        if axe_X== -1 and triangle == 1 :
            dir=11

        if axe_X== -1 and croix == 1 :
            dir=16

        if axe_X== -1 and carre == 1 :
            dir=14

        if axe_X== 1 and croix == 1 :
            dir=18

        if axe_X== 1 and rond == 1 :
            dir=15

        if axe_X== 1 and triangle == 1 :
            dir=13

    if select==1:
        data=[dir,speed,select,home,start,led_ir]
    else:
        data=[0,speed,select,home,start,led_ir]

    msg = oscbuildparse.OSCMessage("/controller", None, data)
    osc_send(msg, "raspberry")
    osc_process()


osc_terminate()
