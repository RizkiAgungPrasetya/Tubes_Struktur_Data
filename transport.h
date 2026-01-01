#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#define MAX_NODE 20
using namespace std;

typedef struct ScheduleNode *addressSchedule;

struct ScheduleNode {
    int time;
    int busNumber;
    string destination;
    int halteCount;
    string halteList[MAX_NODE];
    addressSchedule left;
    addressSchedule right;
};

struct BSTSchedule {
    addressSchedule root;
};

struct Graph {
    int V;
    int adj[MAX_NODE][MAX_NODE];
};

void createBST(BSTSchedule &T);
addressSchedule createNode(int time, int bus, string dest,
                           string halte[], int count);
void insertSchedule(BSTSchedule &T, int time, int bus,
                    string dest, string halte[], int count);
void inorderSchedule(addressSchedule P);
void searchSchedule(addressSchedule P, int time);
addressSchedule deleteSchedule(addressSchedule root, int time);

void saveScheduleToFile(BSTSchedule T);
void loadScheduleFromFile(BSTSchedule &T);

void createGraph(Graph &G, int jumlahNode);

#endif