

#define echopin D2  //variabe echo pin memakai pin D2
#define trigpin D1  //variabe trigpin memakai pin D1
#define led1 D5     //variabe led1 memakai pin D5
#define led2 D6     //variabe led2 memakai pin D6
#define led3 D7     //variabe led3 memakai pin D7

void setup() {
  // put your setup code here, to run once;
 pinMode(echopin, INPUT);    //variabe echopin di pakai sebagai input
 pinMode(trigpin, OUTPUT);   //variabe trigpin di pakai sebagai output

 pinMode(led1, OUTPUT);     //variabe led1 di pakai sebagai output
 pinMode(led2, OUTPUT);     //variabe led2 di pakai sebagai output
 pinMode(led3, OUTPUT);     //variabe led3 di pakai sebagai output

 Serial.begin(9600);
 }


void loop() {
  // put your main code here, to run repeatedly:
float luas_alas = 6;    //variabe luas_alas bernilai 23.11
float tinggi_gelas = 5;  //variabe tinggi_gelas bernilai 3.16

digitalWrite(trigpin, LOW);  //memastika netral
delayMicroseconds(2);

digitalWrite(trigpin, HIGH); //memberi input
delayMicroseconds(10);

digitalWrite(trigpin, LOW);  //menerima input

int echotime = pulseIn(echopin, HIGH); //echotime bertipe data int 

float jarakpantul =  echotime * 0.034 / 2;    // jrak pantul
float tinggiair = tinggi_gelas - jarakpantul; // tinggi air
float volume = luas_alas * tinggiair;         // volume



//KELUARAN PROGRAM//


Serial.print("jarak permukaan : ");
Serial.print(jarakpantul);
Serial.print(" cm ");

Serial.print("tinggi permukaan : ");
Serial.print(tinggiair);
Serial.print(" cm ");

Serial.print("volume : ");
Serial.print(volume);
Serial.println(" cm3 ");

//PROGRAM IF UNTUK MENYALAHKAN LED 
/*
apabila tinggi air > 0.10 cm maka led 1 menyalah
apabila tinggi air > 1 cm maka led 2 menyalah
apabila tinggi air > 2 cm maka led 3 menyalah

*/

if(tinggiair > 0.10 )  
   {   
    digitalWrite(led1,HIGH);
   }   
  else   
   {   
   digitalWrite(led1,LOW);   
   }   
  if(tinggiair > 1.00 )   
   {   
   digitalWrite(led2,HIGH); 
   }  
   else   
   {   
   digitalWrite(led2,LOW);    
   }   
   if(tinggiair > 2.00 )   
   {  
   digitalWrite(led3,HIGH);  
   }  
   else  
   {  
   digitalWrite(led3,LOW);    
   }  
   Serial.println("");
   Serial.println("LEVEL KETINGGAN AIR");



  //PROGRAM IF UNTUK MENYALAHKAN LED 
  /*
  apabila tinggi air > 0.10 cm maka program menguarkan output Tinggi air tinggi III (bahaya)
  apabila tinggi air > 1 cm maka program menguarkan output Tinggi air sedang II (waspada)
  apabila tinggi air > 2 cm maka program menguarkan output Tinggi air rendah I  (siaga)

  */
   if(tinggiair > 2.00 ) {
    Serial.println("Tinggi air tinggi III (bahaya)");

   }else if (tinggiair > 1.00 ) {
     Serial.println("Tinggi air sedang II (waspada)");
   }
   else if (tinggiair > 0.10 ){ 
     Serial.println("Tinggi air rendah I  (siaga)"); 
   }

   else {
     Serial.println(" WADAH KOSONG ");
     Serial.println(" MOHON ISI AIR DI WADAH ");
   }

   Serial.println("=============================");

delay(3000);
}
