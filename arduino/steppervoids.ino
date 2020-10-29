
 void steppermotor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperMotor");
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
  void stepperhome(){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperHome");
  
    digitalWrite(dirPin, LOW);
  while(digitalRead(endstop)== HIGH){
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  }
  
  digitalWrite(dirPin, HIGH);
  
  for(int x = 0; x < 10; x++){
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
  
  }
  delay(1000);
    
 }
