const int pot1Pin = A0; // POT1 - controls buzzers and wiper of POT1 is coonected to A0 
const int pot2Pin = A1; // POT2 - controls LED delay and wiper of POT2 is connected to A1

// piezo Buzzers are connected to 2, 3, 4 in arduino to get Pwm signals
const int buzzer1 = 2;
const int buzzer2 = 3;
const int buzzer3 = 4;

// LEDs are connected to 5,6,7,8,9
const int ledPins[] = {5, 6, 7, 8, 9};
const int numLEDs = 5;

void setup() {
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pot1Val = analogRead(pot1Pin);
  int pot2Val = analogRead(pot2Pin); 
  if (pot1Val <= 341) {
    digitalWrite(buzzer1, HIGH);
    digitalWrite(buzzer2, LOW);
    digitalWrite(buzzer3, LOW);
  } else if (pot1Val <= 682) {
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, HIGH);
    digitalWrite(buzzer3, LOW);
  } else {
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, LOW);
    digitalWrite(buzzer3, HIGH);
  }
  //some issue jp correct from here
  int delayTime = map(pot2Val, 0, 1023, 50, 1000);
  for (int i = 0; i < numLEDs; i++) {
    for (int j = 0; j < numLEDs; j++) {
      digitalWrite(ledPins[j], (i == j) ? HIGH : LOW);
    }
    delay(delayTime);
  }
}

/* made it on TinkerCAD and the Project Link is
https://www.tinkercad.com/things/aa5LzF97wHL-electronics-club-task?sharecode=JwrIGiNqPD5M5X9BCiRwpH6SfXA67CFoMvkvOPQEzpk
*/
