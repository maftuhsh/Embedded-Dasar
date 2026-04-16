# 📘 Modul 4 – Praktikum Sistem Embedded  
## Pemrograman Sensor Suhu DHT11 dan Kipas (Fan)

Link Simulasi Percobaan 1: https://app.cirkitdesigner.com/project/8c18d5e1-074d-4155-bfe8-3878e3f598e9

Link Simulasi Percobaan 2: https://app.cirkitdesigner.com/project/cdaa47d0-16d1-4d86-8fc2-e1cb22d3e49c

---

## 🎯 Tujuan Praktikum

Setelah praktikum ini, mahasiswa diharapkan mampu:
- Memahami cara kerja sensor suhu DHT11  
- Membaca data suhu dari sensor  
- Mengontrol kipas berdasarkan suhu  
- Menampilkan data suhu ke LCD  
- Mengintegrasikan sensor, aktuator, dan display  

---

## 🧠 Konsep Dasar

Sistem ini menggunakan konsep monitoring dan kontrol suhu:

```
DHT11 (Sensor) → Arduino (Controller) →  
   ├── Fan (Output kontrol suhu)  
   └── LCD (Output informasi)  
```

### Cara Kerja:
1. Sensor membaca suhu lingkungan  
2. Arduino memproses data  
3. Jika suhu > batas → Fan ON  
4. Jika suhu ≤ batas → Fan OFF  
5. Data suhu ditampilkan ke LCD  

---

## 🔧 Komponen yang Digunakan

- Sensor DHT11  
- Arduino UNO  
- Fan / Motor DC  
- Motor Driver (L298N)  
- LCD 16x2  
- Kabel Jumper  
- Breadboard  

---

## ⚙️ Percobaan 1: Sensor Suhu + Fan

### Tujuan
Mengontrol kipas berdasarkan suhu.

### Logika Program
- Jika suhu > 30°C → Fan ON  
- Jika suhu ≤ 30°C → Fan OFF  

### Flow Sistem

```
Baca Suhu → Bandingkan → 
   ├── > 30°C → Fan ON
   └── ≤ 30°C → Fan OFF
```

### Contoh Program

```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 9

DHT dht(DHTPIN, DHTTYPE);

float suhu;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  suhu = dht.readTemperature();

  if (suhu > 30) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  Serial.print("Suhu: ");
  Serial.println(suhu);

  delay(2000);
}
```

---

## 🧪 Analisis Percobaan 1

- Menggunakan kontrol sederhana (if-else)  
- Sistem otomatis berbasis threshold  
- Fan hanya ON/OFF (belum menggunakan PWM)  

---

## 💡 Percobaan 2: Sensor Suhu + LCD

### Tujuan
Menampilkan suhu dan kelembaban ke LCD.

### Flow Sistem

```
Baca Sensor → Tampilkan ke LCD → Update tiap 2 detik
```

### Contoh Program

```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(suhu);

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum);

  delay(2000);
}
```

---

## 🧪 Analisis Percobaan 2

- Sistem menampilkan data secara real-time  
- Tidak memerlukan Serial Monitor  
- Merupakan dasar Human-Machine Interface (HMI)  

---

## 📌 Tugas Praktikum

### Tugas 1
- Buat program DHT11 + Fan  
- Lakukan analisa program  

### Tugas 2
- Buat program DHT11 + LCD  
- Baris 1: NIM  
- Baris 2: Temperature (T) dan Humidity (H)  

---

## ⚠️ Catatan Penting

- DHT11 memiliki akurasi terbatas  
- Pastikan wiring benar  
- Jika LCD tidak tampil, cek alamat I2C  
- Perhatikan delay pembacaan sensor  

---

## 🚀 Pengembangan Lanjutan

- Gunakan PWM untuk kontrol kecepatan fan  
- Gunakan sensor DHT22 (lebih akurat)  
- Integrasi dengan IoT (ESP32)  
- Implementasi kontrol otomatis lebih kompleks  

---

## 🧾 Kesimpulan

- DHT11 dapat membaca suhu secara real-time  
- Arduino memproses data dan mengontrol output  
- Fan bekerja sebagai aktuator otomatis  
- LCD menampilkan informasi ke pengguna  
- Sistem ini merupakan dasar kontrol otomatis sederhana  

---