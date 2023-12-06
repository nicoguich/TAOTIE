void afficher_bot(){
  
  rectMode(CENTER);
  fill(200,0,0);
  pushMatrix();
  translate(100 + bot[bot_select][0]*(ecartX),100 + ((grille_size_y-1)-bot[bot_select][1])*(ecartY));
  rotate(PI/4);
rect(0,0, 50,50);
popMatrix();

  fill(200,0,0);

  circle(100 + new_coord_bot[bot_select][0]*(ecartX),100 + ((grille_size_y-1)-new_coord_bot[bot_select][1])*(ecartY),30);
  
}
