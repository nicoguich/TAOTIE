void F_batterie() {


  Sensor_batterie[0] = byte(101);
  batterie_value_temp = map(analogRead(batterie_pin), 0, 1024, 0, 255);
  //   Serial.println(analogRead(batterie_pin));

  if (batterie_value_temp != batterie_value) {

    batterie_value = batterie_value_temp;
    Sensor_batterie[1] = batterie_value;
    if (int(show_bat) == 1) {
      Serial3.write(Sensor_batterie, 13);
    }
  }


  if (batterie_value < limit_batterie) {
    low_batterie=1;
    batterie_ok=0;

    digitalWrite(led4, HIGH);


  }
  else{
    low_batterie=0;
 digitalWrite(led4, LOW);
    
  }

/*
if ((batterie_value>230)&&(batterie_ok==0)){

  batterie_ok=1;
  en_charge=0;


  if (SD.exists("retour.txt")){
    
  myFile = SD.open("retour.txt");
  
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
*/

  

}
