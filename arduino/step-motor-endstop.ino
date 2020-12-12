// Define pin connections & motor's steps per revolution
const int enablePin = 36;
const int m0pin = 38;
const int m1pin = 40;
const int m2pin = 42;
const int endstop = 14;
const int dirPin = 15;
const int stepPin = 16;
const int stepsPerRevolution = 200;
const int axisStep = 1000;
int stepdelay = 400;
void setup()
{
  // Declare pins as Outputs
  pinMode(enablePin, OUTPUT);
  pinMode(m0pin, OUTPUT);
  pinMode(m1pin, OUTPUT);
  pinMode(m2pin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(endstop, INPUT);

  digitalWrite(m0pin,LOW);
  digitalWrite(m1pin,LOW);
  digitalWrite(m2pin,LOW);
   
   //home
     digitalWrite(enablePin,LOW);
     digitalWrite(dirPin, LOW);
  while(digitalRead(endstop)== HIGH){
      digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
   
  }
  
  digitalWrite(dirPin, HIGH);
  
  for(int x = 0; x < 100; x++){
     digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    
  
  }
  delay(1000);
      digitalWrite(enablePin,HIGH);

}
void loop(){
  if(digitalRead(enablePin)==HIGH){
  pinMode(enablePin,LOW);
}
 //Set motor direction COUNTER clockwise
   
    digitalWrite(dirPin, HIGH);
  for(int x = 0; x < axisStep; x++){
      digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
   
  }

  digitalWrite(dirPin, LOW);
  
  for(int x = 0; x <axisStep; x++){
     digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    
  
  }
  delay(1000);
  
}
