#include "RGBStrip.h"
#include "drive.h"
#include "pins.h"

bool startGame = false;
bool isBucketLifting = false;
const int endTimeMilliseconds = 2 * 60 * 1000;

// Define robot speeds
#define SPEED1 100 // Slow speed
#define SPEED2 200 // Medium speed
#define SPEED3 255 // Fast speed

// Distance threshold definitions
#define DIST1 50  // Distance threshold for switching to slow speed
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
      driveForward(SPEED1);
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

    turnRight(SPEED1, 10000);
    driveStop();
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST1)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
    FSM_STATE = RETURN_HOME;

    break;

  case RETURN_HOME:
    if (elapsedTime > endTimeMilliseconds)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }

    turnRight(SPEED1, 10000);
    driveStop();
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST2)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
    break;

  case STOP_FOREVER:
    while (true)
    {
      driveStop();
    }
    break;
  }
}