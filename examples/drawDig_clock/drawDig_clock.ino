// 800x480 digital clock example (tested with SSD1963, 7 inch, parallel data bus)

// Source: https://github.com/rtek1000/TFT_DDIG

/*
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

// Date and time functions using just software, based on millis() & timer
// Need RTClib (by Adafruit) https://github.com/adafruit/RTClib or
// You can add/install RTClib: Sketch > Include lbrary > Manage library > "Filter your search" > Type: RTClib)

// Include the TFT library https://github.com/Bodmer/TFT_eSPI
// #include "SPI.h"
//#include <TFT_eSPI.h>              // Hardware-specific library

#include "TFT_DDIG.h"
#include <TimeLib.h>
#include <Wire.h>         // this #include still required because the RTClib depends on it
#include "RTClib.h"

TFT_DDIG tft = TFT_DDIG();         // Invoke custom library

RTC_Millis rtc;

int second_old = 0, disp_d10 = 0, disp_d1 = 0, disp_u1 = 0, disp_u10 = 0;
bool blink_point;

#define LED_A_pin 23 // Backlight control

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_A_pin, OUTPUT);

  analogWrite(LED_A_pin, 127);
  
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));

  // Initialise the TFT
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  Serial.begin(9600);

  tft.fillScreen(TFT_BLACK);

  tft.fillCircle(400, 160, 10, TFT_MAGENTA);
  tft.fillCircle(400, 320, 10, TFT_MAGENTA);

  tft.configDigit(162, 480, 30); //  Width, Height, Depth

  DateTime now = rtc.now();

  disp_u1 = now.second() - ((now.second() / 10) * 10);
  disp_u10 = now.second() / 10;
  disp_d1 = now.minute() - ((now.minute() / 10) * 10);
  disp_d10 = now.minute() / 10;

  tft.drawDigit(disp_u1, 638, 0, TFT_GREEN, TFT_BLACK); // update test
  tft.drawDigit(disp_u10, 426, 0, TFT_GREEN, TFT_BLACK); // update test
  tft.drawDigit(disp_d1, 214, 0, TFT_GREEN, TFT_BLACK); // update test
  tft.drawDigit(disp_d10, 0, 0, TFT_GREEN, TFT_BLACK); // update test
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  if (second_old != now.second())
  {
    second_old = now.second();

    disp_u1 = now.minute() - ((now.minute() / 10) * 10);
    tft.drawDigit(disp_u1, 638, 0, TFT_GREEN, TFT_BLACK); // update test

    if (disp_u10 != (now.minute() / 10))
    {
      disp_u10 = now.minute() / 10;
      tft.drawDigit(disp_u10, 426, 0, TFT_GREEN, TFT_BLACK); // update test
      if (disp_d1 != (now.hour() - ((now.hour() / 10) * 10)))
      {
        disp_d1 = now.hour() - ((now.hour() / 10) * 10);
        tft.drawDigit(disp_d1, 214, 0, TFT_GREEN, TFT_BLACK); // update test
        if (disp_d10 != (now.hour() / 10))
        {
          disp_d10 = now.hour() / 10;
          tft.drawDigit(disp_d10, 0, 0, TFT_GREEN, TFT_BLACK); // update test
        }
      }
    }

    if (blink_point)
    {
      blink_point = false;
      tft.fillCircle(400, 160, 10, TFT_BLACK);
      tft.fillCircle(400, 320, 10, TFT_BLACK);

      tft.drawCircle(400, 160, 10, TFT_GREEN);
      tft.drawCircle(400, 320, 10, TFT_GREEN);
    }
    else
    {
      blink_point = true;
      tft.fillCircle(400, 160, 10, TFT_GREEN);
      tft.fillCircle(400, 320, 10, TFT_GREEN);
    }
  }
}
