


void moveMotor() {

  FrontWheel.setSpeed(FrontSpeed);
  LeftWheel.setSpeed(LeftSpeed);
  RightWheel.setSpeed(RightSpeed);
  BackWheel.setSpeed(BackSpeed);




  if (m < 11) {


        
if ((FrontWheel.distanceToGo() == 0)&&(BackWheel.distanceToGo() == 0)&& (LeftWheel.distanceToGo() == 0)&&(RightWheel.distanceToGo() == 0)&&(m!=0)){


  Serial3.write(byte(123));
  m=0;
}

    if (FrontWheel.distanceToGo() == 0) {
      FrontWheel.setCurrentPosition(0);
      digitalWrite(enable_front,HIGH);
      
    }
    else {
      FrontWheel.runSpeed();
    }

    if (LeftWheel.distanceToGo() == 0) {
      LeftWheel.setCurrentPosition(0);
      digitalWrite(enable_left,HIGH);

    }
    else {
      LeftWheel.runSpeed();
    }

    if (RightWheel.distanceToGo() == 0) {
      RightWheel.setCurrentPosition(0);
      digitalWrite(enable_right,HIGH);
 
    }
    else {
      RightWheel.runSpeed();
    }

    if (BackWheel.distanceToGo() == 0) {
      BackWheel.setCurrentPosition(0);
      digitalWrite(enable_back,HIGH);
      
    }
    else {
      BackWheel.runSpeed();
    }
  }

  else {
    FrontWheel.runSpeed();
    LeftWheel.runSpeed();
    RightWheel.runSpeed();
    BackWheel.runSpeed();
  }


}




void moveBackward() {


  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,HIGH);

  FrontWheel.moveTo(0);
  LeftWheel.moveTo(pos);
  RightWheel.moveTo(-pos);
  BackWheel.moveTo(0);
  FrontSpeed = 0;
  LeftSpeed = wheelSpeed;
  RightSpeed = -wheelSpeed;
  BackSpeed = 0;


}


void moveForward() {

  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,HIGH);

  
  FrontSpeed = 0;
  LeftSpeed = -wheelSpeed;
  RightSpeed = wheelSpeed;
  BackSpeed = 0;
  FrontWheel.moveTo(0);
  LeftWheel.moveTo(-pos);
  RightWheel.moveTo(pos);
  BackWheel.moveTo(0);


}



void moveSidewaysLeft() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,LOW);

  
  FrontSpeed = wheelSpeed;
  LeftSpeed = 0;
  RightSpeed = 0;
  BackSpeed = -wheelSpeed;
  FrontWheel.moveTo(pos);
  LeftWheel.moveTo(0);
  RightWheel.moveTo(0);
  BackWheel.moveTo(-pos);

}


void moveSidewaysRight() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,LOW);


  
  FrontSpeed = -wheelSpeed;
  LeftSpeed = 0;
  RightSpeed = 0;
  BackSpeed = wheelSpeed;
  FrontWheel.moveTo(-pos);
  LeftWheel.moveTo(0);
  RightWheel.moveTo(0);
  BackWheel.moveTo(pos);

}



void rotateLeft() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);


  
  FrontSpeed = -wheelSpeed;
  LeftSpeed = -wheelSpeed;
  RightSpeed = -wheelSpeed;
  BackSpeed = -wheelSpeed;
  FrontWheel.moveTo(-pos);
  LeftWheel.moveTo(-pos);
  RightWheel.moveTo(-pos);
  BackWheel.moveTo(-pos);

}



void rotateRight() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);
  
  FrontSpeed = wheelSpeed;
  LeftSpeed = wheelSpeed;
  RightSpeed = wheelSpeed;
  BackSpeed = wheelSpeed;
  FrontWheel.moveTo(pos);
  LeftWheel.moveTo(pos);
  RightWheel.moveTo(pos);
  BackWheel.moveTo(pos);

}



void moveLeftBackward() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  FrontSpeed = wheelSpeed;
  LeftSpeed = wheelSpeed;
  RightSpeed = -wheelSpeed;
  BackSpeed = -wheelSpeed;
  FrontWheel.moveTo(pos);
  LeftWheel.moveTo(pos);
  RightWheel.moveTo(-pos);

  BackWheel.moveTo(-pos);

}



void moveLeftForward() {

  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  FrontSpeed = wheelSpeed;
  LeftSpeed = -wheelSpeed;
  RightSpeed = wheelSpeed;
  BackSpeed = -wheelSpeed;

  FrontWheel.moveTo(pos);
  LeftWheel.moveTo(-pos);
  RightWheel.moveTo(pos);
  BackWheel.moveTo(-pos);

}


void moveRightBackward() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  FrontSpeed = -wheelSpeed;
  LeftSpeed = wheelSpeed;
  RightSpeed = -wheelSpeed;
  BackSpeed = wheelSpeed;
  FrontWheel.moveTo(-pos);
  LeftWheel.moveTo(pos);
  RightWheel.moveTo(-pos);
  BackWheel.moveTo(pos);

}




void moveRightForward() {


  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);

  
  FrontSpeed = -wheelSpeed;
  LeftSpeed = -wheelSpeed;
  RightSpeed = wheelSpeed;
  BackSpeed = wheelSpeed;

  FrontWheel.moveTo(-pos);
  LeftWheel.moveTo(-pos);
  RightWheel.moveTo(pos);
  BackWheel.moveTo(pos);

}



void stopMoving() {


  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,HIGH);

  
  FrontWheel.setSpeed(0);
  LeftWheel.setSpeed(0);
  RightWheel.setSpeed(0);
  BackWheel.setSpeed(0);
  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);
  FrontWheel.moveTo(0);
  LeftWheel.moveTo(0);
  RightWheel.moveTo(0);
  BackWheel.moveTo(0);

}
