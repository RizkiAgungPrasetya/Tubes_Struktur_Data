#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
using namespace std;

#define MAX_NODE 20

typedef struct ScheduleNode *addressSchedule;

struct ScheduleNode {
    int id;
    int busNumber;
    string departureTime;
    int travelTime;
    string destination;
    int halteCount;
    string halteList[MAX_NODE];
    addressSchedule left;
    addressSchedule right;
};

struct BSTSchedule {
    addressSchedule root;
};

/* BST */
void initBST(BSTSchedule &T);
addressSchedule createNode(int id, int bus, string depart, int travel,
                           string dest, string halte[], int count);
void insertSchedule(BSTSchedule &T, int id, int bus, string depart,
                    int travel, string dest, string halte[], int count);
void inorderSchedule(addressSchedule P);
void searchScheduleByHalte(addressSchedule P, string halte);

/* CRUD */
bool isIDExist(addressSchedule P, int id);
addressSchedule deleteSchedule(addressSchedule root, int id);
addressSchedule findMin(addressSchedule P);

/* File */
void saveAllSchedule(addressSchedule P, ofstream &file);
void rewriteScheduleFile(addressSchedule root);
void loadScheduleFromFile(BSTSchedule &T);

#endif