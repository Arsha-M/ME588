#ifndef ULTRASONIC_H
#define ULTRASONIC_H

double distanceInInches(int triggerPin, int echoPin);
void stayParallel(int stopDistanceInches);

#endif // ULTRASONIC_H