#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#define spd1 2
#define spd2 14
#define spd3 12
#define spd4 13

#define forward 16
#define backward 5
#define left 4
#define right 0

String command; //wifi command store

const char* ssid = "Make DIY";
ESP8266WebServer server(80);


void setup() {
 
 pinMode(forward, OUTPUT);
 pinMode(backward, OUTPUT);  
 pinMode(left, OUTPUT);
 pinMode(right, OUTPUT);
  
  Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void goAhead(){
  digitalWrite(forward, HIGH);
}
void goBack(){
  digitalWrite(backward, HIGH);
}
void goLeft(){
  digitalWrite(left, HIGH);
}
void goRight(){
  digitalWrite(right, HIGH);
}

void loop() {
    server.handleClient();
    
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else{
        digitalWrite(16, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(0, LOW);
      }
      //else if (command == "I") goAheadRight();
      //else if (command == "G") goAheadLeft();
      //else if (command == "J") goBackRight();
      //else if (command == "H") goBackLeft();
      //else if (command == "0") speedCar = 400;
      //else if (command == "1") speedCar = 470;
      //else if (command == "2") speedCar = 540;
      //else if (command == "3") speedCar = 610;
      //else if (command == "4") speedCar = 680;
      //else if (command == "5") speedCar = 750;
      //else if (command == "6") speedCar = 820;
      //else if (command == "7") speedCar = 890;
      //else if (command == "8") speedCar = 960;
      //else if (command == "9") speedCar = 1023;
      //else if (command == "S") stopRobot();

      
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
