
#define leftArmPin 6
  //left bucket arm: 625 - 0 deg; 1265 - 90 deg, 1900 - 180 deg; 2225 - 270 deg
  //left swinging arm: 2600 - 'closed', 400 - 'open' (as far as possible - will run into side), 700 - more reasonable for 'open' - 1900
 #define rightArmPin 5
  //rigth bucket arm: 1525 - 0 deg; 865 - 90 deg;
  //right swinging arm: 350 - 'closed', 2600 - 'open' (as far as possible - will run into side), 1900 - more reasonable for 'open' - 1900
int pulseR_close = 340;
int pulseL_close = 2610;
int pulseR_open = 2000;
int pulseL_open = 950;

void setup() {
  pinMode(leftArmPin, OUTPUT);
  pinMode(rightArmPin, OUTPUT);

}

void loop() {
  digitalWrite(rightArmPin, HIGH);
  delayMicroseconds(pulseR_close); //duration of pulse in microseconds
  digitalWrite(rightArmPin, LOW);
  delayMicroseconds(20000-pulseR_close); //20ms - duration of the pulse
  digitalWrite(leftArmPin, HIGH);
  delayMicroseconds(pulseL_close); //duration of pulse in microseconds
  digitalWrite(leftArmPin, LOW);
  delayMicroseconds(20000-pulseL_close); //20ms - duration of the pulse
  delay(1000);
  openArms(350,2600);
  delay(1000);
  closeArms(2000,950);
  //delay(4000);
}

void openArms(int posR, int posL) {
  while (posR < pulseR_open){
    if (posL > pulseL_open){
      digitalWrite(leftArmPin, HIGH);
      delayMicroseconds(posL); //duration of pulse in microseconds
      digitalWrite(leftArmPin, LOW);
      delayMicroseconds(20000-posL); //20ms - duration of the pulse
      posL -= 10;
    }
    if (posL > pulseL_open-60){
      digitalWrite(rightArmPin, HIGH);
      delayMicroseconds(posR); //duration of pulse in microseconds
      digitalWrite(rightArmPin, LOW);
      delayMicroseconds(20000-posR); //20ms - duration of the pulse
      posR += 10;
    }
  }
}


void closeArms(int posR, int posL) {
  while (posL > pulseL_close){
    if (posR > pulseR_close) {
      digitalWrite(rightArmPin, HIGH);
      delayMicroseconds(posR); //duration of pulse in microseconds
      digitalWrite(rightArmPin, LOW);
      delayMicroseconds(20000-posR); //20ms - duration of the pulse
      posR -= 10;
    }    
    if (posR > pulseR_close) {
      digitalWrite(leftArmPin, HIGH);
      delayMicroseconds(posL); //duration of pulse in microseconds
      digitalWrite(leftArmPin, LOW);
      delayMicroseconds(20000-posL); //20ms - duration of the pulse
      posL += 10;
    }
  }
}




