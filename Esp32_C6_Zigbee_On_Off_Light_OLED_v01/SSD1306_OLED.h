/*
  Management of an external SSD1306 OLED display with a resolution of 128x64 pixels
  07.02.2026 V02 added oDisplayPowerOn() and oDisplayNormalDisplay()
  05.02.2026 V01 Initial version

*/

#ifndef IS_SSD1306_OLED
#define IS_SSD1306_OLED
#endif

/*
Wiring OLED SSD1306 - ESP32-C6 SM
GND - GND
VCC - 3.3V
SCL - GPIO 0
SDA - GPIO 1
*/

// ------------------------------------------------------------------
// SSD1306 OLED display

#define SSD1306_FLIP_SCREEN_ORIENTATION true

/*
// ESP32-C6 16 MB
#define SSD1306_I2C_SDA_PIN 10
#define SSD1306_I2C_SCL_PIN 11
*/

// ESP32-C6 Super Mini
/*
// variante 1
#define SSD1306_I2C_SDA_PIN 1
#define SSD1306_I2C_SCL_PIN 0
*/
// variante 2
#define SSD1306_I2C_SDA_PIN 19
#define SSD1306_I2C_SCL_PIN 20


#define SSD1306_I2C_ADDRESS 0x3C

#include "FONT_MONOSPACE_9.h"   // gives 5 rows with 25 characters each
#include "FONT_MONOSPACE_13.h"  // gives 5 rows with 16 characters each
#include "FONT_MONOSPACE_18.h"  // gives 4 rows with 115 characters each

#include <Wire.h>
#include "SSD1306.h"  // https://github.com/ThingPulse/esp8266-oled-ssd1306 version 4.6.2
SSD1306Wire oDisplay(SSD1306_I2C_ADDRESS, SSD1306_I2C_SDA_PIN, SSD1306_I2C_SCL_PIN);

char* testLine1 = "12345678901234567890123456";
char* testLine2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* testLine3 = "abcdefghijklmnopqrstuvwxyz";
char* testLine4 = "!§$%&()=?´`^°+*~#',;.:-_@€";
char* testLine5_9 = "Font: Monospace 9";
char* testLine5_13 = "Font: Monosp.13";
char* testLine5_18 = "Fnt:MoSpo18";

String oDisplay1 = "";
String oDisplay2 = "";
String oDisplay3 = "";
String oDisplay4 = "";
String oDisplay5 = "";

void setupSsd1306() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.init();
#ifdef SSD1306_FLIP_SCREEN_ORIENTATION
  oDisplay.flipScreenVertically();
#endif
  oDisplay.clear();
  oDisplay.display();
  Serial.println(F("The SSD1306 OLED display is set up"));
#endif  
}

void oDisplayPowerOff() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.displayOff();
#endif  
}

void oDisplayPowerOn() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.displayOn();
#endif  
}

// use oDisplayNormalDisplay() to bring the display back to 'uninverted' mode
void oDisplayInvertDisplay() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.invertDisplay();
#endif  
}

void oDisplayNormalDisplay() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.normalDisplay();
#endif  
}

void oDisplayData() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.clear();
  oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
  oDisplay.setFont(Monospaced_plain_9);
  oDisplay.drawString(0, 0, oDisplay1);
  oDisplay.drawString(0, 12, oDisplay2);
  oDisplay.drawString(0, 24, oDisplay3);
  oDisplay.drawString(0, 36, oDisplay4);
  oDisplay.drawString(0, 48, oDisplay5);
  oDisplay.display();
#endif  
}

void oDisplayData13() {
#ifndef SUPPRESS_DISPLAY_OUTPUT
  oDisplay.clear();
  oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
  oDisplay.setFont(Monospaced_plain_13);
  oDisplay.drawString(0, 0, oDisplay1);
  oDisplay.drawString(0, 12, oDisplay2);
  oDisplay.drawString(0, 24, oDisplay3);
  oDisplay.drawString(0, 36, oDisplay4);
  oDisplay.drawString(0, 48, oDisplay5);
  oDisplay.display();
#endif  
}

void oDisplayData18() {
#ifndef SUPPRESS_DISPLAY_OUTPUT  
  oDisplay.clear();
  oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
  oDisplay.setFont(Monospaced_plain_18);
  oDisplay.drawString(0, 0, oDisplay1);
  oDisplay.drawString(0, 15, oDisplay2);
  oDisplay.drawString(0, 30, oDisplay3);
  oDisplay.drawString(0, 45, oDisplay4);
  oDisplay.display();
#endif  
}

void oDisplayData1813() {
#ifndef SUPPRESS_DISPLAY_OUTPUT
  oDisplay.clear();
  oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
  oDisplay.setFont(Monospaced_plain_18);
  oDisplay.drawString(0, 0, oDisplay1);
  oDisplay.setFont(Monospaced_plain_13);
  oDisplay.drawString(0, 20, oDisplay2);
  oDisplay.drawString(0, 34, oDisplay3);
  oDisplay.drawString(0, 48, oDisplay4);
  oDisplay.display();
#endif  
}

void oDisplayClearData() {
  oDisplay1 = "";
  oDisplay2 = "";
  oDisplay3 = "";
  oDisplay4 = "";
  oDisplay5 = "";
}

void oDisplayTestdata9() {
  oDisplay1 = testLine1;
  oDisplay2 = testLine2;
  oDisplay3 = testLine3;
  oDisplay4 = testLine4;
  oDisplay5 = testLine5_9;
  oDisplayData();
}

void oDisplayTestdata13() {
  oDisplay1 = testLine1;
  oDisplay2 = testLine2;
  oDisplay3 = testLine3;
  oDisplay4 = testLine4;
  oDisplay5 = testLine5_13;
  oDisplayData13();
}

void oDisplayTestdata18() {
  oDisplay1 = testLine1;
  oDisplay2 = testLine2;
  oDisplay3 = testLine3;
  oDisplay4 = testLine5_18;
  oDisplayData18();
}

void oDisplayTestdata1813() {
  oDisplay1 = testLine5_18;
  oDisplay2 = testLine5_13;
  oDisplay3 = testLine5_13;
  oDisplay4 = testLine5_13;
  oDisplayData1813();
}