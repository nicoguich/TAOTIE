void detection_qtr() {



  /// repérage de quelque chose
  int detect_sensor=0;

  for (int x=0; x< qtr_value.length; x++) {

    if (qtr_value[x]==1) {
      qtr_color[x]=color(255, 0, 0);
      qtr_ok[x]=true;
      img_sel=img[12];
      detect_sensor++;

      
    capteur_ok=true;
    ligne_ok=false;
    T_ok=false;
    croisement_ok=false;
    coin_ok=false;
    } else {
      qtr_color[x]=color(0, 0, 0);
      qtr_ok[x]=false;
    }
  }


  if (detect_sensor==0) {

    img_sel=img[2];
    capteur_ok=false;
    ligne_ok=false;
    T_ok=false;
    croisement_ok=false;
    coin_ok=false;
  }

/*

  /// repérage ligne avant arriere

  if (((qtr_value[0]==seuil_qtr)||(qtr_value[1]==seuil_qtr)||(qtr_value[2]==seuil_qtr))&&((qtr_value[6]==seuil_qtr)||(qtr_value[7]==seuil_qtr)||(qtr_value[8]==seuil_qtr))) {
    capteur_ok=false;
    ligne_ok=true;
    T_ok=false;
    croisement_ok=false;
    coin_ok=false;
    img_sel=img[1];
    int xmax=0;
    int ymax=0;
    int valueXmax=0;
    int valueYmax=0;

    for (int x=0; x < 3; x++) {
      if (qtr_value[x]==seuil_qtr) {
        if (qtr_value[x]>valueXmax) {
          valueXmax=qtr_value[x];
          xmax=x;
        }
        for (int y =6; y<9; y++) {
          if (qtr_value[y]>seuil_qtr) {
            if (qtr_value[y]>valueYmax) {
              valueYmax=qtr_value[y];
              ymax=y;
            }
          }
        }
      }
    }

    if ((xmax==0)&&(ymax==6)) {
      type_ligne=1;
    }
    if ((xmax==0)&&(ymax==7)) {
      type_ligne=2;
    }
    if ((xmax==0)&&(ymax==8)) {
      type_ligne=3;
    }

    if ((xmax==1)&&(ymax==6)) {
      type_ligne=4;
    }
    if ((xmax==1)&&(ymax==7)) {
      type_ligne=5;
    }
    if ((xmax==1)&&(ymax==8)) {
      type_ligne=6;
    }

    if ((xmax==2)&&(ymax==6)) {
      type_ligne=7;
    }
    if ((xmax==2)&&(ymax==7)) {
      type_ligne=8;
    }
    if ((xmax==2)&&(ymax==8)) {
      type_ligne=9;
    }
  }





  /// repérage ligne gauche droite

  if (((qtr_value[3]>seuil_qtr)||(qtr_value[4]>seuil_qtr)||(qtr_value[5]>seuil_qtr))&&((qtr_value[9]>seuil_qtr)||(qtr_value[10]>seuil_qtr)||(qtr_value[11]>seuil_qtr))) {

    img_sel=img[0];
    capteur_ok=false;
    ligne_ok=true;
    T_ok=false;
    croisement_ok=false;
    coin_ok=false;
    
    int xmax=0;
    int ymax=0;
    int valueXmax=0;
    int valueYmax=0;

    for (int x=3; x < 6; x++) {
      if (qtr_value[x]>seuil_qtr) {
        if (qtr_value[x]>valueXmax) {
          valueXmax=qtr_value[x];
          xmax=x;
        }
        for (int y =9; y<12; y++) {
          if (qtr_value[y]>seuil_qtr) {
            if (qtr_value[y]>valueYmax) {
              valueYmax=qtr_value[y];
              ymax=y;
            }
          }
        }
      }
    }

    if ((xmax==3)&&(ymax==9)) {
      type_ligne=10;
    }
    if ((xmax==3)&&(ymax==10)) {
      type_ligne=11;
    }
    if ((xmax==3)&&(ymax==11)) {
      type_ligne=12;
    }

    if ((xmax==4)&&(ymax==9)) {
      type_ligne=13;
    }
    if ((xmax==4)&&(ymax==10)) {
      type_ligne=14;
    }
    if ((xmax==4)&&(ymax==11)) {
      type_ligne=15;
    }

    if ((xmax==5)&&(ymax==9)) {
      type_ligne=16;
    }
    if ((xmax==5)&&(ymax==10)) {
      type_ligne=17;
    }
    if ((xmax==5)&&(ymax==11)) {
      type_ligne=18;
    } 
    
    
    
    
    
    
  }


  /// repérage croisement


  if ( (qtr_value[1]>seuil_qtr)&&(qtr_value[7]>seuil_qtr)&& (qtr_value[4]>seuil_qtr)&&(qtr_value[10]>seuil_qtr)) {
    capteur_ok=false;
    ligne_ok=false;
    croisement_ok=true;
    T_ok=false;
    coin_ok=false;

    img_sel=img[3];
    
  }


  /// repérage T

  if ((qtr_value[0]>seuil_qtr)&&(qtr_value[1]>seuil_qtr)&&(qtr_value[2]>seuil_qtr)&&(qtr_value[7]>seuil_qtr)) {
    capteur_ok=false;
    ligne_ok=false;
    T_ok=true;
    croisement_ok=false;
    coin_ok=false;
    img_sel=img[6];
    type_T=1;
  }


  if ((qtr_value[6]>seuil_qtr)&&(qtr_value[7]>seuil_qtr)&&(qtr_value[8]>seuil_qtr)&&(qtr_value[1]>seuil_qtr)) {
    capteur_ok=false;
    ligne_ok=false;
    T_ok=true;
    croisement_ok=false;
    coin_ok=false;

    img_sel=img[7];
    type_T=2;
  }


  if ((qtr_value[9]>seuil_qtr)&&(qtr_value[10]>seuil_qtr)&&(qtr_value[11]>seuil_qtr)&&(qtr_value[4]>seuil_qtr)) {
    capteur_ok=false;
    ligne_ok=false;
    T_ok=true;
    croisement_ok=false;
    coin_ok=false;
    img_sel=img[5];
    type_T=3;
  }

  if ((qtr_value[3]>seuil_qtr)&&(qtr_value[4]>seuil_qtr)&&(qtr_value[5]>seuil_qtr)&&(qtr_value[10]>seuil_qtr)) {
    capteur_ok=false;
    ligne_ok=false;
    T_ok=true;
    croisement_ok=false;
    coin_ok=false;
    img_sel=img[4];
    type_T=4;
  }
  */
}
