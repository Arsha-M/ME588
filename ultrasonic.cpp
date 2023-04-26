#include "drive.h"
#include "ultrasonic.h"

#include <Arduino.h>

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

// void stayParallel(int stopDistanceInches)
// {
//     double frontDistance;
//     double yaw;
//     int turnThreshold = 1;
//     do {
//         R1Distance = distanceInInches(R1TriggerPin, R1EchoPin);
//         R2Distance = distanceInInches(R2TriggerPin, R2EchoPin);
//         yaw = R1Distance - R2Distance;
//         if(yaw > turnThreshold)
//         {
//             // Turn Right
//         }
//         else if(yaw < -turnThreshold)
//         {
//             // Turn Left
//         }
//         else
//         {
//             // driveStraight
//         }
//         frontDistance = distanceInInches(frontTriggerPin, frontEchoPin);
//     }
//     while (frontDistance >= stopDistanceInches);
// }