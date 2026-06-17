#include <Arduino.h>

// Масив з номерами GPIO для світлодіодів (підключені через резистори до GND)
const uint8_t ledPins[] = {4, 5, 6, 7};
const uint8_t numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");

  for (uint8_t i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Тест: всі LED вмикаються на 1 секунду при старті
  for (uint8_t i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
  delay(1000);
  for (uint8_t i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
  delay(500);
}

void loop() {
  // Послідовне миготіння: один за одним вперед
  for (uint8_t i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(300);
    digitalWrite(ledPins[i], LOW);
  }

  // Послідовне миготіння: один за одним назад
  for (int8_t i = numLeds - 2; i >= 1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(300);
    digitalWrite(ledPins[i], LOW);
  }
}

