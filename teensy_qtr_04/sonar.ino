void sonar(){


///SONAR AVANT
// Clears the trigPin
digitalWrite(trigPin_av, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_av, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_av, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_av = pulseIn(echoPin_av, HIGH);
// Calculating the distance
distance_av= duration_av*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_av>255){distance_av=255;}
dataSensor[0]=byte(distance_av);



///SONAR ARRIERE
// Clears the trigPin
digitalWrite(trigPin_ar, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_ar, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_ar, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_ar = pulseIn(echoPin_ar, HIGH);
// Calculating the distance
distance_ar= duration_ar*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_ar>255){distance_ar=255;}
dataSensor[2]=byte(distance_ar);


///SONAR DROITE
// Clears the trigPin
digitalWrite(trigPin_droite, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_droite, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_droite, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_droite = pulseIn(echoPin_droite, HIGH);
// Calculating the distance
distance_droite= duration_droite*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_droite>255){distance_droite=255;}
dataSensor[1]=byte(distance_droite);



///SONAR GAUCHE
// Clears the trigPin
digitalWrite(trigPin_gauche, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_gauche, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_gauche, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_gauche = pulseIn(echoPin_gauche, HIGH);
// Calculating the distance
distance_gauche= duration_gauche*0.034/2;
// Prints the distance on the Serial Monitor
if (distance_gauche>255){distance_gauche=255;}
dataSensor[3]=byte(distance_gauche);

  
}
