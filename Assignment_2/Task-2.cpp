#include <iostream>
using namespace std;

struct FeetInches {
    int feet;
    int inches;
};

struct RoomDimension {
    FeetInches length;
    FeetInches width;
};

int computeTheCarpetingCost(const RoomDimension& room) {
    double l = room.length.feet + room.length.inches / 12.0;
    double w = room.width.feet + room.width.inches / 12.0;

    double area = l * w;
    int cost = area * 18;
    return cost;
}

int main() {
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;

    RoomDimension* rooms = new RoomDimension[n];

    for (int i = 0; i < n; i++) {
        cout << "\nRoom " << i + 1 << endl;
        cout << "Length feet: ";
        cin >> rooms[i].length.feet;
        cout << "Length inches: ";
        cin >> rooms[i].length.inches;
        cout << "Width feet: ";
        cin >> rooms[i].width.feet;
        cout << "Width inches: ";
        cin >> rooms[i].width.inches;
    }

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Total cost of the house\n";
        cout << "2. Cost of one room\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                total = total + computeTheCarpetingCost(rooms[i]);
            }
            cout << "Total cost = Rs. " << total << endl;
        }
        else if (choice == 2) {
            int num;
            cout << "Enter room number: ";
            cin >> num;
            if (num >= 1 && num <= n) {
                cout << "Cost = Rs. " << computeTheCarpetingCost(rooms[num - 1]) << endl;
            }
            else {
                cout << "Wrong room number!\n";
            }
        }
        else if (choice != 3) {
            cout << "Wrong choice!\n";
        }

    } while (choice != 3);

    delete[] rooms;

    return 0;
}