# Modul 5 Embedded System

## Komunikasi Digital :
    Komunikasi digital adalah proses pengiriman data dalam bentuk sinyal diskrit (0 dan 1 / HIGH dan LOW) antar perangkat.

    Analoginya:
    Analog = gelombang bebas (kontinu)
    Digital = potongan-potonan jelas (bit)

    Jadi komunikasi digital itu:
    “Bagaimana dua perangkat berbicara menggunakan bahasa biner”

    Contoh:
    - Arduino kirim data ke sensor
    - ESP32 kirim data ke server
    - Laptop komunikasi dengan flashdisk
    
    Elemen penting:
    - Pengirim (Transmitter)
    - Penerima (Receiver)
    - Media (kabel / wireless)
    - Protokol (aturan komunikasi)


## UART (Universal Asynchronous Receiver Transmitter)







##  Perbandingan Antara UART dan SPI
    | Aspek        | UART          | SPI                   |
    | ------------ | ------------- | --------------------- |
    | Sinkronisasi | Tidak (async) | Ya (clock)            |
    | Jalur        | 2             | 4+                    |
    | Kecepatan    | Lebih lambat  | Sangat cepat          |
    | Komunikasi   | 1-1           | 1-master banyak slave |
    | Kompleksitas | Sederhana     | Lebih kompleks        |
    | Duplex       | Half          | Full                  |
