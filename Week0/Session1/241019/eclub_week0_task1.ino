const int buzz1 = 8;
const int buzz2 = 6;
const int buzz3 = 3;
const int POT1 = A0;
const int POT2 = A5;
unsigned long previousTime = millis();
short currLed = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(POT1, INPUT);
  pinMode(buzz1, OUTPUT);
  pinMode(buzz2, OUTPUT);
  pinMode(buzz3, OUTPUT);
  pinMode(POT2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

int speed(){
  unsigned short val = analogRead(POT2);
  return map(val, 0, 1023, 20, 1000); 
}

void loop()
{
  int POT1val = analogRead(A0);
  int POT2val = analogRead(A5);
  
  Serial.print(POT1val);
  Serial.print(',');
  Serial.println(POT2val);
  
  unsigned long currentTime = millis();
  if (POT1val >= 0 && POT1val <= 341) {
    digitalWrite(buzz1, HIGH);
  } else {
    digitalWrite(buzz1, LOW);
  }
  if (POT1val >= 342 && POT1val <= 682) {
    digitalWrite(buzz2, HIGH);
  } else {
    digitalWrite(buzz2, LOW);
  }
  if (POT1val >= 683 && POT1val <= 1023) {
    digitalWrite(buzz3, HIGH);
  } else {
    digitalWrite(buzz3, LOW);
  }
  float spd = speed();
  digitalWrite(currLed, HIGH);
  if (currentTime - previousTime >= (unsigned short)spd) {
    digitalWrite(currLed, LOW);
    if (currLed != 9){
      currLed--;
    }
    else{
      currLed = 13;
    }
  	digitalWrite(currLed, HIGH);
    previousTime = millis();
  }
}

//TinkerCAD link: https://www.tinkercad.com/things/aUcoRhhF9VS-eclub-week0-task?sharecode=TwHtbdNTVDVtpHMzsWX5OLY1HeCKOXJ8v9pUULyYy_k