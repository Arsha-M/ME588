#ifndef DRIVE_H
#define DRIVE_H

void driveSetup();

void turnRight(int speed, int durationMilliseconds);
void turnLeft(int speed, int durationMilliseconds);
void driveForward(int speed);
void driveBackward(int speed);
void driveStop();

void forwardRight(int speed);
void forwardLeft(int speed);

#endif // DRIVE_H