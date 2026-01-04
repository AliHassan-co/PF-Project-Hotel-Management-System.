#include "room.h"

int main() {
    loadFromFile();
    int choice;

    do {
        cout << "\n1. Add Room\n2. View Rooms\n3. Search Room\n4. Book Room\n";
        cout << "5. Vacate Room\n6. Delete Room\n7. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: addRoom(); break;
        case 2: viewRooms(); break;
        case 3: searchRoom(); break;
        case 4: bookRoom(); break;
        case 5: vacateRoom(); break;
        case 6: deleteRoom(); break;
        }
    } while (choice != 7);

    return 0;
}
