#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 300

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  randomSeed(analogRead(0));
}

int colorToAlpha(int toFix){
  if(toFix > 255)
    return 255 - (toFix%255);
  
  return abs(toFix);

  
}

void loop() {
  bool isRedReverse = false;
  bool isGreenReverse = false;
  bool isBlueReverse = false;

  int red = 0;
  int green = 96;
  int blue = 192;

  int speed = 20;

  int loopCount = 0;
  while(true){
    if(red <= 0 || red >= 255)
      isRedReverse = !isRedReverse;

    if(green <= 0 || green >= 255)
      isGreenReverse = !isGreenReverse;

    if(blue <= 0 || blue >= 255)
      isBlueReverse = !isBlueReverse;

    if(isRedReverse)
      red+= speed;
    else
      red-= speed;

    if(isGreenReverse)
      green+= speed;
    else
      green-= speed;

    if(isBlueReverse)
      blue+= speed;
    else
      blue-= speed;
    
    chase(strip.Color(colorToAlpha(red), colorToAlpha(green), colorToAlpha(blue)), ((loopCount / 10) % 3 == 0) ? 18 : 2); // Red

    loopCount++;
  }
  /*chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue*/
}

static void chase(uint32_t c, uint16_t delayForOurThing) {
  int randomMax = random(0,25);
  //for(uint16_t oneColorRun = 0; oneColorRun < randomMax; oneColorRun++){
    for(uint16_t offset = 0; offset < 12; offset+=1){
      for(uint16_t j=0; j<strip.numPixels(); j++){
        //uint16_t dumbColor = strip.Color(random(0,255),random(0,255),random(0,255));
        //int newOffset = (oneColorRun > randomSwitch) ? offset : -offset;
        if((j+offset)%13 == 0 || (j+1+offset) % 13 == 0)
          strip.setPixelColor(j, 0); // Erase pixel a few steps back
        else
          strip.setPixelColor(j, c); // Erase pixel a few steps back
      }
      strip.show();
      delay(delayForOurThing);
    }
  //}
}
