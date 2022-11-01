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
void setup(){
  
  size(1920,1200);
  
    oscP5 = new OscP5(this,5009);
    chataigne = new NetAddress("192.168.100.180",5008);
/*  
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
     
     
     */
}




void draw(){
  
  background(255);
  
  afficher_grille(grille_size_x,grille_size_y);
  afficher_table();
  afficher_bot();
  afficher_bouton();
  
  
  
  
  
  
}




void oscEvent(OscMessage theOscMessage) {

  
    if (theOscMessage.checkAddrPattern("/grille")==true) {
     grille_size_x= theOscMessage.get(0).intValue();
     grille_size_y= theOscMessage.get(1).intValue();
      
    }
    
    
        if (theOscMessage.checkAddrPattern("/coord_table")==true) {
          
          for (int x= 0; x< nb_table; x++){
          table[x][0]= theOscMessage.get(x*2).intValue();
          table[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          
        }
        
        
                if (theOscMessage.checkAddrPattern("/coord_bot")==true) {
          
         
          bot[0]= theOscMessage.get(0).intValue();
          bot[1]= theOscMessage.get(1).intValue();
          
          
        }
  
}
