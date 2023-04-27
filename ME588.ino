#include "RGBStrip.h"
#include "drive.h"
#include "pins.h"

bool startGame = false;
bool isBucketLifting = false;
const int endTimeMilliseconds = 2 * 60 * 1000;

// Define robot speeds
#define SPEED1 205 // Slow speed
#define SPEED2 220 // Medium speed
#define SPEED3 255 // Fast speed

// Distance threshold definition
#define DIST1 30  // Distance threshold for switching to slow speed
#define DIST2 20  // Distance threshold for switching to medium speed
#define DIST3 300 // Distance threshold for switching to fast speed
const int DO_NOTHING = 0;
const int LINE_FOLLOW_FORWARD = 1;
const int TURN_RIGHT_INTO_WALL = 2;
const int RETURN_HOME = 3;
const int STOP_FOREVER = 4;
int FSM_STATE = DO_NOTHING;

void setup()
{
  pinSetup();
  driveSetup();
  RGBSetup();
}

int getFrontDistance()
{
  digitalWrite(frontTriggerPin, LOW); // Clear the trigPin by setting it LOW:
  delayMicroseconds(2);               // Set the trigPin high for 10 microseconds:
  digitalWrite(frontTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  long duration = pulseIn(frontEchoPin, HIGH); // Read the echoPin, and calculate the duration in microseconds:
  int distance = duration / 58;                // Calculate the distance in centimeters using the speed of sound:
  return distance;
}

unsigned long startTime;
unsigned long currentTime;
unsigned long elapsedTime;
int frontDistance;

int irLeftVal;
int irMiddleVal;
int irRightVal;

const int irThreshold = 200;

bool lastTurnRight = false;

void loop()
{
  if (!startGame && startGame != digitalRead(START_PIN))
  {
    startTime = millis();
  }
  else if (startGame)
  {
    currentTime = millis();
    elapsedTime = currentTime - startTime;
  }
  startGame = digitalRead(START_PIN);

  switch (FSM_STATE)
  {
  case DO_NOTHING:
    if (startGame && elapsedTime < endTimeMilliseconds)
    {
      FSM_STATE = LINE_FOLLOW_FORWARD;
    }
    updateRGBStrip(0);
    break;

  case LINE_FOLLOW_FORWARD:
    if (elapsedTime > endTimeMilliseconds)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST1)
    {
      irLeftVal = analogRead(irLeftPin);
      irMiddleVal = analogRead(irMiddlePin);
      irRightVal = analogRead(irRightPin);

      Serial.println(irRightVal);
      Serial.println(irMiddleVal);
      Serial.println(irLeftVal);

      if(irMiddleVal < irThreshold)
      {
        Serial.println("Entered Middle");
        driveForward(SPEED1);
      }
      else if (irLeftVal < irThreshold)
      {
        Serial.println("Entered Left");
        turnLeft(SPEED2, 25);
      }
      else if (irRightVal < irThreshold)
      {
        Serial.println("Entered Right");
        turnRight(SPEED2, 25);
      }
      frontDistance = getFrontDistance();
    }
    driveStop();
    FSM_STATE = TURN_RIGHT_INTO_WALL;
    break;

  case TURN_RIGHT_INTO_WALL:
    if (elapsedTime > endTimeMilliseconds)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }

    turnRight(SPEED2, 750);
    driveStop();
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST2)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
    FSM_STATE = RETURN_HOME;
    delay(3000);
    break;

  case RETURN_HOME:
    if (elapsedTime > endTimeMilliseconds)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }

    turnRight(SPEED2, 750);
    driveStop();
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST2)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
    FSM_STATE = STOP_FOREVER;
    break;

  case STOP_FOREVER:
    while (true)
    {
      driveStop();
    }
    break;
  }
}