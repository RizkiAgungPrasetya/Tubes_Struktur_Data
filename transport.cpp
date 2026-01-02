#include "transport.h"
#include <fstream>
#include <sstream>

void initBST(BSTSchedule &T) {
    T.root = NULL;
}

addressSchedule createNode(int id, int bus, string depart, int travel,
                           string dest, string halte[], int count) {
    addressSchedule P = new ScheduleNode;
    P->id = id;
    P->busNumber = bus;
    P->departureTime = depart;
    P->travelTime = travel;
    P->destination = dest;
    P->halteCount = count;
    for (int i = 0; i < count; i++)
        P->halteList[i] = halte[i];
    P->left = P->right = NULL;
    return P;
}

void insertSchedule(BSTSchedule &T, int id, int bus, string depart,
                    int travel, string dest, string halte[], int count) {
    addressSchedule baru = createNode(id, bus, depart, travel, dest, halte, count);

    if (T.root == NULL) {
        T.root = baru;
        return;
    }

    addressSchedule parent = NULL, curr = T.root;
    while (curr != NULL) {
        parent = curr;
        if (id < curr->id)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (id < parent->id)
        parent->left = baru;
    else
        parent->right = baru;
}

void inorderSchedule(addressSchedule P) {
    if (P == NULL) return;

    inorderSchedule(P->left);

    cout << "\nID Jadwal     : " << P->id << endl;
    cout << "Nomor Bus     : " << P->busNumber << endl;
    cout << "Jam Berangkat : " << P->departureTime << endl;
    cout << "Waktu Tempuh  : " << P->travelTime << " menit" << endl;
    cout << "Tujuan        : " << P->destination << endl;
    cout << "Rute          : ";
    for (int i = 0; i < P->halteCount; i++) {
        cout << P->halteList[i];
        if (i < P->halteCount - 1) cout << " -> ";
    }
    cout << endl;

    inorderSchedule(P->right);
}

void searchScheduleByHalte(addressSchedule P, string halte) {
    if (P == NULL) return;

    searchScheduleByHalte(P->left, halte);

    for (int i = 0; i < P->halteCount; i++) {
        if (P->halteList[i] == halte) {
            cout << "\nID Jadwal     : " << P->id << endl;
            cout << "Nomor Bus     : " << P->busNumber << endl;
            cout << "Jam Berangkat : " << P->departureTime << endl;
            cout << "Waktu Tempuh  : " << P->travelTime << " menit" << endl;
            cout << "Tujuan        : " << P->destination << endl;
            cout << "Rute          : ";
            for (int j = 0; j < P->halteCount; j++) {
                cout << P->halteList[j];
                if (j < P->halteCount - 1) cout << " -> ";
            }
            cout << endl;
            break;
        }
    }

    searchScheduleByHalte(P->right, halte);
}

bool isIDExist(addressSchedule P, int id) {
    if (P == NULL) return false;
    if (P->id == id) return true;
    if (id < P->id)
        return isIDExist(P->left, id);
    return isIDExist(P->right, id);
}

addressSchedule findMin(addressSchedule P) {
    while (P && P->left != NULL)
        P = P->left;
    return P;
}

addressSchedule deleteSchedule(addressSchedule root, int id) {
    if (root == NULL) return root;

    if (id < root->id)
        root->left = deleteSchedule(root->left, id);
    else if (id > root->id)
        root->right = deleteSchedule(root->right, id);
    else {
        if (root->left == NULL) {
            addressSchedule temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            addressSchedule temp = root->left;
            delete root;
            return temp;
        }

        addressSchedule temp = findMin(root->right);
        root->id = temp->id;
        root->busNumber = temp->busNumber;
        root->departureTime = temp->departureTime;
        root->travelTime = temp->travelTime;
        root->destination = temp->destination;
        root->halteCount = temp->halteCount;
        for (int i = 0; i < temp->halteCount; i++)
            root->halteList[i] = temp->halteList[i];

        root->right = deleteSchedule(root->right, temp->id);
    }
    return root;
}

void saveAllSchedule(addressSchedule P, ofstream &file) {
    if (P == NULL) return;

    saveAllSchedule(P->left, file);

    file << P->id << "|"
         << P->busNumber << "|"
         << P->departureTime << "|"
         << P->travelTime << "|"
         << P->destination << "|"
         << P->halteCount << "|";

    for (int i = 0; i < P->halteCount; i++)
        file << P->halteList[i] << "|";

    file << endl;

    saveAllSchedule(P->right, file);
}

void rewriteScheduleFile(addressSchedule root) {
    ofstream file("jadwal.txt");
    saveAllSchedule(root, file);
    file.close();
}

void loadScheduleFromFile(BSTSchedule &T) {
    ifstream file("jadwal.txt");
    if (!file.is_open()) return;

    string line, temp, dest, depart, halte[MAX_NODE];
    int id, bus, travel, count;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        getline(ss, temp, '|'); id = stoi(temp);
        getline(ss, temp, '|'); bus = stoi(temp);
        getline(ss, depart, '|');
        getline(ss, temp, '|'); travel = stoi(temp);
        getline(ss, dest, '|');
        getline(ss, temp, '|'); count = stoi(temp);

        for (int i = 0; i < count; i++)
            getline(ss, halte[i], '|');

        insertSchedule(T, id, bus, depart, travel, dest, halte, count);
    }
    file.close();
}