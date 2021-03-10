void ligne(){
  
dataSensor[4]=byte(map(sensorValues[0],0,500,0,255));
dataSensor[5]=byte(map(sensorValues[1],0,500,0,255));
dataSensor[6]=byte(map(sensorValues[2],0,500,0,255));

dataSensor[7]=byte(map(sensorValues[3],0,500,0,255));
dataSensor[8]=byte(map(sensorValues[4],0,500,0,255));
dataSensor[9]=byte(map(sensorValues[5],0,500,0,255));

dataSensor[10]=byte(map(sensorValues[6],0,500,0,255));
dataSensor[11]=byte(map(sensorValues[7],0,500,0,255));
dataSensor[12]=byte(map(sensorValues[8],0,500,0,255));

dataSensor[13]=byte(map(sensorValues[9],0,500,0,255));
dataSensor[14]=byte(map(sensorValues[10],0,500,0,255));
dataSensor[15]=byte(map(sensorValues[11],0,500,0,255));

/*
  if (print_sensor == true) {
    for (uint8_t i = 0; i < 3; i++)
    {
      Serial.print("av:");
      Serial.print(sensorValues_av[i]);
      Serial.print('\t');
    }
    Serial.println();
    for (uint8_t i = 0; i < 3; i++)
    {
      Serial.print("ar:");
      Serial.print(sensorValues_ar[i]);
      Serial.print('\t');
    }

    Serial.println();
    for (uint8_t i = 0; i < 4; i++)
    {
      Serial.print("gauche:");
      Serial.print(sensorValues_gauche[i]);
      Serial.print('\t');
    }
    Serial.println();
    for (uint8_t i = 0; i < 4; i++)
    {
      Serial.print("droite:");
      Serial.print(sensorValues_droite[i]);
      Serial.print('\t');
    }

    Serial.println();

  }








  //////////AVANT



  ////pas de ligne
  if ((sensorValues_av[0] < 400) && (sensorValues_av[1] < 400) && (sensorValues_av[2] < 400) ) {
    if (ligne_av == 1) {
      data[1] = 48;
    }
    ligne_av = 0;
  }
  else if ((sensorValues_av[0] > 800) || (sensorValues_av[1] > 800) || (sensorValues_av[2] > 800)) {
    if (coin_av == 0) {
      ligne_av = 1;
    }
  }




  ////perpendiculaire
  if ((sensorValues_av[0] > 800) && (sensorValues_av[1] > 800) && (sensorValues_av[2] > 800) ) {

    if (croisement_av == 0)  {

      if (croisement_av == 0) {
        data[1] = 65;
      }
      croisement_av = 1;
    }
  }
  else {
    croisement_av = 0;

  }


  ///////coin
  if ((sensorValues_av[0] > 800) && (sensorValues_av[2] > 800) && (sensorValues_av[1] < 400)) {

    if (coin_av == 0) {
      data[1] = 67;
    }
    coin_av = 1;


  }
  else {
    coin_av = 0;
  }




  if ((coin_av == 0) && (croisement_av == 0) && (ligne_av == 1)) {

    data[1] = getMax(sensorValues_av, 3) + 49;

    tempvalue_av = getMax(sensorValues_av, 3);

  }





  ///////////////ARRIERE////



  ////pas de ligne
  if ((sensorValues_ar[0] < 50) && (sensorValues_ar[1] < 50) && (sensorValues_ar[2] < 50)) {
    if (ligne_ar == 1) {
      data[2] = 48;
    }
    ligne_ar = 0;
  }
  else if ((sensorValues_ar[0] > 400) || (sensorValues_ar[1] > 400) || (sensorValues_ar[2] > 400)) {
    if (coin_ar == 0) {
      ligne_ar = 1;
    }
  }




  ////perpendiculaire
  if ((sensorValues_ar[0] > 400) && (sensorValues_ar[1] > 400) && (sensorValues_ar[2] > 400) ) {

    if (croisement_ar == 0) {
      data[2] = 65;
    }
    croisement_ar = 1;
  }
  else {
    croisement_ar = 0;
  }



  ///////coin
  if ((sensorValues_ar[0] > 400) && (sensorValues_ar[2] > 400) && (sensorValues_ar[1] < 50)) {

    if (coin_ar == 0) {
      data[2] = 67;
    }
    coin_ar = 1;


  }
  else {
    coin_ar = 0;
  }




  if ((coin_ar == 0) && (croisement_ar == 0) && (ligne_ar == 1)) {

    data[2] = getMax(sensorValues_ar, 3) + 49;

    tempvalue_ar = getMax(sensorValues_ar, 3);

  }







  //////////GAUCHE



  ////pas de ligne
  if ((sensorValues_gauche[0] < 500) && (sensorValues_gauche[1] < 500) && (sensorValues_gauche[2] < 500) && (sensorValues_gauche[3] < 500)) {
    if (ligne_gauche == 1) {
      data[3] = 48;
    }
    ligne_gauche = 0;
  }
  else if ((sensorValues_gauche[0] > 800) || (sensorValues_gauche[1] > 800) || (sensorValues_gauche[2] > 800) || (sensorValues_gauche[3] > 800))  {
    if (coin_gauche == 0) {
      ligne_gauche = 1;
    }
  }




  ////perpendiculaire
  if ((sensorValues_gauche[0] > 800) && (sensorValues_gauche[1] > 800) && (sensorValues_gauche[2] > 800) && (sensorValues_gauche[3] > 800)) {

    if (croisement_gauche == 0)  {

      if (croisement_gauche == 0) {
        data[3] = 65;
      }
      croisement_gauche = 1;
    }
  }
  else {
    croisement_gauche = 0;

  }


  ///////coin
  if ((sensorValues_gauche[0] > 800) && (sensorValues_gauche[3] > 800) && (sensorValues_gauche[1] < 500)) {

    if (coin_gauche == 0) {
      data[3] = 67;
    }
    coin_gauche = 1;


  }

  else {
    coin_gauche = 0;
  }




  if ((coin_gauche == 0) && (croisement_gauche == 0) && (ligne_gauche == 1)) {

    data[3] = getMax(sensorValues_gauche, 4) + 49;

    tempvalue_gauche = getMax(sensorValues_gauche, 4);

  }





  ///////////////DROITE////

  ////pas de ligne
  if ((sensorValues_droite[0] < 200) && (sensorValues_droite[1] < 200) && (sensorValues_droite[2] < 200) && (sensorValues_droite[3] < 200)) {
    if (ligne_droite == 1) {
      data[4] = 48;
    }
    ligne_droite = 0;
  }
  else if ((sensorValues_droite[0] > 300) || (sensorValues_droite[1] > 300) || (sensorValues_droite[2] > 300) || (sensorValues_droite[3] > 300)) {
    if (coin_droite == 0) {
      ligne_droite = 1;
    }
  }




  ////perpendiculaire
  if ((sensorValues_droite[0] > 300) && (sensorValues_droite[1] > 300) && (sensorValues_droite[2] > 300) && (sensorValues_droite[3] > 300)) {

    if (croisement_droite == 0)  {

      if (croisement_droite == 0) {
        data[4] = 65;
      }
      croisement_droite = 1;
    }
  }
  else {
    croisement_droite = 0;

  }


  ///////coin
  if ((sensorValues_droite[0] > 300) && (sensorValues_droite[3] > 300) && (sensorValues_droite[1] < 200)) {

    if (coin_droite == 0) {
      data[4] = 67;
    }
    coin_droite = 1;


  }

  else {
    coin_droite = 0;
  }




  if ((coin_droite == 0) && (croisement_droite == 0) && (ligne_droite == 1)) {

    data[4] = getMax(sensorValues_droite, 4) + 49;

    tempvalue_droite = getMax(sensorValues_droite, 4);

  }

  */
}









int getMax(int* array, int size)
{
  int index = 0;
  int minimum = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] > minimum) {
      minimum = array[i];
      index = i;
    }

  }
  return index;
}
