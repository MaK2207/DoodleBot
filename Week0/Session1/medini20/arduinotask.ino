int pot1 = A2;
int pot2 = A4;
int buz1 = 2;
int buz2 = 4;
int buz3 = 7;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 9;
int led5 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(buz1,OUTPUT);
  pinMode(buz2,OUTPUT);
  pinMode(buz3,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  
}
void loop() {
  int x = analogRead(pot1);
  Serial.println(x);
  if (x<342){
  	digitalWrite(buz1, HIGH);
    digitalWrite(buz2,LOW);
    digitalWrite(buz3,LOW);
  }
  else if (x>682){
    digitalWrite(buz1,LOW);
    digitalWrite(buz2,LOW);
  	digitalWrite(buz3,HIGH);
  }
  else {
    digitalWrite(buz1,LOW);
  	digitalWrite(buz2,HIGH);
    digitalWrite(buz3,LOW);
  }
  int y = analogRead(pot2);
  
  digitalWrite(led1, HIGH);
  delay(y);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(y);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(y);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(y);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(y);
  digitalWrite(led5, LOW);
}

//https://www.tinkercad.com/things/is1UONXbjK7-funky-albar-kasi?sharecode=BnMt6kcZukO2BzD0imYR6tYwH25qG8Lace8ciZrjnqA
