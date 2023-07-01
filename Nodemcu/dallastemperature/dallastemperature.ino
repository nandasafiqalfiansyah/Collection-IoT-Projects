#include <OneWire.h>
#include <DallasTemperature.h>

// Pin data yang digunakan untuk menghubungkan sensor suhu
#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);

  Serial.print("Suhu Celsius: ");
  Serial.print(temperatureC);
  Serial.print("°C");

  Serial.print("   Suhu Fahrenheit: ");
  Serial.print(temperatureF);
  Serial.println("°F");

  delay(1000); // Delay 1 detik antara pembacaan suhu
}

