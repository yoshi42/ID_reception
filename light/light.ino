#include "FastLED.h"          // библиотека для работы с лентой


#define LED_COUNT 50         // число сигментов в  ленте1 


#define LED_CEIRCLE 1         // число сигментов в однов кольце
#define LED_DT 2           // пин, куда подключен DIN ленты
int max_bright = 255;         // максимальная яркость (0 - 255)
struct CRGB leds[LED_COUNT];
int brightness = 255;
int thisdelay = 20;          //-FX LOOPS DELAY VAR
int thisstep = 0;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
byte hue;
int ihue = 0;

int16_t position = 2;
boolean direction = true;


void setup() {
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость
  LEDS.addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT);  // настрйоки для нашей ленты (ленты на WS2811, WS2812, WS2812B)
  one_color_all(0, 0, 0);          // погасить все светодио
  LEDS.show();
}

void loop() {
   lighter();
  // rainbow();
   LEDS.show();
   delay(50);
}





void lighter() {
  FastLED.clear();
  if (direction) {
    position++;
    if (position > LED_COUNT - 4) {
      direction = false;
    }
  } else {
    position--;
    if (position < 3) {
      direction = true;
    }
  }
  rain(position);
}

// ****************************** РАДУГА ******************************
void rainbow() {
  hue += 1;
  for (int i = 0; i < LED_COUNT; i++)
    leds[i] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
    delay(5);
}
void rain(int i) {
  hue += 1;
  leds[i-2] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
  leds[i-1] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
  leds[i] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
  leds[i+1] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
  leds[i+2] = CHSV((byte)(hue + i * float(255 / LED_COUNT)), 255, 255);
    
}

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
  
}

