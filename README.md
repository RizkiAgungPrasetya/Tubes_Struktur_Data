# Tubes_Struktur_Data

# 🏛️ Tubes Struktur Data

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge\&logo=c%2B%2B)
![Course](https://img.shields.io/badge/Course-Struktur_Data-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-On_Progress-green?style=for-the-badge)

> **Tugas Besar Mata Kuliah Struktur Data**

---

## 👥 Anggota Kelompok 5

|  No | Nama Mahasiswa             |      NIM     |
| :-: | :------------------------- | :----------: |
|  1. | **Julian Saputra**         | 103112400260 |
|  2. | **Rizki Agung Prasetya**   | 103112400263 |
|  3. | **Fakhri Naabil Prasetyo** | 103112400274 |

---

<p align="center"> Dibuat dengan semangat ngoding dan kerja sama 💪 Mahasiswa Informatika Telkom University Purwokerto </p>

🚍 Transport Route & Schedule Management System

(Graph + Binary Search Tree Based Transportation Scheduler)

Sistem ini dirancang untuk mengatur rute transportasi dan jadwal perjalanan menggunakan dua struktur data utama: Graph dan Binary Search Tree (BST).
Cocok digunakan untuk simulasi transportasi seperti bus, kereta, shuttle kampus, angkot, dan moda lainnya.

🧩 Deskripsi Singkat Sistem

Sistem memiliki dua komponen inti:

1️⃣ Graph – Model Rute Transportasi

Graph digunakan untuk memetakan jaringan transportasi:

Node = halte/stasiun/lokasi

Edge = jalur yang menghubungkan dua lokasi

Graph memungkinkan sistem untuk:

Menentukan jalur dari titik awal → tujuan

Menampilkan semua rute yang tersedia

Mengetahui hubungan antar lokasi

Mencari jalur alternatif

Visualisasi jaringan transportasi

2️⃣ Binary Search Tree (BST) – Manajemen Jadwal

BST digunakan untuk menyimpan dan mengelola data jadwal transportasi, seperti:

Waktu keberangkatan

Waktu kedatangan

ID kendaraan

Rute

Estimasi waktu tempuh

Keuntungan penggunaan BST:

Pencarian jadwal cepat (berdasarkan waktu atau ID)

Penambahan dan penghapusan jadwal efisien

Otomatis terurut menggunakan in-order traversal

Dapat mencari jadwal terdekat berikutnya

💡 Fitur Sistem
🔹 Fitur Graph

Menentukan jalur tercepat A → B

Menampilkan rute yang tersedia

Menyimpan seluruh halte/stasiun

Visualisasi hubungan antar titik transportasi

🔹 Fitur BST

Menyimpan seluruh jadwal dalam struktur terurut

Mencari jadwal terdekat dari waktu tertentu

Menambahkan dan menghapus jadwal

Menampilkan daftar jadwal secara otomatis terurut

Pencarian ID kendaraan cepat melalui node

🏗️ Arsitektur Sistem (Ringkas)
Graph (Rute)
 ├── Node: Lokasi transportasi
 └── Edge: Jalur antar lokasi

Binary Search Tree (Jadwal)
 ├── Key utama: Waktu keberangkatan
 ├── Data: ID kendaraan, rute, durasi, tujuan
 └── Operasi: insert, delete, find, traversal

🧪 Simulasi yang Dapat Dilakukan

Sistem mendukung berbagai operasi seperti:

🔧 Operasi Graph

Menambahkan halte/stasiun baru

Menambahkan jalur baru

Pencarian rute antara dua lokasi

🔧 Operasi BST

Menambahkan jadwal baru

Menghapus jadwal tertentu

Mencari jadwal berdasarkan waktu atau ID

Menampilkan jadwal terurut waktu

📝 Ringkasan Hasil Diskusi Kelompok

Graph digunakan untuk memetakan lokasi transportasi dan jalurnya.

Setiap halte/stasiun direpresentasikan sebagai node.

Koneksi antar lokasi disimpan sebagai edge.

Jadwal keberangkatan dan kedatangan diatur menggunakan BST.

Setiap node BST menyimpan waktu, rute, ID kendaraan, dan durasi perjalanan.

Operasi find() pada BST mempercepat pencarian jadwal.

In-order traversal digunakan untuk menampilkan jadwal mulai dari paling pagi → paling malam.

Sistem mampu menampilkan rute perjalanan via graph lalu memberikan jadwal transportasi via BST.

📌 Teknologi / Struktur Data yang Digunakan

Graph (Adjacency List / Matrix)

Binary Search Tree

Algoritma pencarian rute

Operation BST: insert, delete, search, traversal


