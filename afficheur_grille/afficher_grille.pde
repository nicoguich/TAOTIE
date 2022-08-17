void afficher_grille(int sizeX,int sizeY){
  
  rect(10,10,width-110,height-110);
  
  float ecartX = (float(width -110))/(sizeX-1);
  float ecartY = (float(height -110))/(sizeY-1);

  
  for(int x = 1; x < sizeX; x++){
    line(10 + x*(ecartX), 10,10 + x*(ecartX),height-100);  
  }
  
  
    for(int y = 1; y < sizeY; y++){
    line(10,10 + y*(ecartY),width-100,10 + y*(ecartY));  
  }
  
  
  
}
