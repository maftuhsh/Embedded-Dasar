int SensorGAS = A0;
int GasValue;
void setup() {
  // put your setup code here, to run once:
  pinMode(SensorGAS,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  GasValue = analogRead(SensorGAS);
  Serial.print("Nilai gas = ");
  Serial.println(GasValue);
  delay(1000);

}