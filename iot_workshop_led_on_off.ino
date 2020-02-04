#include<ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include<WiFiClient.h>

#include "index.h"
#define LED 2
const char* ssid = "ISRO";
const char* password = "bk#bk9898";

ESP8266WebServer server(80);

void handleRoot(){
  String s = MAIN_page;
  server.send(200, "text/html", s);
 }
void handleLEDon() { 
 String s = MAIN_page;
 digitalWrite(LED,LOW);
 server.send(200, "text/html", s);
}
 
void handleLEDoff() { 
 String s = MAIN_page;
 digitalWrite(LED,HIGH); 
 server.send(200, "text/html", s);
}

void setup() {
  pinMode(LED, OUTPUT);
  delay(500);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
    }
  Serial.println("Connected to ...");
  Serial.println(ssid);
  Serial.println(" Server Started on ip  ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/ledOn", handleLEDon); 
  server.on("/ledOff", handleLEDoff);
  server.begin();
  Serial.println("Server is Started waiting for client");
  
  
}

void loop() {
    server.handleClient();
}
