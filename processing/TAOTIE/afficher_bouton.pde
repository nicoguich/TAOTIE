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
  if ((mousePressed == true)&&(mouseX>(width*0.005))&&(mouseX<(width*0.005)+200)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
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
  rect ((width*0.005),height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("START",(width*0.005)+40,height-((height*0.2)-50));
  
  
  
  
    /////////STOP/////////
  if ((mousePressed == true)&&(mouseX>(width*0.17))&&(mouseX<(width*0.17)+200)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
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
  rect ((width*0.17),height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("STOP",(width*0.17)+40,height-((height*0.2)-50));
  
  
  
  
  
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
  if ((mousePressed == true)&&(mouseX>(width*0.78))&&(mouseX<(width*0.78)+200)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
  fill(0,200,0);
  if (checkpage==0){
    
    page=2;

checkpage=1;}
  }
  else{
    fill(100,0,200);

    checkpage=0;
  }
  rect ((width*0.78),height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("CONTROL",(width*0.78)+40,height-((height*0.2)-50));
  
  

  
}









 ////////////////////////////PAGE 2/////////////////////////////////////////////////

if (page==2){
        /////////PAGE/////////
  if ((mousePressed == true)&&(mouseX>(width*0.78))&&(mouseX<(width*0.78)+200)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
  fill(0,200,0);
  if (checkpage==0){
    
    page=1;

checkpage=1;}
  }
  else{
    fill(100,0,200);

    checkpage=0;
  }
  rect ((width*0.78),height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("GRID",(width*0.78)+40,height-((height*0.2)-50));
  
  
  
  
  
  
  
            /////////GRILLE X -/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05))&&(mouseX<(width*0.05)+200)&&(mouseY>(height*0.16))&&(mouseY<(height*0.16)+100)) {
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
  rect ((width*0.05),(height*0.16),200,100,30);
  fill(255);
  textSize(30);
  text("GRID X -",(width*0.05)+40,(height*0.16)+50);
  
  
  
            /////////GRILLE X +/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05)+250)&&(mouseX<(width*0.05)+450)&&(mouseY>(height*0.16))&&(mouseY<(height*0.16)+100)) {
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
  rect ((width*0.05)+250,(height*0.16),200,100,30);
  fill(255);
  textSize(30);
  text("GRID X +",(width*0.05)+290,(height*0.16)+50);
  
  
  

  
  
  
  
  
  
          /////////GRILLE Y -/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05))&&(mouseX<(width*0.05)+200)&&(mouseY>(height*0.16)+110)&&(mouseY<(height*0.16)+210)) {
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
  rect ((width*0.05),(height*0.16)+110,200,100,30);
  fill(255);
  textSize(30);
  text("GRID Y -",(width*0.05)+40,(height*0.16)+160);
  
  
  
            /////////GRILLE Y +/////////
    if ((mousePressed == true)&&(mouseX>(width*0.05)+250)&&(mouseX<(width*0.05)+450)&&(mouseY>(height*0.16)+110)&&(mouseY<(height*0.16)+210)) {
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
  rect ((width*0.05)+250,(height*0.16)+110,200,100,30);
  fill(255);
  textSize(30);
  text("GRID Y +",(width*0.05)+290,(height*0.16)+160);
  
  
  
  
  
           /////////NB TABLE -/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05))&&(mouseX<(width*0.05)+200)&&(mouseY>(height*0.16)+220)&&(mouseY<(height*0.16)+320)) {
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
   rect ((width*0.05),(height*0.16)+220,200,100,30);
  fill(255);
  textSize(30);
  text("NB TABLE -",(width*0.05)+40,(height*0.16)+270);
  
  
  
            /////////NB TABLE +/////////
    if ((mousePressed == true)&&(mouseX>(width*0.05)+250)&&(mouseX<(width*0.05)+450)&&(mouseY>(height*0.16)+220)&&(mouseY<(height*0.16)+320)) {
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
  rect ((width*0.05)+250,(height*0.16)+220,200,100,30);
  fill(255);
  textSize(30);
  text("NB TABLE +",(width*0.05)+290,(height*0.16)+270); 
  
  
  
  
  
  
      fill(0);
  
    text(grille_size_x,(width*0.05)+480,(height*0.16)+50);
    
    text(grille_size_y,(width*0.05)+480,(height*0.16)+160);
  
    text(nb_table,(width*0.05)+480,(height*0.16)+270);
    
    
    
                /////////SAVE/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05))&&(mouseX<(width*0.05)+200)&&(mouseY>(height*0.16)+330)&&(mouseY<(height*0.16)+430)) {
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
  rect ((width*0.05),(height*0.16)+330,200,100,30);
  fill(255);
  textSize(30);
  text("SAVE",(width*0.05)+40,(height*0.16)+380); 
  
  
  
  
 
    
    
    
    
    
    
    
    /////// led on ////////////
    

  if ((mousePressed == true)&&(mouseX>(width*0.05)+550)&&(mouseX<(width*0.05)+650)&&(mouseY>(height*0.16))&&(mouseY<(height*0.16)+100)) {
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
  rect ((width*0.05)+550,(height*0.16),100,100,30);
  fill(255);
  textSize(30);
  text("led on",(width*0.05)+560,(height*0.16)+50);
    
    
        /////// led off ////////////
    

 if ((mousePressed == true)&&(mouseX>(width*0.05)+700)&&(mouseX<(width*0.05)+800)&&(mouseY>(height*0.16))&&(mouseY<(height*0.16)+100)) {
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
  rect ((width*0.05)+700,(height*0.16),100,100,30);
  fill(255);
  textSize(30);
  text("led off",(width*0.05)+710,(height*0.16)+50);
    
    
    
        /////// verin up ////////////
    

  if ((mousePressed == true)&&(mouseX>(width*0.05)+550)&&(mouseX<(width*0.05)+650)&&(mouseY>(height*0.16)+110)&&(mouseY<(height*0.16)+210)) {
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
  rect ((width*0.05)+550,(height*0.16)+110,100,100,30);
  fill(255);
  textSize(30);
  text("up",(width*0.05)+580,(height*0.16)+160);
    
    
        /////// verin down ////////////
    

 if ((mousePressed == true)&&(mouseX>(width*0.05)+700)&&(mouseX<(width*0.05)+800)&&(mouseY>(height*0.16)+110)&&(mouseY<(height*0.16)+210)) {
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
  rect ((width*0.05)+700,(height*0.16)+110,100,100,30);
  fill(255);
  textSize(30);
  text("down",(width*0.05)+710,(height*0.16)+160);
    
    
    
  
  
  
          /////////RESET/////////
  if ((mousePressed == true)&&(mouseX>(width*0.05))&&(mouseX<(width*0.05)+200)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
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
  rect ((width*0.05),height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("RESET POS",(width*0.05)+20,height-(height*0.2)+50);
  
  
  
  
            /////////reboot soft/////////
 if ((mousePressed == true)&&(mouseX>(width*0.05)+250)&&(mouseX<(width*0.05)+450)&&(mouseY>height-(height*0.2))&&(mouseY<height-(height*0.2)+100)) {
  fill(0,200,0);
  if (reboot_soft==0){
    
    reboot_soft=1;
    
      OscMessage myMessage = new OscMessage("/reboot_soft");
  myMessage.add(0); 
  tablette.send(myMessage, chataigne); 
  delay(50);
  
  myMessage = new OscMessage("/reboot_soft");
  myMessage.add(1); 
  tablette.send(myMessage, chataigne); 

reboot_soft=1;}
  }
  else{
    fill(0,0,200);

    reboot_soft=0;
  }
  rect ((width*0.05)+250,height-(height*0.2),200,100);
  fill(255);
  textSize(30);
  text("REBOOT SOFT",(width*0.05)+260,height-(height*0.2)+50);



        /////////AVANCE/////////
  if ((mousePressed == true)&&(mouseX>(width*0.8)-((width*0.08)/2))&&(mouseX<(width*0.8)+((width*0.08)/2))&&(mouseY>(height*0.125)-((width*0.08)/2))&&(mouseY<(height*0.125)+((width*0.08)/2))) {
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
  circle (width*0.8,height*0.125,width*0.08);
  fill(255);
  textSize(int(width*0.015));
  text("forward",(width*0.8)-((width*0.06)/2),width*0.08);
  
  
  
          /////////RECUL/////////
  if ((mousePressed == true)&&(mouseX>(width*0.8)-((width*0.08)/2))&&(mouseX<(width*0.8)+((width*0.08)/2))&&(mouseY>(height*0.375)-((width*0.08)/2))&&(mouseY<(height*0.375)+((width*0.08)/2))) {
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
  circle (width*0.8,height*0.375,width*0.08);
  fill(255);
  textSize(int(width*0.015));
  text("backward",(width*0.8)-((width*0.06)/2),height*0.375);
  
  
  
            /////////ROTATE LEFT/////////
  if ((mousePressed == true)&&(mouseX>(width*0.73)-((width*0.08)/2))&&(mouseX<(width*0.73)+((width*0.08)/2))&&(mouseY>(height *0.54)-((width*0.08)/2))&&(mouseY<(height *0.54)+((width*0.08)/2))) {
  fill(0,200,0);
  if (rotate_left==0){
    
    rotate_left=1;
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(10); 
  tablette.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    rotate_left=0;
  }
  circle (width*0.73,height *0.54,width*0.08);
  fill(255);
  textSize(int(width*0.015));
  text("rot left",(width*0.73)-((width*0.06)/2) ,height *0.54);
  
  
              /////////ROTATE RIGHT/////////
  if ((mousePressed == true)&&(mouseX>(width*0.89)-(width*0.08)/2)&&(mouseX<(width*0.89)+(width*0.08)/2)&&(mouseY>(height *0.54)-((width*0.08)/2))&&(mouseY<(height *0.54)+((width*0.08)/2))) {
  fill(0,200,0);
  if (rotate_right==0){
    
    rotate_right=1;
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(9); 
  tablette.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    rotate_right=0;
  }
  circle (width*0.89,height *0.54,(width*0.08));
    fill(255);
  textSize(int(width*0.015));
  text("rot right",(width*0.89)-((width*0.06)/2),height *0.54);
  
  
  
  
  
  
            /////////GAUCHE/////////
  if ((mousePressed == true)&&(mouseX>(width*0.73)-((width*0.08)/2))&&(mouseX<(width*0.73)+((width*0.08)/2))&&(mouseY>(height*0.25)-((width*0.08)/2))&&(mouseY<(height*0.25)+((width*0.08)/2))) {
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
  circle (width*0.73,height*0.25,(width*0.08));
    fill(255);
  textSize(int(width*0.015));
  text("left",(width*0.73)-((width*0.06)/2),height*0.25);
  
  
  
  
              /////////DROITE/////////
  if ((mousePressed == true)&&(mouseX>(width*0.89)-(width*0.08)/2)&&(mouseX<(width*0.89)+(width*0.08)/2)&&(mouseY>(height*0.25)-((width*0.08)/2))&&(mouseY<(height*0.25)+((width*0.08)/2))) {
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
  circle (width*0.89,height*0.25,(width*0.08));
      fill(255);
  textSize(int(width*0.015));
  text("right",(width*0.89)-((width*0.06)/2),height*0.25);



//////////////CHECK ZERO//////////////////

if ((avance==0) &&(recul==0) &&(gauche==0)&&(droite==0)&&(rotate_right==0)&&(rotate_left==0)){
  
  
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
