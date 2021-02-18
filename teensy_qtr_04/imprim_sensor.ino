void imprim_sensor(){


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






  
}
