void afficher_grille(int sizeX,int sizeY){
  
  rect(10,10,width-20,height-150);
  
  ecartX = (float(width -20))/(sizeX-1);
  ecartY = (float(height -150))/(sizeY-1);

  
  for(int x = 1; x < sizeX; x++){
    line(10 + x*(ecartX), 10,10 + x*(ecartX),height-140);  
  }
  
  
    for(int y = 1; y < sizeY; y++){
    line(10,10 + y*(ecartY),width-10,10 + y*(ecartY));  
  }
  
  
  
}
