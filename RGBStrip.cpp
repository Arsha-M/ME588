#include "RGBStrip.h"
#include "pins.h"

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void RGBSetup()
{
  NeoPixel.begin();
}

void updateRGBStrip(bool isBucketLifting)
{
  int currentOrangeLED = 2;
  unsigned long orangeLEDSetTime = millis();

  if (digitalRead(START_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(0, NeoPixel.Color(255, 255, 255));
  }
  else
  {
    NeoPixel.setPixelColor(0, NeoPixel.Color(0, 0, 0));
  }

  if (digitalRead(RED_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(255, 0, 0));
  }
  else if (digitalRead(GREEN_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 255, 0));
  }
  else if (digitalRead(YELLOW_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(255, 255, 0));
  }
  else if (digitalRead(BLUE_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 255));
  }
  else
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 0));
  }

  NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.

  if (isBucketLifting)
  {
    NeoPixel.setPixelColor(currentOrangeLED, NeoPixel.Color(255, 165, 0));
    NeoPixel.show();
    if ((millis() - orangeLEDSetTime) > orangeLEDDelay)
    {
      Serial.println(orangeLEDSetTime);
      NeoPixel.setPixelColor(currentOrangeLED, NeoPixel.Color(0, 0, 0));
      NeoPixel.show();
      currentOrangeLED++;
      if (currentOrangeLED == 8)
      {
        currentOrangeLED = 2;
      }
      orangeLEDSetTime = millis();
    }
  }
}