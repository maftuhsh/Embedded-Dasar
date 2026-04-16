#include <DHT.h>

#define DHTPIN 7       
#define DHTTYPE DHT11  
#define ENB 5          
#define IN3 9          
#define IN4 6          

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  int pwmValue = map(temperature, 20, 40, 0, 255);
  pwmValue = constrain(pwmValue, 0, 255);

  analogWrite(ENB, pwmValue);

  delay(2000);
}