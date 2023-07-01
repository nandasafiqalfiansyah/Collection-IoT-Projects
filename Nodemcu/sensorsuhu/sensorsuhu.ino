#include <ESP8266WiFi.h>
#include <Wire.h>
#include "DHT.h"

#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht11(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
      // memulai program dht11
  dht11.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  // Sensor DHT11 membaca suhu
  float t = dht11.readTemperature();
  float h = dht11.readHumidity();

   // Menampilkan suhu kepada serial monitor
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println();

//delay 5 detik
    delay(5000);
}
