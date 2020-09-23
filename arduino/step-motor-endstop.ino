// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 15, 16, 17, 18);

int endstop = 15;

void setup()
{
  pinMode(endstop, INPUT) ;
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() 
{
  // step one revolution in one direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  if (digitalRead(endstop == HIGH)){
    myStepper.step(0);
  }
  
}
