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
const int echoPin1 =23;
const int trigPin1 =22;
long duration1;
int distance1;
const int echoPin2 =34;
const int trigPin2 =35;
long duration2;
int distance2;
int tankfill1;
int tankfill2;
//water lever sensor analog input
int level_input=21; // analog input
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
int delayDisplay = 2000;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 //lcd
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print("Process:");
 lcd.setCursor(0,1);
 lcd.print("Initialazition");
 delay(delayDisplay);
 lcd.setCursor(0,1);
 lcd.print("                 ");
 
 //Relay
 
 pinMode(Relay1 , OUTPUT );
 pinMode(Relay2 , OUTPUT );
 pinMode(Relay3 , OUTPUT );
 pinMode(Relay4 , OUTPUT );
 pinMode(Relay5 , OUTPUT );
 pinMode(Relay6 , OUTPUT );

 digitalWrite(Relay1 , HIGH);
  digitalWrite(Relay2 , HIGH);
  digitalWrite(Relay3 , HIGH);
  digitalWrite(Relay4 , HIGH);
  digitalWrite(Relay5 , HIGH);
  digitalWrite(Relay6 , HIGH);
 delay(1000);
 
 lcd.setCursor(9,0);
 lcd.print("Relay");
 delay(delayDisplay);
 digitalWrite(Relay6 , LOW);
 delay(1000);
 digitalWrite(Relay6 , HIGH);
 delay(1000);
 lcd.setCursor(9,0);
 lcd.print("                 ");

  


//ph
 
pinMode(A15 , INPUT );
 lcd.setCursor(9,0);
 lcd.print("Ph");
 delay(delayDisplay);

 ph();
 if ((phValue >= 0) && (phValue <= 0)){
   lcd.setCursor(0,1);
 lcd.print("Test ok");
 delay(delayDisplay);
 }
 else{
   lcd.setCursor(0,1);
 lcd.print("Test fail");
  delay(delayDisplay);
 }
 lcd.setCursor(9,0);
 lcd.print("                 ");
   lcd.setCursor(0,1);
 lcd.print("                 ");

//hcsr1
 lcd.setCursor(9,0);
 lcd.print(" Hcsr-C");
 delay(delayDisplay);

pinMode(trigPin1 , OUTPUT );
pinMode(echoPin1 , INPUT );
hcsr1();
if ( (tankfill1 >= 0) && (tankfill1 <=100)){
   lcd.setCursor(0,1);
 lcd.print("Test ok");
 delay(delayDisplay);
}
else{
  lcd.setCursor(0,1);
 lcd.print("Test Fail");
 delay(delayDisplay);
}
 lcd.setCursor(9,0);
 lcd.print("                 ");
   lcd.setCursor(0,1);
 lcd.print("                 ");
//hcsr2
 lcd.setCursor(9,0);
 lcd.print("Hcsr-O");
 delay(delayDisplay);
 
pinMode(trigPin2 , OUTPUT );
pinMode(echoPin2 , INPUT );
hcsr2();
if ( (tankfill2 >= 0) && (tankfill2 <=100)){
   lcd.setCursor(0,1);
 lcd.print("Test ok");
 delay(delayDisplay);
 lcd.setCursor(0,1);
 lcd.print("                 ");
}
else{
  lcd.setCursor(0,1);
 lcd.print("Test Fail");
 delay(delayDisplay);
}
 lcd.setCursor(9,0);
 lcd.print("                 ");
   lcd.setCursor(0,1);
 lcd.print("                 ");


// water level
 lcd.setCursor(8,0);
 lcd.print("Waterlevel");
 delay(delayDisplay);
 
pinMode(level_input , INPUT);
if(digitalRead(level_input) == LOW){
   lcd.setCursor(0,1);
 lcd.print("State:Close");
 delay(delayDisplay);
}
else{
  lcd.setCursor(0,1);
 lcd.print("State:Open");
 delay(delayDisplay);
}
lcd.setCursor(8,0);
 lcd.print("                 ");
lcd.setCursor(0,1);
 lcd.print("                 ");

//switch
lcd.setCursor(8,0);
 lcd.print("Switches");
 delay(delayDisplay);
pinMode(switch1 , INPUT);
pinMode(switch2 , INPUT);
pinMode(switch3 , INPUT);
pinMode(switch4 , INPUT);
pinMode(switch5 , INPUT);
pinMode(switch6 , INPUT);

if ((analogRead(switch1) > 800) && (analogRead(switch2) > 800) && (analogRead(switch3) > 800) && (analogRead(switch4) > 800) && (analogRead(switch5) > 800) && (analogRead(switch6) > 800)) {

 lcd.setCursor(0,1);
 lcd.print("Test ok");
 delay(delayDisplay);
}
else{
  lcd.setCursor(0,1);
 lcd.print("Test fail");
 delay(delayDisplay);
}
lcd.setCursor(8,0);
 lcd.print("                 ");
lcd.setCursor(0,1);
 lcd.print("                 ");

