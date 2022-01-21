
#include <EEPROM.h>
#include <AccelStepper.h>

// Define the stepper motors and the pins the will use

AccelStepper arriere_droitWheel(1, 3, 4);  // Stepper1 // (Type:driver, STEP, DIR) -
AccelStepper avant_droitWheel(1, 11, 12); // Stepper2
AccelStepper arriere_gaucheWheel(1, 14, 15);  // Stepper3
AccelStepper avant_gaucheWheel(1, 6, 9);   // Stepper4



const int BUFFER_SIZE = 6;
byte data2[BUFFER_SIZE];




int wheelSpeed = 5000;
int avant_gaucheSpeed, arriere_droitSpeed, arriere_gaucheSpeed, avant_droitSpeed;

int dataIn, m = -1, dir, compteurdata;
long pos, timer;

int rec=0;
byte datawheel[4];
int led = 20;
int batterie_level_pin=23;
int enable_arriere_droit = 2, enable_arriere_gauche = 13, enable_avant_gauche = 5, enable_avant_droit = 10;
byte data_command[2];
boolean on_move = false;
int m_temp[2];
float batterie_level, batterie_level_temp;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);


  pinMode (led, OUTPUT);
  pinMode(enable_arriere_droit, OUTPUT);
  pinMode(enable_arriere_gauche, OUTPUT);
  pinMode(enable_avant_gauche, OUTPUT);
  pinMode(enable_avant_droit, OUTPUT);
  pinMode(17,OUTPUT);



 
 analogWrite(17,250);
  analogWrite(led,130);
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




  for (int x = 0; x < 5; x++) {
    data2[x] = 0;
  }
m_temp[1]=0;
m=0;






Serial.setTimeout(100);
delay(2000);
}
void loop() {
  if (Serial3.available() > 0) {

    batterie();
    
    byte data = Serial3.readBytes(data2,BUFFER_SIZE);
    //Serial.print(data);



    
    pos = (256 * data2[0]) + data2[1];
    dir = data2[2];
    wheelSpeed = int ((256 * data2[3]) + data2[4]);
    Serial.print("pos ");
    Serial.print(pos);
    Serial.print("/ dir ");
    Serial.print(dir);
    Serial.print("/ speed ");
    Serial.println(wheelSpeed);

if (dir!=255){

if (m!=-1){
      m = int(dir);
      m_temp[0]=m_temp[1];
      m_temp[1]=m;}
else{
m = int(dir);
      m_temp[0]=0;
      m_temp[1]=m;
  
}
      
      
    
    pos = int(pos);


    if ((m == 4) || (m == 14)) {
      moveSidewaysLeft();

      on_move = true;
    }
    if ((m == 5) || (m == 15)) {
      moveSidewaysRight();

      on_move = true;
    }
    if ((m == 2) || (m == 12)) {

      moveForward();

      on_move = true;
    }
    if ((m == 7) || (m == 17) ) {
      moveBackward() ;

      on_move = true;
    }
    if ((m == 3) || (m == 13) ) {
      moveRightForward();

      on_move = true;
    }
    if ((m == 1) || (m == 11) ) {
     moveLeftForward();

      on_move = true;
    }
    if ((m == 8) || (m == 18) ) {
      moveRightBackward();

      on_move = true;
    }
    if ((m == 6) || (m == 16) ) {
      moveLeftBackward();

      on_move = true;
    }
    if ((m == 9) || (m == 19)) {
      rotateLeft();

      on_move = true;
    }
    if ((m == 10) || (m == 20)) {
     rotateRight();

      on_move = true;
    }

    if (m == 0) {
      stopMoving();


    }
  }
 else{

 analogWrite(17,wheelSpeed);

  
 }
  }







  moveMotor();




}
