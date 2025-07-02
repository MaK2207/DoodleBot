int sensorVal1 = 0;
int sensorVal2 = 0;
int Pot1 = A3;
int Pot2 = A4;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop()
{
  sensorVal1 = analogRead(Pot1);
  sensorVal1 = analogRead(Pot1);

  //int x = analogRead(Pot1);
  //int y = analogRead(Pot2);
  
  int speed = map(analogRead(Pot2), 1, 1023, 1, 20);
  speed = constrain(speed, 1, 100);
  Serial.println(speed);
  
  if (sensorVal1 >0 && sensorVal1 < 341) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  } 
  else if (sensorVal1 >= 341 && sensorVal1 < 682) {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
  } 
  else if (sensorVal1 >= 682 && sensorVal1 <= 1023) {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
  }

  analogWrite(3, HIGH);
  delay(1000/speed);
  analogWrite(3, LOW);

  analogWrite(5, HIGH);
  delay(1000/speed);
  analogWrite(5, LOW);

  analogWrite(6, HIGH);
  delay(1000/speed);
  analogWrite(6, LOW);

  analogWrite(9, HIGH);
  delay(1000/speed);
  analogWrite(9, LOW);

  analogWrite(10, HIGH);
  delay(1000/speed);
  analogWrite(10, LOW);
  
  //  https://www.tinkercad.com/things/4zPnk8mYutR-assignment01?sharecode=b92mPi95o1-cJqn7bL_zQ9T8TXLm5jhDeU93NzfiAo8
}