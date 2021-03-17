void oscEvent(OscMessage theOscMessage) {
  



  if (theOscMessage.checkAddrPattern("/qtr")==true) {

    
    
    for (int x=0; x<12; x++) {
    
        qtr_value[x]=theOscMessage.get(x).intValue();
      

    }
  }
}



void send_osc(){
  
   OscMessage myOscMessage = new OscMessage("/command");
   
   myOscMessage.add(int(dir));
   myOscMessage.add(int(step));
   myOscMessage.add(int(speed));
  oscP5.send(myOscMessage, taotie_robot);
  println("step: "+step+" dir : "+dir+" speed : "+speed+ " align : "+ alignement);  

  envoi=false;
  if ((on_ligneH==true)||(on_ligneV==true)){
  dir=dir_on_ligne;
speed=cp5.getController("speed").getStringValue();
}
}
