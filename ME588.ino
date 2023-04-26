#include "pins.h"
#include "RGBStrip.h"

int startGame = 0;
bool isBucketLifting = false;

// Define robot speeds
#define SPEED1 100 // Slow speed
#define SPEED2 200 // Medium speed
#define SPEED3 255 // Fast speed

// Distance threshold definitions
#define DIST1 50  // Distance threshold for switching to slow speed
#define DIST2 20  // Distance threshold for switching to medium speed
#define DIST3 300 // Distance threshold for switching to fast speed

void setup()
{
  RGBSetup();
  pinSetup();

  // Start motors at 0
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

// Function to turn robot left
void turnRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(enA, SPEED1);
  analogWrite(enB, SPEED1);
}

void loop()
{
  int counter = 0;

  while (startGame)
  {
    // Read distance from front ultrasonic sensor
    long duration, distance;
    digitalWrite(frontTriggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(frontTriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(frontTriggerPin, LOW);
    duration = pulseIn(frontEchoPin, HIGH);
    distance = duration * 0.034 / 2;

    while (counter < 1)
    {
      // Front Ultrasonic Sensor Logic
      if (distance <= DIST1)
      {
        // Drive the robot forward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        analogWrite(enA, SPEED1);
        analogWrite(enB, SPEED1);
      }
      else
      {
        // Turn left for 10 seconds
        turnRight();
        delay(10000);

        counter = counter + 1;
      }
    }

    while (counter >= 1)
    {
      if (distance <= DIST2)
      {
        // Drive the robot forward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        analogWrite(enA, SPEED1);
        analogWrite(enB, SPEED1);
      }
      else
      {
        break;
      }
    }
  }

  startGame = 0;
}