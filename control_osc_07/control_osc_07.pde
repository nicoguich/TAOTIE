
import oscP5.*;
import netP5.*;
import controlP5.*;
import org.gamecontrolplus.gui.*;
import org.gamecontrolplus.*;
import net.java.games.input.*;

ControlIO control;
Configuration config;
ControlDevice gpad;
ControlHat hat;


float lx, ly, lz, rx, ry, rz;
boolean A, B, X, Y, left_gachette,left_gachette_valid, right_gachette,right_gachette_valid, select, start, home, left_thumb, right_thumb;
boolean hat_left, hat_right, hat_up, hat_down;
float hat_x, hat_y;
int dir_manette, dir_manette_temp;



int seuil_qtr=127;
int seuil_sonar=7;
boolean ligne_noire=true;

PImage img[]=new PImage[13];
PImage img_sel;

int sonar_value[]=new int[4];
color sonar_color[]= new color[4];
int qtr_value[]= new int[12];
int qtr_value_temp[]= new int[12];
boolean qtr_ok[]=new boolean[12];
int qtr_calibrate_blanc[]=new int[12];
int qtr_calibrate_noir[]=new int[12];
color qtr_color[]= new color[12];
boolean envoi=false, alignement=false;
int type_ligne=0, type_ligne_temp, type_T=0, type_coin=0;
boolean on_T_ar=false,on_T_av=false,on_T_gauche=false,on_T_droite=false,go_on=false, on_T=false, on_croisement=false, on_ligneH=false, on_ligneV=false, ligne_ok=false, croisement_ok=false, coin_ok=false, T_ok=false, capteur_ok=false, perdu_temp=false, follow_ligne=false, calibrate_blanc=false, calibrate_noir=false;
int capteur_max, capteur_max_temp, rotate=0;

String stepX="0", stepY="0", step="0", dir="0", dir_temp, speed="0", speed_perdu="300", dir_on_ligne="0";

int etape_perdu=0, etape_croisement=0, compteur_croisement, dir_change=0, etape_go=0;

ControlP5 cp5;

OscP5 oscP5;

NetAddress taotie_robot; 

