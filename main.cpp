#include <iostream>
#include <fstream>
#include <sstream>
#include "transport.h"
using namespace std;

/* ===== LINKED LIST CUSTOMER ===== */
struct CustomerNode {
    string username;
    string password;
    CustomerNode *next;
};

CustomerNode *headCustomer = NULL;

/* ===== DATABASE CUSTOMER ===== */
bool isCustomerExist(string username) {
    ifstream file("customer.txt");
    string line, u, p;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, u, '|');
        getline(ss, p, '|');
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void saveCustomerToFile(string username, string password) {
    ofstream file("customer.txt", ios::app);
    file << username << "|" << password << endl;
    file.close();
}

void loadCustomerFromFile() {
    ifstream file("customer.txt");
    string line, u, p;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, u, '|');
        getline(ss, p, '|');

        CustomerNode *baru = new CustomerNode;
        baru->username = u;
        baru->password = p;
        baru->next = headCustomer;
        headCustomer = baru;
    }
    file.close();
}

/* ===== LOGIN ===== */
bool loginAdmin() {
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    return (u == "admin" && p == "admin123");
}

bool loginCustomer() {
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;

    CustomerNode *temp = headCustomer;
    while (temp != NULL) {
        if (temp->username == u && temp->password == p)
            return true;
        temp = temp->next;
    }
    cout << "Login gagal!\n";
    return false;
}

void registerCustomer() {
    string username, password;
    cout << "Username baru: ";
    cin >> username;

    if (isCustomerExist(username)) {
        cout << "Username sudah terdaftar!\n";
        return;
    }

    cout << "Password baru: ";
    cin >> password;

    saveCustomerToFile(username, password);

    CustomerNode *baru = new CustomerNode;
    baru->username = username;
    baru->password = password;
    baru->next = headCustomer;
    headCustomer = baru;

    cout << "Registrasi berhasil!\n";
}

/* ===== MENU ADMIN (LENGKAP) ===== */
void menuAdmin(BSTSchedule &jadwal) {
    int pilih;
    while (true) {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Lihat Jadwal\n";
        cout << "3. Hapus Jadwal\n";
        cout << "4. Ubah Jadwal\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 0) break;

        if (pilih == 1) {
            int time, bus, count;
            string dest, halte[MAX_NODE];

            cout << "Nomor Bus: ";
            cin >> bus;
            cout << "Waktu: ";
            cin >> time;
            cin.ignore();

            cout << "Tujuan: ";
            getline(cin, dest);

            cout << "Jumlah Halte: ";
            cin >> count;
            cin.ignore();

            for (int i = 0; i < count; i++) {
                cout << "Nama Halte " << i + 1 << ": ";
                getline(cin, halte[i]);
            }

            insertSchedule(jadwal, time, bus, dest, halte, count);
            saveScheduleToFile(jadwal);
            cout << "Jadwal ditambahkan\n";
        }

        else if (pilih == 2) {
            inorderSchedule(jadwal.root);
        }

        else if (pilih == 3) {
            int t;
            cout << "Waktu jadwal yang dihapus: ";
            cin >> t;

            jadwal.root = deleteSchedule(jadwal.root, t);
            saveScheduleToFile(jadwal);
            cout << "Jadwal dihapus\n";
        }

        else if (pilih == 4) {
            int lama;
            cout << "Waktu jadwal lama: ";
            cin >> lama;

            jadwal.root = deleteSchedule(jadwal.root, lama);

            int time, bus, count;
            string dest, halte[MAX_NODE];

            cout << "\n--- Data Jadwal Baru ---\n";
            cout << "Nomor Bus: ";
            cin >> bus;
            cout << "Waktu Baru: ";
            cin >> time;
            cin.ignore();

            cout << "Tujuan: ";
            getline(cin, dest);

            cout << "Jumlah Halte: ";
            cin >> count;
            cin.ignore();

            for (int i = 0; i < count; i++) {
                cout << "Nama Halte " << i + 1 << ": ";
                getline(cin, halte[i]);
            }

            insertSchedule(jadwal, time, bus, dest, halte, count);
            saveScheduleToFile(jadwal);
            cout << "Jadwal diubah\n";
        }
    }
}

/* ===== MENU CUSTOMER ===== */
void menuCustomer(BSTSchedule &jadwal) {
    int pilih;
    while (true) {
        cout << "\n=== MENU CUSTOMER ===\n";
        cout << "1. Lihat Jadwal\n";
        cout << "2. Cari Jadwal\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 0) break;

        if (pilih == 1)
            inorderSchedule(jadwal.root);
        else if (pilih == 2) {
            int t;
            cout << "Cari waktu: ";
            cin >> t;
            searchSchedule(jadwal.root, t);
        }
    }
}

/* ===== MAIN ===== */
int main() {
    BSTSchedule jadwal;
    Graph G;

    createBST(jadwal);
    createGraph(G, 10);
    loadScheduleFromFile(jadwal);
    loadCustomerFromFile();

    int pilih;
    while (true) {
        cout << "\n===== SISTEM LOGIN =====\n";
        cout << "1. Login Admin\n";
        cout << "2. Login Customer\n";
        cout << "3. Registrasi Customer\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 0) break;

        if (pilih == 1) {
            if (loginAdmin())
                menuAdmin(jadwal);
        }
        else if (pilih == 2) {
            if (loginCustomer())
                menuCustomer(jadwal);
        }
        else if (pilih == 3)
            registerCustomer();
    }

    return 0;
}
