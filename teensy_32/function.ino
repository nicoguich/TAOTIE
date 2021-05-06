


void moveMotor() {

  FrontWheel.setSpeed(FrontSpeed);
  LeftWheel.setSpeed(LeftSpeed);
  RightWheel.setSpeed(RightSpeed);
  BackWheel.setSpeed(BackSpeed);




  if (m < 11) {


        
if ((FrontWheel.distanceToGo() == 0)&&(BackWheel.distanceToGo() == 0)&& (LeftWheel.distanceToGo() == 0)&&(RightWheel.distanceToGo() == 0)&&(m!=0)){

Serial.println("distance 0");

 data_command[0] = 123;

  data_command[1] = byte(255);
  data_command[2] = byte(255);
  Serial3.write(data_command, 3);
  delay(100);

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




void moveLeftBackward(){//




if (m_temp[0]!=0){
data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
       

}
  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

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






 on_move = false;


}


void moveRightForward(){//




if (m_temp[0]!=0){
data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
      


}

  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);
  
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






  on_move = false;

}



void moveLeftForward() {//


 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);


 }


  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);


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





         on_move = false; 

}


void moveRightBackward() {//



 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
   

 }


  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

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







     on_move = false;
  

}



void rotateLeft() {


 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
    


 }

   LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);


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



 
  
    on_move = false;
}



void rotateRight() {


 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
  


 }

   LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);


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



 

        on_move = false;

}



void moveSidewaysLeft() {//


 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
 

 }


  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

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


 

  
       on_move = false;
}



void moveForward() {//

 
 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
 
 }

  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

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
 



 

         on_move = false;

}


void moveBackward()  {//




 if (m_temp[0]!=0){ 


data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);

 }



  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);


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





 

          on_move = false;


}




void moveSidewaysRight() {//




 if (m_temp[0]!=0){ 

data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);


 }



  digitalWrite(enable_front,LOW);
  digitalWrite(enable_left,LOW);
  digitalWrite(enable_right,LOW);
  digitalWrite(enable_back,LOW);



  LeftWheel.setCurrentPosition(0);
  FrontWheel.setCurrentPosition(0);
  BackWheel.setCurrentPosition(0);
  RightWheel.setCurrentPosition(0);

  
  FrontSpeed = -wheelSpeed;
  LeftSpeed = -wheelSpeed;
  RightSpeed = wheelSpeed;
  BackSpeed = wheelSpeed;

  FrontWheel.moveTo(-pos);
  LeftWheel.moveTo(-pos);
  RightWheel.moveTo(pos);
  BackWheel.moveTo(pos);



 
          on_move = false;

}



void stopMoving() {


  digitalWrite(enable_front,HIGH);
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);
  digitalWrite(enable_back,HIGH);



 data_command[0] = 123;

 if (m_temp[0]==1){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

 
 if (m_temp[0]==2){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}

        if (m_temp[0]==3){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}


     if (m_temp[0]==4){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}

      if (m_temp[0]==5){
  data_command[1] = byte(RightWheel.distanceToGo() >> 8);
  data_command[2] = byte(RightWheel.distanceToGo() - ((RightWheel.distanceToGo() >> 8) * 256));}

       if (m_temp[0]==6){
  data_command[1] = byte(LeftWheel.distanceToGo() >> 8);
  data_command[2] = byte(LeftWheel.distanceToGo() - ((LeftWheel.distanceToGo() >> 8) * 256));}
  

   if (m_temp[0]==7){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}

     if (m_temp[0]==8){
  data_command[1] = byte(BackWheel.distanceToGo() >> 8);
  data_command[2] = byte(BackWheel.distanceToGo() - ((BackWheel.distanceToGo() >> 8) * 256));}


   if (m_temp[0]==9){
  data_command[1] = byte((-1*FrontWheel.distanceToGo()) >> 8);
  data_command[2] = byte((-1*FrontWheel.distanceToGo())  - (((-1*FrontWheel.distanceToGo())  >> 8) * 256));}

 if (m_temp[0]==10){
  data_command[1] = byte(FrontWheel.distanceToGo() >> 8);
  data_command[2] = byte(FrontWheel.distanceToGo() - ((FrontWheel.distanceToGo() >> 8) * 256));}


  Serial3.write(data_command, 3);
  delay(100);
        on_move = false;
 
      

  
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
