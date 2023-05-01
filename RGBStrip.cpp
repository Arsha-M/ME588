#include "RGBStrip.h"
#include "pins.h"

Adafruit_NeoPixel NeoPixel = Adafruit_NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_RGBW + NEO_KHZ800);

void RGBSetup()
{
  NeoPixel.begin();
}

// Updates RGB strip with proper LED colors. Should be called every time a drive state is called.
// driveState = -1 means driveBackward
// driveState = 0 means driveStop();
// driveState = 1 means driveForward();
// driveState = 2 means turnRight();
void updateRGBStrip(int driveState)
{
  NeoPixel.clear();

  if (digitalRead(START_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(0, NeoPixel.Color(0, 0, 0, 100));
  }
  else
  {
    NeoPixel.setPixelColor(0, NeoPixel.Color(0, 0, 0, 0));
  }

  if (digitalRead(RED_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 50, 0, 0));
  }
  else if (digitalRead(GREEN_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(50, 0, 0, 0));
  }
  else if (digitalRead(YELLOW_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(50, 50, 0, 0));
  }
  else if (digitalRead(BLUE_PIN) == HIGH)
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 50, 0));
  }
  else
  {
    NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 0, 0));
  }

  switch(driveState)
  {
    case -1:
      for(int i=2; i < 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(0, 100, 0, 0));
      }
      break;
    case 0:
      for(int i = 2; i < 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(87, 255, 51, 0));
      }
      break;
    
    case 1:
      for(int i = 2; i < 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(100, 0, 0, 0));
      }
      break;
    
    case 2:
      for (int i = 2; i< 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(0, 0, 100, 0));
      }
      break;
    
    case 3:
      for (int i = 2; i< 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(0, 100, 100, 0));
      }
      break;
    default:
            for (int i = 2; i< 8; i++)
      {
        NeoPixel.setPixelColor(i, NeoPixel.Color(0, 0, 0, 0));
      }
      break;

  }

  NeoPixel.show();
}