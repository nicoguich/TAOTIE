
import controlP5.*;
import oscP5.*;
import netP5.*;
  
OscP5 oscP5;
NetAddress myRemoteLocation;

ControlP5 cp5;


int grille_size_x, grille_size_y;

int nb_table=15;
int table[][] = new int[nb_table][2];

void setup(){
  
  size(800,800);
  
    oscP5 = new OscP5(this,5008);
  
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




void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
}
