#include "ws2812_led.h"
#define NUM_LEDS 50
#define DELAY_TIME 20

ws2812led* leds;

void setup() {
  leds = new ws2812led(NUM_LEDS);
}

void loop() {
  // Turn off all LEDs
  leds->clear_all();
  // Move the LED chaser
  for (int i = 0; i < NUM_LEDS; i++) {
    leds->set(i, CRGB::Red);
    delay(DELAY_TIME);
  }
  // Move the LED chaser in reverse
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds->set(i, CRGB::Green);
    delay(DELAY_TIME);  // Delay between LED movements
  }

  leds->set_all(CRGB::Blue);
  delay(DELAY_TIME*NUM_LEDS);  // Delay between LED movements
}