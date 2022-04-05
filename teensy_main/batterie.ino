void batterie(){


  batterie_level=analogRead(batterie_level_pin);
 
  
 if(batterie_level!=batterie_level_temp){
  batterie_level_temp=batterie_level;
  batterie_level=map(batterie_level,750,990,10,1024);
 //Serial3.print(2);
 //Serial3.println(int(batterie_level));
 
 }

  
}
