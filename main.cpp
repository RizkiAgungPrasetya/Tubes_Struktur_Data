#include "transport.h"
#include <fstream>

bool registerCustomer(string u, string p) {
    ifstream in("customer.txt");
    string user, pass;
    while (in >> user >> pass)
        if (user == u) return false;
    in.close();

    ofstream out("customer.txt", ios::app);
    out << u << " " << p << endl;
    out.close();
    return true;
}

bool loginCustomer(string u, string p) {
    ifstream in("customer.txt");
    string user, pass;
    while (in >> user >> pass)
        if (user == u && pass == p) return true;
    in.close();
    return false;
}

void menuAdmin(BSTSchedule &jadwal) {
    int pilih;
    do {
        cout << "\nMENU ADMIN\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Lihat Semua Jadwal\n";
        cout << "3. Ubah Jadwal\n";
        cout << "4. Hapus Jadwal\n";
        cout << "5. Reset Semua Jadwal\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            int id, bus, travel, count;
            string depart, dest, halte[MAX_NODE];

            cout << "ID Jadwal: ";
            cin >> id; cin.ignore();
            if (isIDExist(jadwal.root, id)) {
                cout << "ID sudah ada\n";
                continue;
            }

            cout << "Nomor Bus: ";
            cin >> bus; cin.ignore();

            cout << "Jam Keberangkatan (HH:MM): ";
            getline(cin, depart);

            cout << "Waktu Tempuh (menit): ";
            cin >> travel; cin.ignore();

            cout << "Tujuan: ";
            getline(cin, dest);

            cout << "Jumlah Halte: ";
            cin >> count; cin.ignore();

            for (int i = 0; i < count; i++) {
                cout << "Halte ke-" << i + 1 << ": ";
                getline(cin, halte[i]);
            }

            insertSchedule(jadwal, id, bus, depart, travel, dest, halte, count);
            rewriteScheduleFile(jadwal.root);
            cout << "Jadwal ditambahkan\n";
        }
        else if (pilih == 2) {
            inorderSchedule(jadwal.root);
        }
        else if (pilih == 3) {
            int id, bus, travel, count;
            string depart, dest, halte[MAX_NODE];

            cout << "ID Jadwal yang diubah: ";
            cin >> id; cin.ignore();

            if (!isIDExist(jadwal.root, id)) {
                cout << "ID tidak ditemukan\n";
                continue;
            }

            jadwal.root = deleteSchedule(jadwal.root, id);

            cout << "Masukkan data baru\n";

            cout << "Nomor Bus: ";
            cin >> bus; cin.ignore();

            cout << "Jam Keberangkatan (HH:MM): ";
            getline(cin, depart);

            cout << "Waktu Tempuh (menit): ";
            cin >> travel; cin.ignore();

            cout << "Tujuan: ";
            getline(cin, dest);

            cout << "Jumlah Halte: ";
            cin >> count; cin.ignore();

            for (int i = 0; i < count; i++) {
                cout << "Halte ke-" << i + 1 << ": ";
                getline(cin, halte[i]);
            }

            insertSchedule(jadwal, id, bus, depart, travel, dest, halte, count);
            rewriteScheduleFile(jadwal.root);
            cout << "Jadwal berhasil diubah\n";
        }
        else if (pilih == 4) {
            int id;
            cout << "ID Jadwal yang dihapus: ";
            cin >> id;
            jadwal.root = deleteSchedule(jadwal.root, id);
            rewriteScheduleFile(jadwal.root);
            cout << "Jadwal dihapus\n";
        }
        else if (pilih == 5) {
            jadwal.root = NULL;
            rewriteScheduleFile(jadwal.root);
            cout << "Semua jadwal direset\n";
        }

    } while (pilih != 0);
}

void menuCustomer(BSTSchedule &jadwal) {
    int pilih;
    do {
        cout << "\nMENU CUSTOMER\n";
        cout << "1. Lihat Semua Jadwal\n";
        cout << "2. Cari Jadwal berdasarkan Halte\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
            inorderSchedule(jadwal.root);
        else if (pilih == 2) {
            string halte;
            cout << "Nama Halte: ";
            getline(cin, halte);
            searchScheduleByHalte(jadwal.root, halte);
        }
    } while (pilih != 0);
}

int main() {
    BSTSchedule jadwal;
    initBST(jadwal);
    loadScheduleFromFile(jadwal);

    int pilih;
    do {
        cout << "\nSISTEM TRANSPORTASI\n";
        cout << "1. Login Admin\n";
        cout << "2. Login Customer\n";
        cout << "3. Registrasi Customer\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (u == "admin" && p == "admin")
                menuAdmin(jadwal);
            else
                cout << "Login admin gagal\n";
        }
        else if (pilih == 2) {
            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (loginCustomer(u, p))
                menuCustomer(jadwal);
            else
                cout << "Login gagal\n";
        }
        else if (pilih == 3) {
            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (registerCustomer(u, p))
                cout << "Registrasi berhasil\n";
            else
                cout << "Username sudah terdaftar\n";
        }

    } while (pilih != 0);

    return 0;
}