#ifndef RGBSTRIP_H
#define RGBSTRIP_H

#include <Adafruit_NeoPixel.h>

constexpr int PIN_NEO_PIXEL = 4;   // Arduino pin that connects to NeoPixel
constexpr int NUM_PIXELS = 8;

constexpr int START_PIN = 13;
constexpr int RED_PIN = 12;
constexpr int GREEN_PIN = 11;
constexpr int YELLOW_PIN = 10;
constexpr int BLUE_PIN = 9;

const int orangeLEDDelay = 300;

void RGBSetup();
void updateRGBStrip(bool isBucketLifting);

#endif // RGBSTRIP_H