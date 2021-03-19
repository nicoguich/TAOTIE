void F_osc_in() {


  if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 7);

    switch (dataIn[0]) {
      case 0 :

        for (int x = 0; x < 6; x++) {
          dataMotor[x] = dataIn[x + 1];
        }
        Serial2.write(dataMotor, 5);
        step = int((256 * dataMotor[0]) + dataMotor[1]);
        dir = int(dataMotor[2]);
        speed = int ((256 * dataMotor[3]) + dataMotor[4]);
        speed_command = speed;
        if (dir==0){
        on_ligneV=false;
        on_ligneH=false;
        go_on=false;
        alignement = false;
        perdu_temp = false;
        on_home=false;
        on_croisement=false;
        on_T_av = false;
        on_T_ar = false;
        on_T_droite = false;
        on_T_gauche = false;
        dir_on_ligne = dir;
        stepX = 0;
        stepY=0;
        dest_stepX=0;
        dest_stepY=0;
        coordX = 0;
        coordY = 0;
        }
        break;

      case 1 :
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

        break;

      case 2:
        EEPROM.write(0, dataIn[1]) ;
        limit_qtr = dataIn[1];
        delay(500);
        break;

      case 3 :
        EEPROM.write(1, dataIn[1]) ;
        limit_sonar = dataIn[1];
        delay(500);
        break;


      case 4 :
        EEPROM.write(2, dataIn[1]) ;
        limit_batterie = dataIn[1];
        delay(500);
        break;

      case 100 :
        alignement = true;
        perdu_temp = false;
        dir_temp = 0;
        etape_perdu = 0;
        break;

      case 101 :
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
        break;



      case 102 :
        int dest_coordX = int(dataIn[1]);
         dest_stepX = int(dataIn[2]);
        int dest_coordY = int(dataIn[3]);
         dest_stepY = int(dataIn[4]);

        stepX = dest_coordX - coordX;
        stepY = dest_coordY - coordY;




        if ((stepX_hors_grille>0)||(stepY_hors_grille>0)){

F_retour_croisement();
          
        }



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

        break;


    }
  }






}
