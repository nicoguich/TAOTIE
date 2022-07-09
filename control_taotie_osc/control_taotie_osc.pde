/////nicolas guichard 2021
import oscP5.*;
import netP5.*;


OscP5 oscP5;

NetAddress chataigne; 

int grilleX=20;
int grilleY=20;

void setup() {


  size(800, 800);

  oscP5 = new OscP5(this, 9999);

  chataigne = new NetAddress("192.168.100.255", 8888);


}




void draw() {


  dessine_grille();
//  dessine_table();
//  dessine_robot();
}
