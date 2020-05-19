
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

int forwardPin = D0;  // Remote control movement pins
int reversePin = D1;
int rightPin = D2;
int leftPin = D3;

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}
void fw() {
  digitalWrite(forwardPin, HIGH);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, LOW);
  Serial.println("FW");
  server.send(200, "text/html", "<h1>You are connected</h1>");
}
void bw() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, HIGH);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, LOW);
  Serial.println("BW");
  server.send(200, "text/html", "<h1>You are connected</h1>");
}
void lt() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, HIGH);
  Serial.println("LT");
  server.send(200, "text/html", "<h1>You are connected</h1>");
}
void rt() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, HIGH);
  digitalWrite(leftPin, LOW);
  Serial.println("RT");
  server.send(200, "text/html", "<h1>You are connected</h1>");
}
void st() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, LOW);
  Serial.println("ST");
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {

	delay(1000);
	Serial.begin(9600);
	Serial.println();
	Serial.print("Configuring access point...");
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
  server.on("/forward", fw);
  server.on("/backward", bw);
  server.on("/left", lt);
  server.on("/right", rt);
  server.on("/stop", st);
	server.begin();
	Serial.println("HTTP server started");

  // Set movement pins as outputs
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  
// Set movement pins to low
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, LOW);
}

void loop() {
	server.handleClient();
}
