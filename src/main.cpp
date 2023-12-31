#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include <SPI.h>
#include <stdio.h>

#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "fonte.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define XInicial 0
#define Yinicial 63

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixelss
#define LETRA_POR_DISPLAY 5
#define CELA_WIDTH 25

#define OLED_MOSI 41
#define OLED_CLK 42
#define OLED_DC 43
#define OLED_CS1 44
#define OLED_RESET 46

extern "C" {
void app_main(void);
}

void app_main() {
  Adafruit_SSD1306 _display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS1);

  while ((!_display.begin(SSD1306_SWITCHCAPVCC))) {
    delay(50);
  }

  _display.begin(SSD1306_SWITCHCAPVCC);
  _display.clearDisplay();                 // limpa o display
  _display.setFont(&BrailleNeue33pt8b);    // seta a fonte utilizada
  _display.setTextSize(1);                 // Normal 1:1 pixel scale
  _display.setTextColor(SSD1306_INVERSE);  // Draw white text
  _display.setCursor(XInicial, Yinicial);  // Start at top-left corner
  _display.cp437(true);                    // Use full 256 char 'Code Page 437' font

  _display.write('o');
  _display.write('i');
  _display.display();

  while (1) {
    delay(5000);
  }
}