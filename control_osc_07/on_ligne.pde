void F_on_ligne() {


  /// gauche droite
  if ((dir.equals("14"))||(dir.equals("15"))) {

    if (dir.equals("14")) {

      if ((qtr_ok[2]==true)||(qtr_ok[6]==true)) {
        on_ligneH=false;
        on_croisement=true;
        cp5.getController("croisement").setValue(1); 
        cp5.getController("ligneH").setValue(0); 
        etape_croisement=0;
      }
    }


    if (dir.equals("15")) {

      if ((qtr_ok[0]==true)||(qtr_ok[8]==true)) {
        on_ligneH=false;
        on_croisement=true;
        cp5.getController("croisement").setValue(1); 
        cp5.getController("ligneH").setValue(0); 
        etape_croisement=0;
      }
    }



    if (on_croisement==false) {

      if ((qtr_ok[3]==true)&&(qtr_ok[9]==false)&&(qtr_ok[4]==false)) {
      speed=speed_perdu;
        dir="19";
      } 

      if ((qtr_ok[3]==false)&&(qtr_ok[9]==true)&&(qtr_ok[10]==false)) {
      speed=speed_perdu;
        dir="20";
        
      } 


      if ((qtr_ok[3]==true)&&(qtr_ok[9]==true)&&(qtr_ok[4]==false)&&(qtr_ok[10]==false)) {
        String dir_temp=dir;
speed=speed_perdu;
        dir="7";
        step="5";
                send_osc();
        delay(200);
        dir=dir_temp;
                step="0";
        send_osc();
      } 


      if ((qtr_ok[11]==true)&&(qtr_ok[5]==false)&&(qtr_ok[10]==false)) {
speed=speed_perdu;
        dir="19";
      } 

      if ((qtr_ok[11]==false)&&(qtr_ok[5]==true)&&(qtr_ok[4]==false)) {
speed=speed_perdu;
        dir="20";
      } 


      if ((qtr_ok[11]==true)&&(qtr_ok[5]==true)&&(qtr_ok[4]==false)&&(qtr_ok[10]==false)) {
        String dir_temp=dir;
speed=speed_perdu;
        dir="2";
        step="5";
                send_osc();
        delay(200);
        dir=dir_temp;
                step="0";
        send_osc();
      }
    }
  }




  /// avant arrière
  if ((dir.equals("12"))||(dir.equals("17"))) {

    if (dir.equals("12")) {

      if ((qtr_ok[11]==true)||(qtr_ok[5]==true)) {
        on_ligneV=false;
        on_croisement=true;
        cp5.getController("croisement").setValue(1); 
        cp5.getController("ligneV").setValue(0); 
        etape_croisement=0;
      }
    }


    if (dir.equals("17")) {

      if ((qtr_ok[9]==true)||(qtr_ok[3]==true)) {
        on_ligneV=false;
        on_croisement=true;
        cp5.getController("croisement").setValue(1); 
        cp5.getController("ligneV").setValue(0); 
        etape_croisement=0;
      }
    }



    if (on_croisement==false) {

      if ((qtr_ok[2]==true)&&(qtr_ok[6]==false)&&(qtr_ok[1]==false)) {
speed=speed_perdu;
        dir="20";
      } 

      if ((qtr_ok[2]==false)&&(qtr_ok[6]==true)&&(qtr_ok[7]==false)) {
speed=speed_perdu;
        dir="19";
      } 


      if ((qtr_ok[2]==true)&&(qtr_ok[6]==true)&&(qtr_ok[7]==false)&&(qtr_ok[1]==false)) {
        String dir_temp=dir;
speed=speed_perdu;
        dir="4";
        step="5";
                send_osc();
        delay(200);
        step="0";
        dir=dir_temp;
        send_osc();
      } 


      if ((qtr_ok[0]==true)&&(qtr_ok[8]==false)&&(qtr_ok[1]==false)) {
speed=speed_perdu;
        dir="19";
      } 

      if ((qtr_ok[0]==false)&&(qtr_ok[8]==true)&&(qtr_ok[7]==false)) {
speed=speed_perdu;
        dir="20";
      } 


      if ((qtr_ok[0]==true)&&(qtr_ok[8]==true)&&(qtr_ok[7]==false)&&(qtr_ok[1]==false)) {
        String dir_temp=dir;
speed=speed_perdu;
        dir="5";
        step="5";
                send_osc();
        delay(200);
        
        dir=dir_temp;
        step="0";
        send_osc();
      }
    }
  }






  if (dir!=dir_temp) {
    dir_temp=dir;
    envoi=true;
  } else {
    dir=dir_on_ligne;
    speed=cp5.getController("speed").getStringValue();
  }
}
