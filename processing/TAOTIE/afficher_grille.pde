void afficher_grille(int sizeX,int sizeY){
  rectMode(CORNERS);
  noFill();
    stroke(0); 
  rect(width*0.05,height*0.08,width-(width*0.05),height-(height*0.3));
  
  if (bot_select!=0){
 
  ecartX = (width -((width*0.05)*2))/(sizeX-1);
  ecartY = (height -((height*0.3)+(height*0.08)))/(sizeY-1);

  
  for(int x = 1; x < sizeX; x++){
    line((width*0.05) + x*(ecartX), height*0.08,(width*0.05) + x*(ecartX),height-(height*0.3));  
  }
  
  
    for(int y = 1; y < sizeY; y++){
    line((width*0.05),(height*0.08) + y*(ecartY),width-(width*0.05),(height*0.08) + y*(ecartY));  
  }
  
  
  
  
  noStroke();
    fill(255);
  rectMode(CORNER);
  rect((pos_interdite[bot_select][0]*ecartX)+(width*0.05)+1,((grille_size_y-1)-pos_interdite[bot_select][1])*(ecartY)+(height*0.08)+1,((pos_interdite[bot_select][2]*ecartX)+(width*0.05))-((pos_interdite[bot_select][0]*ecartX)+(width*0.05))-2,((grille_size_y-1)-pos_interdite[bot_select][3])*(ecartY)-((grille_size_y-1)-pos_interdite[bot_select][1])*(ecartY));
  
  }
}
