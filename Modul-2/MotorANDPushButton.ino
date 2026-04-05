#define pb 2
#define pinA 7
#define pinB 8
#define pwm 11

int count = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(pb, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(pb) == LOW) {
        count++;
        if (count > 1) {
            count = 0;
        }

        while (digitalRead(pb) == LOW) {
            delay(10);
        }

        Serial.println(count);
    }

    // KONTROL MOTOR
    if (count == 0) {
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        analogWrite(pwm, 200);
    } else {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        analogWrite(pwm, 200);
    }
}
