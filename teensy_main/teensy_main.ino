#include <AccelStepper.h>
#include <Servo.h> 
 

AccelStepper arriere_droitWheel(1, 3, 4);  // Stepper1 // (Type:driver, STEP, DIR) 
AccelStepper avant_droitWheel(1, 11, 12); // Stepper2
AccelStepper arriere_gaucheWheel(1, 14, 15);  // Stepper3
AccelStepper avant_gaucheWheel(1, 6, 9);   // Stepper4



const int BUFFER_SIZE = 7;
char data[BUFFER_SIZE];

Servo verin;

int wheelSpeed = 5000;
int avant_gaucheSpeed, arriere_droitSpeed, arriere_gaucheSpeed, avant_droitSpeed;

int dataIn, m = -1, dir, compteurdata;
long pos, timer;

int rec=0;
byte datawheel[4];
int led = 20;
int led_ir=17;
int verin_pin=16;
int batterie_level_pin=23;
int enable_arriere_droit = 2, enable_arriere_gauche = 13, enable_avant_gauche = 5, enable_avant_droit = 10;
float batterie_level, batterie_level_temp;

void setup() {
  Serial.begin(9600);


  pinMode (led, OUTPUT);
  pinMode(enable_arriere_droit, OUTPUT);
  pinMode(enable_arriere_gauche, OUTPUT);
  pinMode(enable_avant_gauche, OUTPUT);
  pinMode(enable_avant_droit, OUTPUT);
  pinMode(led_ir,OUTPUT);



 
  analogWrite(led,200);
  analogWrite(led_ir,255);
  digitalWrite(enable_arriere_droit,HIGH);
  digitalWrite(enable_avant_gauche,HIGH);
  digitalWrite(enable_avant_droit,HIGH);
  digitalWrite(enable_arriere_gauche,HIGH);

  

  // Set initial seed values for the steppers
  arriere_droitWheel.setMaxSpeed(wheelSpeed);
  avant_gaucheWheel.setMaxSpeed(wheelSpeed);
  avant_droitWheel.setMaxSpeed(wheelSpeed);
  arriere_gaucheWheel.setMaxSpeed(wheelSpeed);


  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);



verin.attach(verin_pin);

verin.write(45);


Serial.setTimeout(100);
delay(2000);
}
void loop() {
  if (Serial.available() > 0) {

    batterie();
    
    Serial.readBytes(data,BUFFER_SIZE);
   
    pos = ( (data[0] & 0x0F) << 16) + ((data[1] & 0xFF) << 8) + (data[2] & 0xFF);
    dir = data[3];
    wheelSpeed = int ((256 * data[5]) + data[4]);
 /*   Serial.print("pos ");
    Serial.println(pos);
    Serial.print("dir ");
    Serial.println(dir);
    Serial.print("speed ");
    Serial.println(wheelSpeed);
 */

switch (int(dir)) {

      case 0 :
      stopMoving();
      break;

      case 1 :
      moveLeftForward();
      break;

      case 2 :
      moveForward();
      break;

      case 3 :
      moveRightForward();
      break;
       
      case 4 :
      moveSidewaysLeft();
      break;

      case 5 :
      moveSidewaysRight();
      break;

      case 6 :
      moveLeftBackward();
      break;

      case 7 :
      moveBackward() ;
      break;

      case 8 :
      moveRightBackward();
      break;

 
      case 9 :
      rotateLeft();
      break;


      case 10 :
      rotateRight();
      break;



      case 20 :
      verin.write(45);;
      break;

      case 21 :
      verin.write(135);;
      break;
  
      case 201 :
      digitalWrite(enable_arriere_droit,HIGH);
      digitalWrite(enable_avant_gauche,HIGH);
      digitalWrite(enable_avant_droit,HIGH);
      digitalWrite(enable_arriere_gauche,HIGH);
      break ;


}

 
}


  moveMotor();


}
