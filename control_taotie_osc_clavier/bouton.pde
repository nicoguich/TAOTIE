public void controlEvent(ControlEvent theEvent) {
 String bouton_name=theEvent.getController().getName();
 
  if((bouton_name.equals("step"))||(bouton_name.equals("speed"))){
    theEvent.getController().setLabel(theEvent.getController().getName()+" "+theEvent.getController().getStringValue());

  }
  

  
if (bouton_name.equals("lost")){
   OscMessage myOscMessage = new OscMessage("/lost");
   
  myOscMessage.add(1);
  oscP5.send(myOscMessage, taotie_robot);
  }
  

  
  
 if ((bouton_name.equals("forward"))||(bouton_name.equals("right_forward"))||(bouton_name.equals("right"))||(bouton_name.equals("right_backward"))||(bouton_name.equals("backward"))||(bouton_name.equals("left_backward"))||(bouton_name.equals("left"))||(bouton_name.equals("left_forward"))||(bouton_name.equals("rotate_right"))||(bouton_name.equals("rotate_left"))||(bouton_name.equals("STOP"))){
  println(bouton_name);
 dir=str(theEvent.getController().getValue());
 if ((step.equals("0"))&&(dir.equals("0.0")==false)){
   step=str(65000);}

  dir_on_ligne=dir;
 
 envoi=true;
 }
 
 
 
 
 
 
 
 if((bouton_name.equals("qtr")==true)||(bouton_name.equals("sonar")==true)||(bouton_name.equals("batterie")==true)){
      OscMessage myOscMessage = new OscMessage("/show");
   
   myOscMessage.add(int(cp5.getController("qtr").getValue()));
   myOscMessage.add(int(cp5.getController("sonar").getValue()));
   myOscMessage.add(0);
   myOscMessage.add(int(cp5.getController("batterie").getValue()));
   myOscMessage.add(0);
   myOscMessage.add(0);
  oscP5.send(myOscMessage, taotie_robot);

   
   
 }
 
 
  if(bouton_name.equals("get_qtr")==true){
    
        OscMessage myOscMessage = new OscMessage("/get_limit_qtr");
        oscP5.send(myOscMessage, taotie_robot);
        
  }
  
    if(bouton_name.equals("get_sonar")==true){
    
        OscMessage myOscMessage = new OscMessage("/get_limit_sonar");
        oscP5.send(myOscMessage, taotie_robot);
        
  }
  
  
    if(bouton_name.equals("get_batterie")==true){
    
        OscMessage myOscMessage = new OscMessage("/get_limit_batterie");
        oscP5.send(myOscMessage, taotie_robot);
        
  }
  
  
    if (bouton_name.equals("send_qtr")){
      
      OscMessage myOscMessage = new OscMessage("/limit_qtr");
      myOscMessage.add(int(send_qtr));
      
      oscP5.send(myOscMessage, taotie_robot);
      
    }
    
    
    
       if (bouton_name.equals("send_sonar")){
      
      OscMessage myOscMessage = new OscMessage("/limit_sonar");
      myOscMessage.add(int(send_sonar));
      
      oscP5.send(myOscMessage, taotie_robot);
      
    }
    
    
       if (bouton_name.equals("send_batterie")){
      
      OscMessage myOscMessage = new OscMessage("/limit_batterie");
      myOscMessage.add(int(send_batterie));
      
      oscP5.send(myOscMessage, taotie_robot);
      
    }
    
    
     if (bouton_name.equals("led")){
       
 
            OscMessage myOscMessage = new OscMessage("/led");
      myOscMessage.add(int(theEvent.getController().getValue()));
      
      oscP5.send(myOscMessage, taotie_robot); 
       
     }
     
     
     
     
     
     
     
     
          if (bouton_name.equals("REC")){
       
 
            OscMessage myOscMessage = new OscMessage("/rec");
      myOscMessage.add(int(theEvent.getController().getValue()));
      
      oscP5.send(myOscMessage, taotie_robot); 
       
     }
     
     
       if (bouton_name.equals("REC_chargeur")){
       
 
            OscMessage myOscMessage = new OscMessage("/rec");
            if (int(theEvent.getController().getValue())==1){
      myOscMessage.add(2);}
      else{
      myOscMessage.add(0);
      }
      
      oscP5.send(myOscMessage, taotie_robot); 
       
     }
     
     
     
     
     
     
     
     
               if (bouton_name.equals("PLAY")){
      
 
            OscMessage myOscMessage = new OscMessage("/play");
      myOscMessage.add(int(theEvent.getController().getValue()));
      
      oscP5.send(myOscMessage, taotie_robot); 
       
     }
     
                    if (bouton_name.equals("PLAY_chargeur")){
      
 
            OscMessage myOscMessage = new OscMessage("/play");
            if (int(theEvent.getController().getValue())==1){
      myOscMessage.add(2);}
      else{
      myOscMessage.add(0);
      }      
      oscP5.send(myOscMessage, taotie_robot); 
       
     }

     
     
     
     
     

  
}
