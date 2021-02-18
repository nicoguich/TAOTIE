
void F_alignement() {



  ///robot perdu
  if (perdu_temp==false) {
    speed=speed_perdu;
    dir="12";

    perdu_temp=true;
  }



  ////detection 1 capteur
  if (capteur_ok) {
    speed=speed_perdu;

    switch (etape_perdu) {

    case 0 :

      if (qtr_ok[5]==true) {
        perdu_temp=false;           
        dir="19";

        rotate=19;
      }

      if (qtr_ok[11]==true) {
        perdu_temp=false;
        dir="20";

        rotate=20;
      }


      if (qtr_ok[3]==true) {
        perdu_temp=false;           
        dir="19";

        rotate=19;
        etape_perdu++;
      }

      if (qtr_ok[9]==true) {
        perdu_temp=false;
        dir="20";

        rotate=20;
        etape_perdu++;
      }

      break;

    case 1 :

      if ((qtr_ok[3]==true)||(qtr_ok[11]==true)) {
        perdu_temp=false;           
        dir="19";

        rotate=19;
      }

      if ((qtr_ok[9]==true)||(qtr_ok[5]==true)) {
        perdu_temp=false;
        dir="20";

        rotate=20;
      }




      break;
    }
  }




  ////detection ligne



  


   if(( qtr_ok[11]==true)&&(qtr_ok[5]==true)) {

     perdu_temp=false;
  speed=cp5.getController("speed").getStringValue();
      dir="0.0";
      send_osc();
      delay(100);
      dir="2.0";
      step="15";
      send_osc();
      delay(1000);
      dir="0.0";
      step="0";
      alignement=false;
      on_ligneH=true;
      type_ligne_temp=18;
      cp5.getController("lost").setValue(0); 
      cp5.getController("ligneH").setValue(1); 
      dir_temp="0";
      
 


   }












   if(( qtr_ok[9]==true)&&(qtr_ok[3]==true)) {
       speed=cp5.getController("speed").getStringValue();

      dir="0.0";
      send_osc();
      delay(100);
      dir="7.0";
      step="15";
      send_osc();
      delay(1000);
      dir="0.0";
      step="0";
      alignement=false;
      on_ligneH=true;
      type_ligne_temp=18;
      cp5.getController("lost").setValue(0); 
      cp5.getController("ligneH").setValue(1); 
      dir_temp="0";
      




    }
  
          if (dir!=dir_temp) {
    dir_temp=dir;
    envoi=true;
  }

}
