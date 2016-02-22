const int redPin = 7;
const int yellowPin = 8;
const int greenPin = 9;
const int clkPin = 2;
const int dtPin = 3;
const int swPin = 6;

int oldA = HIGH;
int encoderVal = 0;
 
int state = 0;
int shortPeriod = 1000;
int longPeriod = 1500;
int maxLongPeriod = 5000;
int targetCount = shortPeriod;
int count = 0;
 
void setup() {
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);
    pinMode(swPin, INPUT);
    digitalWrite(swPin, HIGH);
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Serial.begin(9600);
}
 
void loop() {
  count++;
  int change = getEncoderTurn();
  longPeriod = longPeriod + change * 100;
  if (longPeriod > maxLongPeriod) {
    longPeriod = maxLongPeriod;
  }
  if (longPeriod < shortPeriod) {
    longPeriod = shortPeriod;
  }
  
  if (digitalRead(swPin) == LOW) {
    setLights(HIGH, HIGH, HIGH);
  } else if (count == targetCount) {
    setState();
    count = 0;
  }
  delay(1);
}
 
void setState() {
  switch (state) {
    case 0:
      //red
      setLights(HIGH, LOW, LOW);
      targetCount = longPeriod;
      state = 1;
      break;
    case 1:
      //green
      setLights(LOW, LOW, HIGH);
      targetCount = longPeriod;
      state = 2;
      break;
    case 2:
      //yellow
      setLights(LOW, HIGH, LOW);
      targetCount = shortPeriod;
      state = 0;
      break;
  }
}

int getEncoderTurn() {
  int result = 0;
  int newA = digitalRead(clkPin);
  if (oldA == HIGH && newA == LOW) {
    int bVal = digitalRead(dtPin);
    result = (bVal == HIGH) ? 1 : -1; 
  }
  oldA = newA;
  return result;
}
 
void setLights(int redState, int yellowState, int greenState) {
  digitalWrite(redPin, redState);
  digitalWrite(yellowPin, yellowState);
  digitalWrite(greenPin, greenState);
}
