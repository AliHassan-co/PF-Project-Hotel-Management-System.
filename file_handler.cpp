#include "room.h"
#include <fstream>
#include <sstream>

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
        stringstream ss(line);
        string no, type, price, status;

        getline(ss, no, ',');
        getline(ss, type, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');

        hotel[totalRooms].roomNumber = stoi(no);
        hotel[totalRooms].type = type;
        hotel[totalRooms].price = stod(price);
        hotel[totalRooms].isBooked = stoi(status);
        totalRooms++;
    }
    inFile.close();
}
