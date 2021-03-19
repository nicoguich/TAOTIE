void F_send_command() {


  


  dataMotor[0] = byte(step >> 8);
  dataMotor[1] = byte(step - ((step >> 8) * 256));
  dataMotor[2] = byte(dir);
  dataMotor[3] = byte(speed >> 8);
  dataMotor[4] = byte(speed - ((speed >> 8) * 256));
  Serial2.write(dataMotor, 5);


  if ((on_ligneH==true)||(on_ligneV==true)){
  dir=dir_on_ligne;
speed=speed_command;
}

envoi=false;

}
