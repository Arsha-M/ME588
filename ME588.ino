#include "RGBStrip.h"

void setup()
{
  RGBSetup();
}

bool isBucketLifting = false;

void loop(){
  updateRGBStrip(isBucketLifting);
}