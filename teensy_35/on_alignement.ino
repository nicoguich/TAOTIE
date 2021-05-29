
void F_alignement() {




  ////detection 1 capteur


if (etape_perdu==0){

        speed = speed_perdu;
    dir = 17;
        if ((qtr_ok[4] == true)&&(qtr_ok[10] == false)) {
        
          dir = 20;
        }

        if ((qtr_ok[10] == true)&&(qtr_ok[4] == false)) {
        
          dir = 19;
        }



         if (( qtr_ok[4] == true) && (qtr_ok[10] == true)&& (qtr_ok[11] == false)&& (qtr_ok[5] == false)&& (qtr_ok[9] == false)&& (qtr_ok[3] == false)) {
       
        etape_perdu=1;
        dir=14;
         }



    
}





  ////detection ligne


if (etape_perdu==1){

 speed = speed_perdu;
dir=14;



         if ((qtr_ok[11] == true)) {
        
          dir = 19;
        }

        
         if ((qtr_ok[9] == true)) {
        
          dir = 20;
        }

    
 

        if ((qtr_ok[3] == true)&&(qtr_ok[9] == true)){

dir=17;

          
        }

                if ((qtr_ok[11] == true)&&(qtr_ok[5] == true)){

dir=12;

          
        }
        



        if ((qtr_ok[1] == true)&&(qtr_ok[7] == true)) {
        
          dir = 14;
          etape_perdu=2;
        }

  




}






  



if (etape_perdu==2){

 speed = speed_perdu;
dir=14;



step=0;
dir = 0;
F_send_command();
on_ligneH = false;
alignement = false;


if (play_sd==6){

int roulette=0;

  
while(roulette==0){
int play_sd_temp=int(random(1,6));
if (play_sd_temp==1){

  if (SD.exists("un.txt")){
  myFile = SD.open("un.txt");
  roulette=1;
  }
}

if (play_sd_temp==2){

  if (SD.exists("deux.txt")){
  myFile = SD.open("deux.txt");
  roulette=1;
  }
}

if (play_sd_temp==3){

  if (SD.exists("trois.txt")){
  myFile = SD.open("trois.txt");
  roulette=1;
  }
}


if (play_sd_temp==4){

  if (SD.exists("quatre.txt")){
  myFile = SD.open("quatre.txt");
  roulette=1;
  }
}


if (play_sd_temp==5){

  if (SD.exists("cinq.txt")){
  myFile = SD.open("cinq.txt");
  roulette=1;
  }
}
}
}


if (play_sd==1){

  if (SD.exists("un.txt")){
  myFile = SD.open("un.txt");
  }
}

if (play_sd==2){

  if (SD.exists("deux.txt")){
  myFile = SD.open("deux.txt");
  }
}

if (play_sd==3){

  if (SD.exists("trois.txt")){
  myFile = SD.open("trois.txt");
  }
}


if (play_sd==4){

  if (SD.exists("quatre.txt")){
  myFile = SD.open("quatre.txt");
  }
}


if (play_sd==5){

  if (SD.exists("cinq.txt")){
  myFile = SD.open("cinq.txt");
  }
}





if (play_sd==10){

  if (SD.exists("chargeur.txt")){
    
  myFile = SD.open("chargeur.txt");
  }
}


  
  
  boucle=1;
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

compteur_sd=0;

lecture_ok=false;

}
      


  if (dir != dir_temp) {
    dir_temp = dir;
    envoi = true;
  }

}






///////////////
