#include "pins.h"

#include <Arduino.h>

// This file specifies the setup for all the Arduino pins that are used.

void pinSetup()
{
    pinMode(PIN_NEO_PIXEL, OUTPUT);

    // Front Ultrasonic Sensor
    pinMode(frontTriggerPin, OUTPUT);
    pinMode(frontEchoPin, INPUT);

    // Motors Pin Modes
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

    pinMode(START_PIN, INPUT);

    pinMode(RED_PIN, INPUT);
    pinMode(GREEN_PIN, INPUT);
    pinMode(BLUE_PIN, INPUT);
    pinMode(YELLOW_PIN, INPUT);

    pinMode(irLeftPin, INPUT);
    pinMode(irMiddlePin, INPUT);
    pinMode(irRightPin, INPUT);
}