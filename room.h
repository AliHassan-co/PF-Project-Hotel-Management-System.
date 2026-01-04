#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ROOMS = 100;

class Room {
public:
    int roomNumber;
    string type;
    double price;
    int isBooked;

    void display() {
        string status = (isBooked == 1) ? "Booked" : "Available";
        cout << left << setw(12) << roomNumber
             << setw(15) << type
             << setw(10) << price
             << setw(12) << status << endl;
    }
};

extern Room hotel[MAX_ROOMS];
extern int totalRooms;

// Function declarations
void saveToFile();
void loadFromFile();
void addRoom();
void viewRooms();
void searchRoom();
void bookRoom();
void vacateRoom();
void deleteRoom();

#endif
