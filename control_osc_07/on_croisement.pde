
void F_on_croisement() {


  ////GAUCHE
  if (dir.equals("14")) {
    switch(etape_croisement) {




    case 0 :

      if ((qtr_ok[1]==true)||(qtr_ok[7]==true)||(qtr_ok[0]==true)||(qtr_ok[8]==true)) {

        etape_croisement++;
      }
      break;



    case 1 :

    coordX=coordX-1;
      if (go_on) {
        stepX=str(int(stepX)+1);
         cp5.getController("stepX").setLabel("coord "+coordX+"\n step "+micro_stepX);

        if ((stepX.equals("0"))&&(stepY.equals("0"))) {

          dir="0";
          dir_on_ligne=dir;
          go_on=false;
          cp5.getController("GO").setValue(0);
          dir_change=0;
          send_osc();
        }




        if ((dir_change!=0)&&(dir_change!=14)) {

          dir=str(dir_change);
          dir_on_ligne=dir;
          send_osc();
        }
        
              if ((qtr_ok[9]==false)&&(qtr_ok[10]==false)&&(qtr_ok[11]==false)) {

        on_T_gauche=true;
        cp5.getController("T").setValue(1);
        coordX=0;
              }
        
        
        
      }
else{

      if ((qtr_ok[9]==false)&&(qtr_ok[10]==false)&&(qtr_ok[11]==false)) {
        coordX=0;
        on_T_gauche=true;
        cp5.getController("T").setValue(1);
        dir="0";
        if ((on_home)&&(on_T_ar==false)){
          dir="17";
        dir_on_ligne=dir;}
          else{
         on_home=false;
         cp5.getController("home").setValue(0);  
            
          }
        send_osc();
      }
}

      etape_croisement++;
      break;






    case 2 :


      if ((qtr_ok[0]==true)||(qtr_ok[8]==true)) {
        etape_croisement++;
      }
      break;

    case 3 :



      if ((qtr_ok[0]==false)&&(qtr_ok[8]==false)) {


        if ((dir_change!=0)&&(dir_change!=14)) {
          cp5.getController("croisement").setValue(0);
          cp5.getController("ligneV").setValue(1);
          on_croisement=false;
          on_ligneV=true;
        } else {

          on_croisement=false;
          on_ligneH=true;
          cp5.getController("croisement").setValue(0); 
          cp5.getController("ligneH").setValue(1);
          
          on_T_droite=false;
        }
      }
      break;
    }
  }



  ////DROITE
  if (dir.equals("15")) {
    switch(etape_croisement) {


    case 0 :

      if ((qtr_ok[1]==true)||(qtr_ok[7]==true)||(qtr_ok[2]==true)||(qtr_ok[6]==true)) {
        etape_croisement++;
      }
      break;

    case 1 :


      coordX=coordX+1;

      if (go_on) {
        stepX=str(int(stepX)-1);
         cp5.getController("stepX").setLabel("coord "+coordX+"\n step "+micro_stepX);

        if ((stepX.equals("0"))&&(stepY.equals("0"))) {

          dir="0";
          dir_on_ligne=dir;
          go_on=false;
          cp5.getController("GO").setValue(0);
          dir_change=0;
          send_osc();
        }





        if ((dir_change!=0)&&(dir_change!=15)) {


          dir=str(dir_change);
          dir_on_ligne=dir;
          send_osc();
        }
        
              if ((qtr_ok[3]==false)&&(qtr_ok[4]==false)&&(qtr_ok[5]==false)) {

        on_T_droite=true;
        cp5.getController("T").setValue(1);
              }
        
        
        
      }

else{
      if ((qtr_ok[3]==false)&&(qtr_ok[4]==false)&&(qtr_ok[5]==false)) {

        on_T_droite=true;
        cp5.getController("T").setValue(1);
        dir="0";
        send_osc();
      }

}
      etape_croisement++;

      break;



    case 2 :

      if ((qtr_ok[2]==true)||(qtr_ok[6]==true)) {
        etape_croisement++;
      }
      break;

    case 3 :


      if ((qtr_ok[2]==false)&&(qtr_ok[6]==false)) {

        if ((dir_change!=0)&&(dir_change!=15)) {
          cp5.getController("croisement").setValue(0);
          cp5.getController("ligneV").setValue(1);
          on_croisement=false;
          on_ligneV=true;
        } else {

          on_croisement=false;
          on_ligneH=true;
          cp5.getController("croisement").setValue(0); 
          cp5.getController("ligneH").setValue(1);
          
          on_T_gauche=false;
        }
      }
      break;
    }
  }






  ////AVANT
  if (dir.equals("12")) {
    switch(etape_croisement) {



    case 0 :

      if ((qtr_ok[10]==true)||(qtr_ok[4]==true)||(qtr_ok[9]==true)||(qtr_ok[3]==true)) {
        etape_croisement++;
      }
      break;

    case 1 :
coordY=coordY+1;
      if (go_on) {
        stepY=str(int(stepY)-1);
         cp5.getController("stepY").setLabel("coord "+coordY+"\n step "+micro_stepY);


        if ((stepX.equals("0"))&&(stepY.equals("0"))) {

          dir="0";
          dir_on_ligne=dir;
          go_on=false;
          cp5.getController("GO").setValue(0);
          dir_change=0;
          send_osc();
        }





        if ((dir_change!=0)&&(dir_change!=12)) {

          dir=str(dir_change);
          dir_on_ligne=dir;
          send_osc();
        }
        
              if ((qtr_ok[0]==false)&&(qtr_ok[1]==false)&&(qtr_ok[2]==false)) {

        on_T_av=true;
        cp5.getController("T").setValue(1);
        
              }
        
        
      }
else{
      if ((qtr_ok[0]==false)&&(qtr_ok[1]==false)&&(qtr_ok[2]==false)) {

        on_T_av=true;
        cp5.getController("T").setValue(1);
        dir="0";
        send_osc();
      }
}
      etape_croisement++;
      break;



    case 2 :

      if ((qtr_ok[9]==true)||(qtr_ok[3]==true)) {
        etape_croisement++;
      }
      break;

    case 3 :





      if ((qtr_ok[9]==false)&&(qtr_ok[3]==false)) {



        if ((dir_change!=0)&&(dir_change!=12)) {
          cp5.getController("croisement").setValue(0);
          cp5.getController("ligneH").setValue(1);
          on_croisement=false;
          on_ligneH=true;
        } else {

          on_croisement=false;
          on_ligneV=true;
          cp5.getController("croisement").setValue(0); 
          cp5.getController("ligneV").setValue(1);
          
          on_T_ar=false;
        }
      }
      break;
    }
  }














  ////ARRIERE
  if (dir.equals("17")) {
    switch(etape_croisement) {





    case 0 :

      if ((qtr_ok[10]==true)||(qtr_ok[4]==true)||(qtr_ok[5]==true)||(qtr_ok[11]==true)) {
        etape_croisement++;
      }
      break;

    case 1 :
coordY=coordY-1;
      if (go_on) {      
        stepY=str(int(stepY)+1);
         cp5.getController("stepY").setLabel("coord "+coordY+"\n step "+micro_stepY);

        if ((stepX.equals("0"))&&(stepY.equals("0"))) {
          dir="0";
          dir_on_ligne=dir;
          go_on=false;
          cp5.getController("GO").setValue(0);
          dir_change=0;
          send_osc();
        }




        if ((dir_change!=0)&&(dir_change!=17)) {

          dir=str(dir_change);
          dir_on_ligne=dir;
          send_osc();
        }
        
        
              if ((qtr_ok[6]==false)&&(qtr_ok[7]==false)&&(qtr_ok[8]==false)) {
coordY=0;
        on_T_ar=true;
        cp5.getController("T").setValue(1);
              }
        
        
      }

else{
      if ((qtr_ok[6]==false)&&(qtr_ok[7]==false)&&(qtr_ok[8]==false)) {
       coordY=0;
        on_T_ar=true;
        cp5.getController("T").setValue(1);
        dir="0";
              if ((on_home)&&(on_T_gauche==false)){
          dir="14";
        dir_on_ligne=dir;}
          else{
         on_home=false;
         cp5.getController("home").setValue(0);  
            
          }
        
        
        send_osc();
      }

}

      etape_croisement++;

      break;



    case 2 :

      if ((qtr_ok[11]==true)||(qtr_ok[5]==true)) {
        etape_croisement++;
      }
      break;

    case 3 :


      if ((qtr_ok[11]==false)&&(qtr_ok[5]==false)) {



        if ((dir_change!=0)&&(dir_change!=17)) {
          cp5.getController("croisement").setValue(0);
          cp5.getController("ligneH").setValue(1);
          on_croisement=false;
          on_ligneH=true;
        } else {

          on_croisement=false;
          on_ligneV=true;
          cp5.getController("croisement").setValue(0); 
          cp5.getController("ligneV").setValue(1);
          
          on_T_av=false;
        }
      }
      break;
    }
  }
}
