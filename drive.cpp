#include "drive.h"
#include "pins.h"
#include "RGBStrip.h"

#include <Arduino.h>

void driveSetup()
{
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}

void turnRight(int speed, int durationMilliseconds)
{
    updateRGBStrip(2);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, speed);
    analogWrite(enB, speed);

    delay(durationMilliseconds);
}

void turnLeft(int speed, int durationMilliseconds)
{
    updateRGBStrip(3);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    analogWrite(enA, speed);
    analogWrite(enB, speed);

    delay(durationMilliseconds);
}

void driveForward(int speed)
{
    updateRGBStrip(1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, speed);
    analogWrite(enB, speed);
}

void driveBackward(int speed)
{
    updateRGBStrip(-1);
}

void driveStop()
{
    updateRGBStrip(0);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}