// Define pin connections & motor's steps per revolution
const int endstop = 14;
const int dirPin = 15;
const int stepPin = 16;
const int stepsPerRevolution = 200;
const int axisStep = 700;
int stepdelay = 2000;
void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(endstop, INPUT);
  

}
void loop()
{
  
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
  
}
