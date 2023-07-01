
// deklarasi pin
const int trigPin = D7;
const int echoPin = D8;
const int relay = D2;

// deklarasi variabel
long duration;
int distance;

void setup() {
  // inisialisasi pin
  pinMode(relay, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // memulai komunikasi serial
  Serial.begin(9600);
}

void loop() {
  // mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // menghitung durasi sinyal pantul
  duration = pulseIn(echoPin, HIGH);

  // menghitung jarak
  distance = (duration / 2) /29.1;

  // menampilkan hasil ke serial monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  //relay
  if (distance >=5){
    digitalWrite(relay,LOW);
  }else{
    digitalWrite(relay,HIGH);
  }

  // delay 500 milidetik sebelum mengulang
  delay(1000);
}
