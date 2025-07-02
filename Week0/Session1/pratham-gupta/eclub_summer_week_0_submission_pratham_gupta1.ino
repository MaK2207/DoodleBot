const int pot1Pin = A0; // POT1 controls buzzer and is connected to A0
const int pot2Pin = A1; // POT2 controls buzzer and is connected to A1

const int buzzerPins[3] = {2, 3, 4};
const int ledPins[5] = {5, 6, 7, 8, 9};

int pot1Value = 0;
int pot2Value = 0;
int currentLED = 0;
unsigned long previousMillis = 0;
int delayTime = 500; // Default delay

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(buzzerPins[i], OUTPUT);
    digitalWrite(buzzerPins[i], LOW);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(pot1Pin, INPUT);
  pinMode(pot2Pin, INPUT);
}

void loop() {
  pot1Value = analogRead(pot1Pin);
  pot2Value = analogRead(pot2Pin);

  // Buzzer Control by POT1
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPins[i], LOW); // Turn all off buzzer at first
  }

  if (pot1Value <= 341) {
    digitalWrite(buzzerPins[0], HIGH);
  } else if (pot1Value <= 682) {
    digitalWrite(buzzerPins[1], HIGH);
  } else {
    digitalWrite(buzzerPins[2], HIGH);
  }

  // LED sequence controlled by POT2
  delayTime = map(pot2Value, 0, 1023, 100, 1000); // Adjustable delay between 100ms to 1000ms
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;

    // Turn all LEDs off
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Light up the current LED
    digitalWrite(ledPins[currentLED], HIGH);

    // Move to the next LED
    currentLED++;
    if (currentLED >= 5) {
      currentLED = 0;
    }
  }
}
