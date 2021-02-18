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
const IPAddress outIp(192,168,100,255);        // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


int dir,pos,speedmotor;

byte data[5];
byte dataIn[16];


OSCErrorCode error;


void setup() {

  Serial.begin(9600);

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

void motor(OSCMessage &msg) {
  dir = msg.getInt(0);
  pos = msg.getInt(1);
  speedmotor= msg.getInt(2);
data[0]= byte(pos>>8);
data[1]=byte(pos-((pos>>8)*256));
data[2]=byte(dir);
data[3]= byte(speedmotor>>8);
data[4]=byte(speedmotor-((speedmotor>>8)*256));
Serial.write(data,5);

}

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/motor", motor);
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }



  if (Serial.available() > 0) {
    Serial.readBytes(dataIn, 16);
        OSCMessage msg("/capteur");
        for (int x=0;x<16;x++){
    msg.add(int(dataIn[x]));}
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
    //delay(20);
  }
  
}
