void oscEvent(OscMessage theOscMessage) {
  
  if (theOscMessage.checkAddrPattern("/copain_base")==true) { 
    
    println("copain_base");
    
  }
  
  
  
  if (theOscMessage.checkAddrPattern("/dist_to_go")==true) { 
    

   if ((int((256*theOscMessage.get(0).intValue())+theOscMessage.get(1).intValue()))!=65535){
    println("dist parcouru:" + (65000- int((256*theOscMessage.get(0).intValue())+theOscMessage.get(1).intValue())));}
    else{
      println("arrivé!!!");
}
    
    
  }
  
  



  if (theOscMessage.checkAddrPattern("/qtr")==true) {
    
    for (int x=0; x<12; x++) {
    
        qtr_value[x]=theOscMessage.get(x).intValue();
    }
  }




  if (theOscMessage.checkAddrPattern("/bat")==true) {
    

    
      println("bat : "+ str(theOscMessage.get(0).intValue()));

}

  if (theOscMessage.checkAddrPattern("/limit_qtr")==true) {
    limit_qtr= theOscMessage.get(0).intValue();

  
}

  if (theOscMessage.checkAddrPattern("/limit_sonar")==true) {
    limit_sonar= theOscMessage.get(0).intValue();

  
}

  if (theOscMessage.checkAddrPattern("/limit_batterie")==true) {
    limit_batterie= theOscMessage.get(0).intValue();

  
}


  if (theOscMessage.checkAddrPattern("/on_state")==true) {
 cp5.getController("ligneH").setValue(theOscMessage.get(0).intValue());
  cp5.getController("ligneV").setValue(theOscMessage.get(1).intValue());
  cp5.getController("croisement").setValue(theOscMessage.get(2).intValue());   
  cp5.getController("T_av").setValue(theOscMessage.get(3).intValue());
  cp5.getController("T_ar").setValue(theOscMessage.get(4).intValue());  
    cp5.getController("T_gauche").setValue(theOscMessage.get(5).intValue());
  cp5.getController("T_droite").setValue(theOscMessage.get(6).intValue());
    
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
