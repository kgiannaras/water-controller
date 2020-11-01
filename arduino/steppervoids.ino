
 void steppermotor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperMotor");
// Set motor direction COUNTER clockwise
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
  void stepperhome(){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperHome");
  
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
