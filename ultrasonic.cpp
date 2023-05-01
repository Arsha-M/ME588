#include "drive.h"
#include "ultrasonic.h"

#include <Arduino.h>

// Returns ultrasonic distance in inches.
double distanceInInches(int triggerPin, int echoPin)
{
    digitalWrite(triggerPin, LOW); // Clear the trigPin by setting it LOW:
    delayMicroseconds(2);          // Set the trigPin high for 10 microseconds:
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    long duration = pulseIn(echoPin, HIGH);       // Read the echoPin, and calculate the duration in microseconds:
    double distance = duration * 0.0135039 * 0.5; // Calculate the distance in inches using the speed of sound:
    return distance;
}