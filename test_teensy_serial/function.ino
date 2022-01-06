


void moveMotor() {

  arriere_droitWheel.setSpeed(arriere_droitSpeed);
  avant_gaucheWheel.setSpeed(avant_gaucheSpeed);
  avant_droitWheel.setSpeed(avant_droitSpeed);
  arriere_gaucheWheel.setSpeed(arriere_gaucheSpeed);




  if (m < 11) {


        
if ((arriere_droitWheel.distanceToGo() == 0)&&(arriere_gaucheWheel.distanceToGo() == 0)&& (avant_gaucheWheel.distanceToGo() == 0)&&(avant_droitWheel.distanceToGo() == 0)&&(m>0)){



 data_command[0] = 123;

  data_command[1] = byte(255);
  data_command[2] = byte(255);
  Serial3.write(data_command, 3);
  delay(10);
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





  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,HIGH);
  digitalWrite(enable_arriere_gauche,HIGH);

  
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




  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,HIGH);
  digitalWrite(enable_arriere_gauche,HIGH);

  
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




  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,HIGH);
  digitalWrite(enable_avant_gauche,HIGH);
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

  avant_gaucheWheel.setCurrentPosition(0);
  arriere_droitWheel.setCurrentPosition(0);
  arriere_gaucheWheel.setCurrentPosition(0);
  avant_droitWheel.setCurrentPosition(0);
  
  digitalWrite(enable_arriere_droit,HIGH);
  digitalWrite(enable_avant_gauche,HIGH);
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
  avant_gaucheWheel.moveTo(pos);
  avant_droitWheel.moveTo(-pos);
  arriere_gaucheWheel.moveTo(-pos);



 
          on_move = false;

}



void stopMoving() {
  

 Serial.println("STOP");
  digitalWrite(enable_arriere_droit,HIGH);
  digitalWrite(enable_avant_gauche,HIGH);
  digitalWrite(enable_avant_droit,HIGH);
  digitalWrite(enable_arriere_gauche,HIGH);



 

  
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
