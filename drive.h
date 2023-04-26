#ifndef DRIVE_H
#define DRIVE_H

void driveSetup();

void turnRight(int speed, int durationMilliseconds);
void turnLeft(int speed, int durationMilliseconds);
void driveForward(int speed);
void driveBackward(int speed);
void driveStop();

#endif // DRIVE_H