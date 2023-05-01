#ifndef PINS_H
#define PINS_H

// This file specifies constants for the Arduino pins.

constexpr int PIN_NEO_PIXEL = 4; // Arduino pin that connects to NeoPixel

constexpr int frontTriggerPin = 6; // front ultrasonic sensor
constexpr int frontEchoPin = 7; // front ultrasonic sensor

constexpr int in4 = 8;  // L298N motor driver input pin 2 for motor B
constexpr int in3 = 9;  // L298N motor driver input pin 1 for motor B
constexpr int in1 = 10; // L298N motor driver input pin 1 for motor A
constexpr int in2 = 11; // L298N motor driver input pin 2 for motor A
constexpr int enB = 12; // L298N motor driver enable pin for motor B
constexpr int enA = 13; // L298N motor driver enable pin for motor A

constexpr int START_PIN = 22;

// Color selection
constexpr int RED_PIN = 26;
constexpr int GREEN_PIN = 27;
constexpr int BLUE_PIN = 28;
constexpr int YELLOW_PIN = 29;

// Line sensor
#define irLeftPin A0
#define irMiddlePin A1
#define irRightPin A2

void pinSetup();

#endif // PINS_H