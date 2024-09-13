#include "ws2812_led.h"
#define LED_PIN 5

ws2812led::ws2812led(led_count_type no_leds) : 
  m_led_count{no_leds}
{
  m_leds = (CRGB*)malloc(sizeof(CRGB) * m_led_count);
  FastLED.addLeds<WS2812, LED_PIN, RGB>(m_leds, m_led_count);
}

void ws2812led::clear_all() {
  for (auto i = 0; i < m_led_count; i++) {
    m_leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void ws2812led::set_all(CRGB colour) {
  for (auto i = 0; i < m_led_count; i++) {
    m_leds[i] = colour;
  }
  FastLED.show();
}

void ws2812led::set(led_count_type n, CRGB colour){
  if(n >= m_led_count) {
    return;
  }
  m_leds[n] = colour;
  FastLED.show();
}