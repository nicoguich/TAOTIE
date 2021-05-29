void F_osc_in() {

/*
if ((digitalRead(36)==LOW)&&(play_sd==0)){
  


play_sd=1;
lecture_ok=true;
      alignement = true;
      perdu_temp = false;
      dir_temp = 0;
      etape_perdu = 0;


}
if (digitalRead(36)==HIGH){
 
  play_sd=0;

}
  

*/
  

  if (Serial2.available() > 0) {
 
     Serial2.readBytes(dist_to_go_temp, 3); //RECEIVE dist_to_go FROM teensy3.2 and send to OSC 8266

     data_get_out[0] = 123;
     data_get_out[1]=dist_to_go_temp[1];
     data_get_out[2]=dist_to_go_temp[2];
   /*  Serial3.write(data_get_out,13);
     delay(10);*/
   if ((play_sd>0)&&(alignement==false)&&(boucle==0)){
     if ((int((256*data_get_out[1])+data_get_out[2]))==65535){
      
      compteur_sd=compteur_sd+3;
      
      if (compteur_sd<compteur_data){
      lecture_ok=false;}
   
      else{

if (play_sd!=10){
        alignement=true;
        on_ligneH = false;}
        
        compteur_sd=0;

        etape_perdu=0;
if (low_batterie==1){
  play_sd=10;
  en_charge=1;
  copain_base=0;
  timer=millis();
  
}       
 } 
 }
 }

      if (rec_sd>0){
        Serial.println("rec_data...");
        Serial.println(String(65000- (int((256*data_get_out[1])+data_get_out[2]))));
        Serial.println(String(dir_data[0]));
        Serial.println();

if(int((256*data_get_out[1])+data_get_out[2])< 65000){
myFile.print(String(65000- (int((256*data_get_out[1])+data_get_out[2]))));
myFile.print(" ");
myFile.print(String(dir_data[0]));
myFile.print(" ");
myFile.print(String(speed_data[0]));
myFile.print("/");}
else{
  myFile.print(String(65000));
  myFile.print(" ");
myFile.print(String(dir));
myFile.print(" ");
myFile.print(String(speed));
myFile.print("/");

}


        
      }



   boucle=0;
    
  }




  


  if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 7);
    //delay(100);



    if ((dataIn[0] == 0)&&(play_sd==0)) {
      for (int x = 0; x < 6; x++) {
        dataMotor[x] = dataIn[x + 1];
      }
      Serial2.write(dataMotor, 5);
      step = int((256 * dataMotor[0]) + dataMotor[1]);
      dir = int(dataMotor[2]);
      speed = int ((256 * dataMotor[3]) + dataMotor[4]);
      speed_command = speed;
      if (dir == 0) {
        on_ligneV = false;
        on_ligneH = false;
        go_on = false;
        alignement = false;
        perdu_temp = false;
        on_home = false;
        on_croisement = false;
        on_T_av = false;
        on_T_ar = false;
        on_T_droite = false;
        on_T_gauche = false;
        dir_on_ligne = dir;
        stepX = 0;
        stepY = 0;
        dest_stepX = 0;
        dest_stepY = 0;
        coordX = 0;
        coordY = 0;
      }

 speed_data[0]=speed_data[1];
    speed_data[1]=speed;     

dir_data[0]=dir_data[1];
    dir_data[1]=dir;  
    }

    else if (dataIn[0] == 1) {
      show_qtr = dataIn[1];
      show_sonar = dataIn[2];
      show_coord = dataIn[3];
      show_bat = dataIn[4];
      show_on = dataIn[5];
      show_lampe = dataIn[6];
      /*    Serial.print(show_qtr);
          Serial.print(" ");
                Serial.print(show_sonar);
          Serial.print(" ");
                Serial.print(show_coord);
          Serial.print(" ");
                      Serial.print(show_bat);
          Serial.print(" ");
                Serial.print(show_on);
          Serial.print(" ");
                Serial.println(show_lampe);*/

    }

    else if (dataIn[0] == 2) {
      EEPROM.write(0, dataIn[1]) ;
      limit_qtr = dataIn[1];
      delay(500);
    }

    else if (dataIn[0] == 3) {
      EEPROM.write(1, dataIn[1]) ;
      limit_sonar = dataIn[1];
      delay(500);
    }


    else if (dataIn[0] == 4) {
      EEPROM.write(2, dataIn[1]) ;
      limit_batterie = dataIn[1];
      delay(500);
    }

    else if (dataIn[0] == 5) {

      data_get_out[0] = 106 ;
      data_get_out[1] = byte(limit_qtr);

      Serial3.write(data_get_out, 13);
    }

    else if (dataIn[0] == 6) {
      data_get_out[0] = 107 ;
      data_get_out[1] = byte(limit_sonar);

      Serial3.write(data_get_out, 13);
    }


    else if (dataIn[0] == 7) {
      data_get_out[0] = 108 ;
      data_get_out[1] = byte(limit_batterie);
      Serial3.write(data_get_out, 13);
    }

    else if (dataIn[0] == 8) {
       led_value = int(dataIn[1]);
     
    }


    else if ((dataIn[0] == 100)&&(play_sd==0)&&(rec_sd==0)) {
      alignement = true;
      perdu_temp = false;
      dir_temp = 0;
      etape_perdu = 0;
    }



