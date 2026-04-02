// MAFTUH SIROJ HAMDANI
// 2412050
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
const int buttonPin = 9;
int pinOut[7] = {A, B, C, D, E, F, G};
int nilai = 9;
int konversi[10][7] = {
 {1,1,1,1,1,1,0}, // 0
 {0,1,1,0,0,0,0}, // 1
 {1,1,0,1,1,0,1}, // 2
 {1,1,1,1,0,0,1}, // 3
 {0,1,1,0,0,1,1}, // 4
 {1,0,1,1,0,1,1}, // 5
 {1,0,1,1,1,1,1}, // 6
 {1,1,1,0,0,0,0}, // 7
 {1,1,1,1,1,1,1}, // 8
 {1,1,1,1,0,1,1} // 9
};
void bacaKonversi(byte digital) {
 for (int segCount = 0; segCount < 7; segCount++) {
 digitalWrite(pinOut[segCount], !konversi[digital][segCount]);
 }
  }
void setup() {
 for (int i = 0; i < 7; i++) {
 pinMode(pinOut[i], OUTPUT);
 }
 Serial.begin(9600);
 pinMode(buttonPin, INPUT_PULLUP);
}
void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    nilai--;          
    delay(500);
  }

  if (nilai < 0) {
    nilai = 9;       
  }

  bacaKonversi(nilai);
}