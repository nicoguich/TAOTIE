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

char ssid[] = "TAOTIE";          // your network SSID (name)
char pass[] = "naomi_wu";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
OSCBundle bundle;
const IPAddress outIp(192, 168, 100, 255);     // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


int dir, pos, speedmotor, limit_qtr_value, limit_sonar_value, limit_batterie_value;
int qtr, sonar, coord, bat, on, lampe;
int length_send, length_on_state = 7, length_qtr = 12, length_bat = 1, length_coord = 4, length_sonar = 4, length_lampe = 1, length_on = 5, length_limit_qtr = 1, length_limit_sonar = 1, length_limit_batterie = 1, length_dist_to_go = 2, length_copain_base=2;


byte data_command[7];
byte data_show[7];
byte dataIn[13];


OSCErrorCode error;


void setup() {

  Serial.begin(115200);

  // Connect to WiFi network
  // Serial.println();
  // Serial.println();
  // Serial.print("Connecting to ");
  //Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    // Serial.print(".");
  }
  // Serial.println("");

  // Serial.println("WiFi connected");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());

  // Serial.println("Starting UDP");
  Udp.begin(localPort);
  // Serial.print("Local port: ");
  // Serial.println(Udp.localPort());





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
      msg.dispatch("/show", show);
      msg.dispatch("/limit_qtr", limit_qtr);
      msg.dispatch("/get_limit_qtr", get_limit_qtr);
      msg.dispatch("/limit_sonar", limit_sonar);
      msg.dispatch("/get_limit_sonar", get_limit_sonar);
      msg.dispatch("/limit_batterie", limit_batterie);
      msg.dispatch("/get_limit_batterie", get_limit_batterie);
      msg.dispatch("/lost", lost);
      msg.dispatch("/home", home);
      msg.dispatch("/go", go);
      msg.dispatch("/led", led);
      msg.dispatch("/rec", rec);
      msg.dispatch("/play", play_sd);
      msg.dispatch("/copain_base", copain_base);


    } else {
      error = msg.getError();
      //    Serial.print("error: ");
      //    Serial.println(error);
    }
  }



  if (Serial.available() > 0) {
    Serial.readBytes(dataIn, 13);
    OSCMessage msg2;

    if (dataIn[0] == 100) {

      msg2 = bundle.add("/qtr");
      length_send = length_qtr;
    }

    if (dataIn[0] == 101) {
      msg2 = bundle.add("/bat");
      length_send = length_bat;
    }

    if (dataIn[0] == 102) {
      msg2 = bundle.add("/coord");
      length_send = length_coord;
    }
    if (dataIn[0] == 103) {
      msg2 = bundle.add("/lampe");
      length_send = length_lampe;
    }

    if (dataIn[0] == 104) {
      msg2 = bundle.add("/sonar");
      length_send = length_sonar;
    }

    if (dataIn[0] == 105) {
      msg2 = bundle.add("/on");
      length_send = length_on;
    }

    if (dataIn[0] == 106) {
      msg2 = bundle.add("/limit_qtr");
      length_send = length_limit_qtr;
    }

    if (dataIn[0] == 107) {
      msg2 = bundle.add("/limit_sonar");
      length_send = length_limit_sonar;
    }

    if (dataIn[0] == 108) {
      msg2 = bundle.add("/limit_batterie");
      length_send = length_limit_batterie;
    }

    if (dataIn[0] == 109) {
      msg2 = bundle.add("/on_state");
      length_send = length_on_state;
    }


    if (dataIn[0] == 110) {
      msg2 = bundle.add("/copain_base");
      length_send = length_copain_base;
    }


    

    if (dataIn[0] == 123) {
      msg2 = bundle.add("/dist_to_go");
      length_send = length_dist_to_go;
    }






    for (int x = 1; x < length_send + 1; x++) {

      msg2.add(int(dataIn[x]));
    }
    Udp.beginPacket(outIp, outPort);
    msg2.send(Udp);
    Udp.endPacket();
    msg2.empty();
    delay(100);
  }

}











