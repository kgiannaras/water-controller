int Relay1 = 45; 
int Relay2 = 46;
int Relay3 = 47;
int Relay4 = 48;
int Relay5 = 49;
int Relay6 = 50;
int Relay7 = 51;
int Relay8 = 52; 
void setup() {
pinMode(Relay1 , OUTPUT);
pinMode(Relay2 , OUTPUT);
pinMode(Relay3 , OUTPUT);
pinMode(Relay4 , OUTPUT);
pinMode(Relay5 , OUTPUT);
pinMode(Relay6 , OUTPUT);
pinMode(Relay7 , OUTPUT);
pinMode(Relay8 , OUTPUT);
}

void loop() {
 digitalWrite(Relay1 , LOW);
 delay(1000); 
 digitalWrite(Relay1 , HIGH);
 delay(1000); 
 
 digitalWrite(Relay2 , LOW);
 delay(1000); 
 digitalWrite(Relay2 , HIGH);
 delay(1000); 
 
 digitalWrite(Relay3 , LOW);
 delay(1000); 
 digitalWrite(Relay3 , HIGH);
 delay(1000); 
 
 digitalWrite(Relay4 , LOW);
 delay(1000); 
 digitalWrite(Relay4 , HIGH);
 delay(1000); 
 
 digitalWrite(Relay5 , LOW);
 delay(1000); 
 digitalWrite(Relay5 , HIGH);
 delay(1000); 

 digitalWrite(Relay6 , LOW);
 delay(1000); 
 digitalWrite(Relay6 , HIGH);
 delay(1000); 

 digitalWrite(Relay7 , LOW);
 delay(1000); 
 digitalWrite(Relay7 , HIGH);
 delay(1000); 

 digitalWrite(Relay8 , LOW);
 delay(1000); 
 digitalWrite(Relay8 , HIGH);
 delay(1000); 
 }
