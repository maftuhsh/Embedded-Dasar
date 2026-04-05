#define pinA 7
#define pinB 8
#define pwm 11

int gasPin = A0;
int nilaiGas = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pwm, OUTPUT);
}

void loop() {
    nilaiGas = analogRead(gasPin);
    Serial.println(nilaiGas);

    if (nilaiGas < 220) {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        analogWrite(pwm, 0);

    } else if (nilaiGas >= 220 && nilaiGas < 400) {
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        analogWrite(pwm, 153); // 100 + 2 angka belakang NIM

    } else {
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        analogWrite(pwm, 255);
    }

    delay(500);
}

