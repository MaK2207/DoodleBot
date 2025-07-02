// Pin Definitions
const int pot1Pin = A0; // POT1
const int pot2Pin = A1; // POT2
const int buttonPin = 9; // Optional button input

const int buzzerPins[3] = {3, 4, 5}; // Buzzer 1, 2, 3
const int ledPins[5] = {6, 7, 8, 10, 11}; // LED sequence pins

// LED chase variables
int currentLed = 0;
unsigned long lastUpdateTime = 0;
int delayTime = 100;

void setup() {
  Serial.begin(1200);

  pinMode(pot1Pin, INPUT);
  pinMode(pot2Pin, INPUT);
  pinMode(buttonPin, INPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(buzzerPins[i], OUTPUT);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pot1Val = analogRead(pot1Pin);
  int pot2Val = analogRead(pot2Pin);
  int buttonVal = digitalRead(buttonPin);

  // Serial output
  Serial.print(pot1Val);
  Serial.print(",");
  Serial.print(pot2Val);
  Serial.print(",");
  Serial.println(buttonVal);

  // --- Buzzer Control ---
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPins[i], LOW); // Turn off all first
  }

  if (pot1Val <= 341) {
    digitalWrite(buzzerPins[0], HIGH); // Buzzer 1
  } else if (pot1Val <= 682) {
    digitalWrite(buzzerPins[1], HIGH); // Buzzer 2
  } else {
    digitalWrite(buzzerPins[2], HIGH); // Buzzer 3
  }

  // --- LED Sequence ---
  delayTime = map(pot2Val, 0, 1023, 50, 1000); // speed control
  unsigned long currentTime = millis();

  if (currentTime - lastUpdateTime >= delayTime) {
    updateLEDSequence();
    lastUpdateTime = currentTime;
  }
}

void updateLEDSequence() {
  // Turn off all LEDs
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Turn on current LED
  digitalWrite(ledPins[currentLed], HIGH);

  // Move to next LED
  currentLed++;
  if (currentLed >= 5) {
    currentLed = 0;
  }
}


// Link for TinkerCad: https://www.tinkercad.com/things/hBhfqzGJUJx/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=fzpyZ-eWjwyTdFYtBl_YtlGAjNtX303yRiCr1bSmcsM
