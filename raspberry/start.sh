#!/bin/bash 

sleep 5 &
python3 /home/pi/Desktop/raspberry_camera.py &
sleep 5 &
python3 /home/pi/Desktop/raspberry_controller.py &
sleep 5 &
python3 /home/pi/Desktop/raspberry_main.py &
