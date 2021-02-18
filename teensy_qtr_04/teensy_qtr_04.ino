#include <QTRSensors.h>


QTRSensors qtr_av, qtr_ar, qtr_gauche, qtr_droite;




boolean print_sensor = false;
long timer;
uint16_t position_av, position_ar, position_gauche, position_droite;
const uint8_t SensorCount = 3;
uint16_t sensorValues_av[SensorCount], sensorValues_ar[SensorCount], sensorValues_gauche[SensorCount], sensorValues_droite[SensorCount];
byte dataSensor[5], dataIn[5];

int trigPin_av= 6, echoPin_av=11;
int trigPin_ar= 0, echoPin_ar=1;
int trigPin_gauche= 4, echoPin_gauche=5;
int trigPin_droite= 2, echoPin_droite=3;


long duration_av,duration_ar,duration_droite,duration_gauche;
int distance_av,distance_ar,distance_droite,distance_gauche;




void setup() {
  timer = millis();
 if(print_sensor){ Serial.begin(9600);}
  Serial2.begin(9600);
  Serial3.begin(9600);




  qtr_av.setTypeRC();
  qtr_av.setSensorPins((const uint8_t[]) {
    21, 22, 23
  }, SensorCount);
  qtr_av.setEmitterPin(29);

  qtr_ar.setTypeRC();
  qtr_ar.setSensorPins((const uint8_t[]) {
    15, 16, 17
  }, SensorCount);
  qtr_ar.setEmitterPin(29);

  qtr_droite.setTypeRC();
  qtr_droite.setSensorPins((const uint8_t[]) {
    18, 19, 20
  }, SensorCount);
  qtr_droite.setEmitterPin(29);


  qtr_gauche.setTypeRC();
  qtr_gauche.setSensorPins((const uint8_t[]) {
    14, 13, 12
  }, SensorCount);
  qtr_gauche.setEmitterPin(29);

  delay(500);

/*
  for (uint16_t i = 0; i < 5; i++)
  {
    qtr_av.calibrate();
    qtr_ar.calibrate();
    qtr_gauche.calibrate();
    qtr_droite.calibrate();
  }


  qtr_av.calibrationOn.minimum[0] = 70;
  qtr_av.calibrationOn.maximum[0] = 450;
  qtr_ar.calibrationOn.minimum[0] = 70;
  qtr_ar.calibrationOn.maximum[0] = 450;

  qtr_av.calibrationOn.minimum[1] = 70;
  qtr_av.calibrationOn.maximum[1] = 450;
  qtr_ar.calibrationOn.minimum[1] = 70;
  qtr_ar.calibrationOn.maximum[1] = 450;

  qtr_av.calibrationOn.minimum[2] = 70;
  qtr_av.calibrationOn.maximum[2] = 450;
  qtr_ar.calibrationOn.minimum[2] = 70;
  qtr_ar.calibrationOn.maximum[2] = 450;



  qtr_gauche.calibrationOn.minimum[0] = 70;
  qtr_gauche.calibrationOn.maximum[0] = 450;
  qtr_droite.calibrationOn.minimum[0] = 70;
  qtr_droite.calibrationOn.maximum[0] = 450;



  qtr_gauche.calibrationOn.minimum[1] = 70;
  qtr_gauche.calibrationOn.maximum[1] = 450;
  qtr_droite.calibrationOn.minimum[1] = 70;
  qtr_droite.calibrationOn.maximum[1] = 450;



  qtr_gauche.calibrationOn.minimum[2] = 70;
  qtr_gauche.calibrationOn.maximum[2] = 450;
  qtr_droite.calibrationOn.minimum[2] = 70;
  qtr_droite.calibrationOn.maximum[2] = 450;

*/

  delay(500);


pinMode(trigPin_av, OUTPUT); 
pinMode(echoPin_av, INPUT);
pinMode(trigPin_ar, OUTPUT); 
pinMode(echoPin_ar, INPUT);
pinMode(trigPin_gauche, OUTPUT); 
pinMode(echoPin_gauche, INPUT);
pinMode(trigPin_droite, OUTPUT); 
pinMode(echoPin_droite, INPUT);
}







void loop() {

  qtr_av.read(sensorValues_av);
  qtr_ar.read(sensorValues_ar);
  qtr_gauche.read(sensorValues_gauche);
  qtr_droite.read(sensorValues_droite);


  if ( print_sensor)  {
    imprim_sensor();
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
  delay(20);





  delay(50);
}
