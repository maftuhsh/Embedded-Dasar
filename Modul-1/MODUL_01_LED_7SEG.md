# 📘 Modul 1 - Pemrograman LED Traffic Light & 7-Segment Counter
## 🧾 Deskripsi

Modul ini membahas dasar pemrograman mikrokontroler dengan dua studi kasus utama:

Simulasi lampu lalu lintas (traffic light) menggunakan LED
Implementasi 7-segment display sebagai up counter dan down counter

Modul ini bertujuan untuk memahami konsep dasar kontrol output digital, timing/delay, serta logika pencacah (counter).

## 🎯 Tujuan Pembelajaran

Setelah menyelesaikan modul ini, mahasiswa diharapkan mampu:

Memahami konsep dasar output digital
Mengontrol LED sesuai urutan tertentu
Mengimplementasikan sistem traffic light sederhana
Menggunakan 7-segment display
Membuat program up counter dan down counter

## 🛠️ Alat dan Bahan
Mikrokontroler (Arduino)
LED (Merah, Kuning, Hijau)
Resistor
7-Segment Display (Common Anode / Cathode)
Breadboard & Kabel jumper
Software IDE (Arduino IDE / sejenisnya)

## 🚦 Bagian 1: Traffic Light LED
📌 Konsep

Traffic light terdiri dari 3 LED:

🔴 Merah (Stop)
🟡 Kuning (Hati-hati)
🟢 Hijau (Jalan)
🔁 Urutan Nyala
Hijau → 5 detik
Kuning → 3 detik
Merah → 4 detik
Ulangi

## 🔢 Bagian 2: 7-Segment Up Counter
📌 Konsep
7-segment digunakan untuk menampilkan angka 0–9 dengan kombinasi 7 LED segment.

### 🔼 Up Counter
Menampilkan angka dari 0 → 9, kemudian mengulang.

### 🔽 Bagian 3: 7-Segment Down Counter
Menampilkan angka dari 9 → 0

## ⚠️ Catatan
 - Perhatikan jenis 7-segment (Common Anode / Cathode), karena logika - HIGH/LOW bisa terbalik
 - Gunakan resistor untuk melindungi LED
 - Delay dapat disesuaikan dengan kebutuhan

## 📚 Kesimpulan
Modul ini memberikan dasar penting dalam:
Pengendalian LED
Pemahaman timing
Logika pencacah digital