void F_go_on() {
  
  
     


  
  if (on_ligneH==true){
    
   if ((stepX.equals("1"))||(stepX.equals("-1"))){
     
     
     if (int(stepY)>0){
       
       dir_change=12;
       
     }
     if (int(stepY)<0){
       
        dir_change=17;
     }
     
     
   }

  }
  
    if (on_ligneV==true){
    
   if ((stepY.equals("1"))||(stepY.equals("-1"))){
     
     
     if (int(stepX)>0){
       
       dir_change=15;
       
     }
    if (int(stepX)<0){
       
        dir_change=14;
     }
     
     
   }
  }
  
  
  
    
}
