#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

char hexaKeys [4] [4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPin [4] = {A0, A1, A2, A3};
byte colPin [4] = {A4, A5, 7, 6};
String data = "";
int Sudut;

Keypad customKeypad = Keypad (makeKeymap (hexaKeys), rowPin, colPin, 4, 4);

#define pinServo 10
Servo servo; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup()
{
  servo.attach (pinServo);
  lcd.begin(16, 2);
  servo.write(0);
  lcd.setCursor(0, 0);
  lcd.print("Sudut : ");
}

void loop()
{
  char key = customKeypad.getKey();
  if (key){
    data += key;
    lcd.setCursor(8, 0);
    lcd.print(data);

    if (key == 'D'){
      int h = data.length();
      data.remove (h - 2, 2);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sudut : ");
      lcd.print(data); 
    }
    if (data == 'D'){
      data = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sudut : ");
    }
    if (key == '#'){
      int h = data.length();
      data.remove (h - 1, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sudut : ");
      lcd.print(data);

      Sudut = data.toInt();
      int readServo = servo.read();
      servo.write(Sudut);

      if (Sudut > 181 || Sudut < 0){
        lcd.clear();
        lcd.print("ERROR");
        servo.write(readServo);
      }
    }

  }
}
