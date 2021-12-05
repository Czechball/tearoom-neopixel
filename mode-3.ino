#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 300

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  randomSeed(analogRead(0));
}

void loop() {
  for(uint16_t i = 0; i <= 255; i+=15){
    uint16_t red = i;
    uint16_t green = (i + (255/3));
    uint16_t blue = (i + ((255/3)*2)));
    chase(strip.Color(red, green > 255 ? green : , blue); // Red
  }
  /*chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue*/
}

static void chase(uint32_t c) {
  int randomMax = random(0,25);
  //for(uint16_t oneColorRun = 0; oneColorRun < randomMax; oneColorRun++){
    for(uint16_t offset = 0; offset < 12; offset++){
      for(uint16_t j=0; j<strip.numPixels(); j++){
        //uint16_t dumbColor = strip.Color(random(0,255),random(0,255),random(0,255));
        //int newOffset = (oneColorRun > randomSwitch) ? offset : -offset;
        if((j+offset)%13 == 0 || (j+1+offset) % 13 == 0)
          strip.setPixelColor(j, 0); // Erase pixel a few steps back
        else
          strip.setPixelColor(j, c); // Erase pixel a few steps back
      }
      strip.show();
      //delay(randomMax);
    }
  //}
}
