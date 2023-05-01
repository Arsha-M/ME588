#include "RGBStrip.h"
#include "drive.h"
#include "pins.h"

bool startGame = false;
const int endTimeMilliseconds = 2 * 60 * 1000;

// Define robot speeds
#define SPEED1 185 // Forward Speed
#define SPEED2 180 // Turning Speed
#define SPEED3 255 // Max Speed

// Distance threshold definition
#define DIST1 30  // Distance threshold for end of field
#define DIST2 20  // Distance threshold for side wall
#define DIST3 60 // Distance threshold for zone wall

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

// Returns ultrasonic distance in cm.
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

void loop()
{
  // Check for start switch and initialize 2 min timer.
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

  // Switch-Case for FSM
  switch (FSM_STATE)
  {
  case DO_NOTHING:
    if (startGame && elapsedTime < endTimeMilliseconds)
    {
      FSM_STATE = LINE_FOLLOW_FORWARD;
    }
    updateRGBStrip(-10);
    break;

  case LINE_FOLLOW_FORWARD:
    if (elapsedTime > endTimeMilliseconds || !startGame)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }
    frontDistance = getFrontDistance();
    if (frontDistance >= DIST1)
    {
      
      irLeftVal = analogRead(irLeftPin);
      irMiddleVal = analogRead(irMiddlePin);
      irRightVal = analogRead(irRightPin);

      // Choose direction based on IR line sensors
      if(irMiddleVal < irThreshold)
      {
        driveForward(SPEED1);
      }
      else if (irLeftVal < irThreshold)
      {
        turnLeft(SPEED2, 25);
      }
      else if (irRightVal < irThreshold)
      {
        turnRight(SPEED2, 25);
      }
      frontDistance = getFrontDistance();
    }
    else
    {
      driveStop();
      FSM_STATE = TURN_RIGHT_INTO_WALL;
    }
    break;

  case TURN_RIGHT_INTO_WALL:
    if (elapsedTime > endTimeMilliseconds || !startGame)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }

    // Turn right towards side wall
    turnRight(SPEED2, 750);
    driveStop();

    // Drive forward until wall detected
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST2)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
  
    FSM_STATE = RETURN_HOME;
    delay(1000); // Pause for debugging
    break;

  case RETURN_HOME:
    if (elapsedTime > endTimeMilliseconds || !startGame)
    {
      FSM_STATE = DO_NOTHING;
      break;
    }

    // Turn right towards home zone
    turnRight(SPEED2, 750);
    driveStop();

    // Drive home until wall
    frontDistance = getFrontDistance();
    while (frontDistance >= DIST3)
    {
      driveForward(SPEED1);
      frontDistance = getFrontDistance();
    }
    driveStop();
    FSM_STATE = STOP_FOREVER; // Stops forever (Robot only ever does 1 pass)
    break;

  case STOP_FOREVER:
    while (true)
    {
      driveStop();
    }
    break;
  }
}