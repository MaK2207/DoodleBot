// Pins Configuration
const int POT1_PIN = A0;
const int POT2_PIN = A1;

const int BUZZER1_PIN = 2;
const int BUZZER2_PIN = 3;
const int BUZZER3_PIN = 4;

const int LED_PINS[5] = {5, 6, 7, 8, 9};

void setup() {
  // Set buzzer pins as output
  pinMode(BUZZER1_PIN, OUTPUT);
  pinMode(BUZZER2_PIN, OUTPUT);
  pinMode(BUZZER3_PIN, OUTPUT);

  // Set LED pins as output
  for (int i = 0; i < 5; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
}

void loop() {
  int pot1Value = analogRead(POT1_PIN);  // 0 to 1023
  int pot2Value = analogRead(POT2_PIN);  // 0 to 1023

  // Buzzer control logic
  if (pot1Value <= 341) {
    digitalWrite(BUZZER1_PIN, HIGH);
    digitalWrite(BUZZER2_PIN, LOW);
    digitalWrite(BUZZER3_PIN, LOW);
  } else if (pot1Value <= 682) {
    digitalWrite(BUZZER1_PIN, LOW);
    digitalWrite(BUZZER2_PIN, HIGH);
    digitalWrite(BUZZER3_PIN, LOW);
  } else {
    digitalWrite(BUZZER1_PIN, LOW);
    digitalWrite(BUZZER2_PIN, LOW);
    digitalWrite(BUZZER3_PIN, HIGH);
  }

  // Map pot2Value to a reasonable delay (e.g., 50ms to 500ms)
  int ledDelay = map(pot2Value, 0, 1023, 50, 500);

  // LED sequence logic
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(LED_PINS[j], j == i ? HIGH : LOW);
    }
    delay(ledDelay);
  }
}
