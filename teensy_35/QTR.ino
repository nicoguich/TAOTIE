void F_qtr() {

  qtr.read(sensorValues);

  int change = 0;
  Sensor_qtr[0] = byte(100);
  capteur_ok = false;
  for (int x = 0; x < 12; x++) {
    Sensor_qtr_temp[x + 1] = byte(map(sensorValues[x], 0, 500, 0, 255));

    if ((Sensor_qtr_temp[x + 1] >= limit_qtr) && (Sensor_qtr[x + 1] != 1)) {

      Sensor_qtr[x + 1] = 1;
      qtr_ok[x] = true;
      capteur_ok = true;
      change++;

    }
    else if ((Sensor_qtr_temp[x + 1] < limit_qtr) && (Sensor_qtr[x + 1] != 0)) {

      Sensor_qtr[x + 1] = 0;
      qtr_ok[x] = false;
      change++;

    }


  }


  if ((change > 0) && (int(show_qtr) == 1)) {

    Serial3.write(Sensor_qtr, 13);
  }

}
