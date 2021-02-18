public void controlEvent(ControlEvent theEvent) {
 String bouton_name=theEvent.getController().getName();
 
  if((bouton_name.equals("stepX"))||(bouton_name.equals("stepY"))||(bouton_name.equals("step"))||(bouton_name.equals("speed"))||(bouton_name.equals("nb"))){
    theEvent.getController().setLabel(theEvent.getController().getName()+" "+theEvent.getController().getStringValue());
    

    
    
    
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
  
  
 if (((bouton_name.equals("lost"))==false)&&((bouton_name.equals("GO"))==false)&&((bouton_name.equals("ligneH"))==false)&&((bouton_name.equals("ligneV"))==false)&&((bouton_name.equals("croisement"))==false)&&((bouton_name.equals("T"))==false)&&(bouton_name.equals("X")==false)&&(bouton_name.equals("Y")==false)&&(bouton_name.equals("step")==false)&&(bouton_name.equals("speed")==false)&&(bouton_name.equals("nb")==false)){
  println(bouton_name);
 dir=str(theEvent.getController().getValue());
 if ((step.equals("0"))&&(dir.equals("0.0")==false)){
   dir=str(int(dir)+10);}

  dir_on_ligne=dir;
 
 envoi=true;
 }
  
}
