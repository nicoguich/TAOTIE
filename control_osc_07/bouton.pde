public void controlEvent(ControlEvent theEvent) {
 String bouton_name=theEvent.getController().getName();
 
  if((bouton_name.equals("step"))||(bouton_name.equals("speed"))){
    theEvent.getController().setLabel(theEvent.getController().getName()+" "+theEvent.getController().getStringValue());

  }
  
  if(bouton_name.equals("stepX")){
   String []list_temp=split(stepX, '.');
    
    dest_coordX=list_temp[0];
    if (list_temp.length>1){
      dest_stepX=list_temp[1];
      
    }
    
    
    stepX=str(int(int(dest_coordX)-coordX));
   
    
   
    
     
    
  }
  
  if (bouton_name.equals("stepY")){
    
       String []list_temp=split(stepY, '.');
    
    dest_coordY=list_temp[0];
    if (list_temp.length>1){
      dest_stepY=list_temp[1];
      
    }
    
    
    
     stepY=str(int(int(dest_coordY)-coordY));
   cp5.getController("stepY").setLabel("coord "+coordY+"\n step "+micro_stepY);
    
  }
  
  
if (bouton_name.equals("lost")){
    
    alignement=boolean(int(theEvent.getController().getValue()));
    perdu_temp=false;
    dir_temp="0.0";
    etape_perdu=0;
  }
  
  if (bouton_name.equals("ligneH")){
    
    on_ligneH=boolean(int(theEvent.getController().getValue()));
    
  }
  
    if (bouton_name.equals("ligneV")){
    
    on_ligneV=boolean(int(theEvent.getController().getValue()));
    
  }
  
  
  
    if (bouton_name.equals("croisement")){
    
    on_croisement=boolean(int(theEvent.getController().getValue()));
   
    
  }
  
    
    if (bouton_name.equals("T")){
    
    on_T=boolean(int(theEvent.getController().getValue()));
   
    
  }
  
  
      if (bouton_name.equals("home")){
    
    on_home=boolean(int(theEvent.getController().getValue()));
    
    
    if (on_home==true){
    
    if ((on_T_gauche==false)&&(on_T_ar==false)){
      if (on_ligneH){
      
      dir="14";}
      
      if (on_ligneV){
        
        dir="17";}
    }
      
   if ((on_T_gauche==true)&&(on_T_ar==false)){
     dir="17";
     
   }
   
   if ((on_T_gauche==false)&&(on_T_ar==true)){
       dir="14"; 
     
   }
if ((on_T_gauche==true)&&(on_T_ar==true)){
     dir="0";
   on_home=false;
   cp5.getController("home").setValue(0);
   coordX=0;
   coordY=0;
   angle=0;
              }
   
    dir_on_ligne=dir;
 
 envoi=true;
   
    } 
  }



 if (bouton_name.equals("GO")){
go_on=boolean(int(theEvent.getController().getValue()));
if(go_on){
 if ((int(stepX)!=0)&&(on_ligneV==false)){
  if (int(stepX)>0){
   dir="15";
   dir_on_ligne=dir;
   send_osc();
  }
  else{
       dir="14";
   dir_on_ligne=dir;
   send_osc();
  }
   
 }
 
 
  else if (on_ligneH==false){
  if (int(stepY)>0){
   dir="12";
   dir_on_ligne=dir;
   send_osc();
  }
  else{
       dir="17";
   dir_on_ligne=dir;
   send_osc();
  }
   
 }
  
  
}

  
 }
  
  
 if (((bouton_name.equals("home"))==false)&&((bouton_name.equals("lost"))==false)&&((bouton_name.equals("GO"))==false)&&((bouton_name.equals("ligneH"))==false)&&((bouton_name.equals("ligneV"))==false)&&((bouton_name.equals("croisement"))==false)&&((bouton_name.equals("T"))==false)&&(bouton_name.equals("X")==false)&&(bouton_name.equals("Y")==false)&&(bouton_name.equals("step")==false)&&(bouton_name.equals("speed")==false)){
  println(bouton_name);
 dir=str(theEvent.getController().getValue());
 if ((step.equals("0"))&&(dir.equals("0.0")==false)){
   dir=str(int(dir)+10);}

  dir_on_ligne=dir;
 
 envoi=true;
 }
  
}
