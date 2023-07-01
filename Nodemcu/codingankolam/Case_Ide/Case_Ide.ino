#include <OneWire.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include <DallasTemperature.h>

// Sensor jarak
#define trigpin D7
#define echopin D8

// Relay
#define relaypin1 D0
#define relaypin2 D1

// Sensor suhu air
#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Sensor DHT11
#define DHTPIN D6 // Pin where the DHT11 sensor is connected
DHT dht(DHTPIN, DHT11);

String apiKey = "TCTDBEBLHLK2NKCW"; // DISI API

// Wi-Fi credentials
const char *ssid = "pcy";
const char *pass = "12345678";
const char *server = "api.thingspeak.com";

// Variable for initial value
float tinggi_wadah = 50;

WiFiClient client;

void setup()
{
  Serial.begin(9600);
  pinMode(relaypin1, OUTPUT);
  pinMode(relaypin2, OUTPUT);

  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);

  dht.begin();
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  delay(4000);
}

void loop()
{
  // Sensor jarak
  digitalWrite(trigpin, LOW); // Memastikan kondisi netral
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH); // Mengirim input
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);                   // Menerima input
  int echotime = pulseIn(echopin, HIGH);        // Waktu echo dalam mikrodetik
  float jarakpantul = echotime * 0.034 / 2;     // Jarak pantul dalam cm
  float tinggiair = tinggi_wadah - jarakpantul; // Tinggi air dalam cm
  Serial.print("Tinggi permukaan: ");
  Serial.print(tinggiair);
  Serial.print(" cm");

  // Sensor suhu air
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print(" Suhu air: ");
  Serial.print(temperatureC);
  Serial.println("°C");

  // Sensor suhu dan kelembaban
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Kelembaban permukaan: ");
  Serial.print(h);
  Serial.print("%, Suhu permukaan: ");
  Serial.print(t);
  Serial.println("°C");

  // Kontrol relay suhu air
  Serial.println("RELAY SUHU AIR ");
  if (temperatureC > 0 && temperatureC < 30)
  {
    digitalWrite(relaypin1,HIGH);
    Serial.println("Pump 1 is OF");
  }else
  {
    digitalWrite(relaypin1, LOW);
    Serial.println("Pump 1 is ON");
  }
  

  // Kontrol relay tinggi air
  Serial.println("RELAY TINGGI AIR ");
  if (tinggiair > 0 && tinggiair <= 50)
  {
    digitalWrite(relaypin2, HIGH);
    Serial.println("Pump 2 is OFF");
  }
  else {
    digitalWrite(relaypin2, LOW);
    Serial.println("Pump 2 is ON");
  }
  

  // Sending data to ThingSpeak
  if (client.connect(server, 80))
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(temperatureC);
    postStr += "&field2=";
    postStr += String(h);
    postStr += "&field3=";
    postStr += String(t);
    postStr += "&field4=";
    postStr += String(tinggiair);

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
