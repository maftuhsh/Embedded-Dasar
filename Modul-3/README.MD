# 📘 Modul III Praktikum Sistem Embedded

## Pembacaan Sensor Gas dan Pengontrolan Servo dengan Keypad

Link simulasi Percobaan 1 : https://wokwi.com/projects/461567518813702145

Link Simulasi Percobaan 2 : https://wokwi.com/projects/461567555153164289
---

## 🧠 Pendahuluan

Dalam sistem embedded, mikrokontroler berfungsi sebagai pusat kendali yang menerima input, memproses data, dan menghasilkan output.

Pada modul ini, sistem dibangun menggunakan beberapa komponen utama:

* Sensor Gas (MQ2) sebagai input lingkungan
* Keypad sebagai input pengguna
* LCD 16x2 sebagai media tampilan
* Motor Servo sebagai aktuator

Modul ini menekankan pada bagaimana sistem membaca data dari sensor dan user, lalu mengontrol output secara real-time.

---

## 🎯 Tujuan Praktikum

Setelah mengikuti praktikum ini, praktikan diharapkan mampu:

* Memahami cara kerja sensor gas (MQ2)
* Menampilkan data ke LCD 16x2
* Menggunakan keypad sebagai input sistem
* Mengontrol motor servo berdasarkan input
* Membuat sistem embedded sederhana berbasis input-output

---

# 🔍 1. Konsep Sistem Embedded

Sistem embedded bekerja dengan alur dasar:

```text
Input → Proses → Output
```

Dalam praktikum ini:

* **Input** → Sensor Gas & Keypad
* **Proses** → Arduino Uno
* **Output** → LCD & Servo

---

# 🔬 2. Sensor Gas MQ2

## 📌 Konsep Dasar

Sensor MQ2 digunakan untuk mendeteksi gas seperti:

* LPG
* Asap
* Alkohol
* CO (Karbon Monoksida)

Sensor ini menghasilkan **sinyal analog** yang nilainya berubah sesuai konsentrasi gas.

---

## ⚙️ Cara Kerja

1. Sensor mendeteksi gas di udara
2. Nilai resistansi berubah
3. Arduino membaca melalui pin analog
4. Data dikonversi menjadi nilai tertentu
5. Nilai ditampilkan ke LCD

---

## ⚠️ Karakteristik

* Sensitivitas tinggi
* Respon cepat
* Membutuhkan kalibrasi

---

# 📟 3. LCD 16x2

## 📌 Konsep Dasar

LCD 16x2 adalah display yang mampu menampilkan:

* 16 karakter per baris
* 2 baris

---

## ⚙️ Cara Kerja

1. Arduino mengirim data karakter
2. LCD menerima melalui pin digital
3. Data ditampilkan sebagai teks

---

## 🧪 Fungsi dalam Praktikum

* Menampilkan nilai sensor gas
* Menampilkan input dari keypad
* Menampilkan sudut servo

---

# ⌨️ 4. Keypad 4x4

## 📌 Konsep Dasar

Keypad terdiri dari matriks:

* 4 baris
* 4 kolom

Total 16 tombol.

---

## ⚙️ Cara Kerja

1. Arduino mengaktifkan baris tertentu
2. Membaca kolom yang terhubung
3. Menentukan tombol yang ditekan

👉 Prinsipnya adalah **scanning matrix**

---

## 🧪 Fungsi dalam Praktikum

* Input nilai sudut servo
* Mengontrol pergerakan servo

---

# 🔄 5. Motor Servo

## 📌 Konsep Dasar

Servo adalah aktuator yang mampu bergerak pada sudut tertentu (0°–180°).

---

## ⚙️ Cara Kerja

Servo bekerja menggunakan sinyal **PWM (Pulse Width Modulation)**:

* 1 ms → ~0°
* 1.5 ms → ~90°
* 2 ms → ~180°

Sinyal ini diulang setiap ±20 ms.

---

## 🔁 Sistem Kontrol

Servo menggunakan **closed-loop control**, artinya:

* Posisi akan dipertahankan secara otomatis
* Jika bergeser → akan dikoreksi

---

# 🧪 6. Percobaan I – Pembacaan Sensor Gas

## 🔄 Alur Kerja

1. Sensor membaca gas
2. Arduino membaca nilai analog
3. Nilai dikonversi
4. Data ditampilkan ke LCD

---

## 🎯 Tujuan

* Memahami pembacaan sensor analog
* Menampilkan data secara real-time

---

# 🧪 7. Percobaan II – Kontrol Servo dengan Keypad

## 🔄 Alur Kerja

1. User menekan tombol keypad
2. Data dikumpulkan sebagai angka
3. Data dikonversi menjadi sudut
4. Servo bergerak sesuai nilai
5. LCD menampilkan sudut

---

## 🎯 Tujuan

* Memahami input digital
* Mengontrol aktuator (servo)
* Validasi input (error handling)

---

# ⚠️ 8. Analisis Sistem

## 🔎 Potensi Masalah

### Sensor Gas

* Noise pada pembacaan
* Nilai tidak stabil

### Keypad

* Bounce pada tombol
* Input tidak terbaca

### Servo

* Sudut tidak valid (>180°)
* Delay respon

---

# 🧠 9. Insight Penting

* Sistem embedded adalah kombinasi:

  * Sensor (input)
  * Aktuator (output)
  * Logika kontrol

* Validasi input sangat penting

* Timing (delay, sampling) mempengaruhi performa

---

# 📌 10. Kesimpulan

Pada praktikum ini, sistem berhasil:

* Membaca kondisi lingkungan melalui sensor gas
* Menerima input user melalui keypad
* Menampilkan informasi ke LCD
* Mengontrol aktuator (servo) secara presisi

👉 Ini merupakan dasar dari sistem otomatisasi dan IoT.

---

✍️ *Modul ini menjadi fondasi penting untuk memahami integrasi sensor, input user, dan kontrol aktuator dalam sistem embedded.*
