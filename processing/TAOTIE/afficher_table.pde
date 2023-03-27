void afficher_table(){
  rectMode(CENTER);
            for (int x= 0; x< nb_table; x++){
              
              if ((table[x][0]!=0) ||(table[x][1]!=0)){
                fill(100);
              rect(100 + table[x][0]*(ecartX),100 + ((grille_size_y-1)-table[x][1])*(ecartY), 100,100);
              }

          }
  
  
  
  
  
  
}
