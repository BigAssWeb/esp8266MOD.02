#include <Arduino.h>
#define LED_PIN 2          // встроенный LED на ESP-01

void setup() { pinMode(LED_PIN, OUTPUT); }
void loop() {
  static uint32_t t0 = millis();
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(1000);
  if (millis() - t0 >= 10000) ESP.restart();   // 10 с → перезагрузка
}
