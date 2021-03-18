void F_on_ligne() {


  /// gauche droite
  if ((dir == 14) || (dir == 15)) {

    if (dir == 14) {

      if ((qtr_ok[2] == true) || (qtr_ok[6] == true)) {
        on_ligneH = false;
        on_croisement = true;
        etape_croisement = 0;
      }
    }


    if (dir == 15) {

      if ((qtr_ok[0] == true) || (qtr_ok[8] == true)) {
        on_ligneH = false;
        on_croisement = true;
        etape_croisement = 0;
      }
    }



    if (on_croisement == false) {

      if ((qtr_ok[3] == true) && (qtr_ok[9] == false) && (qtr_ok[4] == false)) {
        speed = speed_perdu;
        dir = 19;
      }

      if ((qtr_ok[3] == false) && (qtr_ok[9] == true) && (qtr_ok[10] == false)) {
        speed = speed_perdu;
        dir = 20;

      }


      if ((qtr_ok[3] == true) && (qtr_ok[9] == true) && (qtr_ok[4] == false) && (qtr_ok[10] == false)) {
        int dir_temp = dir;
        speed = speed_perdu;
        dir = 7;
        step = 5;
        F_send_command();


        delay(200);
        dir = dir_temp;
        step = 0;
        F_send_command();
      }


      if ((qtr_ok[11] == true) && (qtr_ok[5] == false) && (qtr_ok[10] == false)) {
        speed = speed_perdu;
        dir = 19;
      }

      if ((qtr_ok[11] == false) && (qtr_ok[5] == true) && (qtr_ok[4] == false)) {
        speed = speed_perdu;
        dir = 20;
      }


      if ((qtr_ok[11] == true) && (qtr_ok[5] == true) && (qtr_ok[4] == false) && (qtr_ok[10] == false)) {
        dir_temp = dir;
        speed = speed_perdu;
        dir = 2;
        step = 5;
        F_send_command();
        delay(200);
        dir = dir_temp;
        step = 0;
        F_send_command();
      }
    }
  }




  /// avant arrière
  if ((dir==12) || (dir==17)) {

    if (dir==12) {

      if ((qtr_ok[11] == true) || (qtr_ok[5] == true)) {
        on_ligneV = false;
        on_croisement = true;
        etape_croisement = 0;
      }
    }


    if (dir==17){

      if ((qtr_ok[9] == true) || (qtr_ok[3] == true)) {
        on_ligneV = false;
        on_croisement = true;
        etape_croisement = 0;
      }
    }



    if (on_croisement == false) {

      if ((qtr_ok[2] == true) && (qtr_ok[6] == false) && (qtr_ok[1] == false)) {
        speed = speed_perdu;
        dir = 20;
      }

      if ((qtr_ok[2] == false) && (qtr_ok[6] == true) && (qtr_ok[7] == false)) {
        speed = speed_perdu;
        dir = 19;
      }


      if ((qtr_ok[2] == true) && (qtr_ok[6] == true) && (qtr_ok[7] == false) && (qtr_ok[1] == false)) {
        dir_temp = dir;
        speed = speed_perdu;
        dir = 4;
        step = 5;
        F_send_command();
        delay(200);
        step = 0;
        dir = dir_temp;
        F_send_command();
      }


      if ((qtr_ok[0] == true) && (qtr_ok[8] == false) && (qtr_ok[1] == false)) {
        speed = speed_perdu;
        dir = 19;
      }

      if ((qtr_ok[0] == false) && (qtr_ok[8] == true) && (qtr_ok[7] == false)) {
        speed = speed_perdu;
        dir = 20;
      }


      if ((qtr_ok[0] == true) && (qtr_ok[8] == true) && (qtr_ok[7] == false) && (qtr_ok[1] == false)) {
        dir_temp = dir;
        speed = speed_perdu;
        dir = 5;
        step = 5;
        F_send_command();
        delay(200);

        dir = dir_temp;
        step = 0;
        F_send_command();
      }
    }
  }






  if (dir != dir_temp) {
    dir_temp = dir;
    envoi = true;
  } else {
    dir = dir_on_ligne;
  }
}
