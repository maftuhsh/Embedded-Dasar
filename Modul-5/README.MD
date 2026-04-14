# Modul 5 Praktikum: Komunikasi UART dan SPI

## 1. Pendahuluan

Dalam sistem embedded dan IoT, komunikasi antar perangkat menjadi hal yang sangat penting. Dua metode komunikasi serial yang paling sering digunakan adalah **UART (Universal Asynchronous Receiver Transmitter)** dan **SPI (Serial Peripheral Interface)**.

Modul ini bertujuan memberikan pemahaman konseptual, cara kerja, serta implementasi praktis agar mudah dipahami dan langsung digunakan dalam praktikum.

---

# 2. Konsep Dasar Komunikasi Digital

Komunikasi digital adalah proses pertukaran data dalam bentuk sinyal biner (0 dan 1) antara dua atau lebih perangkat.

## Karakteristik:

* Data dikirim dalam bentuk bit
* Lebih tahan terhadap noise dibanding analog
* Membutuhkan protokol komunikasi

## Elemen Sistem:

1. Transmitter (pengirim)
2. Receiver (penerima)
3. Media transmisi (kabel)
4. Protokol komunikasi

---

# 3. UART (Universal Asynchronous Receiver Transmitter)

## 3.1 Definisi

UART adalah metode komunikasi serial **asynchronous**, artinya tidak menggunakan sinyal clock untuk sinkronisasi.

## 3.2 Konsep Dasar

Karena tidak ada clock, UART menggunakan **baud rate** untuk menyamakan kecepatan komunikasi antara pengirim dan penerima.

Contoh baud rate:

* 9600 bps
* 115200 bps

Kedua perangkat HARUS memiliki baud rate yang sama.

---

## 3.3 Struktur Data UART

Setiap data dikirim dalam bentuk frame:

```
Start Bit | Data Bits | Parity Bit (opsional) | Stop Bit
```

Penjelasan:

* Start bit: tanda awal (LOW)
* Data bits: isi data (5–9 bit, biasanya 8 bit)
* Parity: pengecekan error (opsional)
* Stop bit: tanda akhir (HIGH)

---

## 3.4 Cara Kerja UART

1. Kondisi idle = HIGH
2. Start bit dikirim (LOW)
3. Data dikirim bit per bit
4. Parity (opsional)
5. Stop bit dikirim (HIGH)

Receiver membaca data berdasarkan timing dari baud rate.

---

## 3.5 Jalur Komunikasi

UART hanya membutuhkan 2 jalur:

* TX (Transmit)
* RX (Receive)

Koneksi:

* TX perangkat A → RX perangkat B
* RX perangkat A → TX perangkat B

---

## 3.6 Kelebihan UART

* Sederhana
* Mudah digunakan
* Cocok untuk debugging (Serial Monitor)

## 3.7 Kekurangan UART

* Kecepatan terbatas
* Tidak cocok banyak perangkat
* Sinkronisasi bergantung baud rate

---

## 3.8 Implementasi UART (Arduino)

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello UART");
  delay(1000);
}
```

---

# 4. SPI (Serial Peripheral Interface)

## 4.1 Definisi

SPI adalah komunikasi serial **synchronous** yang menggunakan sinyal clock untuk sinkronisasi.

---

## 4.2 Konsep Dasar

SPI menggunakan arsitektur:

* 1 Master
* 1 atau lebih Slave

Master mengontrol komunikasi.

---

## 4.3 Jalur Komunikasi SPI

SPI menggunakan 4 jalur utama:

1. MOSI (Master Out Slave In)
2. MISO (Master In Slave Out)
3. SCLK (Clock)
4. SS/CS (Slave Select)

---

## 4.4 Cara Kerja SPI

1. Master memilih slave (CS = LOW)
2. Master menghasilkan clock
3. Data dikirim sinkron dengan clock
4. Data dapat dikirim dan diterima secara bersamaan (full duplex)
5. Setelah selesai, CS kembali HIGH

---

## 4.5 Karakteristik SPI

* Full duplex
* Kecepatan tinggi
* Sinkron dengan clock
* Mendukung banyak slave

---

## 4.6 Kelebihan SPI

* Sangat cepat
* Stabil
* Bisa komunikasi dua arah sekaligus

## 4.7 Kekurangan SPI

* Membutuhkan banyak kabel
* Lebih kompleks
* Tidak ada standar protokol tetap

---

## 4.8 Implementasi SPI (Arduino)

```cpp
#include <SPI.h>

void setup() {
  SPI.begin();
  pinMode(SS, OUTPUT);
}

void loop() {
  digitalWrite(SS, LOW);
  SPI.transfer(0x55);
  digitalWrite(SS, HIGH);
  delay(1000);
}
```

---

# 5. Perbandingan UART vs SPI

| Aspek        | UART           | SPI            |
| ------------ | -------------- | -------------- |
| Sinkronisasi | Tidak (async)  | Ya (clock)     |
| Jalur        | 2              | 4+             |
| Kecepatan    | Lebih lambat   | Sangat cepat   |
| Komunikasi   | Point-to-point | Multi-device   |
| Duplex       | Half duplex    | Full duplex    |
| Kompleksitas | Sederhana      | Lebih kompleks |

---

# 6. Studi Kasus Penggunaan

## UART digunakan untuk:

* Debugging
* Komunikasi dengan PC
* Modul GPS

## SPI digunakan untuk:

* Sensor cepat
* SD Card
* LCD / OLED display

---

# 7. Kesalahan Umum dalam Praktikum

### UART:

* Baud rate tidak sama
* Salah sambung TX dan RX

### SPI:

* Salah pin (MOSI/MISO)
* Tidak mengatur CS dengan benar
* Clock tidak sesuai

---

# 8. Kesimpulan

* UART cocok untuk komunikasi sederhana dan debugging
* SPI cocok untuk komunikasi cepat dan kompleks
* Pemilihan tergantung kebutuhan sistem

---

# 9. Latihan Praktikum

1. Kirim data dari Arduino ke Serial Monitor menggunakan UART
2. Hubungkan dua Arduino menggunakan UART
3. Kirim data menggunakan SPI ke modul sensor
4. Analisis perbedaan kecepatan UART dan SPI

---

# 10. Insight Tambahan

* UART lebih mudah dipelajari, cocok untuk pemula
* SPI lebih powerful untuk sistem kompleks
* Dalam sistem nyata, keduanya sering digunakan bersamaan

---

