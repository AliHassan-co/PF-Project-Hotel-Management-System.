#include "room.h"

void bookRoom() {
    int rNo;
    cout << "Enter room number to book: ";
    cin >> rNo;

    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == rNo) {
            hotel[i].isBooked = 1;
            saveToFile();
            cout << "Room booked.\n";
            return;
        }
    }
    cout << "Room not found.\n";
}

void vacateRoom() {
    int rNo;
    cout << "Enter room number to vacate: ";
    cin >> rNo;

    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == rNo) {
            hotel[i].isBooked = 0;
            saveToFile();
            cout << "Room vacated.\n";
            return;
        }
    }
    cout << "Room not found.\n";
}
