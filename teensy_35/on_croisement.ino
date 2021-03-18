
void F_on_croisement() {


  ////GAUCHE
  if (dir == 14) {
    switch (etape_croisement) {




      case 0 :

        if ((qtr_ok[1] == true) || (qtr_ok[7] == true) || (qtr_ok[0] == true) || (qtr_ok[8] == true)) {

          etape_croisement++;
        }
        break;



      case 1 :

        coordX--;
        if (go_on) {
          stepX++;


          if ((stepX == 0) && (stepY == 0)) {

            dir = 0;
            dir_on_ligne = dir;
            go_on = false;
            dir_change = 0;
            F_send_command();
          }




          if ((dir_change != 0) && (dir_change != 14)) {

            dir = dir_change;
            dir_on_ligne = dir;
            F_send_command();
          }

          if ((qtr_ok[9] == false) && (qtr_ok[10] == false) && (qtr_ok[11] == false)) {

            on_T_gauche = true;
            coordX = 0;
          }



        }
        else {

          if ((qtr_ok[9] == false) && (qtr_ok[10] == false) && (qtr_ok[11] == false)) {
            coordX = 0;
            on_T_gauche = true;
            dir = 0;
            if ((on_home) && (on_T_ar == false)) {
              dir = 17;
              dir_on_ligne = dir;
            }
            else {
              on_home = false;

            }
            F_send_command();
          }
        }

        etape_croisement++;
        break;






      case 2 :


        if ((qtr_ok[0] == true) || (qtr_ok[8] == true)) {
          etape_croisement++;
        }
        break;

      case 3 :



        if ((qtr_ok[0] == false) && (qtr_ok[8] == false)) {


          if ((dir_change != 0) && (dir_change != 14)) {

            on_croisement = false;
            on_ligneV = true;
          } else {

            on_croisement = false;
            on_ligneH = true;


            on_T_droite = false;
          }
        }
        break;
    }
  }



  ////DROITE
  if (dir == 15) {
    switch (etape_croisement) {


      case 0 :

        if ((qtr_ok[1] == true) || (qtr_ok[7] == true) || (qtr_ok[2] == true) || (qtr_ok[6] == true)) {
          etape_croisement++;
        }
        break;

      case 1 :


        coordX++;

        if (go_on) {
          stepX--;


          if ((stepX == 0) && (stepY == 0)) {

            dir = 0;
            dir_on_ligne = dir;
            go_on = false;
            dir_change = 0;
            F_send_command();
          }





          if ((dir_change != 0) && (dir_change != 15)) {


            dir = dir_change;
            dir_on_ligne = dir;
            F_send_command();
          }

          if ((qtr_ok[3] == false) && (qtr_ok[4] == false) && (qtr_ok[5] == false)) {

            on_T_droite = true;
          }



        }

        else {
          if ((qtr_ok[3] == false) && (qtr_ok[4] == false) && (qtr_ok[5] == false)) {

            on_T_droite = true;

            dir = 0;
            F_send_command();
          }

        }
        etape_croisement++;

        break;



      case 2 :

        if ((qtr_ok[2] == true) || (qtr_ok[6] == true)) {
          etape_croisement++;
        }
        break;

      case 3 :


        if ((qtr_ok[2] == false) && (qtr_ok[6] == false)) {

          if ((dir_change != 0) && (dir_change != 15)) {
            on_croisement = false;
            on_ligneV = true;
          } else {

            on_croisement = false;
            on_ligneH = true;
            on_T_gauche = false;
          }
        }
        break;
    }
  }






  ////AVANT
  if (dir == 12) {
    switch (etape_croisement) {



      case 0 :

        if ((qtr_ok[10] == true) || (qtr_ok[4] == true) || (qtr_ok[9] == true) || (qtr_ok[3] == true)) {
          etape_croisement++;
        }
        break;

      case 1 :
        coordY++;
        if (go_on) {
          stepY--;

          if ((stepX == 0) && (stepY == 0)) {

            dir = 0;
            dir_on_ligne = dir;
            go_on = false;
            dir_change = 0;
            F_send_command();
          }





          if ((dir_change != 0) && (dir_change != 12)) {

            dir = dir_change;
            dir_on_ligne = dir;
            F_send_command();
          }

          if ((qtr_ok[0] == false) && (qtr_ok[1] == false) && (qtr_ok[2] == false)) {

            on_T_av = true;

          }


        }
        else {
          if ((qtr_ok[0] == false) && (qtr_ok[1] == false) && (qtr_ok[2] == false)) {

            on_T_av = true;

            dir = 0;
            F_send_command();
          }
        }
        etape_croisement++;
        break;



      case 2 :

        if ((qtr_ok[9] == true) || (qtr_ok[3] == true)) {
          etape_croisement++;
        }
        break;

      case 3 :





        if ((qtr_ok[9] == false) && (qtr_ok[3] == false)) {



          if ((dir_change != 0) && (dir_change != 12)) {

            on_croisement = false;
            on_ligneH = true;
          } else {

            on_croisement = false;
            on_ligneV = true;
            on_T_ar = false;
          }
        }
        break;
    }
  }














  ////ARRIERE
  if (dir == 17) {
    switch (etape_croisement) {





      case 0 :

        if ((qtr_ok[10] == true) || (qtr_ok[4] == true) || (qtr_ok[5] == true) || (qtr_ok[11] == true)) {
          etape_croisement++;
        }
        break;

      case 1 :
        coordY--;
        if (go_on) {
          stepY++;

          if ((stepX == 0) && (stepY == 0)) {
            dir = 0;
            dir_on_ligne = dir;
            go_on = false;
            dir_change = 0;
            F_send_command();
          }




          if ((dir_change != 0) && (dir_change != 17)) {

            dir = dir_change;
            dir_on_ligne = dir;
            F_send_command();
          }


          if ((qtr_ok[6] == false) && (qtr_ok[7] == false) && (qtr_ok[8] == false)) {
            coordY = 0;
            on_T_ar = true;
          }


        }

        else {
          if ((qtr_ok[6] == false) && (qtr_ok[7] == false) && (qtr_ok[8] == false)) {
            coordY = 0;
            on_T_ar = true;
            dir = 0;
            if ((on_home) && (on_T_gauche == false)) {
              dir = 14;
              dir_on_ligne = dir;
            }
            else {
              on_home = false;
            }


            F_send_command();
          }

        }

        etape_croisement++;

        break;



      case 2 :

        if ((qtr_ok[11] == true) || (qtr_ok[5] == true)) {
          etape_croisement++;
        }
        break;

      case 3 :


        if ((qtr_ok[11] == false) && (qtr_ok[5] == false)) {



          if ((dir_change != 0) && (dir_change != 17)) {
            on_croisement = false;
            on_ligneH = true;
          } else {

            on_croisement = false;
            on_ligneV = true;
            on_T_av = false;
          }
        }
        break;
    }
  }
}
