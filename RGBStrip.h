#ifndef RGBSTRIP_H
#define RGBSTRIP_H

#include <Adafruit_NeoPixel.h>

constexpr int NUM_PIXELS = 8;

void RGBSetup();
void updateRGBStrip(int driveStatus);

#endif // RGBSTRIP_H