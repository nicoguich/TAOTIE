


void moveMotor() {

  LeftFrontWheel.setSpeed(LeftFrontSpeed);
  LeftBackWheel.setSpeed(LeftBackSpeed);
  RightFrontWheel.setSpeed(RightFrontSpeed);
  RightBackWheel.setSpeed(RightBackSpeed);




  if (m < 11) {

    if (LeftFrontWheel.distanceToGo() == 0) {
      LeftFrontWheel.setCurrentPosition(0);
    }
    else {
      LeftFrontWheel.runSpeed();
    }

    if (LeftBackWheel.distanceToGo() == 0) {
      LeftBackWheel.setCurrentPosition(0);
    }
    else {
      LeftBackWheel.runSpeed();
    }

    if (RightFrontWheel.distanceToGo() == 0) {
      RightFrontWheel.setCurrentPosition(0);
    }
    else {
      RightFrontWheel.runSpeed();
    }

    if (RightBackWheel.distanceToGo() == 0) {
      RightBackWheel.setCurrentPosition(0);
    }
    else {
      RightBackWheel.runSpeed();
    }
  }

  else {
    LeftFrontWheel.runSpeed();
    LeftBackWheel.runSpeed();
    RightFrontWheel.runSpeed();
    RightBackWheel.runSpeed();
  }


}




void moveForward() {


  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,HIGH);

  LeftFrontWheel.moveTo(0);
  LeftBackWheel.moveTo(pos);
  RightFrontWheel.moveTo(-pos);
  RightBackWheel.moveTo(0);
  LeftFrontSpeed = 0;
  LeftBackSpeed = wheelSpeed;
  RightFrontSpeed = -wheelSpeed;
  RightBackSpeed = 0;


}


void moveBackward() {

  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,HIGH);

  
  LeftFrontSpeed = 0;
  LeftBackSpeed = -wheelSpeed;
  RightFrontSpeed = wheelSpeed;
  RightBackSpeed = 0;
  LeftFrontWheel.moveTo(0);
  LeftBackWheel.moveTo(-pos);
  RightFrontWheel.moveTo(pos);
  RightBackWheel.moveTo(0);


}



void moveSidewaysRight() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,LOW);

  
  LeftFrontSpeed = wheelSpeed;
  LeftBackSpeed = 0;
  RightFrontSpeed = 0;
  RightBackSpeed = -wheelSpeed;
  LeftFrontWheel.moveTo(pos);
  LeftBackWheel.moveTo(0);
  RightFrontWheel.moveTo(0);
  RightBackWheel.moveTo(-pos);

}


void moveSidewaysLeft() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,LOW);


  
  LeftFrontSpeed = -wheelSpeed;
  LeftBackSpeed = 0;
  RightFrontSpeed = 0;
  RightBackSpeed = wheelSpeed;
  LeftFrontWheel.moveTo(-pos);
  LeftBackWheel.moveTo(0);
  RightFrontWheel.moveTo(0);
  RightBackWheel.moveTo(pos);

}



void rotateLeft() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);


  
  LeftFrontSpeed = -wheelSpeed;
  LeftBackSpeed = -wheelSpeed;
  RightFrontSpeed = -wheelSpeed;
  RightBackSpeed = -wheelSpeed;
  LeftFrontWheel.moveTo(-pos);
  LeftBackWheel.moveTo(-pos);
  RightFrontWheel.moveTo(-pos);
  RightBackWheel.moveTo(-pos);

}



void rotateRight() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);
  
  LeftFrontSpeed = wheelSpeed;
  LeftBackSpeed = wheelSpeed;
  RightFrontSpeed = wheelSpeed;
  RightBackSpeed = wheelSpeed;
  LeftFrontWheel.moveTo(pos);
  LeftBackWheel.moveTo(pos);
  RightFrontWheel.moveTo(pos);
  RightBackWheel.moveTo(pos);

}



void moveRightForward() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  LeftFrontSpeed = wheelSpeed;
  LeftBackSpeed = wheelSpeed;
  RightFrontSpeed = -wheelSpeed;
  RightBackSpeed = -wheelSpeed;
  LeftFrontWheel.moveTo(pos);
  LeftBackWheel.moveTo(pos);
  RightFrontWheel.moveTo(-pos);

  RightBackWheel.moveTo(-pos);

}



void moveRightBackward() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  LeftFrontSpeed = wheelSpeed;
  LeftBackSpeed = -wheelSpeed;
  RightFrontSpeed = wheelSpeed;
  RightBackSpeed = -wheelSpeed;

  LeftFrontWheel.moveTo(pos);
  LeftBackWheel.moveTo(-pos);
  RightFrontWheel.moveTo(pos);
  RightBackWheel.moveTo(-pos);

}


void moveLeftForward() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  LeftFrontSpeed = -wheelSpeed;
  LeftBackSpeed = wheelSpeed;
  RightFrontSpeed = -wheelSpeed;
  RightBackSpeed = wheelSpeed;
  LeftFrontWheel.moveTo(-pos);
  LeftBackWheel.moveTo(pos);
  RightFrontWheel.moveTo(-pos);
  RightBackWheel.moveTo(pos);

}




void moveLeftBackward() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  LeftFrontSpeed = -wheelSpeed;
  LeftBackSpeed = -wheelSpeed;
  RightFrontSpeed = wheelSpeed;
  RightBackSpeed = wheelSpeed;

  LeftFrontWheel.moveTo(-pos);
  LeftBackWheel.moveTo(-pos);
  RightFrontWheel.moveTo(pos);
  RightBackWheel.moveTo(pos);

}



void stopMoving() {


  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,HIGH);

  
  LeftFrontWheel.setSpeed(0);
  LeftBackWheel.setSpeed(0);
  RightFrontWheel.setSpeed(0);
  RightBackWheel.setSpeed(0);
  LeftBackWheel.setCurrentPosition(0);
  LeftFrontWheel.setCurrentPosition(0);
  RightBackWheel.setCurrentPosition(0);
  RightFrontWheel.setCurrentPosition(0);
  LeftFrontWheel.moveTo(0);
  LeftBackWheel.moveTo(0);
  RightFrontWheel.moveTo(0);
  RightBackWheel.moveTo(0);

}
