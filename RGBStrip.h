#ifndef RGBSTRIP_H
#define RGBSTRIP_H

#include <Adafruit_NeoPixel.h>

constexpr int NUM_PIXELS = 8;

const int orangeLEDDelay = 300;

void RGBSetup();
void updateRGBStrip(bool isBucketLifting);
void updateRGBStrip(int driveStatus);

#endif // RGBSTRIP_H


//asdf