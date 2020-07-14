const int echoPin2 =23;
const int trigPin2 =22;
int x;
int tankfill2;
long duration2;
int distance2;
unsigned long int avgValue2;
int buf2[10],temp;
void setup() {
  Serial.begin(9600);
  Serial.print("ready");
pinMode(trigPin2 , OUTPUT );

pinMode(echoPin2 , INPUT );
}

void loop() {
  for(int i=0;i<10;i++) 
 {
  digitalWrite(trigPin2, LOW);// Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin2, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);


  buf2[i]= pulseIn(echoPin2, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds 
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf2[i]>buf2[j])
   {
    temp=buf2[i];
    buf2[i]=buf2[j];
    buf2[j]=temp;
   }
  }
 }
 avgValue2=0;
 for(int i=2;i<8;i++)
 {
 avgValue2+=buf2[i];
 }
 float distance2 =(float)avgValue2*0.034/2/6;
Serial.print("Distance2: ");// Prints the distance on the Serial Monitor
Serial.println(distance2); 
 x =distance2/25*100;
tankfill2 = 100-x;

Serial.print("percentage fill: ");
Serial.print(tankfill2); 
Serial.println("%");
}
