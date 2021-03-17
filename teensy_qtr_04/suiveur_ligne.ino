void ligne(){

qtr.read(sensorValues);
delay(50);

  
int change=0;
dataSensor[0]=byte(0);

for (int x=0;x<12;x++){
dataSensor_temp[x+1]=byte(map(sensorValues[x],0,500,0,255));
if ((int(dataSensor_temp[x+1])>=limit_qtr)&&(dataSensor[x+1]!=1)){

dataSensor[x+1]=1;
change++;
  
}
else if ((int(dataSensor_temp[x+1])<limit_qtr)&&(dataSensor[x+1]!=0)){

dataSensor[x+1]=0;
change++;
  
}


}


if (change>0){
Serial3.write(dataSensor, 13);
}




}









int getMax(int* array, int size)
{
  int index = 0;
  int minimum = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] > minimum) {
      minimum = array[i];
      index = i;
    }

  }
  return index;
}
