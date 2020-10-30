// Define pin connections & motor's steps per revolution
const int endstop = 14;
const int dirPin = 15;
const int stepPin = 16;
const int stepsPerRevolution = 200;
const int axisStep = 700;
int stepdelay = 4000;
void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(endstop, OUTPUT);
  
    digitalWrite(dirPin, LOW);
  while(digitalRead(endstop)== HIGH){
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  }
  
  digitalWrite(dirPin, HIGH);
  
  for(int x = 0; x < 100; x++){
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  
  }
  delay(1000);
}
void loop()
{
  // Set motor direction COUNTER clockwise
  digitalWrite(dirPin, HIGH);

  // Spin motor slowly
  for(int x = 0; x < axisStep; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  }
  
  delay(1000);
  // Set motor direction clockwise
  digitalWrite(dirPin, LOW);

  // Spin motor quickly
  for(int x = 0; x <axisStep; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  } 
  delay(1000);
  
}
