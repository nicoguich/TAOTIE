void afficher_bouton(){
  rectMode(CORNER);
  
 /////////////////////////////////bouton bot/////////////////////////////////// 
  for(int x=0; x<nb_bot_max; x++){
    noStroke();
    fill(255);
   if (bot_ip[x]!=ip_null){
    fill(160);
    if (bot_select==x){
     fill(0,0,255); 
    }
     rect(((width/10) *x)+30, 5,100,50);
     fill(255);
     textSize(30);
     text("bot"+str(x),((width/10) *x)+50,50);
     fill(0);
     textSize(15);
     text(bot_ip[x],((width/10) *x)+30,70);
    
   }

   
    
    
   
 if ((mousePressed == true)&&(mouseX>((width/10) *x)+30)&&(mouseX<((width/10) *x)+130)&&(mouseY>5)&&(mouseY<55)) {
       bot_select=x;
       String[] list_ip = split(bot_ip[x], '/');
       chataigne = new NetAddress(list_ip[1],5008);
     }
     


  }
    
    
  
  ////////////////////////////PAGE 1/////////////////////////////////////////////////
  if (page==1){
  /////////HOME/////////
  if ((mousePressed == true)&&(mouseX>10)&&(mouseX<210)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (home==0){
  OscMessage myMessage = new OscMessage("/home");
  myMessage.add(1); 
  tablette.send(myMessage, chataigne); 
  }
  
home=1;}
  else{
    fill(0,0,200);
  if (home==1){
  OscMessage myMessage = new OscMessage("/home");
  myMessage.add(0); 
  tablette.send(myMessage, chataigne); 
  }
    home=0;
  }
  rect (10,height-250,200,100);
  fill(255);
  textSize(30);
  text("START",50,height-200);
  
  
  
  
    /////////STOP/////////
  if ((mousePressed == true)&&(mouseX>250)&&(mouseX<450)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (stop==0){
  OscMessage myMessagestop = new OscMessage("/stop");
  myMessagestop.add(1); 
  tablette.send(myMessagestop, chataigne); 
  }
  
stop=1;}
  else{
    fill(200,0,0);
  if (stop==1){
  OscMessage myMessagestop = new OscMessage("/stop");
  myMessagestop.add(0); 
  tablette.send(myMessagestop, chataigne); 
  }
    stop=0;
  }
  rect (250,height-250,200,100);
  fill(255);
  textSize(30);
  text("STOP",290,height-200);
  
  
  
  
  
      /////////PLAY LED/////////
   if (anim_led){
  if ((mousePressed == true)&&(mouseX>490)&&(mouseX<690)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (play_led==0){
  OscMessage myMessagestop = new OscMessage("/play_led");
  myMessagestop.add(1); 
  tablette.send(myMessagestop, router); 
  }
  
play_led=1;}
  else{
    fill(200,0,0);
  if (play_led==1){
  OscMessage myMessagestop = new OscMessage("/play_led");
  myMessagestop.add(0); 
  tablette.send(myMessagestop, router); 
  }
    play_led=0;
  }
  rect (490,height-250,200,100);
  fill(255);
  textSize(30);
  text("PLAY LED",530,height-200);
  
  
  
  
        /////////STOP LED/////////
  if ((mousePressed == true)&&(mouseX>730)&&(mouseX<930)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (stop_led==0){
  OscMessage myMessagestop = new OscMessage("/stop_led");
  myMessagestop.add(1); 
  tablette.send(myMessagestop, router); 
  }
  
stop_led=1;}
  else{
    fill(200,0,0);
  if (stop_led==1){
  OscMessage myMessagestop = new OscMessage("/stop_led");
  myMessagestop.add(0); 
  tablette.send(myMessagestop, router); 
  }
    stop_led=0;
  }
  rect (730,height-250,200,100);
  fill(255);
  textSize(30);
  text("STOP LED",770,height-200);
  
   }
  
  
      /////////PAGE/////////
  if ((mousePressed == true)&&(mouseX>1500)&&(mouseX<1700)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (checkpage==0){
    
    page=2;

checkpage=1;}
  }
  else{
    fill(100,0,200);

    checkpage=0;
  }
  rect (1500,height-250,200,100);
  fill(255);
  textSize(30);
  text("CONTROL",1540,height-200);
  

  
}









 ////////////////////////////PAGE 2/////////////////////////////////////////////////

if (page==2){
        /////////PAGE/////////
  if ((mousePressed == true)&&(mouseX>1500)&&(mouseX<1700)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (checkpage==0){
    
    page=1;

checkpage=1;}
  }
  else{
    fill(100,0,200);

    checkpage=0;
  }
  rect (1500,height-250,200,100);
  fill(255);
  textSize(30);
  text("GRID",1550,height-200);
  
  
  
  
  
  
  
            /////////GRILLE X -/////////
  if ((mousePressed == true)&&(mouseX>100)&&(mouseX<300)&&(mouseY>200)&&(mouseY<300)) {
  fill(0,200,0);
  if(xmoins==0){
          OscMessage myMessage = new OscMessage("/grille_size_x_moins");
  tablette.send(myMessage, chataigne); 
xmoins=1;}

  }
  else{
    xmoins=0;
    fill(0,0,200);


  }
  rect (100,200,200,100,30);
  fill(255);
  textSize(30);
  text("GRID X -",140,250);
  
  
  
            /////////GRILLE X +/////////
  if ((mousePressed == true)&&(mouseX>350)&&(mouseX<550)&&(mouseY>200)&&(mouseY<300)) {
  fill(0,200,0);
  if (xplus==0){
  
            OscMessage myMessage = new OscMessage("/grille_size_x_plus");
  tablette.send(myMessage, chataigne); 
  xplus=1;
  }
  }
  else{
    fill(0,0,200);
    xplus=0;


  }
  rect (350,200,200,100,30);
  fill(255);
  textSize(30);
  text("GRID X +",390,250);
  
  
  

  
  
  
  
  
  
          /////////GRILLE Y -/////////
  if ((mousePressed == true)&&(mouseX>200)&&(mouseX<300)&&(mouseY>310)&&(mouseY<410)) {
  fill(0,200,0);
  
    if (ymoins==0){
  
            OscMessage myMessage = new OscMessage("/grille_size_y_moins");
  tablette.send(myMessage, chataigne); 

  ymoins=1;
  }

  }
  else{
    fill(0,0,200);
    ymoins=0;


  }
  rect (100,310,200,100,30);
  fill(255);
  textSize(30);
  text("GRID Y -",140,360);
  
  
  
            /////////GRILLE Y +/////////
  if ((mousePressed == true)&&(mouseX>350)&&(mouseX<550)&&(mouseY>310)&&(mouseY<410)) {
  fill(0,200,0);
    if (yplus==0){
  
            OscMessage myMessage = new OscMessage("/grille_size_y_plus");
  tablette.send(myMessage, chataigne); 

  yplus=1;
  }


  }
  else{
    fill(0,0,200);
yplus=0;

  }
  rect (350,310,200,100,30);
  fill(255);
  textSize(30);
  text("GRID Y +",390,360);
  
  
  
  
  
           /////////NB TABLE -/////////
  if ((mousePressed == true)&&(mouseX>200)&&(mouseX<300)&&(mouseY>420)&&(mouseY<520)) {
  fill(0,200,0);
  
    if (tablemoins==0){
  
            OscMessage myMessage = new OscMessage("/table_moins");
  tablette.send(myMessage, chataigne); 

  tablemoins=1;
  }

  }
  else{
    fill(0,0,200);
    tablemoins=0;


  }
  rect (100,420,200,100,30);
  fill(255);
  textSize(30);
  text("NB TABLE -",140,470);
  
  
  
            /////////NB TABLE +/////////
  if ((mousePressed == true)&&(mouseX>350)&&(mouseX<550)&&(mouseY>420)&&(mouseY<520)) {
  fill(0,200,0);
    if (tableplus==0){
  
            OscMessage myMessage = new OscMessage("/table_plus");
  tablette.send(myMessage, chataigne); 

  tableplus=1;
  }


  }
  else{
    fill(0,0,200);
tableplus=0;

  }
  rect (350,420,200,100,30);
  fill(255);
  textSize(30);
  text("NB TABLE +",390,470); 
  
  
  
  
  
  
      fill(0);
  
    text(grille_size_x,600,250);
    
    text(grille_size_y,600,360);
  
    text(nb_table,600,470);
    
    
    
                /////////SAVE/////////
  if ((mousePressed == true)&&(mouseX>200)&&(mouseX<400)&&(mouseY>630)&&(mouseY<730)) {
  fill(0,200,0);
    if (save==0){
  
            OscMessage myMessage = new OscMessage("/save");
  tablette.send(myMessage, chataigne); 

  save=1;
  }


  }
  else{
    fill(0,0,200);
save=0;

  }
  rect (200,630,200,100,30);
  fill(255);
  textSize(30);
  text("SAVE",240,680); 
  
  
  
  
 
    
    
    
    
    
    
    
    /////// led on ////////////
    

  if ((mousePressed == true)&&(mouseX>1500)&&(mouseX<1600)&&(mouseY>200)&&(mouseY<300)) {
  fill(0,200,0);
  if(led_on==0){
          OscMessage myMessage = new OscMessage("/led_on");
  tablette.send(myMessage, chataigne); 
led_on=1;}

  }
  else{
    led_on=0;
    fill(0,0,200);


  }
  rect (1500,200,100,100,30);
  fill(255);
  textSize(30);
  text("led on",1510,250);
    
    
        /////// led off ////////////
    

  if ((mousePressed == true)&&(mouseX>1620)&&(mouseX<1720)&&(mouseY>200)&&(mouseY<300)) {
  fill(0,200,0);
  if(led_off==0){
          OscMessage myMessage = new OscMessage("/led_off");
  tablette.send(myMessage, chataigne); 
led_on=1;}

  }
  else{
    led_off=0;
    fill(0,0,200);


  }
  rect (1620,200,100,100,30);
  fill(255);
  textSize(30);
  text("led off",1630,250);
    
    
    
        /////// led on ////////////
    

  if ((mousePressed == true)&&(mouseX>1500)&&(mouseX<1600)&&(mouseY>400)&&(mouseY<500)) {
  fill(0,200,0);
  if(verin_up==0){
          OscMessage myMessage = new OscMessage("/verin_up");
  tablette.send(myMessage, chataigne); 
verin_up=1;}

  }
  else{
    verin_up=0;
    fill(0,0,200);


  }
  rect (1500,400,100,100,30);
  fill(255);
  textSize(30);
  text("up",1510,450);
    
    
        /////// verin up ////////////
    

  if ((mousePressed == true)&&(mouseX>1620)&&(mouseX<1720)&&(mouseY>400)&&(mouseY<500)) {
  fill(0,200,0);
  if(verin_down==0){
          OscMessage myMessage = new OscMessage("/verin_down");
  tablette.send(myMessage, chataigne); 
verin_down=1;}

  }
  else{
 verin_down=0;
    fill(0,0,200);


  }
  rect (1620,400,100,100,30);
  fill(255);
  textSize(30);
  text("down",1630,450);
    
    
    
  
  
  
          /////////RESET/////////
  if ((mousePressed == true)&&(mouseX>300)&&(mouseX<500)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (reset==0){
    
    reset=1;
    
      OscMessage myMessage = new OscMessage("/reset_table");
  myMessage.add(0); 
  tablette.send(myMessage, chataigne); 
  delay(50);
  
  myMessage = new OscMessage("/reset_table");
  myMessage.add(1); 
  tablette.send(myMessage, chataigne); 

reset=1;}
  }
  else{
    fill(0,0,200);

    reset=0;
  }
  rect (300,height-250,200,100);
  fill(255);
  textSize(30);
  text("RESET POS",320,height-200);
  
  



        /////////AVANCE/////////
  if ((mousePressed == true)&&(mouseX>985)&&(mouseX<1350)&&(mouseY>75)&&(mouseY<225)) {
  fill(0,200,0);
  if (avance==0){
    
    avance=1;
    
    
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(2); 
  tablette.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    avance=0;
  }
  circle (1060,150,150);
  
  
  
          /////////RECUL/////////
  if ((mousePressed == true)&&(mouseX>985)&&(mouseX<1135)&&(mouseY>375)&&(mouseY<525)) {
  fill(0,200,0);
  if (recul==0){
    
    recul=1;
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(7); 
  tablette.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    recul=0;
  }
  circle (1060,450,150);
  
  
            /////////GAUCHE/////////
  if ((mousePressed == true)&&(mouseX>835)&&(mouseX<985)&&(mouseY>225)&&(mouseY<375)) {
  fill(0,200,0);
  if (gauche==0){
    
    gauche=1;
      OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(4); 
  tablette.send(myMessage, chataigne); 
}
  }
  else{
    fill(0,0,200);

    gauche=0;
  }
  circle (910,300,150);
  
  
  
  
              /////////DROITE/////////
  if ((mousePressed == true)&&(mouseX>1135)&&(mouseX<1285)&&(mouseY>225)&&(mouseY<375)) {
  fill(0,200,0);
  if (droite==0){
    
    droite=1;
      OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(5); 
  tablette.send(myMessage, chataigne); 
}
  }
  else{
    fill(0,0,200);

    droite=0;
  }
  circle (1210,300,150);
  
}


//////////////CHECK ZERO//////////////////

if ((avance==0) &&(recul==0) &&(gauche==0)&&(droite==0)){
  
  
  if (checkzero==0){
   checkzero=1;
   
         OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(0); 
  tablette.send(myMessage, chataigne); 
    
    
  }
  
  
}

else{
  
 checkzero=0; 
  
  
  
}









}