//led
lcd.setCursor(0,1);
 lcd.print("Leds");
 delay(delayDisplay);
 lcd.setCursor(0,1);
 lcd.print("                 ");
pinMode(led1 , INPUT);
pinMode(led2 , INPUT);
pinMode(led3 , INPUT);
pinMode(led4 , INPUT);
pinMode(led5 , INPUT);
pinMode(led6 , INPUT);
  
digitalWrite(led1 , HIGH);
digitalWrite(led2 , HIGH);
digitalWrite(led3 , HIGH);
digitalWrite(led4 , HIGH);
digitalWrite(led5 , HIGH);
digitalWrite(led6 , HIGH);
delay(1000);

digitalWrite(led1 , LOW);
digitalWrite(led2 , LOW);
digitalWrite(led3 , LOW);
digitalWrite(led4 , LOW);
digitalWrite(led5 , LOW);
digitalWrite(led6 , LOW);
delay(1000);

lcd.setCursor(0,1);
 lcd.print("Init done");
 delay(delayDisplay);


Serial.println("ready");
}


void loop() {


  
  // put your main code here, to run repeatedly:
 hcsr1(); //function level tank 1 (clean) tankfill1
 hcsr2(); //function level tank 2 (ojino) tankfill2

lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Tank-C:");
 lcd.setCursor(7,0);
 lcd.print(tankfill1);
 lcd.setCursor(10,0);
 lcd.print("%");

  lcd.setCursor(0,1);
 lcd.print("Tank-O:");
 lcd.setCursor(7,1);
 lcd.print(tankfill2);
 lcd.setCursor(10,1);
 lcd.print("%");
 delay(delayDisplay);

 
  //water lever sensor analog input 
  lcd.clear();
// lcd.setCursor(0,0);
 lcd.print("Water Level");
  delay(delayDisplay);
 
 if(digitalRead(level_input) == LOW){
   lcd.setCursor(0,1);
 lcd.print("State:Closed");
  delay(delayDisplay);
  lcd.clear();
  ph(); // function ph phValue
  lcd.setCursor(0,1);
lcd.print("phValue:");
lcd.setCursor(8,1);
lcd.print(phValue);
delay(delayDisplay);
 lcd.clear();
 if(phValue >= 7,2){
//if ( c = 0 ) {
if(tankfill1 < 85){
 digitalWrite(Relay1 , LOW);
 digitalWrite(led1 , HIGH);
 }
 else{
 digitalWrite(Relay1 , HIGH);
  digitalWrite(led1 , LOW);
 }//end else
 //}//end if c = 0
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

 

 }// end if switch low
else{
  lcd.setCursor(0,1);
  lcd.print("State:Open");
  delay(delayDisplay);
  lcd.clear();
}//end else
  

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


 
if (analogRead(switch1) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch1 close");
 lcd.setCursor(0,1);
 lcd.print("Fill Tank-C");
  digitalWrite(Relay1 , LOW);
  digitalWrite(led1 , HIGH); 
}
else{
  digitalWrite(Relay1 , HIGH);
  digitalWrite(led1 , LOW);
}
 
 
 
 if (analogRead(switch2) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch2 close");
 lcd.setCursor(0,1);
 lcd.print("Fill Tank-O");
  digitalWrite(Relay2 , LOW);
  digitalWrite(led2 , HIGH); 
}
else{
  digitalWrite(Relay2 , HIGH);
  digitalWrite(led2 , LOW);
}
if (analogRead(switch3) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch3 close");
  digitalWrite(Relay3 , LOW);
  digitalWrite(led3 , HIGH); 
}
else{
  digitalWrite(Relay3 , HIGH);
  digitalWrite(led3 , LOW);
}

if (analogRead(switch4) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch4 close");
  digitalWrite(Relay4 , LOW);
  digitalWrite(led4 , HIGH); 
}
else{
  digitalWrite(Relay4 , HIGH);
  digitalWrite(led4 , LOW);
}
if (analogRead(switch5) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch5 close");
  digitalWrite(Relay5 , LOW);
  digitalWrite(led5 , HIGH); 
}
else{
  digitalWrite(Relay5 , HIGH);
  digitalWrite(led5 , LOW);
}
if (analogRead(switch6) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("Switch6 close");
  digitalWrite(Relay6 , LOW);
  digitalWrite(led6 , HIGH); 
}
else{
  digitalWrite(Relay6 , HIGH);
  digitalWrite(led6 , LOW);
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
Serial.print("Distance1 C: ");// Prints the distance on the Serial Monitor
Serial.println(distance1); 

x =distance1/25*100;
tankfill1 = 100-x;

Serial.print("percentage fill1 C: ");
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
Serial.print("Distance2 O: ");// Prints the distance on the Serial Monitor
Serial.println(distance2); 

x =distance2/25*100;
tankfill2 = 100-x;

Serial.print("percentage fill2 O: ");
Serial.print(tankfill2); 
Serial.println("%");



delay(20);
return(tankfill2);
}//HCSR2
