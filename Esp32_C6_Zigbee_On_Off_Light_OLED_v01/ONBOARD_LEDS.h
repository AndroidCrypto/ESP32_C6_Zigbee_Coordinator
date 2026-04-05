/*
  Management of the onboard LED and RGB LED
  15.03.2026 V04 Implemented delayless flashing of the RGB LED (1 flash for 50 millis)
  02.03.2026 V03 The ESP32-C6 8/16 MB Dev Board has just the RGB LED, not the regular LED
                 Removed all methods for the regular LED
  05.02.2026 V02 Implemented color lookup helper for RGB LED
  04.02.2026 V01 Initial version
*/

#ifndef IS_ONBOARD_LEDS
#define IS_ONBOARD_LEDS
#endif

#define IS_ONBOARD_LED
#define ONBOARD_LED_PIN 15     // this is a small blue LED
#define ONBOARD_RGB_LED_PIN 8  // this is a WS2812 RGB LED
#define ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS 10

#include <FastLED.h> // https://github.com/FastLED/FastLED version 3.10.3
#define NUM_RGB_LEDS 1
CRGB rgbLed[NUM_RGB_LEDS];

// section LED

void setupOnboardLeds() {
#ifdef IS_ONBOARD_LED
  pinMode(ONBOARD_LED_PIN, OUTPUT);
  digitalWrite(ONBOARD_LED_PIN, LOW);  // LED off
#endif
  FastLED.addLeds<WS2812, ONBOARD_RGB_LED_PIN, GRB>(rgbLed, NUM_RGB_LEDS);
  rgbLed[0] = CRGB::Black; // RGB LED off
  FastLED.show();
}

void setOnboardLed(bool isLedOn) {
#ifdef IS_ONBOARD_LED  
  if (isLedOn) {
    digitalWrite(ONBOARD_LED_PIN, HIGH);  // LED on
  } else {
    digitalWrite(ONBOARD_LED_PIN, LOW);  // LED off
  }
#endif  
}

void onboardLedFlash(uint16_t flashes, uint16_t delaymS) {
#ifdef IS_ONBOARD_LED
  uint16_t index;
  for (index = 1; index <= flashes; index++) {
    digitalWrite(ONBOARD_LED_PIN, HIGH);
    delay(delaymS);
    digitalWrite(ONBOARD_LED_PIN, LOW);
    delay(delaymS);
  }
#endif  
}

// section RGB LED

uint8_t RGB_LED_FLASH_DUREATION_MILLIS = 50;

// set these in main for flashing to true
bool setRedLedFlash = false;
bool setGreenLedFlash = false;
bool setBlueLedFlash = false;
bool setWhiteLedFlash = false;

bool isRedLedOn = false;
bool isGreenLedOn = false;
bool isBlueLedOn = false;
bool isWhiteLedOn = false;

long lastRedLedFlashMillis = 0;
long lastGreenLedFlashMillis = 0;
long lastBlueLedFlashMillis = 0;
long lastWhiteLedFlashMillis = 0;

void setRgbLedRed(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Red; 
  FastLED.show();
}

void setRgbLedGreen(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Green; 
  FastLED.show();
}

void setRgbLedBlue(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Blue; 
  FastLED.show();
}

void setRgbLedYellow(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Yellow; 
  FastLED.show();
}

void setRgbLedMint(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Aqua; 
  FastLED.show();
}

void setRgbLedPurple(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::Purple; 
  FastLED.show();
}

void setRgbLedWhite(uint8_t brightness) {
  FastLED.setBrightness(brightness);
  rgbLed[0] = CRGB::White; 
  FastLED.show();
}

void setRgbLedOff() {
  FastLED.setBrightness(0);
  rgbLed[0] = CRGB::Black;
  FastLED.show();
}

