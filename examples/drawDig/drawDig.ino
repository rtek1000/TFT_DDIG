// 800x480 example (tested with SSD1963, 7 inch, parallel data bus)

// Source: https://github.com/rtek1000/TFT_DDIG

/*
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

// Include the TFT library https://github.com/Bodmer/TFT_eSPI
// #include "SPI.h"
//#include <TFT_eSPI.h>              // Hardware-specific library

#include "TFT_DDIG.h"

TFT_DDIG tft = TFT_DDIG();         // Invoke custom library

#define LED_A_pin 23 // Backlight control

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_A_pin, OUTPUT);

  analogWrite(LED_A_pin, 127);

  // Initialise the TFT
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long millis1;

  int i = 0, j;

  while (1)
  {
    tft.configDigit(96, 144, 10); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      tft.drawDigit(j, 150, 0, TFT_GREEN, TFT_BLACK); // update test
    }

    millis1 = millis();
    tft.drawDigit(i, 150, 0, TFT_GREEN, TFT_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 96x144: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    tft.configDigit(15, 30, 3); //  Width, Height, Depth

    j = 15;
    while (j--)
    {
      tft.drawDigit(j, 300, 0, TFT_GREEN, TFT_BLACK); // update test
    }

    millis1 = millis();
    tft.drawDigit(i, 300, 0, TFT_GREEN, TFT_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 15x30: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    tft.configDigit(200, 480, 30); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      tft.drawDigit(j, 350, 0, TFT_GREEN, TFT_BLACK); // update test
    }

    millis1 = millis();
    tft.drawDigit(i, 350, 0, TFT_GREEN, TFT_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 200x480: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    tft.configDigit(100, 300, 15); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      tft.drawDigit(j, 600, 0, TFT_GREEN, TFT_BLACK); // update test
    }

    millis1 = millis();
    tft.drawDigit(i, 600, 0, TFT_GREEN, TFT_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 100x480: ");
    Serial.println(millis1, DEC);

    i++;
    if (i > 15) // SevenSegment96x144Num.c works only between 0-9
    {
      i = 0;
    }
  }
}
