


int trigPin1 = 23;
int echoPin1 = 22;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);


}

void sensor1(){ // Αυτή η λειτουργία είναι για τον πρώτο αισθητήρα , των τοίχων
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
      Serial.print("1st Sensor: ");
      Serial.print(distance1); 
      Serial.print("cm    ");
 
  }
void loop() {
Serial.println("\n");
sensor1();  // ανιχνευση τοιχου
delay(500);
}
