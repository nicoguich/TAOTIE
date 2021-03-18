
void F_alignement() {



  ///robot perdu
  if (perdu_temp == false) {
    speed = speed_perdu;
    dir = 12;

    perdu_temp = true;
  }



  ////detection 1 capteur
  if (capteur_ok) {
    speed = speed_perdu;

    switch (etape_perdu) {

      case 0 :

        if (qtr_ok[5] == true) {
          perdu_temp = false;
          dir = 19;
        }

        if (qtr_ok[11] == true) {
          perdu_temp = false;
          dir = 20;
        }


        if (qtr_ok[3] == true) {
          perdu_temp = false;
          dir = 19;
          etape_perdu++;
        }

        if (qtr_ok[9] == true) {
          perdu_temp = false;
          dir = 20;
          etape_perdu++;
        }

        break;

      case 1 :

        if ((qtr_ok[3] == true) || (qtr_ok[11] == true)) {
          perdu_temp = false;
          dir = 19;
        }

        if ((qtr_ok[9] == true) || (qtr_ok[5] == true)) {
          perdu_temp = false;
          dir = 20;
        }




        break;
    }
  }




  ////detection ligne






  if (( qtr_ok[11] == true) && (qtr_ok[5] == true)) {

    perdu_temp = false;
    speed = speed_command;
    dir = 0;
    F_send_command();
    delay(100);
    dir = 2;
    step = 15;
    F_send_command();
    delay(1000);
    dir = 0;
    step = 0;
    alignement = false;
    on_ligneH = true;
    dir_temp = 0;

  }












  if (( qtr_ok[9] == true) && (qtr_ok[3] == true)) {
    speed = speed_command;

    dir = 0;
    F_send_command();
    delay(100);
    dir = 7;
    step = 15;
    F_send_command();
    delay(1000);
    dir = 0;
    step = 0;
    alignement = false;
    on_ligneH = true;
    dir_temp = 0;





  }

  if (dir != dir_temp) {
    dir_temp = dir;
    envoi = true;
  }

}
