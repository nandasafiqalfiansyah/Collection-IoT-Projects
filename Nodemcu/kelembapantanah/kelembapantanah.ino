
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>


int sensorPin = A0; // Pin analog untuk sensor kelembapan tanah
int moistureValue = 0;

String apiKey = "KBO0FKK95ZHGVHUA";

const char *ssid = "test";
const char *pass = "18181818";
const char *server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, pass);
  // put your setup code here, to run once:
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  delay(4000);

}

void loop() {

  moistureValue = analogRead(sensorPin); // Membaca nilai analog dari sensor kelembapan

  Serial.print("Kelembapan Tanah: ");
  Serial.println(moistureValue);
  
  // Sending data to ThingSpeak
  if (client.connect(server, 80))
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(moistureValue);
    

    postStr += "\r\n\r\n\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\r\n\r\n");
    client.print(postStr);
  }
  client.stop();
  Serial.println("Waiting...");
  delay(1500);

}