else if ((dataIn[0] == 103)&&(play_sd==0)) {
  
rec_sd=int(dataIn[1]);

  
if (rec_sd==1){
  Serial.println("rec un");
    if (SD.exists("un.txt")){ 
      Serial.println("remove");
  SD.remove("un.txt");
    myFile = SD.open("un.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("un.txt", FILE_WRITE);
Serial.println("create parcours un");
  }
play_sd=0;}


if (rec_sd==2){
  Serial.println("rec deux");
    if (SD.exists("deux.txt")){ 
      Serial.println("remove");
  SD.remove("deux.txt");
    myFile = SD.open("deux.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("deux.txt", FILE_WRITE);
  }
play_sd=0;}


if (rec_sd==3){
  Serial.println("rec trois");
    if (SD.exists("trois.txt")){ 
      Serial.println("remove");
  SD.remove("trois.txt");
    myFile = SD.open("trois.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("trois.txt", FILE_WRITE);
  }
play_sd=0;}


if (rec_sd==4){
  Serial.println("rec quatre");
    if (SD.exists("quatre.txt")){ 
      Serial.println("remove");
  SD.remove("quatre.txt");
    myFile = SD.open("quatre.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("quatre.txt", FILE_WRITE);
  }
play_sd=0;}

if (rec_sd==5){
  Serial.println("rec cinq");
    if (SD.exists("cinq.txt")){ 
      Serial.println("remove");
  SD.remove("cinq.txt");
    myFile = SD.open("cinq.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("cinq.txt", FILE_WRITE);
  }
play_sd=0;}





if (rec_sd==10){
  Serial.println("rec chargeur");
    if (SD.exists("chargeur.txt")){ 
      Serial.println("remove chargeur");
  SD.remove("chargeur.txt");
    myFile = SD.open("chargeur.txt", FILE_WRITE);
  }
  else{
myFile = SD.open("chargeur.txt", FILE_WRITE);
    
  }
play_sd=0;}








if( rec_sd==0){
  Serial.println("close_rec");

  myFile.print(String(0));
  myFile.print(" ");
myFile.print(String(0));
myFile.print(" ");
myFile.print(String(speed));
myFile.print("/");


  myFile.close();

  if (SD.exists("chargeur.txt")){
    
  myFile = SD.open("chargeur.txt");
  
  compteur_data=0;
  int compteur_nombre=0;
    int data_temp=0;
    int compteur_calcul=0;
    int lecture_nombre;
    
    while (myFile.available()) {
      lecture_nombre=myFile.read();
     if((int(lecture_nombre)-48!=-16)&&(int(lecture_nombre)-48!=-1)){
     nombre[compteur_nombre]= int(lecture_nombre)-48;
     compteur_nombre++;
    }
    else if ((int(lecture_nombre)-48==-16)||(int(lecture_nombre)-48==-1)){
    for (int x=compteur_nombre-1; x>-1;x--){
data_temp=data_temp+(nombre[x]*pow(10,compteur_calcul));
compteur_calcul++;

    }
    data_sd[compteur_data]=int(data_temp);
    compteur_data++;
    compteur_calcul=0;
    compteur_nombre=0;
    data_temp=0;
    

    }
  
    }
    // close the file:
    myFile.close();

delay(100);


 Serial.println("rec_retour");
    if (SD.exists("retour.txt")){ 
      Serial.println("remove retour_base");
  SD.remove("retour.txt");
    retourFile = SD.open("retour.txt", FILE_WRITE);
  }
  else{


retourFile = SD.open("retour.txt", FILE_WRITE);
    
  }


int dir_temp;
    for (int x=compteur_data-6;x>-1;x=x-3){
   Serial.println("write retour");   


retourFile.print(String(data_sd[x]));

retourFile.print(" ");
if(data_sd[x+1]==1){
  dir_temp=8;
}
else if(data_sd[x+1]==2){
  dir_temp=7;
}

else if(data_sd[x+1]==3){
  dir_temp=6;
}

else if(data_sd[x+1]==4){
  dir_temp=5;
}

else if(data_sd[x+1]==5){
  dir_temp=4;
}


else if(data_sd[x+1]==6){
  dir_temp=3;
}


else if(data_sd[x+1]==7){
  dir_temp=2;
}


else if(data_sd[x+1]==8){
  dir_temp=1;
}

else if(data_sd[x+1]==9){
  dir_temp=10;
}

else if(data_sd[x+1]==10){
  dir_temp=9;
}
retourFile.print(String(dir_temp));
retourFile.print(" ");
retourFile.print(String(data_sd[x+2]));
retourFile.print("/");

Serial.print(data_sd[x]);
Serial.print("  ");
Serial.print(dir_temp);
Serial.print("  ");
Serial.println(data_sd[x+2]);



      
    }
    retourFile.print(String(3000));
    retourFile.print(" ");
    retourFile.print(String(3));
retourFile.print(" ");
retourFile.print(String(500));
retourFile.print("/");
    retourFile.close();
    Serial.println("close retour");
  
}


}

}





else if ((dataIn[0] == 104)&&(rec_sd==0)) {

  

play_sd=int(dataIn[1]);
if ((play_sd>0)&&(play_sd!=10)){ 
lecture_ok=true;
alignement = true;
perdu_temp = false;
dir_temp = 0;
etape_perdu = 0;
compteur_sd=0;
      EEPROM.write(3, dataIn[1]) ;
      delay(200);
    
}
if (play_sd==10){

  lecture_ok=true;
alignement = true;
perdu_temp = false;
dir_temp = 0;
etape_perdu = 0;
compteur_sd=0;


  en_charge=1;
  copain_base=0;
  timer=millis();
}



}

else if (dataIn[0] == 105){


copain_base=1;


  
}









    
  }
}
