int level_input = 14 ;
void setup() {
 Serial.begin(9600);
 Serial.println("Ready");
 pinMode(level_input , INPUT);

}

void loop() {
  if (analogRead(level_input) > 200){
    Serial.println("Filled tank");
  }
  else{
    Serial.println("Empty tank");
  }
}
