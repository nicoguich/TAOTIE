import controlP5.*;
import oscP5.*;
import netP5.*;
  
OscP5 tablette;
String ip_null;
NetAddress chataigne;
NetAddress router;
ControlP5 cp5;


int grille_size_x = 10, grille_size_y=8;

boolean anim_led=false;

float ecartX, ecartY;
int nb_bot_max=10;
int nb_bot=0;
int bot_select=0;

int grille_size[][]=new int [nb_bot_max][3];


int nb_table=20;
int table[][] = new int[nb_table][2];
int table_1[][] = new int[nb_table][2];
int table_2[][] = new int[nb_table][2];
int table_3[][] = new int[nb_table][2];
int table_4[][] = new int[nb_table][2];
int table_5[][] = new int[nb_table][2];
int table_6[][] = new int[nb_table][2];
int table_7[][] = new int[nb_table][2];
int table_8[][] = new int[nb_table][2];
int table_9[][] = new int[nb_table][2];
int table_10[][] = new int[nb_table][2];
int pos_interdite[][] = new int[nb_bot_max][4];


int bot[][] = new int[nb_bot_max][2];
String bot_ip[]= new String[nb_bot_max];
int new_coord[] = new int[2];
int new_coord_bot[][]= new int [nb_bot_max][2];
int home=0,stop=0, play_led=0,stop_led=0,save=0;
int main=0,camera=0,serial=0,wifi=0;

int page=1;
int checkpage=0;
int reset=0;

int avance=0,recul=0,droite=0,gauche=0,checkzero=0;;

int xmoins=0,xplus=0,ymoins=0,yplus=0,tablemoins=0,tableplus=0,led_on=0,led_off=0,verin_down=0,verin_up=0;
int coordrectX_left,coordrectX_right,coordrectY_up,coordrectY_down,coordrectX_left_temp,coordrectY_up_temp,dragged=0;
int [] pos_interditeX=new int [2];
int [] pos_interditeY=new int [2];
int pos_interditeX_temp,pos_interditeY_temp;


void setup(){
  
  size(1920,1200);
  
    tablette = new OscP5(this,5009);
    ip_null = ("-1");
    chataigne = new NetAddress("192.168.4.190",5008);
    router = new NetAddress("192.168.100.15",5010);
   for (int x=0; x< bot_ip.length;x++){
     bot_ip[x]=ip_null;
   }
   

}




void draw(){
  
  background(255);
 
  

  
  
  afficher_bouton();
      grille_size_x= grille_size[bot_select][0];
     grille_size_y= grille_size[bot_select][1];
     nb_table=  grille_size[bot_select][2];;
  
  if (page==1){


  afficher_grille(grille_size_x,grille_size_y);
  
  afficher_table();
  afficher_bot();
//  pos_curseur();
  
  message();
  }
    
  
}




void oscEvent(OscMessage theOscMessage) {

  /////GRILLE
    if (theOscMessage.checkAddrPattern("/grille")==true) {
     for (int x=0;x<nb_bot_max;x++){

        if (theOscMessage.address().equals( bot_ip[x])){
          grille_size[x][0]=theOscMessage.get(0).intValue();
          grille_size[x][1]=theOscMessage.get(1).intValue();
          grille_size[x][2]=theOscMessage.get(2).intValue();

          
        }
//     grille_size_x= theOscMessage.get(0).intValue();
//     grille_size_y= theOscMessage.get(1).intValue();
//     nb_table=theOscMessage.get(2).intValue();
    }
    }
    
    /////TABLE
        if (theOscMessage.checkAddrPattern("/coord_table")==true) {
        for (int y=0;y<nb_bot_max;y++){
        if (theOscMessage.address().equals( bot_ip[y])){

          if (y==1){
          for (int x= 0; x< nb_table; x++){
          table_1[x][0]= theOscMessage.get(x*2).intValue();
          table_1[x][1]= theOscMessage.get((x*2)+1).intValue();
          
          }
          }
                    if (y==2){
          for (int x= 0; x< nb_table; x++){
          table_2[x][0]= theOscMessage.get(x*2).intValue();
          table_2[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==3){
          for (int x= 0; x< nb_table; x++){
          table_3[x][0]= theOscMessage.get(x*2).intValue();
          table_3[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==4){
          for (int x= 0; x< nb_table; x++){
          table_4[x][0]= theOscMessage.get(x*2).intValue();
          table_4[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==5){
          for (int x= 0; x< nb_table; x++){
          table_5[x][0]= theOscMessage.get(x*2).intValue();
          table_5[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==6){
          for (int x= 0; x< nb_table; x++){
          table_6[x][0]= theOscMessage.get(x*2).intValue();
          table_6[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==7){
          for (int x= 0; x< nb_table; x++){
          table_7[x][0]= theOscMessage.get(x*2).intValue();
          table_7[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==8){
          for (int x= 0; x< nb_table; x++){
          table_8[x][0]= theOscMessage.get(x*2).intValue();
          table_8[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==9){
          for (int x= 0; x< nb_table; x++){
          table_9[x][0]= theOscMessage.get(x*2).intValue();
          table_9[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
                    if (y==10){
          for (int x= 0; x< nb_table; x++){
          table_10[x][0]= theOscMessage.get(x*2).intValue();
          table_10[x][1]= theOscMessage.get((x*2)+1).intValue();
          }
          }
        }
        }
          
        }
        
     //////BOT   
     
     for (int y=0;y<nb_bot_max;y++){
        if (theOscMessage.address().equals( bot_ip[y])){
          if (theOscMessage.checkAddrPattern("/coord_bot")==true) {
          bot[y][0]= theOscMessage.get(0).intValue();
          bot[y][1]= theOscMessage.get(1).intValue();
        }
        }
     }
             //////NEW COORD  
             for (int y=0;y<nb_bot_max;y++){
        if (theOscMessage.address().equals(bot_ip[y])){
          if (theOscMessage.checkAddrPattern("/new_coordonate")==true) {
          new_coord_bot[y][0]= theOscMessage.get(0).intValue();
          new_coord_bot[y][1]= theOscMessage.get(1).intValue();
        }
        }
        }
     ///////MESSAGE
     
     if (theOscMessage.checkAddrPattern("/ping_main")==true) {

       main= theOscMessage.get(0).intValue();}
            if (theOscMessage.checkAddrPattern("/ping_camera")==true) {
       camera= theOscMessage.get(0).intValue();}
            if (theOscMessage.checkAddrPattern("/serial")==true) {
       serial= theOscMessage.get(0).intValue();}

            if (theOscMessage.checkAddrPattern("/wifi")==true) {
      wifi= theOscMessage.get(0).intValue();}
      
      
      
      
      
        ///////POSITION INTERDITE
        
    if (theOscMessage.checkAddrPattern("/coordonate_pos_interdite")==true) {
              for (int y=0;y<nb_bot_max;y++){
        if (theOscMessage.address().equals( bot_ip[y])){
            pos_interdite[y][0]=theOscMessage.get(0).intValue();
            pos_interdite[y][1]=theOscMessage.get(1).intValue();
            pos_interdite[y][2]=theOscMessage.get(2).intValue();
            pos_interdite[y][3]=theOscMessage.get(3).intValue();
        }
              }
    }
      
      
      /////ID
      
      if (theOscMessage.checkAddrPattern("/id")==true) {

        bot_ip[ theOscMessage.get(0).intValue()]= theOscMessage.address();

       compte_bot();
    }
       
      
  
}
