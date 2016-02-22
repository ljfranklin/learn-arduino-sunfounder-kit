#include <LiquidCrystal.h>

char message[]="hello, world!             ";
const int messageLength = sizeof(message) / sizeof(char);
const int displayWidth = 16;
const int displayHeight = 2;
int delayTime = 250;

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup() {
  lcd.begin(displayWidth, displayHeight);
}

void loop() {
  lcd.setCursor(displayWidth - 1,0);
  for (int i = 0; i < messageLength; i++) {
    lcd.scrollDisplayLeft();
    lcd.print(message[i]);
    delay(delayTime);
  }
  lcd.clear();
}
