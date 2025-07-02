const int potPin = A0;
const int potPin2 = A1;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int buzzer1 = 7;
const int buzzer2 = 8;
const int buzzer3 = 9;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(potPin)+50);

  digitalWrite(led1, HIGH); 
  delay(analogRead(potPin)+50);                
  digitalWrite(led1, LOW); 
  delay(analogRead(potPin)+50);
  
  digitalWrite(led2, HIGH);
  delay(analogRead(potPin)+50);                
  digitalWrite(led2, LOW);  
  delay(analogRead(potPin)+50);
  
  digitalWrite(led3, HIGH); 
  delay(analogRead(potPin)+50);                
  digitalWrite(led3, LOW);
  delay(analogRead(potPin)+50);
  
  digitalWrite(led4, HIGH);
  delay(analogRead(potPin)+50);                
  digitalWrite(led4, LOW);  
  delay(analogRead(potPin)+50);
  
  digitalWrite(led5, HIGH); 
  delay(analogRead(potPin)+50);                
  digitalWrite(led5, LOW); 
  delay(analogRead(potPin)+50);
  
  
  if (analogRead(potPin2) <= 341) {
    digitalWrite(buzzer1, HIGH);
    digitalWrite(buzzer2, LOW);
    digitalWrite(buzzer3, LOW);
  } else if (analogRead(potPin2) <= 682) {
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, HIGH);
    digitalWrite(buzzer3, LOW);
  } else {
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, LOW);
    digitalWrite(buzzer3, HIGH);
  }
}


//https://www.tinkercad.com/things/aZmWQMVyaLO-pot2/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=Q8aACZh9_2I5g3Yo6UamLeQpHYH47WURvjeKmdVrS2c