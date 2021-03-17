void sonar(){
  int change=0;

Sensor_sonar[0]=byte(4);


///SONAR AVANT
// Clears the trigPin
digitalWrite(trigPin_av, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_av, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_av, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_av = pulseIn(echoPin_av, HIGH,30000);
// Calculating the distance
distance_av= duration_av*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_av>255){distance_av=255;}
Sensor_sonar_temp[1]=byte(distance_av);

if ((Sensor_sonar_temp[1]<=limit_sonar)&&(Sensor_sonar[1]!=1)){

Sensor_sonar[1]=1;
change++;

  
}

if ((Sensor_sonar_temp[1]>limit_sonar)&&(Sensor_sonar[1]!=0)){

Sensor_sonar[1]=0;
change++;

  
}



///SONAR ARRIERE
// Clears the trigPin
digitalWrite(trigPin_ar, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_ar, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_ar, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_ar = pulseIn(echoPin_ar, HIGH,30000);
// Calculating the distance
distance_ar= duration_ar*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_ar>255){distance_ar=255;}
Sensor_sonar_temp[3]=byte(distance_ar);

if ((Sensor_sonar_temp[3]<=limit_sonar)&&(Sensor_sonar[3]!=1)){

Sensor_sonar[3]=1;
change++;

  
}

if ((Sensor_sonar_temp[3]>limit_sonar)&&(Sensor_sonar[3]!=0)){

Sensor_sonar[3]=0;
change++;

  
}





///SONAR DROITE
// Clears the trigPin
digitalWrite(trigPin_droite, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_droite, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_droite, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_droite = pulseIn(echoPin_droite, HIGH,30000);
// Calculating the distance
distance_droite= duration_droite*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_droite>255){distance_droite=255;}
Sensor_sonar_temp[2]=byte(distance_droite);


if ((Sensor_sonar_temp[2]<=limit_sonar)&&(Sensor_sonar[2]!=1)){

Sensor_sonar[2]=1;
change++;

  
}

if ((Sensor_sonar_temp[2]>limit_sonar)&&(Sensor_sonar[2]!=0)){

Sensor_sonar[2]=0;
change++;

    
}





///SONAR GAUCHE
// Clears the trigPin
digitalWrite(trigPin_gauche, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_gauche, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_gauche, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_gauche = pulseIn(echoPin_gauche, HIGH,30000);
// Calculating the distance
distance_gauche= duration_gauche*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_gauche>255){distance_gauche=255;}
Sensor_sonar_temp[4]=byte(distance_gauche);

if ((Sensor_sonar_temp[4]<=limit_sonar)&&(Sensor_sonar[4]!=1)){

Sensor_sonar[4]=1;
change++;

  
}

if ((Sensor_sonar_temp[4]>limit_sonar)&&(Sensor_sonar[4]!=0)){

Sensor_sonar[4]=0;
change++;

    
}

if (change>0){
Serial3.write(Sensor_sonar, 13);
}




  
}
