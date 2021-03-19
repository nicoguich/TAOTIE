void F_hors_grille(){

  digitalWrite(led2,HIGH);
byte fin_mvt=0;



if (dest_stepX>0){

dir=5;
step=dest_stepX;
F_send_command();

  

  while (fin_mvt!=123){
  if (Serial2.available() > 0) {
    Serial2.readBytes(coord_in, 1); //RECEIVE fin_mvt FROM teensy3.2 and send to OSC 8266
   
    fin_mvt = int(coord_in[0]);

  }
  }
  fin_mvt=0; 
  stepX_hors_grille=dest_stepX;
}




if (dest_stepY>0){

dir=2;
step=dest_stepY;
F_send_command();

  

  while (fin_mvt!=123){
  if (Serial2.available() > 0) {
    Serial2.readBytes(coord_in, 1); //RECEIVE fin_mvt FROM teensy3.2 and send to OSC 8266
   
    fin_mvt = int(coord_in[0]);

  }
  }
   fin_mvt=0;  
    stepY_hors_grille=dest_stepY;
}


  digitalWrite(led2,LOW);

}
