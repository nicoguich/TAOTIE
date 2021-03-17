void ligne() {

  qtr.read(sensorValues);
  delay(50);


  int change = 0;
  Sensor_qtr[0] = byte(0);

  for (int x = 0; x < 12; x++) {
    Sensor_qtr_temp[x + 1] = byte(map(sensorValues[x], 0, 500, 0, 255));

    if ((Sensor_qtr_temp[x + 1] >= limit_qtr) && (Sensor_qtr[x + 1] != 1)) {

      Sensor_qtr[x + 1] = 1;
      qtr_ok[x]=true;
      change++;

    }
    else if ((Sensor_qtr_temp[x + 1] < limit_qtr) && (Sensor_qtr[x + 1] != 0)) {

      Sensor_qtr[x + 1] = 0;
      qtr_ok[x]=false;
      change++;

    }


  }


  if (change > 0) {
    Serial3.write(Sensor_qtr, 13);
  }




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
