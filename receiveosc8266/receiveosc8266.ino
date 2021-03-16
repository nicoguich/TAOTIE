/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266

  Example for receiving open sound control (OSC) bundles on the ESP8266
  Send integers '0' or '1' to the address "/led" to turn on/off the built-in LED of the esp8266.

  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

char ssid[] = "LE HOOP";          // your network SSID (name)
char pass[] = "lescoworkssontcuites";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
OSCBundle bundle;
const IPAddress outIp(192,168,100,255);        // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


int dir,pos,speedmotor;
int qtr,sonar,coord,bat,on,lampe;
int length_send,length_qtr=12,length_bat=1,length_coord=2,length_sonar=4,length_lampe=1,length_on=5;


byte data_command[7];
byte data_show[7];
byte dataIn[13];


OSCErrorCode error;


void setup() {

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());





}

void command(OSCMessage &msg) {
dir = msg.getInt(0);
pos = msg.getInt(1);
speedmotor= msg.getInt(2);

/*
Serial.print("/command ");
Serial.print(dir);
Serial.print(" ");
Serial.print(pos);
Serial.print(" ");
Serial.println(speedmotor);
*/
data_command[0]=byte(0);  
data_command[1]= byte(pos>>8);
data_command[2]=byte(pos-((pos>>8)*256));
data_command[3]=byte(dir);
data_command[4]= byte(speedmotor>>8);
data_command[5]=byte(speedmotor-((speedmotor>>8)*256));
Serial.write(data_command,7);

}



void show(OSCMessage &msg) {

//qtr,sonar,coord,bat,on,lampe
qtr = msg.getInt(0);
sonar = msg.getInt(1);
coord = msg.getInt(2);
bat = msg.getInt(3);
on = msg.getInt(4);
lampe = msg.getInt(5);
/*
Serial.print("/show ");
Serial.print(qtr);
Serial.print(" ");
Serial.print(sonar);
Serial.print(" ");
Serial.print(coord);
Serial.print(" ");
Serial.print(bat);
Serial.print(" ");
Serial.print(on);
Serial.print(" ");
Serial.println(lampe);
*/
data_show[0]=byte(1);
data_show[1]=byte(qtr);  
data_show[2]= byte(sonar);
data_show[3]=byte(coord);
data_show[4]=byte(bat);
data_show[5]= byte(on);
data_show[6]=byte(lampe);
Serial.write(data_show,7);

}



void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/command", command);
      msg.dispatch("/show",show);
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }



  if (Serial.available() > 0) {
    Serial.readBytes(dataIn, 13);
OSCMessage msg2;
   
switch (dataIn[0]){
case 0 :
  msg2= bundle.add("/qtr");
  length_send = length_qtr;
  break;
  
case 1:
  msg2= bundle.add("/bat");
  length_send = length_bat;
  break;
  
  case 2 :
  msg2= bundle.add("/coord");
  length_send = length_coord;
  break;
  
  case 3 :
  msg2= bundle.add("/lampe");
  length_send = length_lampe;
  break;
  
  case 4 :
  msg2= bundle.add("/sonar");
  length_send = length_sonar;
  break;
  
  case 5 :
  msg2= bundle.add("/on");
  length_send = length_on;
  break;

  
}
     
 for (int x=1;x<length_send+1;x++){
         
    msg2.add(int(dataIn[x]));}
    Udp.beginPacket(outIp, outPort);
    msg2.send(Udp);
    Udp.endPacket();
    msg2.empty();
    delay(20);
  }
  
}
