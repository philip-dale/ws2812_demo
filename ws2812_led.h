#include <FastLED.h>

typedef uint16_t led_count_type;

class ws2812led {
public:
  ws2812led(led_count_type no_leds);
  void clear_all();
  void set_all(CRGB colour);
  void set(led_count_type n, CRGB colour);

private:
  led_count_type m_led_count;
  CRGB * m_leds;
};