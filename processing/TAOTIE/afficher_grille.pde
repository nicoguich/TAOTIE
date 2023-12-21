void afficher_grille(int sizeX,int sizeY){
  rectMode(CORNERS);
  noFill();
    stroke(0); 
  rect(100,100,width-100,height-380);
  
  if (bot_select!=0){
 
  ecartX = (float(width -200))/(sizeX-1);
  ecartY = (float(height -480))/(sizeY-1);

  
  for(int x = 1; x < sizeX; x++){
    line(100 + x*(ecartX), 100,100 + x*(ecartX),height-380);  
  }
  
  
    for(int y = 1; y < sizeY; y++){
    line(100,100 + y*(ecartY),width-100,100 + y*(ecartY));  
  }
  
  
  
  
  noStroke();
    fill(255);
  rectMode(CORNER);
  rect((pos_interdite[bot_select][0]*ecartX)+101,((grille_size_y-1)-pos_interdite[bot_select][1])*(ecartY)+101,((pos_interdite[bot_select][2]*ecartX)+100)-((pos_interdite[bot_select][0]*ecartX)+100)-2,((grille_size_y-1)-pos_interdite[bot_select][3])*(ecartY)-((grille_size_y-1)-pos_interdite[bot_select][1])*(ecartY));
  
  }
}
