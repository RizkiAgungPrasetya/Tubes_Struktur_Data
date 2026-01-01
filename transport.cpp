#include "transport.h"
#include <fstream>
#include <sstream>
#include <functional>

void createBST(BSTSchedule &T) {
    T.root = NULL;
}

addressSchedule createNode(int time, int bus, string dest,
                           string halte[], int count) {
    addressSchedule P = new ScheduleNode;
    P->time = time;
    P->busNumber = bus;
    P->destination = dest;
    P->halteCount = count;
    for (int i = 0; i < count; i++)
        P->halteList[i] = halte[i];
    P->left = P->right = NULL;
    return P;
}

void insertSchedule(BSTSchedule &T, int time, int bus,
                    string dest, string halte[], int count) {
    addressSchedule baru = createNode(time, bus, dest, halte, count);
    if (T.root == NULL) {
        T.root = baru;
        return;
    }

    addressSchedule parent = NULL, curr = T.root;
    while (curr != NULL) {
        parent = curr;
        if (time < curr->time)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (time < parent->time)
        parent->left = baru;
    else
        parent->right = baru;
}

void inorderSchedule(addressSchedule P) {
    if (P != NULL) {
        inorderSchedule(P->left);
        cout << "Bus " << P->busNumber
             << " | Waktu: " << P->time
             << " | Tujuan: " << P->destination << endl;
        cout << "Rute: ";
        for (int i = 0; i < P->halteCount; i++) {
            cout << P->halteList[i];
            if (i < P->halteCount - 1) cout << " -> ";
        }
        cout << "\n\n";
        inorderSchedule(P->right);
    }
}

void searchSchedule(addressSchedule P, int time) {
    if (P == NULL) {
        cout << "Jadwal tidak ditemukan!\n";
        return;
    }
    if (P->time == time)
        cout << "Bus " << P->busNumber << " | Waktu: " << P->time
             << " | Tujuan: " << P->destination << endl;
    else if (time < P->time)
        searchSchedule(P->left, time);
    else
        searchSchedule(P->right, time);
}

addressSchedule findMin(addressSchedule node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

addressSchedule deleteSchedule(addressSchedule root, int time) {
    if (root == NULL) return root;

    if (time < root->time)
        root->left = deleteSchedule(root->left, time);
    else if (time > root->time)
        root->right = deleteSchedule(root->right, time);
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
        root->time = temp->time;
        root->busNumber = temp->busNumber;
        root->destination = temp->destination;
        root->halteCount = temp->halteCount;
        for (int i = 0; i < temp->halteCount; i++)
            root->halteList[i] = temp->halteList[i];
        root->right = deleteSchedule(root->right, temp->time);
    }
    return root;
}

void saveScheduleToFile(BSTSchedule T) {
    ofstream file("jadwal.txt");
    function<void(addressSchedule)> save =
    [&](addressSchedule P) {
        if (P != NULL) {
            save(P->left);
            file << P->time << "|"
                 << P->busNumber << "|"
                 << P->destination << "|"
                 << P->halteCount << "|";
            for (int i = 0; i < P->halteCount; i++)
                file << P->halteList[i] << "|";
            file << endl;
            save(P->right);
        }
    };
    save(T.root);
    file.close();
}

void loadScheduleFromFile(BSTSchedule &T) {
    ifstream file("jadwal.txt");
    string line, temp, dest, halte[MAX_NODE];
    int time, bus, count;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, temp, '|'); time = stoi(temp);
        getline(ss, temp, '|'); bus = stoi(temp);
        getline(ss, dest, '|');
        getline(ss, temp, '|'); count = stoi(temp);
        for (int i = 0; i < count; i++)
            getline(ss, halte[i], '|');
        insertSchedule(T, time, bus, dest, halte, count);
    }
    file.close();
}

void createGraph(Graph &G, int jumlahNode) {
    G.V = jumlahNode;
}