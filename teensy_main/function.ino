


void moveMotor() {

  arriere_droitWheel.setSpeed(arriere_droitSpeed);
  avant_gaucheWheel.setSpeed(avant_gaucheSpeed);
  avant_droitWheel.setSpeed(avant_droitSpeed);
  arriere_gaucheWheel.setSpeed(arriere_gaucheSpeed);




  if (m < 11) {


        
if ((arriere_droitWheel.distanceToGo() == 0)&&(arriere_gaucheWheel.distanceToGo() == 0)&& (avant_gaucheWheel.distanceToGo() == 0)&&(avant_droitWheel.distanceToGo() == 0)&&(m>0)){


/*
Serial.print(3);
 Serial.println(255);*/
 m=-1;
}

    if (arriere_droitWheel.distanceToGo() == 0) {
      arriere_droitWheel.setCurrentPosition(0);
     // digitalWrite(enable_arriere_droit,HIGH);
      
    }
    else {
      arriere_droitWheel.runSpeed();
    }

    if (avant_gaucheWheel.distanceToGo() == 0) {
      avant_gaucheWheel.setCurrentPosition(0);
    //  digitalWrite(enable_avant_gauche,HIGH);

    }
    else {
      avant_gaucheWheel.runSpeed();
    }

    if (avant_droitWheel.distanceToGo() == 0) {
      avant_droitWheel.setCurrentPosition(0);
    //  digitalWrite(enable_avant_droit,HIGH);
 
    }
    else {
      avant_droitWheel.runSpeed();
    }

    if (arriere_gaucheWheel.distanceToGo() == 0) {
      arriere_gaucheWheel.setCurrentPosition(0);
     // digitalWrite(enable_arriere_gauche,HIGH);
      
    }
    else {
      arriere_gaucheWheel.runSpeed();
    }
  }

  else {
    arriere_droitWheel.runSpeed();
    avant_gaucheWheel.runSpeed();
    avant_droitWheel.runSpeed();
    arriere_gaucheWheel.runSpeed();
  }


}




void moveLeftBackward(){//
/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }

*/


  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = 0;
  arriere_gaucheSpeed = 0;
  arriere_droitWheel.moveTo(-pos);
  avant_gaucheWheel.moveTo(pos);
  avant_droitWheel.moveTo(0);
  arriere_gaucheWheel.moveTo(0);






  on_move = false;



}


void moveRightForward(){//
/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }

*/
  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = 0;
  arriere_gaucheSpeed = 0;
  arriere_droitWheel.moveTo(pos);
  avant_gaucheWheel.moveTo(-pos);
  avant_droitWheel.moveTo(0);
  arriere_gaucheWheel.moveTo(0);






  on_move = false;

}



void moveLeftForward() {//

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }

*/
  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = 0;
  avant_gaucheSpeed = 0;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;
  arriere_droitWheel.moveTo(0);
  avant_gaucheWheel.moveTo(0);
  avant_droitWheel.moveTo(pos);
  arriere_gaucheWheel.moveTo(-pos);






  on_move = false;
}


void moveRightBackward() {//

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }
*/
  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = 0;
  avant_gaucheSpeed = 0;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;
  arriere_droitWheel.moveTo(0);
  avant_gaucheWheel.moveTo(0);
  avant_droitWheel.moveTo(-pos);
  arriere_gaucheWheel.moveTo(pos);






  on_move = false;

}



void rotateLeft() {

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }

*/
   avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);


  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);


  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;
  arriere_droitWheel.moveTo(pos);
  avant_gaucheWheel.moveTo(pos);
  avant_droitWheel.moveTo(pos);
  arriere_gaucheWheel.moveTo(pos);



 
  
    on_move = false;
}



void rotateRight(){

  /*

 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }

*/
   avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);


  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;
  arriere_droitWheel.moveTo(-pos);
  avant_gaucheWheel.moveTo(-pos);
  avant_droitWheel.moveTo(-pos);
  arriere_gaucheWheel.moveTo(-pos);



 

        on_move = false;

}



void moveSidewaysLeft() {//

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }


*/
  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);

  

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;
  arriere_droitWheel.moveTo(-pos);
  avant_gaucheWheel.moveTo(pos);
  avant_droitWheel.moveTo(pos);

  arriere_gaucheWheel.moveTo(-pos);


 

  
       on_move = false;
}



void moveForward() {//

  /*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }
 */
 

  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);



 digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;

  arriere_droitWheel.moveTo(pos);
  avant_gaucheWheel.moveTo(-pos);
  avant_droitWheel.moveTo(pos);
  arriere_gaucheWheel.moveTo(-pos);
 



 

         on_move = false;

}


void moveBackward()   {//

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }
*/

  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);


  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;
  arriere_droitWheel.moveTo(-pos);
  avant_gaucheWheel.moveTo(pos);
  avant_droitWheel.moveTo(-pos);
  arriere_gaucheWheel.moveTo(pos);





 

          on_move = false;


}




void moveSidewaysRight() {//

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }
*/

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);

  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;

  arriere_droitWheel.moveTo(pos);
  avant_gaucheWheel.moveTo(-pos);
  avant_droitWheel.moveTo(-pos);
  arriere_gaucheWheel.moveTo(pos);



 
 on_move = false;

}



void stopMoving() {

/*
 if (abs(avant_gaucheWheel.currentPosition())>0){
 Serial.print(1);
 Serial.print( m_temp[0]); 
 Serial.println(abs(avant_gaucheWheel.currentPosition()));}
 else{ 
  Serial.print(1);
  Serial.print( m_temp[0]);
  Serial.println(abs(avant_droitWheel.currentPosition()));
   }
   */

// Serial.println("STOP");
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



 

  
  arriere_droitWheel.setSpeed(0);
  avant_gaucheWheel.setSpeed(0);
  avant_droitWheel.setSpeed(0);
  arriere_gaucheWheel.setSpeed(0);
  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  arriere_droitWheel.moveTo(0);
  avant_gaucheWheel.moveTo(0);
  avant_droitWheel.moveTo(0);
  arriere_gaucheWheel.moveTo(0);

  batterie();

}
