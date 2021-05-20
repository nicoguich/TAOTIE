void F_osc_in() {

/*
if (digitalRead(6)!=button_state){
  button_state=digitalRead(6);
  Serial.println("bouton");
 if (play_sd==0){ 
play_sd=1;
lecture_ok=true;
      alignement = true;
      perdu_temp = false;
      dir_temp = 0;
      etape_perdu = 0;


delay(200);}
else{
 
  play_sd=0;
delay(200);
}
  
}

  */

  if (Serial2.available() > 0) {
 
     Serial2.readBytes(dist_to_go_temp, 3); //RECEIVE dist_to_go FROM teensy3.2 and send to OSC 8266

     data_get_out[0] = 123;
     data_get_out[1]=dist_to_go_temp[1];
     data_get_out[2]=dist_to_go_temp[2];
     Serial3.write(data_get_out,13);
     delay(100);
   if (((play_sd==1)||(play_sd==2))&&(alignement==false)&&(boucle==0)){
     if ((int((256*data_get_out[1])+data_get_out[2]))==65535){
      


      compteur_sd=compteur_sd+3;
      
      if (compteur_sd<compteur_data){
      lecture_ok=false;}
      else{
       
        compteur_sd=0;
        alignement=true;
        on_ligneV = false;
        on_ligneH = false;
        go_on = false;
        perdu_temp = false;
        on_home = false;
        on_croisement = false;




       
      }

      
     }
    }


      if ((rec_sd==1)||(rec_sd==2)){
        Serial.println("rec_data...");
        Serial.println(String(65000- (int((256*data_get_out[1])+data_get_out[2]))));
        Serial.println(String(dir_data[0]));
        Serial.println();

if(int((256*data_get_out[1])+data_get_out[2])< 65000){
myFile.print(String(65000- (int((256*data_get_out[1])+data_get_out[2]))));}
else{
  myFile.print(String(65000));

}
myFile.print(" ");
myFile.print(String(dir_data[0]));
myFile.print(" ");
myFile.print(String(speed));
myFile.print("/");
        
      }



   boucle=0;
    
  }




  


  if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 7);
    delay(100);



    if (dataIn[0] == 0) {
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


    else if (dataIn[0] == 100) {
      alignement = true;
      perdu_temp = false;
      dir_temp = 0;
      etape_perdu = 0;
    }

    else if (dataIn[0] == 101) {
      on_home = true;
      if ((on_T_gauche == false) && (on_T_ar == false)) {
        if (on_ligneH) {

          dir = 14;
        }

        if (on_ligneV) {

          dir = 17;
        }
      }

      if ((on_T_gauche == true) && (on_T_ar == false)) {
        dir = 17;

      }

      if ((on_T_gauche == false) && (on_T_ar == true)) {
        dir = 14;

      }
      if ((on_T_gauche == true) && (on_T_ar == true)) {
        dir = 0;
        on_home = false;
        coordX = 0;
        coordY = 0;
        angle = 0;
      }

      dir_on_ligne = dir;

      envoi = true;
    }



    else if (dataIn[0] == 102) {
      int dest_coordX = int(dataIn[1]);
      dest_stepX = int(dataIn[2]);
      int dest_coordY = int(dataIn[3]);
      dest_stepY = int(dataIn[4]);

      stepX = dest_coordX - coordX;
      stepY = dest_coordY - coordY;







      go_on = true;
      if (go_on) {
        if ((int(stepX) != 0) && (on_ligneV == false)) {
          if (int(stepX) > 0) {
            dir = 15;
            dir_on_ligne = dir;
            F_send_command();
          }
          else {
            dir = 14;
            dir_on_ligne = dir;
            F_send_command();
          }

        }


        else if (on_ligneH == false) {
          if (int(stepY) > 0) {
            dir = 12;
            dir_on_ligne = dir;
            F_send_command();
          }
          else {
            dir = 17;
            dir_on_ligne = dir;
            F_send_command();
          }
        }
      }
    }

else if (dataIn[0] == 103) {
  
rec_sd=int(dataIn[1]);  
if (rec_sd==1){
  Serial.println("rec");
    if (SD.exists("test.txt")){ 
      Serial.println("remove");
  SD.remove("test.txt");
    myFile = SD.open("test.txt", FILE_WRITE);
  }
  else{


myFile = SD.open("test.txt", FILE_WRITE);
    
  }
play_sd=0;}

if (rec_sd==2){
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
  Serial.println("close_rec chargeur");
  myFile.close();
}

}





else if (dataIn[0] == 104) {

play_sd=int(dataIn[1]); 
if (play_sd==1){
      
play_sd=1;
lecture_ok=true;
alignement = true;
perdu_temp = false;
dir_temp = 0;
etape_perdu = 0;
compteur_sd=0;
}


if (play_sd==2){
      
play_sd=2;
lecture_ok=true;
alignement = true;
perdu_temp = false;
dir_temp = 0;
etape_perdu = 0;
compteur_sd=0;
}






}





    
  }
}
