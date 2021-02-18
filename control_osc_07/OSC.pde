void oscEvent(OscMessage theOscMessage) {
  



  if (theOscMessage.checkAddrPattern("/capteur")==true) {

    
    
    for (int x=0; x<16; x++) {
      if (x<4) {
        sonar_value[x]=theOscMessage.get(x).intValue();
      } else {
        if (ligne_noire){
      //  qtr_value[x-4]=int(map(theOscMessage.get(x).intValue(),qtr_calibrate_blanc[x-4],qtr_calibrate_noir[x-4],0,255));
       // qtr_value[x-4]=(theOscMessage.get(x).intValue()+qtr_value_temp[x-4])/2;
        qtr_value[x-4]=theOscMessage.get(x).intValue();
      }
        else{
          qtr_value[x-4]=abs(theOscMessage.get(x).intValue()-255);
        }
      }
    }
  }
}



void send_osc(){
  
   OscMessage myOscMessage = new OscMessage("/motor");
   
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
