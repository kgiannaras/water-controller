int c;
//PH
const int analogInPin = A15; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;
int phValue;

//HC-SR04
int x;
int y;
unsigned long int avgValue1;
unsigned long int avgValue2;
int buf1[10];
int buf2[10];
const int echoPin1 =22;
const int trigPin1 =23;
long duration1;
int distance1;
const int echoPin2 =34;
const int trigPin2 =35;
long duration2;
int distance2;
int tankfill1;
int tankfill2;
//water lever sensor analog input
int level_input=20; // analog input
//Relay
int Relay1 =45 ;
int Relay2 =46 ;
int Relay3 =47 ;
int Relay4 =48 ;
int Relay5 =49 ;
int Relay6 =50 ;
//led
int led1 =25 ;
int led2 =24 ;
int led3 =26 ;
int led4 =28 ;
int led5 =30 ;
int led6 =32 ;
//switch
int switch1 =A9;
int switch2 =A10;
int switch3 =A11;
int switch4 =A12;
int switch5 =A13;
int switch6 =A14;
#include <LiquidCrystal.h>
//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
int l;
void setup() {
  // put your setup code here, to run once:
 //lcd
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print("R.I.");
lcd.setCursor(5,0);
lcd.print("Tank1:");
 lcd.setCursor(0,1);
 lcd.print("Tank2:");
 //Relay
 pinMode(Relay1 , OUTPUT );
pinMode(Relay2 , OUTPUT );
 pinMode(Relay3 , OUTPUT );
//ph
pinMode(A15 , INPUT );
//hcsr
pinMode(trigPin1 , OUTPUT );
pinMode(trigPin2 , OUTPUT );
pinMode(echoPin1 , INPUT );
pinMode(echoPin2 , INPUT );
// water level
pinMode(level_input , INPUT);
//switch
pinMode(switch1 , INPUT);
pinMode(switch2 , INPUT);
pinMode(switch3 , INPUT);
pinMode(switch4 , INPUT);
pinMode(switch5 , INPUT);
pinMode(switch6 , INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 hcsr1(); //function level tank 1 (clean) tankfill1
 hcsr2(); //function level tank 2 (ojino) tankfill2

  //water lever sensor analog input 
 if(digitalRead(level_input) < HIGH{
  ph(); // function ph phValue
 if(phValue >= 7,2){
if ( c = 0 ) {
if(tankfill1 < 85){
 digitalWrite(Relay1 , LOW);
 digitalWrite(led1 , HIGH);
 }
 else{
 digitalWrite(Relay1 , HIGH);
  digitalWrite(led1 , LOW);
 }//end else
 }//end if c = 0
 }//end if 7,2+
 
 else{
  
 if(tankfill2 < 85){
 digitalWrite(Relay2 , LOW);
 digitalWrite(led2 , HIGH);
 }
 else{
 digitalWrite(Relay2 , HIGH);
 digitalWrite(led2 , LOW);
 }//end else
 
 }//end 7,2- 

 

 }// end if switch high

  

 /*
 if ( tankfill1 < 5) {

if(analogRead(level_input) > 200){
digitalWrite(Relay3 , LOW);
digitalWrite(led3 , HIGH);
}
else{
 digitalWrite(Relay3 , HIGH);
digitalWrite(led3 , LOW);
 }//end else
 }
 
 
 if ( tankfill2 < 5) {

if(analogRead(level_input) > 200){
digitalWrite(Relay3 , LOW);
digitalWrite(led3, HIGH);
}
else{
 digitalWrite(Relay3 , HIGH);
 digitalWrite(led3 , LOW);
 c = 1;
 }//end else
 }

if ( c = 1) {
  
  if ( tankfill2 < 85) {
    digitalWrite(Relay2 , LOW);
 digitalWrite(led2 , HIGH);
 }
 
 else{
 digitalWrite(Relay2 , HIGH);
 digitalWrite(led2 , LOW);
 c = 0;
 }//end else
 
  
}
 
*/
 lcd.setCursor(11,0);
 lcd.print(tankfill1);
 
 lcd.setCursor(14,0);
 lcd.print("%");

 /////////////////////////////////////////////////////
 
 
 lcd.setCursor(6,1);
 lcd.print(tankfill2);
 lcd.setCursor(9,1);
 lcd.print("%");

if (analogRead(switch1) < 200) {
  digitalWrite(Relay1 , HIGH);
  digitalWrite(led1 , HIGH);
}
 if (analogRead(switch2) < 200) {
  digitalWrite(Relay2 , HIGH);
  digitalWrite(led2 , HIGH);
}
  
}//end loop

 

void ph() {

for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 {
 avgValue+=buf[i];
 }
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 Serial.print("ph = ");
 Serial.println(phValue);
 
 delay(20);
return(phValue);
}
void hcsr1(){

for(int i=0;i<10;i++) 
 {
  digitalWrite(trigPin1, LOW);// Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin1, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);


  buf1[i]= pulseIn(echoPin1, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds 
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf1[i]>buf1[j])
   {
    temp=buf1[i];
    buf1[i]=buf1[j];
    buf1[j]=temp;
   }
  }
 }
 avgValue1=0;
 for(int i=2;i<8;i++)
 {
 avgValue1+=buf[i];
 }
 float distance1 =(float)avgValue1*0.034/2/6;
Serial.print("Distance1: ");// Prints the distance on the Serial Monitor
Serial.println(distance1); 

x =distance1/25*100;
tankfill1 = 100-x;

Serial.print("percentage fill1: ");
Serial.print(tankfill1); 
Serial.println("%");
delay(20);
return(tankfill1);
}//END HCSR1

void hcsr2(){
for(int i=0;i<10;i++) 
 {
  digitalWrite(trigPin2, LOW);// Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin2, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);


  buf2[i]= pulseIn(echoPin2, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds 
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf2[i]>buf2[j])
   {
    temp=buf2[i];
    buf2[i]=buf2[j];
    buf2[j]=temp;
   }
  }
 }
 avgValue2=0;
 for(int i=2;i<8;i++)
 {
 avgValue2+=buf[i];
 }
 float distance2 =(float)avgValue2*0.034/2/6;
Serial.print("Distance2: ");// Prints the distance on the Serial Monitor
Serial.println(distance2); 

x =distance2/25*100;
tankfill2 = 100-x;

Serial.print("percentage fill2: ");
Serial.print(tankfill2); 
Serial.println("%");

delay(20);
return(tankfill2);
}//HCSR2
