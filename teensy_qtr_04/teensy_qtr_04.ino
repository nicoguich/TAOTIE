#include <QTRSensors.h>


QTRSensors qtr_av, qtr_ar, qtr_gauche, qtr_droite;



int batterie_pin = A18;
boolean print_sensor = false;
long timer;
uint16_t position_av, position_ar, position_gauche, position_droite;
const uint8_t SensorCount = 3;
uint16_t sensorValues_av[SensorCount], sensorValues_ar[SensorCount], sensorValues_gauche[SensorCount], sensorValues_droite[SensorCount];
byte dataSensor[5], dataIn[5], datawheel[4];

int trigPin_av= 11, echoPin_av=12;
int trigPin_ar= 26, echoPin_ar=27;
int trigPin_gauche= 28, echoPin_gauche=29;
int trigPin_droite= 24, echoPin_droite=25;


long duration_av,duration_ar,duration_droite,duration_gauche;
int distance_av,distance_ar,distance_droite,distance_gauche;
int led1=2,led2=3,led3=4,led4=5;
int batterie_value=0;



void setup() {
  timer = millis();
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);




  qtr_av.setTypeRC();
  qtr_av.setSensorPins((const uint8_t[]) {
    23, 22, 21
  }, SensorCount);
  qtr_av.setEmitterPin(38);

  qtr_ar.setTypeRC();
  qtr_ar.setSensorPins((const uint8_t[]) {
    17, 16, 15
  }, SensorCount);
  qtr_ar.setEmitterPin(38);

  qtr_droite.setTypeRC();
  qtr_droite.setSensorPins((const uint8_t[]) {
    18, 19, 20
  }, SensorCount);
  qtr_droite.setEmitterPin(38);


  qtr_gauche.setTypeRC();
  qtr_gauche.setSensorPins((const uint8_t[]) {
    39, 13, 14
  }, SensorCount);
  qtr_gauche.setEmitterPin(38);

 // delay(500);



pinMode(trigPin_av, OUTPUT); 
pinMode(echoPin_av, INPUT);
pinMode(trigPin_ar, OUTPUT); 
pinMode(echoPin_ar, INPUT);
pinMode(trigPin_gauche, OUTPUT); 
pinMode(echoPin_gauche, INPUT);
pinMode(trigPin_droite, OUTPUT); 
pinMode(echoPin_droite, INPUT);



pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);


digitalWrite(led3,HIGH);


}







void loop() {

  qtr_av.read(sensorValues_av);
  qtr_ar.read(sensorValues_ar);
  qtr_gauche.read(sensorValues_gauche);
  qtr_droite.read(sensorValues_droite);


  if ( print_sensor)  {
    imprim_sensor();
  }

batterie_value=analogRead(batterie_pin);
Serial.println(batterie_value);

  //RECEIVE DATA MOTOR FROM teensy3.2 and send to OSC 8266
  if (Serial2.available() > 0) {
    Serial2.readBytes(datawheel, 4);
 
  }



  //RECEIVE DATA MOTOR FROM OSC 8266
  if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 5);
    Serial2.write(dataIn, 5);
  }


 // sonar();
  ligne();

  //SEND DATA CAPTEUR TO OSC 8266

  Serial3.write(dataSensor, 16);
  delay(80);


}
