#ifndef PINS_H
#define PINS_H

constexpr int PIN_NEO_PIXEL = 4; // Arduino pin that connects to NeoPixel

constexpr int frontTriggerPin = 6;
constexpr int frontEchoPin = 7;

constexpr int in4 = 8;  // L298N motor driver input pin 2 for motor B
constexpr int in3 = 9;  // L298N motor driver input pin 1 for motor B
constexpr int in1 = 10; // L298N motor driver input pin 1 for motor A
constexpr int in2 = 11; // L298N motor driver input pin 2 for motor A
constexpr int enB = 12; // L298N motor driver enable pin for motor B
constexpr int enA = 13; // L298N motor driver enable pin for motor A

constexpr int START_PIN = 22;

constexpr int RED_PIN = 23;
constexpr int GREEN_PIN = 24;
constexpr int BLUE_PIN = 25;
constexpr int YELLOW_PIN = 26;

void pinSetup();

#endif // PINS_H