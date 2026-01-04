#include "room.h"

void viewRooms() {
    cout << left << setw(12) << "No"
         << setw(15) << "Type"
         << setw(10) << "Price"
         << setw(12) << "Status" << endl;

    cout << "--------------------------------------------\n";

    for (int i = 0; i < totalRooms; i++)
        hotel[i].display();
}

void searchRoom() {
    int rNo;
    cout << "Enter room number: ";
    cin >> rNo;

    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == rNo) {
            hotel[i].display();
            return;
        }
    }
    cout << "Room not found.\n";
}
