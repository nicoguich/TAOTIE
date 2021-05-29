#include <QTRSensors.h>
#include <EEPROM.h>
#include <SD.h>


QTRSensors qtr;



File myFile,retourFile;
int data_sd[10000];
int nombre[4];
int compteur_data=0;
const int chipSelect = BUILTIN_SDCARD;
int rec_sd=0,play_sd=0, compteur_sd=0;
boolean lecture_ok=false;
int dir_data[2],speed_data[2];
int boucle=0;
int button_state,button_change;
int low_batterie, en_charge=0,batterie_ok=0,copain_base=0;


int batterie_pin = 37;
int print_Sensor = 0;
long timer;
int limit_qtr, limit_sonar, limit_batterie;
const uint8_t SensorCount = 12;
uint16_t sensorValues[SensorCount];
byte data_get_out[13],Sensor_qtr[13], Sensor_qtr_temp[13], Sensor_sonar[13], Sensor_sonar_temp[13], dataIn[7], dataMotor[5], Sensor_batterie[13], dist_to_go_temp[3],dist_to_go[13], coord_out[13];
byte show_qtr, show_sonar, show_coord, show_bat, show_on, show_lampe;
boolean qtr_ok[12];
boolean on_home = false, on_T_ar = false, on_T_av = false, on_T_gauche = false, on_T_droite = false, go_on = false, on_T = false,on_T_temp=false, on_croisement = false,on_croisement_temp=false, on_ligneH = false,on_ligneH_temp=false, on_ligneV = false,on_ligneV_temp=false, ligne_ok = false, croisement_ok = false, coin_ok = false, T_ok = false, capteur_ok = false, perdu_temp = false, follow_ligne = false, hors_grille=false;
boolean envoi = false, alignement = false;
int etape_perdu = 0, etape_croisement = 0, compteur_croisement, dir_change = 0, etape_go = 0;
int speed, speed_command=1000, speed_perdu = 500, step = 0, dir, dir_temp, dir_on_ligne, pos;
int coordX=0, coordY=0, angle, stepX=0, stepY=0, stepX_hors_grille=0,stepY_hors_grille=0;
int dest_stepX=0,dest_stepY=0;

int trigPin_av = 11, echoPin_av = 12;
int trigPin_ar = 26, echoPin_ar = 27;
int trigPin_gauche = 28, echoPin_gauche = 29;
int trigPin_droite = 24, echoPin_droite = 25;


long duration_av, duration_ar, duration_droite, duration_gauche;
int distance_av, distance_ar, distance_droite, distance_gauche;
int led1 = 2, led2 = 3, led3 = 4, led4 = 5, fat_led=33; 
int batterie_value, batterie_value_temp;
int led_value=255;




void setup() {
  timer = millis();
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
  SD.begin(chipSelect);



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
  pinMode(36,INPUT);


  limit_qtr = EEPROM.read(0);
  limit_sonar = EEPROM.read(1);
  limit_batterie = EEPROM.read(2);
  play_sd=EEPROM.read(3);
  delay(500);




  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(fat_led,OUTPUT);


  

lecture_ok=true;
alignement = true;
dir_temp = 0;
etape_perdu = 0;
compteur_sd=0;
delay(2000);

}







void loop() {




  F_osc_in();// RECEIVE DATA FROM ESP8266 AND SEND TO TEENSY3.2

  F_qtr();//READ AND SEND QTR TO ESP8266
  F_sonar(); //READ AND SEND SONAR TO ESP8266
  F_batterie(); //READ AND SEND BATTERIE TO ESP8266

  if (alignement) F_alignement();


  if(rec_sd>0){


      digitalWrite(led3,HIGH);
  }


  if (play_sd>0){

F_play_sd();
    digitalWrite(led3,HIGH);
    
  }
  if ((play_sd==0)&&(rec_sd==0)){
        digitalWrite(led3,LOW);
  }


  if ((on_ligneH) || (on_ligneV)){
 
    digitalWrite(led2,HIGH);
  }
  else{
     digitalWrite(led2,LOW);
  }

digitalWrite(led1, HIGH);
 analogWrite(fat_led, led_value);

 
  if ( print_Sensor == 1)F_imprim_sensor();
  if (envoi) F_send_command();




}
