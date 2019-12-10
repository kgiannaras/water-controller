    int in1 = 41;
    int in2 = 43;
    int in3 = 45;
    int in4 = 47;
    void setup() {
      pinMode(in1, OUTPUT);
      digitalWrite(in1, HIGH);
       pinMode(in2, OUTPUT);
      digitalWrite(in2, HIGH);
       pinMode(in3, OUTPUT);
      digitalWrite(in3, HIGH);
       pinMode(in4, OUTPUT);
      digitalWrite(in4, HIGH);
    }
    void loop() {    
 
  digitalWrite(in1, LOW);
  delay(1000);
  digitalWrite(in1, HIGH);
  delay(1000);
   digitalWrite(in2, LOW);
  delay(1000);
  digitalWrite(in2, HIGH);
  delay(1000);
   digitalWrite(in3, LOW);
  delay(1000);
  digitalWrite(in3, HIGH);
  delay(1000);
   digitalWrite(in4, LOW);
  delay(1000);
  digitalWrite(in4, HIGH);
  delay(1000);

    }
