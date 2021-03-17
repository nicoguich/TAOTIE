void detection_sonar(){
  
  for (int x=0;x<sonar_value.length;x++){
    
    
    if (sonar_value[x]<seuil_sonar){
      sonar_color[x]=color(255,0,0);}
      else{
        sonar_color[x]=color(0,0,0);}
  }
    
  
  
  
  
}
