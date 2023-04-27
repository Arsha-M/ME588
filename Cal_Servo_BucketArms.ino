#define leftServoPin 6
  //left bucket arm: 625 - 0 deg; 1265 - 90 deg, 1900 - 180 deg; 2225 - 270 deg
  //left swinging arm: 350 - 'closed', 2600 - 'open' (as far as possible - will run into side), 1900 - more reasonable for 'open' - 1900
#define rightServoPin 5
  //rigth bucket arm: 1525 - 0 deg; 865 - 90 deg;
  //right swinging arm: 2600 - 'closed', 400 - 'open' (as far as possible - will run into side), 1000 - more reasonable for 'open' - 1900
int pulseL_liftB = 1535;
int pulseR_liftB = 665;
int pulseL_lowerB = 850;
int pulseR_lowerB = 1350;

void setup() {
  pinMode(leftServoPin, OUTPUT);
  pinMode(rightServoPin, OUTPUT);

}

void loop() {
  liftBucket(pulseL_lowerB, pulseR_lowerB);
  delay(5000);
  lowerBucket(pulseL_liftB, pulseR_liftB);
  delay(5000);
}

void liftBucket(int PLLower, int PRLower) {
  while ((PLLower < pulseL_liftB)&&(PRLower > pulseR_liftB)){
    digitalWrite(leftServoPin, HIGH);
    delayMicroseconds(PLLower); //duration of pulse in microseconds
    digitalWrite(leftServoPin, LOW);
    delayMicroseconds(20000-PLLower); //20ms - duration of the pulse

    digitalWrite(rightServoPin, HIGH);
    delayMicroseconds(PRLower); //duration of pulse in microseconds
    digitalWrite(rightServoPin, LOW);
    delayMicroseconds(20000-PRLower); //20ms - duration of the pulse

    PLLower += 2;
    PRLower -= 2;
  }
}

void lowerBucket(int PLLift, int PRLift) {
  while ((PLLift > pulseL_lowerB)&&(PRLift < pulseR_lowerB)){
    digitalWrite(leftServoPin, HIGH);
    delayMicroseconds(PLLift); //duration of pulse in microseconds
    digitalWrite(leftServoPin, LOW);
    delayMicroseconds(20000-PLLift); //20ms - duration of the pulse

    digitalWrite(rightServoPin, HIGH);
    delayMicroseconds(PRLift); //duration of pulse in microseconds
    digitalWrite(rightServoPin, LOW);
    delayMicroseconds(20000-PRLift); //20ms - duration of the pulse

    PLLift -= 2;
    PRLift += 2;
  }
}