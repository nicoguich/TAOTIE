void afficher_bouton(){
  rectMode(CORNER);
  
  
  
  ////////////////////////////PAGE 1/////////////////////////////////////////////////
  if (page==1){
  /////////HOME/////////
  if ((mousePressed == true)&&(mouseX>10)&&(mouseX<210)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (home==0){
  OscMessage myMessage = new OscMessage("/home");
  myMessage.add(1); 
  oscP5.send(myMessage, chataigne); 
  }
  
home=1;}
  else{
    fill(0,0,200);
  if (home==1){
  OscMessage myMessage = new OscMessage("/home");
  myMessage.add(0); 
  oscP5.send(myMessage, chataigne); 
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
  oscP5.send(myMessagestop, chataigne); 
  }
  
stop=1;}
  else{
    fill(200,0,0);
  if (stop==1){
  OscMessage myMessagestop = new OscMessage("/stop");
  myMessagestop.add(0); 
  oscP5.send(myMessagestop, chataigne); 
  }
    stop=0;
  }
  rect (250,height-250,200,100);
  fill(255);
  textSize(30);
  text("STOP",290,height-200);
  
  
  
  
      /////////PAGE/////////
  if ((mousePressed == true)&&(mouseX>1500)&&(mouseX<1700)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (checkpage==0){
    
    page=2;

checkpage=1;}
  }
  else{
    fill(0,0,200);

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
    fill(0,0,200);

    checkpage=0;
  }
  rect (1500,height-250,200,100);
  fill(255);
  textSize(30);
  text("GRILLE",1550,height-200);
  
  
  
  
  
          /////////RESET/////////
  if ((mousePressed == true)&&(mouseX>300)&&(mouseX<500)&&(mouseY>height-250)&&(mouseY<height-150)) {
  fill(0,200,0);
  if (reset==0){
    
    reset=1;
    
      OscMessage myMessage = new OscMessage("/reset_table");
  myMessage.add(0); 
  oscP5.send(myMessage, chataigne); 
  delay(50);
  
  myMessage = new OscMessage("/reset_table");
  myMessage.add(1); 
  oscP5.send(myMessage, chataigne); 

reset=1;}
  }
  else{
    fill(0,0,200);

    reset=0;
  }
  rect (300,height-250,200,100);
  fill(255);
  textSize(30);
  text("RESET",340,height-200);




        /////////AVANCE/////////
  if ((mousePressed == true)&&(mouseX>910)&&(mouseX<1010)&&(mouseY>100)&&(mouseY<200)) {
  fill(0,200,0);
  if (avance==0){
    
    avance=1;
    
    
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(2); 
  oscP5.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    avance=0;
  }
  circle (960,150,100);
  
  
  
          /////////RECUL/////////
  if ((mousePressed == true)&&(mouseX>910)&&(mouseX<1010)&&(mouseY>400)&&(mouseY<500)) {
  fill(0,200,0);
  if (recul==0){
    
    recul=1;
  OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(7); 
  oscP5.send(myMessage, chataigne); 
    
    
}
  }
  else{
    fill(0,0,200);

    recul=0;
  }
  circle (960,450,100);
  
  
            /////////GAUCHE/////////
  if ((mousePressed == true)&&(mouseX>760)&&(mouseX<860)&&(mouseY>250)&&(mouseY<350)) {
  fill(0,200,0);
  if (gauche==0){
    
    gauche=1;
      OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(4); 
  oscP5.send(myMessage, chataigne); 
}
  }
  else{
    fill(0,0,200);

    gauche=0;
  }
  circle (810,300,100);
  
  
  
  
              /////////DROITE/////////
  if ((mousePressed == true)&&(mouseX>1060)&&(mouseX<1160)&&(mouseY>250)&&(mouseY<350)) {
  fill(0,200,0);
  if (droite==0){
    
    droite=1;
      OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(5); 
  oscP5.send(myMessage, chataigne); 
}
  }
  else{
    fill(0,0,200);

    droite=0;
  }
  circle (1110,300,100);
  
}


//////////////CHECK ZERO//////////////////

if ((avance==0) &&(recul==0) &&(gauche==0)&&(droite==0)){
  
  
  if (checkzero==0){
   checkzero=1;
   
         OscMessage myMessage = new OscMessage("/dir");
  myMessage.add(0); 
  oscP5.send(myMessage, chataigne); 
    
    
  }
  
  
}

else{
  
 checkzero=0; 
  
  
  
}









}
