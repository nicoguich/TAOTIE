void batterie(){


Sensor_batterie[0]=1;
batterie_value_temp=map(analogRead(batterie_pin),0,1024,0,255);

if (batterie_value_temp!=batterie_value){

batterie_value=batterie_value_temp;
Sensor_batterie[1]=batterie_value;
Serial3.write(Sensor_batterie, 13);
}
//Serial.println(batterie_value);
  
}
