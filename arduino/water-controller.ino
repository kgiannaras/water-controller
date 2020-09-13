//step motor
#include <Stepper.h>
const int stepsPerRevolution = 200;
const int axisStep = 1600;
Stepper myStepper(stepsPerRevolution, 15, 16, 17, 18);
int endstop = 14;
//hw-103
const int analogHw = A8; 
int soilMoisture;
int buf4[10];
int avgValue4;
int v;
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
int z;
unsigned long int avgValue1;
unsigned long int avgValue2;
unsigned long int avgValue3;
int buf1[10];
int buf2[10];
int buf3[10];
const int echoPin1 =23;
const int trigPin1 =22;
long duration1;
int distance1;
const int echoPin2 =34;
const int trigPin2 =35;
long duration2;
int distance2;
const int echoPin3 = 20;
const int trigPin3 =19;
long duration3;
int distance3;
int tankfill1; //pososto stathmis neroy tank clear
int tankfill2;
int tankfill3;
int delayHcsr = 10;
//water lever sensor analog input
int level_input=21; // analog input
//Relay
int Relay1 =45 ;// hlektrobana k
int Relay2 =46 ;// hlektrobana o
int Relay3 =47 ;// potisma
int Relay4 =48 ;// antlia k
int Relay5 =49 ;// keno
int Relay6 =50 ;// antlia e
int Relay7 =51;
int Relay8 =52;
int a = 0;
int g = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
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
int delayDisplay = 1000;
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
 pinMode(Relay7 , OUTPUT );
 pinMode(Relay8 , OUTPUT );

 digitalWrite(Relay1 , HIGH);
 digitalWrite(Relay2 , HIGH);
 digitalWrite(Relay3 , HIGH);
 digitalWrite(Relay4 , HIGH);
 digitalWrite(Relay5 , HIGH);
 digitalWrite(Relay6 , HIGH);
 digitalWrite(Relay7 , HIGH);
 digitalWrite(Relay8 , HIGH);
 delay(1000);
 
 lcd.setCursor(9,0);
 lcd.print("Relay");
 delay(delayDisplay);
 digitalWrite(Relay8 , LOW);
 delay(1000);
 digitalWrite(Relay8 , HIGH);
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

//hcsr1 test
 lcd.setCursor(9,0);
 lcd.print(" Hcsr-C");
 delay(delayDisplay);

