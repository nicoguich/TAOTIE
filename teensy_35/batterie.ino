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

    digitalWrite(led1, HIGH);


  }

}
