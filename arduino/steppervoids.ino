
 void steppermotor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperMotor");
if(digitalRead(enablePin)==HIGH){
  pinMode(enablePin,LOW);
}
// Set motor direction COUNTER clockwise
    lcd.setCursor(0,1);
  lcd.print("Right");
    digitalWrite(dirPin, HIGH);
  for(int x = 0; x < axisStep; x++){
      digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
   
  }
    lcd.setCursor(0,1);
    lcd.print("       ");
  lcd.setCursor(0,1);
  lcd.print("Left");
  digitalWrite(dirPin, LOW);
  
  for(int x = 0; x <axisStep; x++){
     digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
    
  
  }
  delay(1000);



  }
  void stepperhome(){
     digitalWrite(enablePin,LOW);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperHome");
   lcd.setCursor(0,1);
  lcd.print("Right");
     digitalWrite(dirPin, LOW);
  while(digitalRead(endstop)== HIGH){
      digitalWrite(stepPin, LOW);
    delayMicroseconds(stepdelay);
     digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepdelay);
   
  }
   lcd.setCursor(0,1);
    lcd.print("       ");
  lcd.setCursor(0,1);
  lcd.print("Left");
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
