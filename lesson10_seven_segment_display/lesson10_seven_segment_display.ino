const int a=7;
const int b=6;
const int c=5;
const int d=11;
const int e=10;
const int f=8;
const int g=9;
const int dp=4;

int displayPins[] = {a,b,c,d,e,f,g,dp};
const int displayPinsCount = sizeof(displayPins)/sizeof(int);
const int lowestNumber = 0;
const int highestNumber = 9;

// negative number used to indicate end of pin array
int numberToPins[][displayPinsCount] = {
  {a,b,c,d,e,f,-1},
  {b,c,-1},
  {a,b,g,e,d,-1},
  {a,b,g,c,d,-1},
  {f,b,g,c,-1},
  {a,f,g,c,d,-1},
  {a,f,g,c,d,e,-1},
  {a,b,c,-1},
  {a,b,c,d,e,f,g,-1},
  {a,b,c,f,g,-1}
};
 
void setup() {
  for (int i = 0; i < displayPinsCount; i++) {
    pinMode(displayPins[i],OUTPUT);
  }
}
 
void loop() {
  for (int numberToDisplay = lowestNumber; numberToDisplay <= highestNumber; numberToDisplay++) {
    changeDisplay(numberToPins[numberToDisplay]);
    delay(1000);
  }
}
 
void changeDisplay(int pins[]) {
  for (int i = 0; i < displayPinsCount; i++) {
    digitalWrite(displayPins[i], LOW); 
  }

  int i = 0;
  int nextPin;
  while (nextPin = pins[i] >= 0) {
    digitalWrite(pins[i], HIGH);
    i++;
  }
}

