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

📃 Deskripsi TUBES
Sistem ini akan berlatar pada pengelolaan transportasi (bus, kereta, atau shuttle kampus) yang beroperasi di dalam suatu jaringan halte atau stasiun. Sistem ini berfungsi sebagai aplikasi pengatur rute dan jadwal perjalanan yang dapat digunakan untuk membantu pengguna menemukan rute terbaik serta jadwal keberangkatan yang tersedia. Sistem ini memiliki mekanik seperti pemilihan rute, pencarian jadwal terdekat, serta pemrosesan data transportasi secara otomatis menggunakan struktur data yang sesuai.
Sistem ini menggunakan algoritma Graph dan Binary Search Tree (BST) dalam pengolahan data transportasi.
Graph digunakan untuk memetakan hubungan antar halte/stasiun, jalur perjalanan, serta menentukan rute yang dapat dilalui pengguna berdasarkan koneksi antar lokasi. Setiap node merepresentasikan halte/stasiun dan setiap edge merupakan jalur penghubung di antara keduanya.
Sedangkan Binary Search Tree digunakan dalam penyimpanan dan pengelolaan jadwal keberangkatan. Setiap jadwal memiliki nilai kunci berupa waktu keberangkatan atau ID rute, sehingga BST memungkinkan sistem melakukan pencarian jadwal dengan cepat, mengurutkan jadwal secara otomatis, serta menambahkan atau menghapus jadwal sesuai kebutuhan pengguna.

---

## 💬 Hasil Diskusi Kelompok
1. Sistem ini menggunakan Graph untuk memetakan semua lokasi transportasi dan jalurnya.
2. Setiap lokasi (halte/stasiun) dibuat peran sebagai node graph.
3. Hubungan antar lokasi (jalur transportasi) dibuat peran sebagai edge graph.
4. Semua jadwal keberangkatan dan kedatangan dikelola menggunakan Binary Search Tree.
5. Setiap jadwal disimpan sebagai node Binary Search Tree yang memiliki atribut waktu, rute, ID kendaraan, dan durasi.
6. Pencarian jadwal ini dibuat cepat menggunakan operasi find() pada Binary Search Tree.
7. In‑order traversal Binary Search Tree digunakan untuk menampilkan jadwal secara terurut dan efisien dari pagi hingga malam.
8. Sistem dapat menampilkan rute perjalanan dengan graph lalu menampilkan jadwal kendaraan yang tersedia melalui Binary Search Tree.
9. Data yang dapat disimulasikan: penambahan rute, penambahan jadwal, penghapusan jadwal, dan pencarian jadwal.

---

<p align="center"> Dibuat dengan semangat ngoding dan kerja sama 💪 Mahasiswa Informatika Telkom University Purwokerto </p>
