const int latchPin = 8;//Pin connected to ST_CP of 74HC595
const int clockPin = 12;//Pin connected to SH_CP of 74HC595
const int dataPin = 11; //Pin connected to DS of 74HC595

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  // cycle through dots one at a time, bottom-left to top-right
  for(int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << row));
      shiftOut(dataPin, clockPin, MSBFIRST, (1 << col));
      digitalWrite(latchPin, HIGH);
      delay(100);
    }
  }
}