void command(OSCMessage &msg) {
  dir = msg.getInt(0);
  pos = msg.getInt(1);
  speedmotor = msg.getInt(2);

  /*
    Serial.print("/command ");
    Serial.print(dir);
    Serial.print(" ");
    Serial.print(pos);
    Serial.print(" ");
    Serial.println(speedmotor);
  */
  data_command[0] = byte(0);
  data_command[1] = byte(pos >> 8);
  data_command[2] = byte(pos - ((pos >> 8) * 256));
  data_command[3] = byte(dir);
  data_command[4] = byte(speedmotor >> 8);
  data_command[5] = byte(speedmotor - ((speedmotor >> 8) * 256));
  Serial.write(data_command, 7);

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
  data_show[0] = byte(1);
  data_show[1] = byte(qtr);
  data_show[2] = byte(sonar);
  data_show[3] = byte(coord);
  data_show[4] = byte(bat);
  data_show[5] = byte(on);
  data_show[6] = byte(lampe);
  Serial.write(data_show, 7);

}


void limit_qtr(OSCMessage &msg) {

  limit_qtr_value = msg.getInt(0);


  /*
    Serial.print("/limit_qtr ");
    Serial.println(limit_qtr_value);
  */
  data_command[0] = byte(2);
  data_command[1] = byte(limit_qtr_value);
  Serial.write(data_command, 7);

}

void limit_sonar(OSCMessage &msg) {

  limit_sonar_value = msg.getInt(0);


  /*
    Serial.print("/limit_sonar ");
    Serial.println(limit_sonar_value);
  */
  data_command[0] = byte(3);
  data_command[1] = byte(limit_sonar_value);
  Serial.write(data_command, 7);

}


void limit_batterie(OSCMessage &msg) {

  limit_batterie_value = msg.getInt(0);


  /*
    Serial.print("/limit_batterie ");
    Serial.println(limit_batterie_value);
  */
  data_command[0] = byte(4);
  data_command[1] = byte(limit_batterie_value);
  Serial.write(data_command, 7);

}



void get_limit_qtr(OSCMessage &msg) {


  data_command[0] = byte(5);
  Serial.write(data_command, 7);

}

void get_limit_sonar(OSCMessage &msg) {


  data_command[0] = byte(6);
  Serial.write(data_command, 7);

}

void get_limit_batterie(OSCMessage &msg) {


  data_command[0] = byte(7);
  Serial.write(data_command, 7);

}



void lost(OSCMessage &msg) {


  data_command[0] = byte(100);
  Serial.write(data_command, 7);

}

void home(OSCMessage &msg) {


  data_command[0] = byte(101);
  Serial.write(data_command, 7);

}

void go(OSCMessage &msg) {

  int X_grid = msg.getInt(0);
  int X_float = msg.getInt(1);
  int Y_grid = msg.getInt(2);
  int Y_float = msg.getInt(3);

  data_command[0] = byte(102);
  data_command[1] = byte(X_grid);
  data_command[2] = byte(X_float);
  data_command[3] = byte(Y_grid);
  data_command[4] = byte(Y_float);
  Serial.write(data_command, 7);

}


void rec(OSCMessage &msg) {

  int rec_ok = msg.getInt(0);

  data_command[0] = byte(103);
  data_command[1] = byte(rec_ok);
  Serial.write(data_command, 7);

}


void play_sd(OSCMessage &msg) {


  int play_ok = msg.getInt(0);

  data_command[0] = byte(104);
  data_command[1] = byte(play_ok);
  Serial.write(data_command, 7);

}



void copain_base(OSCMessage &msg) {


  

  data_command[0] = byte(105);
  data_command[1] = byte(1);
  Serial.write(data_command, 7);

}



void led(OSCMessage &msg) {


  int led_value = msg.getInt(0);

  data_command[0] = byte(8);
  data_command[1] = byte(led_value);

  Serial.write(data_command, 7);


}
