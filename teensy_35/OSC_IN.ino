void osc_in(){


 if (Serial3.available() > 0) {
    Serial3.readBytes(dataIn, 7);

    switch (dataIn[0]){
    case 0 :
    for (int x=0;x<6;x++){
    dataMotor[x]=dataIn[x+1];}
      Serial2.write(dataMotor, 5);
    pos = (256 * dataMotor[0]) + dataMotor[1];
    dir = dataMotor[2];
      break;

      case 1 :
      show_qtr=dataIn[1];
      show_sonar=dataIn[2];
      show_coord=dataIn[3];
      show_bat=dataIn[4];
      show_on=dataIn[5];
      show_lampe=dataIn[6];
      break;
    
   case 2:
      EEPROM.write(0, dataIn[1]) ;
      limit_qtr = dataIn[1];
      delay(500);
    break;

    case 3 :
      EEPROM.write(1, dataIn[1]) ;
      limit_sonar = dataIn[1];
      delay(500);
    break;


    case 4 :
      EEPROM.write(2, dataIn[1]) ;
      limit_batterie = dataIn[1];
      delay(500);
    break;
    
  }
 }





  
}