int led = 13;
char state;
void setup() {
  pinMode(led , OUTPUT); 
  Serial2.begin(9600);
  Serial.begin(9600);
  digitalWrite(led, HIGH);
  Serial.println ("Arduino welcome");
 
    }  

void loop() {
    if   ( Serial2.available() )      { 
      state = Serial2.read(); 
      Serial.println (state);
    }
    
    if ( state == 'r' ) {
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
    state = ' ';
    }
     
    else if ( state == 'f' ) {
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
     state = ' ';
    }
}
