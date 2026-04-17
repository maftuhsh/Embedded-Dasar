#include <LiquidCrystal.h>
const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

#define pinGas A0

unsigned long waktusebelum = 0;
int nilaisensor = 0;

void setup()
{
  lcd.begin (16, 2);
  lcd.backlight();
  pinMode (pinGas, INPUT);
}

void loop()
{
  if (millis () - waktusebelum - 100){
  nilaisensor = analogRead (pinGas);
 			 nilaisensor = nilaisensor * 0.0097;
  lcd.clear();
  waktusebelum - millis();
}

lcd.setCursor(0, 0);
lcd.print("pinGas : ");
lcd.print(nilaisensor);
lcd.print(" % ");
delay (10);
}
