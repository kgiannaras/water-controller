
 void steppermotor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperMotor");
  // step one revolution in one direction:
  Serial.println("counterclockwise");
  myStepper.step(-axisStep);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("clockwise");
  myStepper.step(axisStep);
  delay(500);
  

  }
  void stepperhome(){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("StepperHome");
    while (digitalRead(endstop) == HIGH){
      myStepper.step(1);
    }
    myStepper.step(-100);
    
 }