pinMode(trigPin1 , OUTPUT );
pinMode(echoPin1 , INPUT );
hcsr1();
if ( (tankfill1 >= 0) && (tankfill1 <=100) ){
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

//hcsr3
 lcd.setCursor(9,0);
 lcd.print("Hcsr-E");
 delay(delayDisplay);
 
pinMode(trigPin3 , OUTPUT );
pinMode(echoPin3 , INPUT );
hcsr3();
if ( (tankfill3 >= 0) && (tankfill3 <=100)){
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

//hw103
  lcd.setCursor(8,0);
  lcd.print("Hw-103");
  delay(delayDisplay);
  pinMode(analogHw,INPUT);

hw103();
if((soilMoisture >= 0) && (soilMoisture <= 100)){
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
//STEP MOTOR
  myStepper.setSpeed(60);
  pinMode(endstop,INPUT);
  lcd.setCursor(9,0);
 lcd.print("Step Motor");
 stepperhome();
 steppermotor();
 lcd.clear();
 lcd.print("Process:");
 lcd.setCursor(9,0);
 lcd.print("               ");

//init done
  lcd.setCursor(0,1);
  lcd.print("Init done");
  delay(delayDisplay);


  Serial.println("ready");
  }//end setup


void loop() {
 
  // put your main code here, to run repeatedly:
 hcsr1(); //function level tank 1 (clean) tankfill1
 hcsr2(); //function level tank 2 (ojino) tankfill2
 hcsr3(); //function level tank 3 (elegxoy) tankfill3
 
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

 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tank-E:");
  lcd.setCursor(7,0);
  lcd.print(tankfill3);
  lcd.setCursor(10,0);
  lcd.print("%");
  delay(delayDisplay);

  //water lever sensor analog input 
  lcd.clear();
// lcd.setCursor(0,0);
   lcd.print("Water Level");
   delay(delayDisplay);
 

 
 if(digitalRead(level_input) == LOW){// check water level
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
 
 
 if(phValue >= 6,9) {// check ph
  lcd.clear();
  if((tankfill1 <= 70) && (tankfill3 >= 30)){
    digitalWrite(Relay1 , LOW);
  digitalWrite(led1 , HIGH);
  delay(500);
  digitalWrite(Relay4 , LOW);
 

   lcd.setCursor(0,0);
   lcd.print("Filling Tank-C");
   lcd.setCursor(0,1);
   lcd.print("Tank-E:");
   lcd.setCursor(7,1);
   lcd.print("   ");  
   lcd.setCursor(7,1);
   lcd.print(tankfill3);
   lcd.setCursor(10,1);
   lcd.print("%");
  
  while((tankfill1 <= 70) && (tankfill3 >= 30)){
  hcsr1;
  hcsr3;
  
 }
  }
  digitalWrite(Relay1 , HIGH);
  digitalWrite(led1 , LOW);
  delay(500);
  digitalWrite(Relay4 , LOW);

  delay(500);
 
 }//end if ph +7,2


 
 if(phValue < 6,9) {// check ph
    lcd.clear();
if((tankfill2 <= 70) && (tankfill3 >= 30)){
 digitalWrite(Relay2,LOW);
 digitalWrite(led2,HIGH);
   
  lcd.setCursor(0,0);
  lcd.print("Filling Tank-O");
  lcd.setCursor(0,1);
  lcd.print("Tank-E:");
  lcd.setCursor(7,1);
  lcd.print("   ");
  lcd.setCursor(7,1);
  lcd.print(tankfill3);
  lcd.setCursor(10,1);
  lcd.print("%");
  delay(delayDisplay);
   }//end if
 else{
  digitalWrite(Relay2,HIGH);
  digitalWrite(led2,LOW);
  delay(500);
 }
 }//end if ph -7,2

 

 }// end if switch low

 
else{//water level open
  lcd.setCursor(0,1);
  lcd.print("State:Open");
  delay(delayDisplay);


 if(digitalRead(Relay2) == LOW){
 if ((tankfill2 >= 70) || (tankfill3 >= 30)){
   digitalWrite(Relay2,HIGH);
   digitalWrite(led2,LOW);
  }
 }

 }//end else
 
hw103(); //function plant soilmoisture
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Soil Humidity:");
lcd.setCursor(0,1);
lcd.print(soilMoisture);
lcd.setCursor(3,1);
lcd.print("%");
delay(delayDisplay);
 
 if((soilMoisture <= 30) && (tankfill1 >= 30)){//potisma
  stepperhome();
   if((soilMoisture <= 50) || (tankfill1 >= 30)){
    lcd.clear();
    digitalWrite(Relay3,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(Relay5 , LOW);
    lcd.print("Tank-O:");
    lcd.setCursor(7,0);
    lcd.print("   ");
    lcd.setCursor(7,0);
    lcd.print(tankfill1 );
    lcd.setCursor(10,0);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Watering Plant");
   
  while((soilMoisture <= 50) || (tankfill1 >= 30)){
    hcsr1();
   steppermotor();
    
}
   }
 }
 //klisimo potisma
 digitalWrite(Relay3,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(Relay5 ,HIGH);
     
  




//anoigma fill clean
if( analogRead(switch1) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch1 close");
  lcd.setCursor(0,1);
  lcd.print("Fill Tank-C");
  delay(delayDisplay);
  digitalWrite(Relay1 , LOW);
  digitalWrite(led1 , HIGH); 
  delay(500);
  digitalWrite(Relay4 , LOW);
 
//klisimo fill clean
//Serial.print("tankfill1=");
//Serial.println(tankfill1);
if (digitalRead(Relay1) == LOW){
  if((tankfill1 >= 70) || (tankfill3 <= 30)){
    
    digitalWrite(Relay1,HIGH);
    digitalWrite(led1,LOW);
    delay(500);
    digitalWrite(Relay4,HIGH);
  }
}
a =1;
}
else{
  if(a ==1){
     digitalWrite(Relay1,HIGH);
     digitalWrite(led1,LOW);
     delay(500);
     digitalWrite(Relay4,HIGH);
     a = 0;
  }
}

if( analogRead(switch2) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch2 close");
  lcd.setCursor(0,1);
  lcd.print("Fill Tank-O");
  delay(delayDisplay);
  digitalWrite(Relay2 , LOW);
  digitalWrite(led2 , HIGH); 

if (digitalRead(Relay2) == LOW){
  if((tankfill2 >= 70) || (tankfill3 <= 30)){
    digitalWrite(Relay2,HIGH);
    digitalWrite(led2,LOW);
  }
}
g =1;
}
else{
  if(g==1){
   digitalWrite(Relay2,HIGH);
   digitalWrite(led2,LOW);
  g = 0;
  }
}
if( analogRead(switch3) < 200) {
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch3 close");
  lcd.setCursor(0,1);
  lcd.print("Water Plants");
  
  digitalWrite(Relay3, LOW);
  digitalWrite(led3 , HIGH); 
  delay(500);
  digitalWrite(Relay5 , LOW);
  stepperhome();

while(( analogRead(switch3) < 200)&&(soilMoisture >= 60)&&(tankfill1 <= 30)) {
 hw103();
 hcsr1();
steppermotor();

}
digitalWrite(Relay3,HIGH);
     digitalWrite(led3,LOW);
     delay(500);
     digitalWrite(Relay5 , HIGH);
}
  
 

if( analogRead(switch4) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch4 close");
  delay(delayDisplay);
  digitalWrite(Relay6 , LOW);
  digitalWrite(led4 , HIGH); 
  if (tankfill3 > 85){
      digitalWrite(Relay6,HIGH);
      digitalWrite(led4,LOW); 
  }

d =1;
}
else{
  if(d ==1){
     digitalWrite(Relay6,HIGH);
     digitalWrite(led4,LOW);
  d = 0;
  }
}

if( analogRead(switch5) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch5 close");
  delay(delayDisplay);
  digitalWrite(Relay7 , LOW);
  digitalWrite(led5 , HIGH); 

e =1;
}
else{
  if(e ==1){
     digitalWrite(Relay7,HIGH);
     digitalWrite(led5,LOW);
  e = 0;
  }
}

if( analogRead(switch6) < 200) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch6 close");
  delay(delayDisplay);
  digitalWrite(Relay8 , LOW);
  digitalWrite(led6 , HIGH); 

f =1;
}

else{
  if(f ==1){
     digitalWrite(Relay8,HIGH);
     digitalWrite(led6,LOW);
  f = 0;
  }
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
  delay(delayHcsr);
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
 avgValue1+=buf1[i];
 }
 float distance1 =(float)avgValue1*0.034/2/6;
Serial.print("Distance1 C: ");// Prints the distance on the Serial Monitor
Serial.println(distance1); 
x =distance1/27*100;
tankfill1 = 100-x;
Serial.print("percentage fill1 C: ");
Serial.print(tankfill1); 
Serial.println("%");
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
 avgValue2+=buf2[i];
 }
 float distance2 =(float)avgValue2*0.034/2/6;
Serial.print("Distance2: ");// Prints the distance on the Serial Monitor
Serial.println(distance2); 
 x =distance2/27*100;
tankfill2 = 100-x;

Serial.print("percentage fill: ");
Serial.print(tankfill2); 
Serial.println("%");
}//HCSR2


void hcsr3(){
  
for(int i=0;i<10;i++) 
 {
digitalWrite(trigPin3, LOW);// Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin3, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);


  buf3[i]= pulseIn(echoPin3, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds 
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf3[i]>buf3[j])
   {
  temp=buf3[i];
  buf3[i]=buf3[j];
  buf3[j]=temp;    
   }
  }
 }
 avgValue3=0;
 for(int i=2;i<8;i++)
 {
 avgValue3+=buf3[i];
 }
 float distance3 =(float)avgValue3*0.034/2/6;
Serial.print("Distance3: ");// Prints the distance on the Serial Monitor
Serial.println(distance3); 
 z =distance3/27*100;
tankfill3 = 100-z;

Serial.print("percentage fill: ");
Serial.print(tankfill3); 
Serial.println("%");

}//HCSR3
void hw103(){

for(int i=0;i<10;i++) 
 { 
  buf4[i]=analogRead(analogHw);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf4[i]>buf4[j])
   {
    temp=buf4[i];
    buf4[i]=buf4[j];
    buf4[j]=temp;
   }
  }
 }
 avgValue4=0;
 for(int i=2;i<8;i++)
 {
 avgValue4+=buf4[i];
 }
 float hwValue=(float)avgValue4/6;
 v = hwValue/1024*100;
 soilMoisture = 100-v;
 Serial.print("Moisture = ");
 Serial.print(soilMoisture);
 Serial.println("%");
 }
 
