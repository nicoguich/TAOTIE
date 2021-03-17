public void getUserInput() {
 

  lx=  gpad.getSlider("x").getValue();
  ly=  gpad.getSlider("y").getValue();  
  lz= gpad.getSlider("z").getValue();  

  rx=  gpad.getSlider("rx").getValue();
  ry=  gpad.getSlider("ry").getValue();  
  rz= gpad.getSlider("rz").getValue();  

  A = gpad.getButton("A").pressed();
  B = gpad.getButton("B").pressed();
  X = gpad.getButton("X").pressed();
  Y = gpad.getButton("Y").pressed();
  left_gachette = gpad.getButton("Left Thumb").pressed();
  right_gachette = gpad.getButton("Right Thumb").pressed();
  select = gpad.getButton("Select").pressed();
  start = gpad.getButton("Unknown").pressed();
  home = gpad.getButton("Mode").pressed();
  left_thumb = gpad.getButton("Left Thumb 3").pressed();
  right_thumb = gpad.getButton("Right Thumb 3").pressed();
  
  hat_left = hat.left();
  hat_right = hat.right();
  hat_up = hat.up();
  hat_down = hat.down();
  hat_x = hat.getX();
  hat_y = hat.getY();
  
 
 
    dir_manette=0;
    
    if ((lx<-0.5)&&(rx<-0.5)){
      dir_manette=14;
      }

     if ((lx>0.5)&&(rx>0.5)){
       dir_manette=15;
     }
     
      if ((ly<-0.5)&&(ry<-0.5)){
      dir_manette=12;
      }

     if ((ly>0.5)&&(ry>0.5)){
       dir_manette=17;
     }
     
     
    if ((rx<-0.5)&&(ly<-0.5)){
      dir_manette=11;
      }
      if ((rx<-0.5)&&(ly>0.5)){
      dir_manette=16;
      }
          if ((rx>0.5)&&(ly<-0.5)){
      dir_manette=13;
      }
           if ((rx>0.5)&&(ly>0.5)){
      dir_manette=18;
      }
      
          if ((ly>0.5)&&(ry<-0.5)){
      dir_manette=20;
      } 
          if ((ry>0.5)&&(ly<-0.5)){
      dir_manette=19;
      } 
      
      if ((left_gachette==true)&&(left_gachette_valid==false)){
        left_gachette_valid=true;
       speed=str(int(speed)-100);
       cp5.getController("speed").setLabel(cp5.getController("speed").getName()+" "+speed);
       cp5.getController("speed").setStringValue(speed);
       envoi=true;
      }
 if (left_gachette==false){  
   
   left_gachette_valid=false;
   
 }
 
 
       if ((right_gachette==true)&&(right_gachette_valid==false)){
        right_gachette_valid=true;
       speed=str(int(speed)+100);
       cp5.getController("speed").setLabel(cp5.getController("speed").getName()+" "+speed);
       cp5.getController("speed").setStringValue(speed);
       envoi=true;
      }
 if (right_gachette==false){  
   
   right_gachette_valid=false;
   
 }
 
 
    
   if (dir_manette!=dir_manette_temp){
     
     dir_manette_temp=dir_manette;
     dir_temp=str(dir_manette);
     dir=str(dir_manette);
     envoi=true;
     
     
     
     
   }
    
    
    
    
    

  
}