void onboardLedFlashRed(uint16_t flashes, uint16_t delaymS) {
  uint16_t index;
  for (index = 1; index <= flashes; index++) {
    setRgbLedRed(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    delay(delaymS);
    setRgbLedOff();
    delay(delaymS);
  }
}

void onboardLedFlashGreen(uint16_t flashes, uint16_t delaymS) {
  uint16_t index;
  for (index = 1; index <= flashes; index++) {
    setRgbLedGreen(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    delay(delaymS);
    setRgbLedOff();
    delay(delaymS);
  }
}

void onboardLedFlashBlue(uint16_t flashes, uint16_t delaymS) {
  uint16_t index;
  for (index = 1; index <= flashes; index++) {
    setRgbLedBlue(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    delay(delaymS);
    setRgbLedOff();
    delay(delaymS);
  }
}

void onboardLedFlashWhite(uint16_t flashes, uint16_t delaymS) {
  uint16_t index;
  for (index = 1; index <= flashes; index++) {
    setRgbLedWhite(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    delay(delaymS);
    setRgbLedOff();
    delay(delaymS);
  }
}

// Call this in the main loop if you plan to use the delayless RGB LED flashing
// rgbLedFlashLoop(); // delayless RGB LED flashing
void rgbLedFlashLoop() {
  if (setRedLedFlash) {
    setRedLedFlash = false;
    isRedLedOn = true;
    setRgbLedRed(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    lastRedLedFlashMillis = millis();
  }

  if (isRedLedOn) {
    if ((millis() - lastRedLedFlashMillis) > RGB_LED_FLASH_DUREATION_MILLIS) {
      setRgbLedRed(0);
      isRedLedOn = false;
    } 
  }

  if (setGreenLedFlash) {
    setGreenLedFlash = false;
    isGreenLedOn = true;
    setRgbLedGreen(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    lastGreenLedFlashMillis = millis();
  }

  if (isGreenLedOn) {
    if ((millis() - lastGreenLedFlashMillis) > RGB_LED_FLASH_DUREATION_MILLIS) {
      setRgbLedGreen(0);
      isGreenLedOn = false;
    } 
  }

  if (setBlueLedFlash) {
    setBlueLedFlash = false;
    isBlueLedOn = true;
    setRgbLedBlue(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    lastBlueLedFlashMillis = millis();
  }

  if (isBlueLedOn) {
    if ((millis() - lastBlueLedFlashMillis) > RGB_LED_FLASH_DUREATION_MILLIS) {
      setRgbLedBlue(0);
      isBlueLedOn = false;
    } 
  }

  if (setWhiteLedFlash) {
    setWhiteLedFlash = false;
    isWhiteLedOn = true;
    setRgbLedWhite(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    lastWhiteLedFlashMillis = millis();
  }

  if (isWhiteLedOn) {
    if ((millis() - lastWhiteLedFlashMillis) > RGB_LED_FLASH_DUREATION_MILLIS) {
      setRgbLedWhite(0);
      isWhiteLedOn = false;
    } 
  }
}


/*
Temperature (Celsius) - RGB LED color
< 10      - white
10...< 19  - blue
19...< 22  - green
22...< 24  - yellow
>= 24      - red
*/
void onboardRgbLedTemperatureLookUp(float temperature) {
  if (temperature < 10) {
    setRgbLedWhite(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if (temperature < 19) {
    setRgbLedBlue(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if (temperature < 22) {
    setRgbLedGreen(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if (temperature < 24) {
    setRgbLedYellow(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else {
    setRgbLedRed(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  }
}

/*
Battery Voltage (Volts) - RGB LED color
< 3.4       - red
3.4...< 3.5 - yellow
3.5...< 3.7 - green
3.7...< 4.1 - mint
>= 4.1      - blue
*/
void onboardRgbLedBatteryVoltageLookUp(float voltage) {
  if (voltage < 3.4) {
    setRgbLedRed(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if(voltage < 3.5) {
    setRgbLedYellow(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if(voltage < 3.7) {
    setRgbLedGreen(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else if(voltage < 4.1) {
    setRgbLedMint(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  } else {
    setRgbLedBlue(ONBOARD_RGB_LED_DEFAULT_BRIGHTNESS);
    return;
  }
}
