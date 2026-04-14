// NAMA : Maftuh Siroj Hamdani
// NIM : 2412050

#include <SoftwareSerial.h> 


#define L1 4      
#define L2 5        
#define L3 6        
#define L4 7        
#define NUM_LEDS 4  
#define MATI 0      


SoftwareSerial SerialExternal(2/*rx*/, 3/*tx*/); 


int leds[NUM_LEDS] = {L1, L2, L3, L4}; 
int data = 0;        
bool state = false;  


void setup() {
  SerialExternal.begin(9600); 
  Serial.begin(9600);         

  
  for (uint8_t indx = 0; indx < NUM_LEDS; indx++) {
    pinMode(leds[indx], OUTPUT); 
  }

  
  Serial.println("Welcome to module 5");
  Serial.println("device2 is running");
}

void loop() {

  if (SerialExternal.available()) {
    data = SerialExternal.read(); 
    state = true;                 
  }

  Serial.println("data dari device1 = " + String(data));

 
  if (data > 0 && data <= NUM_LEDS) {
   
    uint8_t bin[NUM_LEDS] = {0b0001, 0b0010, 0b0100, 0b1000};

    --data; 


    for (uint8_t j = 0; j < NUM_LEDS; j++) {
      uint8_t val = (bin[j] >> data) & 1; 
      Serial.print("LED" + String(j + 1) + " = " + String(val) + " \t"); 
      digitalWrite(leds[j], val); 
    }

    Serial.println(); 
    data++; 
  }

  
  else {
    for (int z = 0; z < NUM_LEDS; z++) {
      digitalWrite(leds[z], MATI); 
    }
    Serial.println("all leds off"); 
  }

 
  if (state) {
    state = false; 
    SerialExternal.write(data);
  }

  delay(250); 
}