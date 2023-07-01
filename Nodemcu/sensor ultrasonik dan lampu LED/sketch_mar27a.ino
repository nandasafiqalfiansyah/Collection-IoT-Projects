// Deklarasi pin untuk sensor ultrasonik dan lampu LED
#define trigPin D2
#define echoPin D3
#define ledPin1 D4
#define ledPin2 D5

// Variabel untuk menyimpan jarak dan volume air
float volume;

void setup() {
  // Set pin untuk sensor ultrasonik dan lampu LED sebagai input/output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  // Baud rate Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Mengirimkan pulse ke pin trigger selama 10 us
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Menghitung waktu perjalanan gelombang suara
  int duration = pulseIn(echoPin, HIGH);
  
  // Menghitung jarak menggunakan waktu yang diperoleh
  float distance = duration * 0.034 / 2;
  
  // Menghitung volume air menggunakan rumus luas lingkaran x tinggi air
  float radius_bak = 4.00; // ukuran diameter bak air
  float tinggi_bak = 4.00; //ukuran tinggi bak


  volume = PI * radius_bak * radius_bak * (25 - distance) / 1000; // tinggi bak air adalah 25 cm

  //REVISI BY NANDA S A
  

  float tinggi_air = tinggi_bak - distance ; // tinggi air

  // float volume = radius_bak * tinggi_air;    // volume

  
  // Menyalakan LED 1 jika volume air kurang dari 5 liter
  if (tinggi_air < 1.00) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
  
  // Menyalakan LED 2 jika volume air lebih dari 10 liter
  if (tinggi_air > 1.25 ) {
    digitalWrite(ledPin2, HIGH);
  } else { 
    digitalWrite(ledPin2, LOW);
  }
  
  // Menampilkan jarak dan volume air di Serial Monitor
  Serial.print("Jarak:");
  Serial.print(distance);

  Serial.print("Jarak: ");
  Serial.print(tinggi_air);
  Serial.print(" cm,");

  Serial.print(" volume,");
  Serial.print(volume);
  Serial.println("liter");
  
  // Delay selama 3 detik sebelum membaca sensor kembali
  delay(3000);
}