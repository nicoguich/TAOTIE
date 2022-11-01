void afficher_destination(int newX,int newY){
  
  if ((newX!=-1) && (newY!=-1)){
    
    circle(10 + newX*(ecartX),10 + ((grille_size_y-1)-newY)*(ecartY),15);
    
  }
  
  
  
}
