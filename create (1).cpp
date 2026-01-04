#include "room.h"

void addRoom() {
    if (totalRooms >= MAX_ROOMS) {
        cout << "Room limit reached!\n";
        return;
    }

    cout << "Room No: ";
    cin >> hotel[totalRooms].roomNumber;

    cout << "Type: ";
    cin >> hotel[totalRooms].type;

    cout << "Price: ";
    cin >> hotel[totalRooms].price;

    hotel[totalRooms].isBooked = 0;
    totalRooms++;
    saveToFile();

    cout << "Room added successfully.\n";
}
