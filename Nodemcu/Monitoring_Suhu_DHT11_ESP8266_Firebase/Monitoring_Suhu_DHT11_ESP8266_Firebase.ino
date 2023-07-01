// Library yang dibutuhkan
#include "DHT.h"
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

// Mendefinisikan pin dan tipe sensor DHT
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht11(DHTPIN, DHTTYPE);

// Isikan sesuai pada Firebase
#define FIREBASE_HOST "https://agrolink-b98ed-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyDz2p26Xy5ujcmnYyxpUOSOPCtAgTLFpbY"

//Nama Wifi
#define WIFI_SSID "Yogi wifi"
#define WIFI_PASSWORD "albet123"  

// mendeklarasikan objek data dari FirebaseESP8266
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  
  // koneksi wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("menghubungkan ke wifi tunggu sebentar yha😊");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("wifi terhubung👌dengan ip : ");
  Serial.print(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  dht11.begin();
}

void loop(){
  
  // Sensor DHT11 membaca suhu dan kelembaban
  float t = dht11.readTemperature();
  float h = dht11.readHumidity();

  float tinggiair = 13;

  // Memeriksa apakah sensor berhasil mambaca suhu dan kelembaban
  if (isnan(t) || isnan(h)) {
    Serial.println("Gagal membaca sensor DHT11");
    delay(1000);
    return;
  }

  // Menampilkan suhu dan kelembaban kepada serial monitor
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println();

  // Memberikan status suhu dan kelembaban kepada firebase
  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/suhu", t)){
      Serial.println("Suhu terkirim");
    } else{
      Serial.println("Suhu tidak terkirim");
      Serial.println("Karena: " + firebaseData.errorReason());
    } 
    
  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/kelembapan", h)){
      Serial.println("Kelembaban terkirim");
      Serial.println();
    } else{
      Serial.println("Kelembaban tidak terkirim");
      Serial.println("Karena: " + firebaseData.errorReason());
    }

    if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/tinggiair", tinggiair)){
      Serial.println("tinggi air terkirim");
      Serial.println();
    } else{
      Serial.println("tinggi air tidak terkirim");
      Serial.println("Karena: " + firebaseData.errorReason());
    }
    
  delay(1000);
}
