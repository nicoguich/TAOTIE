
void F_alignement() {


if (on_ligneH==false){
  ///robot perdu
  if (perdu_temp == false) {
    speed = speed_perdu;
    dir = 17;

    perdu_temp = true;
  }



  ////detection 1 capteur



        if ((qtr_ok[4] == true)&&(qtr_ok[10] == false)) {
          perdu_temp = false;
          dir = 20;
        }

        if ((qtr_ok[10] == true)&&(qtr_ok[4] == false)) {
          perdu_temp = false;
          dir = 19;
        }




  ////detection ligne






  if (( qtr_ok[9] == true) && (qtr_ok[3] == true)) {

    perdu_temp = false;
    speed = speed_perdu;
    dir = 17;
     F_send_command();


  }

  

  if (( qtr_ok[11] == true) && (qtr_ok[5] == true)) {
    perdu_temp = false;
    speed = speed_perdu;
    dir = 12;
     F_send_command();


  }



  if (( qtr_ok[4] == true) && (qtr_ok[10] == true)) {
    speed = speed_perdu;

    dir = 14;
    step = 0;
    F_send_command();
    //alignement = false;
    on_ligneH = true;
    on_ligneH_temp=false;
    dir_temp = 14;
  
  }

}
else{

dir=14;

  /// gauche droite
  if ((dir == 14) || (dir == 15)) {


      if ((qtr_ok[3] == true) ) {
        speed = speed_perdu;
        dir = 19;
      }

      if ((qtr_ok[9] == true)&&(qtr_ok[11] == false)) {
        speed = speed_perdu;
        dir = 20;

      }


      if ((qtr_ok[3] == true) && (qtr_ok[9] == true)) {

        speed = speed_perdu;
        dir = 17;

      }


      if ((qtr_ok[11] == true)&&(qtr_ok[9] == false))  {
        speed = speed_perdu;
        dir = 19;
      }

      if(qtr_ok[5] == true) {
        speed = speed_perdu;
        dir = 20;
      }


      if ((qtr_ok[11] == true) && (qtr_ok[5] == true)) {
        speed = speed_perdu;
        dir = 12;

      }


  if ((qtr_ok[1] == true) && (qtr_ok[7] == true)) {


step=0;
dir = 0;
F_send_command();
on_ligneH = false;
alignement = false;

if (play_sd==1){

if( (qtr_ok[1]==true)&&(qtr_ok[7]==true)){


boucle=1;
  
    
  if (SD.exists("test.txt")){
    
  myFile = SD.open("test.txt");
  
  compteur_data=0;
  int compteur_nombre=0;
    int data_temp=0;
    int compteur_calcul=0;
    int lecture_nombre;
    lecture_ok=false;
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


    for (int x=0;x<compteur_data;x++){
if (x%3==0){

  Serial.print("step:");
}
else if (x%3==1){

  Serial.print("dir:");
}
else if (x%3==2){

  Serial.print("speed:");
}
Serial.println(data_sd[x]);
      
    }


     
  }

compteur_sd=0;

 lecture_ok=false;

}
      
    }




    
  }

      
    
  }



  
}




  if (dir != dir_temp) {
    dir_temp = dir;
    envoi = true;
  }

}






///////////////
