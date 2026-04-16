/*
 * Arduino Sketch for interfacing with an LCD and DHT11 sensor.
 * This code initializes the LCD and reads temperature and humidity
 * from the DHT11 sensor, displaying the values on the LCD.
 * 
 * LCD Pins Used:
 * - RS: D13
 * - E: D12
 * - DB4: D5
 * - DB5: D4
 * - DB6: D3
 * - DB7: D2
 * 
 * DHT11 Sensor Pin:
 * - DATA: D11
 */

#include <LiquidCrystal.h>
#include <DHT.h>

// Initialize the LCD with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

// DHT11 sensor setup
#define DHTPIN 11     // Pin where the DHT11 is connected
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the LCD
  lcd.begin(16, 2);
  lcd.print("Initializing...");
  
  // Start the DHT sensor
  dht.begin();
  
  delay(2000); // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  // Read temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }
  
  // Display temperature and humidity on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");
  
  delay(2000); // Wait for 2 seconds before next update
}