#define leftBinPin 6
#define rightBinPin 5
int pulseL_lift = 900;
int pulseR_lift = 1550;
int pulseL_lower = 250;
int pulseR_lower = 2200;

void setup() {
  pinMode(leftBinPin, OUTPUT);
  pinMode(rightBinPin, OUTPUT);

}

void loop() {
  liftBins(pulseL_lower, pulseR_lower);
  delay(3000);
  lowerBins(pulseL_lift, pulseR_lift);
  delay(3000);
}

void liftBins(int PLLower, int PRLower) {
  while ((PLLower < pulseL_lift)&&(PRLower > pulseR_lift)){
    digitalWrite(leftBinPin, HIGH);
    delayMicroseconds(PLLower); //duration of pulse in microseconds
    digitalWrite(leftBinPin, LOW);
    delayMicroseconds(20000-PLLower); //20ms - duration of the pulse

    digitalWrite(rightBinPin, HIGH);
    delayMicroseconds(PRLower); //duration of pulse in microseconds
    digitalWrite(rightBinPin, LOW);
    delayMicroseconds(20000-PRLower); //20ms - duration of the pulse

    PLLower += 2;
    PRLower -= 2;
  }
}

void lowerBins(int PLLift, int PRLift) {
  while ((PLLift > pulseL_lower)&&(PRLift < pulseR_lower)){
    digitalWrite(leftBinPin, HIGH);
    delayMicroseconds(PLLift); //duration of pulse in microseconds
    digitalWrite(leftBinPin, LOW);
    delayMicroseconds(20000-PLLift); //20ms - duration of the pulse

    digitalWrite(rightBinPin, HIGH);
    delayMicroseconds(PRLift); //duration of pulse in microseconds
    digitalWrite(rightBinPin, LOW);
    delayMicroseconds(20000-PRLift); //20ms - duration of the pulse

    PLLift -= 2;
    PRLift += 2;
  }
}