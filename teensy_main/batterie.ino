void batterie(){

if ( m==0){
  batterie_level=analogRead(batterie_level_pin);
 Serial3.print(2);
 Serial3.println(int(batterie_level));
 batterie_level_temp=batterie_level;
}

  
}
