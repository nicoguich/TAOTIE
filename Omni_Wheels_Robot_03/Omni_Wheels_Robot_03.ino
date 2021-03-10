
#include <AccelStepper.h>

// Define the stepper motors and the pins the will use

AccelStepper FrontWheel(1, 3, 4);  // Stepper1 // (Type:driver, STEP, DIR) -
AccelStepper RightWheel(1, 6, 9); // Stepper2
AccelStepper BackWheel(1, 11, 12);  // Stepper3
AccelStepper LeftWheel(1, 14, 15);   // Stepper4



int wheelSpeed = 5000;
int LeftSpeed, FrontSpeed, BackSpeed, RightSpeed;

int dataIn, m = -1, dir, compteurdata;
long pos, timer;
byte data2[5];
byte datawheel[4];
int led = 16;
int enable_front=2,enable_back=10,enable_left=13,enable_right=5;




void setup() {

  Serial.begin(9600);
  Serial3.begin(9600);

  // Set initial seed values for the steppers
  FrontWheel.setMaxSpeed(wheelSpeed);
  LeftWheel.setMaxSpeed(wheelSpeed);
  RightWheel.setMaxSpeed(wheelSpeed);
  BackWheel.setMaxSpeed(wheelSpeed);


  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

  pinMode (led, OUTPUT);
  pinMode(enable_front,OUTPUT);
  pinMode(enable_back,OUTPUT);
  pinMode(enable_left,OUTPUT);
  pinMode(enable_right,OUTPUT);


  for (int x = 0; x < 5; x++) {
    data2[x] = 0;
  }

delay(5000);

}

void loop() {


  // Check for incoming data

  if (Serial3.available() > 0) {
    Serial3.readBytes(data2, 5); // Read the data



    pos = (256 * data2[0]) + data2[1];
    dir = data2[2];
    wheelSpeed = int ((256 * data2[3]) + data2[4]);

        if ((int(dir)> 40) || (int(dir)< 0)||(int(wheelSpeed)>5000)||(int(wheelSpeed)<0)||(int(pos)<0)) {
dir=0;
pos=0;
wheelSpeed=0;
    }



    m = int(dir);
    pos = int(pos * 32);



    Serial.print(m);
    Serial.print("  ");
    Serial.print(pos / 32);
    Serial.print("  ");
    Serial.println(wheelSpeed);




    if ((m == 4) || (m == 14) || (m == 24) || (m == 34)) {
      moveSidewaysLeft();
    }
    if ((m == 5) || (m == 15) || (m == 25) || (m == 35)) {
      moveSidewaysRight();
    }
    if ((m == 2) || (m == 12) || (m == 22) || (m == 32)) {

      moveForward();
    }
    if ((m == 7) || (m == 17) || (m == 27) || (m == 37)) {
      moveBackward();
    }
    if ((m == 3) || (m == 13) || (m == 23) || (m == 33)) {
      moveRightForward();
    }
    if ((m == 1) || (m == 11) || (m == 21) || (m == 31)) {
      moveLeftForward();
    }
    if ((m == 8) || (m == 18) || (m == 28) || (m == 38)) {
      moveRightBackward();
    }
    if ((m == 6) || (m == 16) || (m == 26) || (m == 36)) {
      moveLeftBackward();
    }
    if ((m == 9) || (m == 19) || (m == 29) || (m == 39)) {
      rotateLeft();
    }
    if ((m == 10) || (m == 20) || (m == 30) || (m == 40)) {
      rotateRight();
    }

    if (m == 0) {
      stopMoving();
    }
  }




  moveMotor();






  // Monitor the battery voltage
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.00) * 3.6; // Convert the reading values from 5v to suitable 12V i
  //Serial.println(voltage);
  // If voltage is below 11V turn on the LED
  if (voltage < 11.5) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }





}
