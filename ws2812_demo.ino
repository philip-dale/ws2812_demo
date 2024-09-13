#include "ws2812_led.h"
#define NUM_LEDS 50
#define DELAY_TIME 20

auto leds = ws2812led(NUM_LEDS);

void setup() {}

void loop() {
  leds.clear_all();
  delay(DELAY_TIME*NUM_LEDS);

  for (auto i = 0; i < NUM_LEDS; ++i) {
    leds.set(i, CRGB::Red);
    delay(DELAY_TIME);
  }

  for (auto i = NUM_LEDS - 1; i >= 0; --i) {
    leds.set(i, CRGB::Green);
    delay(DELAY_TIME);
  }
  
  leds.set_all(CRGB::Blue);
  delay(DELAY_TIME*NUM_LEDS);

  leds.set_all(CRGB::Linen);
  delay(DELAY_TIME*NUM_LEDS);
}