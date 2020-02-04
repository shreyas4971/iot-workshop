// dobz --> server and client librarys
#include<ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include<WiFiClient.h>

#include "index.h"
const char* ssid = "ISRO";
const char* password = "bk#bk9898";



ESP8266WebServer server(80);

void handleRoot(){
  String s = MAIN_page;
  server.send(200, "text/html", s);
  }

void handleADC() {
 int a = analogRead(A0);
 String adcValue = String(a);
 
 server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
}

void setup() {
  pinMode(A0, INPUT);
  delay(500);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
 
  server.on("/", handleRoot);
  server.on("/readADC", handleADC);
  server.begin();
  Serial.println("Web Server is Satrted");
  
  
}

void loop() {
  server.handleClient();

}
