


void moveMotor() {

  arriere_droitWheel.setSpeed(arriere_droitSpeed);
  avant_gaucheWheel.setSpeed(avant_gaucheSpeed);
  avant_droitWheel.setSpeed(avant_droitSpeed);
  arriere_gaucheWheel.setSpeed(arriere_gaucheSpeed);


  arriere_droitWheel.runSpeed();
  avant_gaucheWheel.runSpeed();
  avant_droitWheel.runSpeed();
  arriere_gaucheWheel.runSpeed();

}




void moveLeftBackward(){

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

}


void moveRightForward(){//

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = 0;
  arriere_gaucheSpeed = 0;

}



void moveLeftForward() {//

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = 0;
  avant_gaucheSpeed = 0;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;

}


void moveRightBackward() {//

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = 0;
  avant_gaucheSpeed = 0;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;

}



void rotateLeft() {

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);


  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;

}



void rotateRight(){


  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;

}



void moveSidewaysLeft() {

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;

}



void moveForward() {


 digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);



  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = wheelSpeed;
  arriere_gaucheSpeed = -wheelSpeed;


}



void moveBackward()   {

  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = -wheelSpeed;
  avant_gaucheSpeed = wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;

}




void moveSidewaysRight() {



  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);

  
  arriere_droitSpeed = wheelSpeed;
  avant_gaucheSpeed = -wheelSpeed;
  avant_droitSpeed = -wheelSpeed;
  arriere_gaucheSpeed = wheelSpeed;


}



void stopMoving() {

// Serial.println("STOP");
  digitalWrite(enable_arriere_droit,LOW);
  digitalWrite(enable_avant_gauche,LOW);
  digitalWrite(enable_avant_droit,LOW);
  digitalWrite(enable_arriere_gauche,LOW);


  arriere_droitWheel.setSpeed(0);
  avant_gaucheWheel.setSpeed(0);
  avant_droitWheel.setSpeed(0);
  arriere_gaucheWheel.setSpeed(0);


  batterie();

}
