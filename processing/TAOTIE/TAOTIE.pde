import controlP5.*;
import oscP5.*;
import netP5.*;
  
OscP5 oscP5;
NetAddress chataigne;

ControlP5 cp5;


int grille_size_x, grille_size_y;

float ecartX, ecartY;

int nb_table=15;
int table[][] = new int[nb_table][2];
int bot[] = new int[2];
int home=0,stop=0;
int main=0,camera=0,serial=0,wifi=0;

int page=1;
int checkpage=0;
int reset=0;

int avance=0,recul=0,droite=0,gauche=0,checkzero=0;;



void setup(){
  
  size(1920,1200);
  
    oscP5 = new OscP5(this,5009);
    chataigne = new NetAddress("192.168.100.255",5008);

}




void draw(){
  
  background(255);
  
  
  afficher_bouton();
  
  if (page==1){
  afficher_grille(grille_size_x,grille_size_y);
  afficher_table();
  afficher_bot();
  
  message();
  }
    
  
}




void oscEvent(OscMessage theOscMessage) {

  /////GRILLE
    if (theOscMessage.checkAddrPattern("/grille")==true) {
     grille_size_x= theOscMessage.get(0).intValue();
     grille_size_y= theOscMessage.get(1).intValue();
    }
    
    /////TABLE
        if (theOscMessage.checkAddrPattern("/coord_table")==true) {
          for (int x= 0; x< nb_table; x++){
          table[x][0]= theOscMessage.get(x*2).intValue();
          table[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          
        }
        
     //////BOT   
          if (theOscMessage.checkAddrPattern("/coord_bot")==true) {
          bot[0]= theOscMessage.get(0).intValue();
          bot[1]= theOscMessage.get(1).intValue();
        }
        
     ///////MESSAGE
     
     if (theOscMessage.checkAddrPattern("/main")==true) {
       main= theOscMessage.get(0).intValue();}
            if (theOscMessage.checkAddrPattern("/camera")==true) {
       camera= theOscMessage.get(0).intValue();}
            if (theOscMessage.checkAddrPattern("/serial")==true) {
       serial= theOscMessage.get(0).intValue();}

            if (theOscMessage.checkAddrPattern("/wifi")==true) {
      wifi= theOscMessage.get(0).intValue();}
       
      
  
}
