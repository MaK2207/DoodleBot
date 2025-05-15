// Dual Potentiometer Control System
// POT1 controls 3 buzzers based on range
// POT2 controls 5 LED sequence speed

int pot1 = A0;
int pot2 = A1;

// Buzzers
int buz1 = 10;
int buz2 = 9;
int buz3 = 8;

// LEDs
int leds[] = {2, 3, 4, 5, 6};
int ledCount = 5;

void setup() {
  // Set buzzer pins as output
  pinMode(buz1, OUTPUT);
  pinMode(buz2, OUTPUT);
  pinMode(buz3, OUTPUT);

  // Set LED pins as output
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }

  // Potentiometers are analog, no pinMode needed
  Serial.begin(9600);
}

void loop() {
  int val1 = analogRead(pot1);  // range: 0 - 1023
  int val2 = analogRead(pot2);  // delay controller

  // Buzzer control based on POT1 range
  if (val1 >= 0 && val1 <= 341) {
    digitalWrite(buz1, HIGH);
    digitalWrite(buz2, LOW);
    digitalWrite(buz3, LOW);
  } else if (val1 > 341 && val1 <= 682) {
    digitalWrite(buz1, LOW);
    digitalWrite(buz2, HIGH);
    digitalWrite(buz3, LOW);
  } else if (val1 > 682) {
    digitalWrite(buz1, LOW);
    digitalWrite(buz2, LOW);
    digitalWrite(buz3, HIGH);
  }

  // LED sequence controlled by POT2 value
  int delayTime = map(val2, 0, 1023, 50, 1000);  // map to 50ms to 1000ms

  for (int i = 0; i < ledCount; i++) {
    // turn on one LED
    digitalWrite(leds[i], HIGH);

    // turn off others
    for (int j = 0; j < ledCount; j++) {
      if (j != i) {
        digitalWrite(leds[j], LOW);
      }
    }

    delay(delayTime);
  }
}

/*
https://www.tinkercad.com/things/803n3ejZQSR/editel?returnTo=%2Fdashboard&sharecode=he7kUZD28qYFTPXGNOh5We1PkRjaTQ5SVUq0AYP4EGo
*/
