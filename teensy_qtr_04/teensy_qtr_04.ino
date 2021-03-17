#include <QTRSensors.h>
#include <EEPROM.h>


QTRSensors qtr;



int batterie_pin = 37;
int print_Sensor = 0;
long timer;
int limit_qtr, limit_sonar, limit_batterie;
const uint8_t SensorCount = 12;
uint16_t sensorValues[SensorCount];
byte Sensor_qtr[13], Sensor_qtr_temp[13], Sensor_sonar[13], Sensor_sonar_temp[13], dataIn[7], Sensor_batterie[13], coord_in[4], coord_out[13];
byte show_qtr,show_sonar,show_coord,show_bat,show_on,show_lampe;


int trigPin_av = 11, echoPin_av = 12;
int trigPin_ar = 26, echoPin_ar = 27;
int trigPin_gauche = 28, echoPin_gauche = 29;
int trigPin_droite = 24, echoPin_droite = 25;


long duration_av, duration_ar, duration_droite, duration_gauche;
int distance_av, distance_ar, distance_droite, distance_gauche;
int led1 = 2, led2 = 3, led3 = 4, led4 = 5;
int batterie_value, batterie_value_temp;



void setup() {
  timer = millis();
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);




  qtr.setTypeRC();
  qtr.setTimeout(500);
  qtr.setSensorPins((const uint8_t[]) {
    23, 22, 21, 18, 19, 20, 17, 16, 15, 39, 13, 14
  }, SensorCount);
  qtr.setEmitterPin(38);



  pinMode(trigPin_av, OUTPUT);
  pinMode(echoPin_av, INPUT);
  pinMode(trigPin_ar, OUTPUT);
  pinMode(echoPin_ar, INPUT);
  pinMode(trigPin_gauche, OUTPUT);
  pinMode(echoPin_gauche, INPUT);
  pinMode(trigPin_droite, OUTPUT);
  pinMode(echoPin_droite, INPUT);


  limit_qtr = EEPROM.read(0);
  limit_sonar = EEPROM.read(1);
  limit_batterie= EEPROM.read(2);
  delay(500);




  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);


  digitalWrite(led3, HIGH);


}







void loop() {


  osc_in();// RECEIVE DATA FROM ESP8266 AND SEND TO TEENSY3.2
 

  //RECEIVE COORDONATE FROM teensy3.2 and send to OSC 8266
  if (Serial2.available() > 0) {
    Serial2.readBytes(coord_in, 4);
    coord_out[0] = 2;
    coord_out[1] = coord_in[0];
    coord_out[2] = coord_in[1];
    coord_out[3] = coord_in[2];
    coord_out[4] = coord_in[3];
   if(show_coord==1) Serial3.write(coord_out, 13);
  }




 if(show_qtr==1) ligne(); //READ AND SEND QTR TO ESP8266

 if(show_sonar==1) sonar(); //READ AND SEND SONAR TO ESP8266

  if(show_bat==1)batterie(); //READ AND SEND BATTERIE TO ESP8266





  if ( print_Sensor == 1)  {
    imprim_sensor();
  }




}
