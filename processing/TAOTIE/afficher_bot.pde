void afficher_bot(){
  
  rectMode(CENTER);
  fill(200,0,0);
  pushMatrix();
  translate(10 + bot[0]*(ecartX),10 + ((grille_size_y-1)-bot[1])*(ecartY));
  rotate(PI/4);
rect(0,0, 100,100);
popMatrix();
  
  
}
