#include <QTRSensors.h>
#include <EEPROM.h>


QTRSensors qtr;



int batterie_pin = 37;
int print_Sensor = 0;
long timer;
int limit_qtr,limit_sonar;
const uint8_t SensorCount = 12;
uint16_t sensorValues[SensorCount];
byte Sensor_qtr[13], Sensor_qtr_temp[13], Sensor_sonar[13], Sensor_sonar_temp[13],dataIn[7];

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
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);




  qtr.setTypeRC();
  qtr.setTimeout(500);
  qtr.setSensorPins((const uint8_t[]){23, 22, 21,18,19,20,17,16,15,39,13,14}, SensorCount);
  qtr.setEmitterPin(38);



pinMode(trigPin_av, OUTPUT); 
pinMode(echoPin_av, INPUT);
pinMode(trigPin_ar, OUTPUT); 
pinMode(echoPin_ar, INPUT);
pinMode(trigPin_gauche, OUTPUT); 
pinMode(echoPin_gauche, INPUT);
pinMode(trigPin_droite, OUTPUT); 
pinMode(echoPin_droite, INPUT);


limit_qtr=EEPROM.read(0);
limit_sonar=EEPROM.read(1);
delay(500);




pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);


digitalWrite(led3,HIGH);


}







void loop() {


// RECEIVE DATA FROM ESP8266
  if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 7);
    if (dataIn[0]<2){
    Serial2.write(dataIn, 7);}
    else if (dataIn[0]==2){
      EEPROM.write(0, dataIn[1]) ;
      limit_qtr=dataIn[1];
      delay(500);
      }

    else if (dataIn[0]==3){
      EEPROM.write(1, dataIn[1]) ;
       limit_sonar=dataIn[1];
      delay(500);
      }
  }
  



  ligne(); //READ AND SEND QTR TO ESP8266

  sonar(); //READ AND SEND SONAR TO ESP8266

 



  if ( print_Sensor==1)  {
    imprim_sensor();
  }
 /*
batterie_value=analogRead(batterie_pin);
//Serial.println(batterie_value);

  //RECEIVE DATA MOTOR FROM teensy3.2 and send to OSC 8266
  if (Serial2.available() > 0) {
    Serial2.readBytes(datawheel, 4);
 
  }







 // sonar();

*/

}
