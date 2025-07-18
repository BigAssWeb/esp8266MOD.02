#include <Arduino.h>

#define SEL_PIN        0          // D3 / GPIO0
#define ADDR_APP_A     0x10000    // где лежит App A
#define ADDR_APP_B     0x20000    // где лежит App B
#define ENTRY_OFFSET   0x1000     // пропускаем заголовок прошивки

typedef void (*entry_t)(void) __attribute__((noreturn));

void setup() {
  pinMode(SEL_PIN, INPUT_PULLUP);       // HIGH, если цепь разомкнута
  bool isClosed = digitalRead(SEL_PIN) == LOW;

  uint32_t addr = (isClosed ? ADDR_APP_B : ADDR_APP_A) + ENTRY_OFFSET;
  entry_t user = reinterpret_cast<entry_t>(addr);
  user();                               // передаём управление → never returns
}

void loop() {}                          // никогда не достигнется
