
import controlP5.*;

ControlP5 cp5;


int grille_size_x, grille_size_y;

int nb_table=15;
int table[][] = new int[nb_table][2];

void setup(){
  
  size(800,800);
  
    cp5 = new ControlP5(this);
    cp5.addSlider("grille_size_y")
     .setPosition(width-50,100)
     .setSize(20,200)
     .setRange(0,50)
     .setValue(10)
     .setColorLabel(0)
     .setColorValue(0)
     ;



    cp5.addSlider("grille_size_x")
     .setPosition(100,height-50)
     .setSize(200,20)
     .setRange(0,50)
     .setValue(10)
     .setColorLabel(0)
     .setColorValue(0)
     ;
}




void draw(){
  
  background(255);
  
  afficher_grille(grille_size_x,grille_size_y);
  afficher_table();
//  afficher_bot();
  
  
  
  
  
  
}
