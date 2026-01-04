#include "room.h"

void deleteRoom() {
    int rNo;
    cout << "Enter room number to delete: ";
    cin >> rNo;

    for (int i = 0; i < totalRooms; i++) {
        if (hotel[i].roomNumber == rNo) {
            for (int j = i; j < totalRooms - 1; j++)
                hotel[j] = hotel[j + 1];

            totalRooms--;
            saveToFile();
            cout << "Room deleted.\n";
            return;
        }
    }
    cout << "Room not found.\n";
}
