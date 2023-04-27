#define binDoorPin 6
int pos = 300;
void setup() {
  pinMode(binDoorPin, OUTPUT);
}

void loop() {
  // initial position
  digitalWrite(binDoorPin, HIGH);
  delayMicroseconds(pos); //duration of pulse in microseconds
  digitalWrite(binDoorPin, LOW);
  delayMicroseconds(pos); //20ms - duration of the pulse
  // specified positions
  pos = closeAll(pos);
  delay(1000);
  pos = openAll(pos);
  delay(1000);
  pos = openConstruction(pos);
  delay(1000);
  pos = openHome(pos);
  delay(1000);
}

int closeAll(int pos) {
  int binDoorPulse = 1650;
  if (pos < binDoorPulse){
    while(pos <= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos += 5;
    }
  } else{
    while(pos >= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos -= 5;
    }
  }
  return pos;
}

int openAll(int pos) {
  int binDoorPulse = 700;
  if (pos < binDoorPulse){
    while(pos <= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos += 5;
    }
  } else{
    while(pos >= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos -= 5;
    }
  }
  return pos;
}

int openConstruction(int pos) {
  int binDoorPulse = 1175;
  if (pos < binDoorPulse){
    while(pos <= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos += 5;
    }
  } else{
    while(pos >= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos -= 5;
    }
  }
  return pos;
}

int openHome(int pos) {
  int binDoorPulse = 2100;
  if (pos < binDoorPulse){
    while(pos <= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos += 5;
    }
  } else{
    while(pos >= binDoorPulse){
      digitalWrite(binDoorPin, HIGH);
      delayMicroseconds(pos); //duration of pulse in microseconds
      digitalWrite(binDoorPin, LOW);
      delayMicroseconds(pos); //20ms - duration of the pulse
      pos -= 5;
    }
  }
  return pos;
}
