void afficher_grille(int sizeX,int sizeY){
  rectMode(CORNERS);
  noFill();
  
  rect(100,100,width-100,height-380);
  
  ecartX = (float(width -200))/(sizeX-1);
  ecartY = (float(height -480))/(sizeY-1);

  
  for(int x = 1; x < sizeX; x++){
    line(100 + x*(ecartX), 100,100 + x*(ecartX),height-380);  
  }
  
  
    for(int y = 1; y < sizeY; y++){
    line(100,100 + y*(ecartY),width-100,100 + y*(ecartY));  
  }
  
  
  
}
