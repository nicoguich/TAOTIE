void imprim_sensor(){


 for (uint8_t i = 0; i <12; i++)
    {
      Serial.print("qtr ");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(map(sensorValues[i],0,500,0,255));
      Serial.print("  ");
    }
    Serial.println();
  /*  for (uint8_t i = 0; i < 3; i++)
    {
      Serial.print("ar:");
      Serial.print(sensorValues_ar[i]);
      Serial.print('\t');
    }

    Serial.println();
    for (uint8_t i = 0; i < 3; i++)
    {
      Serial.print("gauche:");
      Serial.print(sensorValues_gauche[i]);
      Serial.print('\t');
    }
    Serial.println();
    for (uint8_t i = 0; i < 3; i++)
    {
      Serial.print("droite:");
      Serial.print(sensorValues_droite[i]);
      Serial.print('\t');
    }

    Serial.println();

*/




  
}
