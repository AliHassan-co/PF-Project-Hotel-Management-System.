#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

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

Room hotel[MAX_ROOMS];
int totalRooms = 0;

void saveToFile() {
    ofstream outFile("hotel_data.csv");
    for (int i = 0; i < totalRooms; i++) {
        outFile << hotel[i].roomNumber << ","
                << hotel[i].type << ","
                << hotel[i].price << ","
                << hotel[i].isBooked << endl;
    }
    outFile.close();
}

void loadFromFile() {
    ifstream inFile("hotel_data.csv");
    if (!inFile) return;

    totalRooms = 0;
    string line;
    while (getline(inFile, line) && totalRooms < MAX_ROOMS) {
        if (line.empty()) continue;
        stringstream ss(line);
        string rNo, rType, rPrice, rStatus;

        if (getline(ss, rNo, ',') &&
            getline(ss, rType, ',') &&
            getline(ss, rPrice, ',') &&
            getline(ss, rStatus, ',')) {
            
            hotel[totalRooms].roomNumber = stoi(rNo);
            hotel[totalRooms].type = rType;
            hotel[totalRooms].price = stod(rPrice);
            hotel[totalRooms].isBooked = stoi(rStatus);
            totalRooms++;
        }
    }
    inFile.close();
}

int main() {
    loadFromFile();
    int choice;

    while (true) {
        cout << "\n1. Add Room\n2. View All Room\n3. Search Room\n4. Book Room\n5. Vacate Room\n6. Delete Room\n7. Exit\nSelection: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            if (totalRooms < MAX_ROOMS) {
                cout << "Room No: "; cin >> hotel[totalRooms].roomNumber;
                cout << "Type(AC/N0n-AC): "; cin >> hotel[totalRooms].type;
                cout << "Price: "; cin >> hotel[totalRooms].price;
                hotel[totalRooms].isBooked = 0;
                totalRooms++;
                saveToFile();
                cout << "[Success] Room Added.\n";
            } else {
                cout << "[Error] Array Full.\n";
            }
        } else if (choice == 2) {
            cout << "\n" << left << setw(12) << "No." << setw(15) << "Type" << setw(10) << "Price" << "Status" << endl;
            cout << "---------------------------------------------------\n";
            for (int i = 0; i < totalRooms; i++) hotel[i].display();
        } else if (choice == 3) {
            int rNo; cout << "Search No: "; cin >> rNo;
            bool found = false;
            for (int i = 0; i < totalRooms; i++) {
                if (hotel[i].roomNumber == rNo) { hotel[i].display(); found = true; break; }
            }
            if (!found) cout << "Not Found.\n";
        } else if (choice == 4) {
            int rNo; cout << "Book No: "; cin >> rNo;
            for (int i = 0; i < totalRooms; i++) {
                if (hotel[i].roomNumber == rNo) { hotel[i].isBooked = 1; saveToFile(); cout << "Booked.\n"; break; }
            }
        } else if (choice == 5) {
            int rNo; cout << "Vacate No: "; cin >> rNo;
            for (int i = 0; i < totalRooms; i++) {
                if (hotel[i].roomNumber == rNo) { hotel[i].isBooked = 0; saveToFile(); cout << "Vacated.\n"; break; }
            }
        } else if (choice == 6) {
            int rNo; cout << "Delete No: "; cin >> rNo;
            for (int i = 0; i < totalRooms; i++) {
                if (hotel[i].roomNumber == rNo) {
                    for (int j = i; j < totalRooms - 1; j++) hotel[j] = hotel[j + 1];
                    totalRooms--;
                    saveToFile();
                    cout << "Deleted.\n";
                    break;
                }
            }
        } else if (choice == 7) break;
    }
    return 0;
}