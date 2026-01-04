# PF-Project-Hotel-Management-System.
2. Objective

The main objective of this project is to develop a simple console-based Hotel Management System that allows the hotel staff to:

Add rooms to the system

View all available rooms

Search for a room

Book or vacate rooms

Delete room records

Maintain data persistence using file handling

This system helps in efficient management of hotel room data without the need for paper-based records.

3. Tools and Technologies Used
Tool/Language	Purpose
C++	Programming language for system logic
File Handling (CSV)	To save and load data persistently
Visual Studio / Code::Blocks	IDE for development
Console Input/Output	For user interaction
4. Modules

The project is divided into separate modules to improve readability and maintenance:

4.1 Room Class (room.h)

Contains attributes of a room: number, type, price, booking status

display() function for formatted output

4.2 File Handling (file_handler.cpp)

saveToFile(): Saves room data to hotel_data.csv

loadFromFile(): Loads room data from hotel_data.csv

4.3 Create Room (create.cpp)

Adds a new room to the system

Checks room limit before adding

Marks new rooms as Available

4.4 Read/View (read.cpp)

viewRooms(): Displays all rooms

searchRoom(): Searches a room by number

4.5 Update (update.cpp)

bookRoom(): Marks room as Booked

vacateRoom(): Marks room as Available

4.6 Delete (delete.cpp)

deleteRoom(): Deletes a room from the system

Updates file after deletion

4.7 Main Program (main.cpp)

Provides a menu-driven interface

Calls functions from all modules

5. Flow of the System

Step 1: Load data from file
Step 2: Show menu
Step 3: Perform operation based on user choice:

Add Room

View Rooms

Search Room

Book Room

Vacate Room

Delete Room

Exit

Step 4: Save changes to file after each operation
Step 5: Repeat menu until exit

6. Class Diagram
+-------------------+
|       Room        |
+-------------------+
| - roomNumber: int |
| - type: string    |
| - price: double   |
| - isBooked: int   |
+-------------------+
| + display(): void |
+-------------------+


Explanation:

Room class represents a single hotel room

Each room object stores all information about a room

Methods are used to display room details

7. Data Flow Diagram (DFD) – Level 0
     +-------------------+
     |   User (Staff)    |
     +-------------------+
               |
               v
         +------------+
         |  Main Menu |
         +------------+
               |
      -------------------------
      |           |           |
      v           v           v
   Add Room    View/Search   Update/Delete
      |           |           |
      -------------------------
               |
               v
        File Handling
  (Save/Load CSV data)

8. Sample Input/Output
Add Room
Room No: 101
Type: Single
Price: 3000
[Success] Room Added.

View Rooms
No.          Type           Price     Status
--------------------------------------------
101          Single         3000      Available
102          Double         5000      Booked

Search Room
Enter room number: 102
102          Double         5000      Booked

Book Room
Enter room number to book: 101
Room booked.

Delete Room
Enter room number to delete: 102
Room deleted.

9. Advantages

Reduces manual work

Saves data permanently in a file

Easy to update and maintain

Modular structure makes it readable and extendable

Console-based, works without GUI

10. Limitations

No customer details (name, contact) included

Room type input does not allow spaces (can fix with getline)

No GUI; fully console-based

No duplicate room number validation (can be added)

11. Future Enhancements

Add Customer Management Module

Include Billing System

Create Graphical User Interface (GUI)

Add Reports (Available rooms, Booked rooms, Revenue)

Implement Database support (MySQL/SQLite)

12. Conclusion

The Hotel Management System provides an efficient way to manage rooms in a hotel. It demonstrates:

File handling for persistent storage

Modular programming with multiple files

Object-Oriented Programming concepts

Menu-driven console application

It can be extended in future with customer booking, billing, and reporting features.