void setup() {


  size(800, 800);

  oscP5 = new OscP5(this, 9999);

  taotie_robot = new NetAddress("192.168.100.255", 8888);




  PFont font = createFont("arial", 20);
  textFont(font);
  cp5 = new ControlP5(this);    

  cp5.addTextfield("stepX")
    .setPosition(20, 400)
    .setSize(100, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setColorCaptionLabel(color(0))
    ;

  cp5.addTextfield("stepY")
    .setPosition(170, 400)
    .setSize(100, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setColorCaptionLabel(color(0))
    ;     



  cp5.addToggle("GO")
    .setValue(false)
    .setPosition(320, 400)
    .setSize(40, 40)
    .updateSize()
    ;


  cp5.addTextfield("step")
    .setPosition(50, 20)
    .setSize(100, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setColorCaptionLabel(color(0))
    ;  

  cp5.addTextfield("speed")
    .setPosition(200, 20)
    .setSize(100, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setColorCaptionLabel(color(0))
    ;  



  PImage[] imgs_forward = {loadImage("forward_a.png"), loadImage("forward_b.png"), loadImage("forward_c.png")};
  cp5.addButton("forward")
    .setValue(2)
    .setPosition(175, 100)
    .setImages(imgs_forward)
    .updateSize()
    ;
  PImage[] imgs_right_forward = {loadImage("right_forward_a.png"), loadImage("right_forward_b.png"), loadImage("right_forward_c.png")};
  cp5.addButton("right_forward")
    .setValue(3)
    .setPosition(250, 100)
    .setImages(imgs_right_forward)
    .updateSize()
    ;


  PImage[] imgs_right = {loadImage("right_a.png"), loadImage("right_b.png"), loadImage("right_c.png")};
  cp5.addButton("right")
    .setValue(5)
    .setPosition(250, 175)
    .setImages(imgs_right)
    .updateSize()
    ; 

  PImage[] imgs_right_backward = {loadImage("right_backward_a.png"), loadImage("right_backward_b.png"), loadImage("right_backward_c.png")};
  cp5.addButton("right_backward")
    .setValue(8)
    .setPosition(250, 250)
    .setImages(imgs_right_backward)
    .updateSize()
    ; 


  PImage[] imgs_backward = {loadImage("backward_a.png"), loadImage("backward_b.png"), loadImage("backward_c.png")};
  cp5.addButton("backward")
    .setValue(7)
    .setPosition(175, 250)
    .setImages(imgs_backward)
    .updateSize()
    ;      



  PImage[] imgs_left_backward = {loadImage("left_backward_a.png"), loadImage("left_backward_b.png"), loadImage("left_backward_c.png")};
  cp5.addButton("left_backward")
    .setValue(6)
    .setPosition(100, 250)
    .setImages(imgs_left_backward)
    .updateSize()
    ;     




  PImage[] imgs_left = {loadImage("left_a.png"), loadImage("left_b.png"), loadImage("left_c.png")};
  cp5.addButton("left")
    .setValue(4)
    .setPosition(100, 175)
    .setImages(imgs_left)
    .updateSize()
    ;     



  PImage[] imgs_left_forward = {loadImage("left_forward_a.png"), loadImage("left_forward_b.png"), loadImage("left_forward_c.png")};
  cp5.addButton("left_forward")
    .setValue(1)
    .setPosition(100, 100)
    .setImages(imgs_left_forward)
    .updateSize()
    ;        




  PImage[] imgs_rotate_left = {loadImage("rotate_right_a.png"), loadImage("rotate_right_b.png"), loadImage("rotate_right_c.png")};
  cp5.addButton("rotate_right")
    .setValue(9)
    .setPosition(210, 325)
    .setImages(imgs_rotate_left)
    .updateSize()
    ;         



  PImage[] imgs_rotate_right = {loadImage("rotate_left_a.png"), loadImage("rotate_left_b.png"), loadImage("rotate_left_c.png")};
  cp5.addButton("rotate_left")
    .setValue(10)
    .setPosition(140, 325)
    .setImages(imgs_rotate_right)
    .updateSize()
    ;  

  cp5.addButton("STOP")
    .setValue(0)
    .setPosition(175, 175)
    .setSize(50, 50)
    .updateSize()
    ;  



  PImage[] imgs_T = {loadImage("button_T_a.png"), loadImage("button_T_c.png")};
  cp5.addToggle("T")
    .setValue(false)
    .setPosition(150, 500)
    .setImages(imgs_T)
    .updateSize()
    ;

  PImage[] imgs_croisement = {loadImage("croisement_a.png"), loadImage("croisement_c.png")};
  cp5.addToggle("croisement")
    .setValue(false)
    .setPosition(210, 500)
    .setImages(imgs_croisement)
    .updateSize()
    ;



  PImage[] imgs_ligneH = {loadImage("ligneH_a.png"), loadImage("ligneH_c.png")};
  cp5.addToggle("ligneH")
    .setValue(false)
    .setPosition(270, 500)
    .setImages(imgs_ligneH)
    .updateSize()
    ;


  PImage[] imgs_ligneV = {loadImage("ligneV_a.png"), loadImage("ligneV_c.png")};
  cp5.addToggle("ligneV")
    .setValue(false)
    .setPosition(270, 560)
    .setImages(imgs_ligneV)
    .updateSize()
    ;


  PImage[] imgs_lost = {loadImage("lost_a.png"), loadImage("lost_c.png")};
  cp5.addToggle("lost")
    .setValue(false)
    .setPosition(330, 500)
    .setImages(imgs_lost)
    .updateSize()
    ;


  cp5.addTextfield("nb")
    .setPosition(20, 500)
    .setSize(100, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setColorCaptionLabel(color(0))
    ;  



  img[0]=loadImage("ligne_gauche_droite.png");
  img[1]=loadImage("ligne_av_ar.png");
  img[2]=loadImage("perdu.png");
  img[3]=loadImage("croisement.png");
  img[4]=loadImage("T_droite.png");
  img[5]=loadImage("T_gauche.png");
  img[6]=loadImage("T_av.png");
  img[7]=loadImage("T_ar.png");
  img[8]=loadImage("coin_av_droit.png");
  img[9]=loadImage("coin_av_gauche.png");
  img[10]=loadImage("coin_ar_gauche.png");
  img[11]=loadImage("coin_ar_droit.png");
  img[12]=loadImage("point.png");
  img_sel=img[2];


  for (int x=0; x<12; x++) {
    qtr_calibrate_blanc[x]=0;
    qtr_calibrate_noir[x]=255;
    qtr_value_temp[x]=0;
  }






  control = ControlIO.getInstance(this);
  // Find a gamepad that matches the configuration file. To match with any 
  // connected device remove the call to filter.
  gpad = control.filter(GCP.GAMEPAD).getMatchedDevice("manette globale");
  if (gpad == null) {
    println("No suitable device configured");
    System.exit(-1); // End the program NOW!
  }
  hat = gpad.getHat("cooliehat: pov");
}




void draw() {
  getUserInput();

  if (envoi) {
    send_osc();
  }

  detection_qtr();
  detection_sonar();

  if (go_on) {
    F_go_on();
  }
  if (alignement) {
    F_alignement();
  }
  if ((on_ligneH)||(on_ligneV)) {
    F_on_ligne();
  }
  if (on_croisement) {
    F_on_croisement();
  }

  if((on_T_av==false)&&(on_T_ar==false)&&(on_T_droite==false)&&(on_T_gauche==false)){
    
   cp5.getController("T").setValue(0); 
   on_T=false;
  }
  else{
    
   on_T=true; 
    
  }
 

  dessine_robot();
}
