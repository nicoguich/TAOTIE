void F_imprim_sensor() {


  for (int i = 0; i < 12; i++)
  {
    //Serial.print("qtr ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(map(sensorValues[i], 0, 500, 0, 255));
    Serial.print("  ");
  }
  Serial.println();





}
