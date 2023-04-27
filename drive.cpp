#include "drive.h"
#include "pins.h"
#include "RGBStrip.h"

#include <Arduino.h>

void driveSetup()
{
    Serial.begin(9600);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}

void turnRight(int speed, int durationMilliseconds)
{
    Serial.println("Right");
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
    Serial.println("Left");
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
    Serial.println("Forward");
    updateRGBStrip(1);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, speed);
    analogWrite(enB, speed-15);
}

void forwardRight(int speed)
{
  updateRGBStrip(2);
      digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, speed-20);
    analogWrite(enB, speed);
}

void forwardLeft(int speed)
{
  updateRGBStrip(3);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, speed);
    analogWrite(enB, speed-20);
}

void driveBackward(int speed)
{
    updateRGBStrip(-1);
}

void driveStop()
{
  Serial.println("Stop");
    updateRGBStrip(0);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}