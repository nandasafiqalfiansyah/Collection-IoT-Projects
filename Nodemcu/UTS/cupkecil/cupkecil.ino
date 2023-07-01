//PENJELASAN PROGRAM 

//MENGGUNAKAN CUP KECIL 5 X 5.5
/*
DELAY 3 DETIK

TINGGI 2 cm
SEDANG 1 cm
RENDAH 0.10 cm

*/

const int trigpin = D7;
const int echopin = D8;
const int ledPin1 = D2;
const int ledPin2 = D3;
const int ledPin3 = D4;

void setup() {
  
 pinMode(echopin, INPUT);    //variabe echopin di pakai sebagai input
 pinMode(trigpin, OUTPUT);   //variabe trigpin di pakai sebagai output

 pinMode(ledPin1, OUTPUT);     //variabe led1 di pakai sebagai output
 pinMode(ledPin2, OUTPUT);     //variabe led2 di pakai sebagai output
 pinMode(ledPin3, OUTPUT);     //variabe led3 di pakai sebagai output

 Serial.begin(9600);  // memulai komunikasi serial dengan baud rate 9600
 }


void loop() {

//INPUT USER

//PANJANG ALAS
float alas = 5; 

//TINGGI CUP KECIL
float tinggi_gelas = 5.5; 


float jari = 0.5 * alas; // mencari jari jari
float jari_jari = jari * jari ; //jari jari kali jari jari
float luas_alas = 3.14 * jari_jari; //A = πr^2 mencari alas gelas lingkaran 

digitalWrite(trigpin, LOW);  //memastika netral
delayMicroseconds(2);

digitalWrite(trigpin, HIGH); //memberi input
delayMicroseconds(10);

digitalWrite(trigpin, LOW);  //menerima input

int echotime = pulseIn(echopin, HIGH); //echotime bertipe data int 

float jarakpantul =  echotime * 0.034 / 2;    // jrak pantul
float tinggiair = tinggi_gelas - jarakpantul; // tinggi air

float volume = luas_alas ;// volume air



//KELUARAN PROGRAM//
Serial.println(" PEROGRAM PENGUKURAN TINGGI VOLUME JARAK PANTUL MENGGUNAKAN CUP KECIL 5 X 5.5 ");

Serial.print("jarak permukaan : ");
Serial.print(jarakpantul);
Serial.print(" cm ");

Serial.print("tinggi permukaan : ");
Serial.print(tinggiair);
Serial.print(" cm ");

Serial.print("volume : ");
Serial.print(volume);
Serial.println(" cm3 ");


if (tinggiair > 2) {

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air TINGGI ");
  } else if (tinggiair > 1) {

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air SEDANG ");
  } else if (tinggiair > 0.10) {

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    Serial.println("Tinggi air RENDAH ");
  } else {

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air terlalu rendah");
  }

  Serial.println(" ");
delay(3000);
}

