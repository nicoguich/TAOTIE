void pos_curseur(){
  
 for (int x=0;x<grille_size_x;x++){
   
   for(int y=0;y<grille_size_y;y++){
   
   
   if ((mouseX>(100 + x*(ecartX))-10)&&(mouseX<(100 + x*(ecartX))+10)&&(mouseY>(100 + y*(ecartY))-10)&&(mouseY<(100 + y*(ecartY))+10)){
     
     text((x+1)+"  "+((abs(y-grille_size_y))), 800,900);
   }

   }
  
 }
  
  
  
  
}
