
float waterMoisture;
int analogPin = A8;
void setup() {
  Serial.begin(9600);
  pinMode(analogPin,INPUT);
  Serial.println("ready");
}

void loop() {

 waterMoisture = (float)  analogRead(analogPin)/1024*100;
 Serial.print("Water Moisture:");
 Serial.print(waterMoisture);
 Serial.println("%");

 
 delay(2000);
}
