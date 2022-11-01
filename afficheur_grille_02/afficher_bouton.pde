void afficher_bouton(){
  rectMode(CORNER);
  
  
  /////////HOME/////////
  if ((mousePressed == true)&&(mouseX>10)&&(mouseX<210)&&(mouseY>height-250)&&(mouseX<height-150)) {
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
  fill(0);
  textSize(30);
  text("HOME",50,height-200);
  
  
  
  
    /////////STOP/////////
  if ((mousePressed == true)&&(mouseX>250)&&(mouseX<450)&&(mouseY>height-250)&&(mouseX<height-150)) {
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
  fill(0);
  textSize(30);
  text("STOP",290,height-200);
  
  
}
