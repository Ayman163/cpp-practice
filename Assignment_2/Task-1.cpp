#include <iostream>
#include <string>
using namespace std;

struct InventoryItem {
    string code;
    string name;
    double cost;
    double sellingPrice;
};

InventoryItem insertItem() {
    InventoryItem item;

    cout << "Enter item name: ";
    getline(cin, item.name);

    cout << "Enter item cost: ";
    cin >> item.cost;
    cin.ignore();

    item.sellingPrice = item.cost + item.cost * 0.4;

    string first3 = item.name.substr(0, 3);

    for (int i = 0; i < first3.length(); i++) {
        if (first3[i] >= 'a' && first3[i] <= 'z') {
            first3[i] = first3[i] - 32;
        }
    }

    item.code = first3 + "_";

    return item;
}

void displayStock(const InventoryItem* items, int size) {
    cout << "\nCode\t\tName\t\tCost\t\tSelling Price\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << items[i].code << "\t"
             << items[i].name << "\t\t"
             << items[i].cost << "\t\t"
             << items[i].sellingPrice << endl;
    }
}

int main() {
    InventoryItem stock[10];

    for (int i = 0; i < 10; i++) {
        cout << "\nItem " << i + 1 << endl;
        stock[i] = insertItem();

        int num = 31203 + i;
        string digits = "";
        while (num > 0) {
            char d = '0' + (num % 10);
            digits = d + digits;
            num = num / 10;
        }
        stock[i].code = stock[i].code + digits;
    }

    displayStock(stock, 10);

    return 0;
}