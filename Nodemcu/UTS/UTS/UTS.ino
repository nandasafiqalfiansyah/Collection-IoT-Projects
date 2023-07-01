//PENJELASAN PROGRAM 

//MENGGUNAKAN GELAS 5 X 12 
/*
DELAY 3 DETIK
TINGGI 7
SEDANG 4
RENDAH 0.10
*/
//MENGGUNAKAN CUP KECIL 5 X 5.5
/*
DELAY 3 DETIK
TINGGI 1.5 cm
SEDANG 1 cm
RENDAH 0.10 cm
*/
//MENGGUNAKAN TIMBA 18 X 50
/*
DELAY 3 DETIK
TINGGI 20 cm
SEDANG 10 cm
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

//INPUT USER MENGGUNAKAN GELAS 5 X 12 
//PANJANG ALAS
float alas = 5; 
//TINGGI GELAS
float tinggi_gelas = 12; 

float jari = 0.5 * alas; // mencari jari jari
float jari_jari = jari * jari ; //jari jari kali jari jari
float luas_alas = 3.14 * jari_jari; //A = πr^2 mencari alas gelas lingkaran 

//INPUT USER MENGGUNAKAN CUP KECIL 5 X 5.5
//PANJANG ALAS
float alas2 = 5; 
//TINGGI CUP
float tinggi_gelas2 = 5.5; 

float jari2 = 0.5 * alas2; // mencari jari jari
float jari_jari2 = jari2 * jari2 ; //jari jari kali jari jari
float luas_alas2 = 3.14 * jari_jari2; //A = πr^2 mencari alas gelas lingkaran 


//INPUT USER MENGGUNAKAN TIMBA 17 X 19
//PANJANG ALAS
float alas3 = 17.5; 
//TINGGI TIMBA
float tinggi_gelas3 = 19; 
float jari3 = 0.5 * alas3; // mencari jari jari
float jari_jari3 = jari3 * jari3 ; //jari jari kali jari jari
float luas_alas3 = 3.14 * jari_jari3; //A = πr^2 mencari alas gelas lingkaran 


digitalWrite(trigpin, LOW);  //memastika netral
delayMicroseconds(2);

digitalWrite(trigpin, HIGH); //memberi input
delayMicroseconds(10);

digitalWrite(trigpin, LOW);  //menerima input

int echotime = pulseIn(echopin, HIGH); //echotime bertipe data int 

//MENGGUNAKAN GELAS 5 X 12 
float jarakpantul =  echotime * 0.034 / 2;    // jrak pantul
float tinggiair = tinggi_gelas - jarakpantul; // tinggi air
float volume = luas_alas ;// volume air

//MENGGUNAKAN CUP KECIL 5 X 5.5
float jarakpantul2 =  echotime * 0.034 / 2;    // jrak pantul
float tinggiair2 = tinggi_gelas2 - jarakpantul2; // tinggi air
float volume2 = luas_alas2 ;// volume air

//MENGGUNAKAN TIMBA 30 X 50
float jarakpantul3 =  echotime * 0.034 / 2;    // jrak pantul
float tinggiair3 = tinggi_gelas3 - jarakpantul3; // tinggi air
float volume3 = luas_alas3 ;// volume air

//KELUARAN PROGRAM //MENGGUNAKAN GELAS 5 X 12 
Serial.println(" PEROGRAM PENGUKURAN TINGGI VOLUME JARAK PANTUL MENGGUNAKAN GELAS 5 X 12 ");

Serial.print("jarak permukaan : ");
Serial.print(jarakpantul);
Serial.print(" cm ");

Serial.print("tinggi permukaan : ");
Serial.print(tinggiair);
Serial.print(" cm ");

Serial.print("volume : ");
Serial.print(volume);
Serial.println(" cm3 ");


if (tinggiair > 7) {

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air TINGGI ");
  } else if (tinggiair > 4) {

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

 //KELUARAN PROGRAM  //MENGGUNAKAN CUP KECIL 5 X 5.5

 Serial.println(" PEROGRAM PENGUKURAN TINGGI VOLUME JARAK PANTUL MENGGUNAKAN CUP KECIL 5 X 5.5 ");

Serial.print("jarak permukaan : ");
Serial.print(jarakpantul2);
Serial.print(" cm ");

Serial.print("tinggi permukaan : ");
Serial.print(tinggiair2);
Serial.print(" cm ");

Serial.print("volume : ");
Serial.print(volume2);
Serial.println(" cm3 ");


if (tinggiair2 > 2) {

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air TINGGI ");
  } else if (tinggiair2 > 1) {

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air SEDANG ");
  } else if (tinggiair2 > 0.10) {

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

// KELUARAN PROGRAM MENGGUNAKAN TIMBA 30 X 50
Serial.println(" PEROGRAM PENGUKURAN TINGGI VOLUME JARAK PANTUL MENGGUNAKAN TIMBA 17 X 19 ");

Serial.print("jarak permukaan : ");
Serial.print(jarakpantul3);
Serial.print(" cm ");

Serial.print("tinggi permukaan : ");
Serial.print(tinggiair3);
Serial.print(" cm ");

Serial.print("volume : ");
Serial.print(volume3);
Serial.println(" cm3 ");


if (tinggiair3 > 12) {

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air TINGGI ");
  } else if (tinggiair3 > 7) {

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("Tinggi air SEDANG ");
  } else if (tinggiair3 > 0.10) {

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

