void pos_curseur(){

  
 for (int x=0;x<grille_size_x;x++){
   
   for(int y=0;y<grille_size_y;y++){
   
   
   if ((mouseX>(100 + x*(ecartX))-50)&&(mouseX<(100 + x*(ecartX))+50)&&(mouseY>(100 + y*(ecartY))-50)&&(mouseY<(100 + y*(ecartY))+50)){

     
    if (dragged==1){
        pos_interditeX[0]=pos_interditeX_temp;
     pos_interditeY[0]= pos_interditeY_temp;
      pos_interditeX[1]=x;
      pos_interditeY[1]=0;
    }
    else{
      
            
      pos_interditeX_temp=x;
      pos_interditeY_temp=(abs(y-grille_size_y)-1);
      
    }
      

   }

   }
  
 }
 
      if (mousePressed==true){
        dragged=1;

     coordrectX_left=coordrectX_left_temp;
     coordrectY_up = coordrectY_up_temp;
     
     coordrectX_right= mouseX-coordrectX_left;
     coordrectY_down= (height-380)-coordrectY_up;
     }
     else{
       dragged=0;
      coordrectX_left_temp=mouseX;
      coordrectY_up_temp=mouseY;
       
     }
  fill(200,10,10,125);
  rectMode(CORNER);
  rect(coordrectX_left,coordrectY_up,coordrectX_right,coordrectY_down);
          
           
  fill(0);
  text(pos_interditeX[0]+"  "+pos_interditeY[0]+"   /   "+pos_interditeX[1]+"  "+pos_interditeY[1], 800,900);
  
  
  
}
