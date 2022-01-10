#include <AccelStepper.h>

// Define the stepper motors and the pins the will use

AccelStepper arriere_droitWheel(1, 3, 4);  // Stepper1 // (Type:driver, STEP, DIR) -
AccelStepper avant_droitWheel(1, 11, 12); // Stepper2
AccelStepper arriere_gaucheWheel(1, 14, 15);  // Stepper3
AccelStepper avant_gaucheWheel(1, 6, 9);   // Stepper4



const int BUFFER_SIZE = 10;
byte data2[BUFFER_SIZE];




int wheelSpeed = 5000;
int avant_gaucheSpeed, arriere_droitSpeed, arriere_gaucheSpeed, avant_droitSpeed;

int dataIn, m = -1, dir, compteurdata;
long pos, timer;

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




  analogWrite(17,230);
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







delay(2000);
}
void loop() {
  if (Serial3.available() > 0) {

    batterie();
    
    byte data = Serial3.readBytesUntil('\n',data2,BUFFER_SIZE);
    //Serial.print(data);
    for (int x=0;x<10;x++){
    
    }


    


    pos = (256 * data2[0]) + data2[1];
    dir = data2[2];
    wheelSpeed = int ((256 * data2[3]) + data2[4]);
    Serial.print("pos ");
    Serial.print(pos);
    Serial.print("/ dir ");
    Serial.print(dir);
    Serial.print("/ speed ");
    Serial.println(wheelSpeed);

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


    /*
        Serial.print(m);
        Serial.print("  ");
        Serial.print(pos / 32);
        Serial.print("  ");
        Serial.println(wheelSpeed);

    */


    if ((m == 4) || (m == 14) || (m == 24) || (m == 34)) {
      moveSidewaysLeft();

      on_move = true;
    }
    if ((m == 5) || (m == 15) || (m == 25) || (m == 35)) {
      moveSidewaysRight();

      on_move = true;
    }
    if ((m == 2) || (m == 12) || (m == 22) || (m == 32)) {

      moveForward();

      on_move = true;
    }
    if ((m == 7) || (m == 17) || (m == 27) || (m == 37)) {
      moveBackward() ;

      on_move = true;
    }
    if ((m == 3) || (m == 13) || (m == 23) || (m == 33)) {
      moveRightForward();

      on_move = true;
    }
    if ((m == 1) || (m == 11) || (m == 21) || (m == 31)) {
     moveLeftForward();

      on_move = true;
    }
    if ((m == 8) || (m == 18) || (m == 28) || (m == 38)) {
      moveRightBackward();

      on_move = true;
    }
    if ((m == 6) || (m == 16) || (m == 26) || (m == 36)) {
      moveLeftBackward();

      on_move = true;
    }
    if ((m == 9) || (m == 19) || (m == 29) || (m == 39)) {
      rotateLeft();

      on_move = true;
    }
    if ((m == 10) || (m == 20) || (m == 30) || (m == 40)) {
     rotateRight();

      on_move = true;
    }

    if (m == 0) {
      stopMoving();


    }
  }








  moveMotor();




}