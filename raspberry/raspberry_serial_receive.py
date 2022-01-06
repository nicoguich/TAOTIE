import RPi.GPIO as GPIO
import serial
import signal






ligne_temp=701
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)

def handler(signum, frame):
    print("prout")
    GPIO.output(17, GPIO.LOW)
    GPIO.output(22, GPIO.LOW)
    exit(1)



GPIO.output(22, GPIO.HIGH)

ser = serial.Serial(
    port='/dev/ttyAMA0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0.1
)


signal.signal(signal.SIGINT, handler)

while True:
    ligne = ser.readline().rstrip()
    if not ligne:
        continue
    if ligne.decode("utf-8").isnumeric()==True :
        ligne = int(ligne)
        ligne_temp=ligne
    else:
        ligne=ligne_temp


    if ligne<700 :
        GPIO.output(17, GPIO.HIGH)
    else:
        GPIO.output(17, GPIO.LOW)

    print (ligne)
