#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 300

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  randomSeed(analogRead(0));
}

void loop() {
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

static void chase(uint32_t c) {
  int randomMax = random(0,10);
  int randomSwitch = random(0,randomMax);
  for(uint16_t oneColorRun = 0; oneColorRun < randomMax; oneColorRun++){
    for(uint16_t offset = 0; offset < 12; offset++){
      for(uint16_t j=0; j<strip.numPixels(); j++){
        int newOffset = (oneColorRun > randomSwitch) ? offset : -offset;
        if((j+newOffset)%13 == 0 || (j+1+newOffset) % 13 == 0)
          strip.setPixelColor(j, 0); // Erase pixel a few steps back
        else
          strip.setPixelColor(j, c); // Erase pixel a few steps back
      }
          strip.show();
    }
  }
}
