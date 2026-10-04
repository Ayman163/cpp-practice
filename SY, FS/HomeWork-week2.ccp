#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string ownerName;
    double balance;
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout<<"Deposit successful" << endl;
            cout<<"added amount is :"<<amount<<endl;
        }
        else {
            cout<<"Deposit failed" << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout<< "Withdrawal successful!" << endl;
        }
        else {
            cout<< "Withdrawal failed!" << endl;
        }
    }
    void display() {
        cout<< "Account Number: " << accountNumber << endl;
        cout<< "Owner Name: " << ownerName << endl;
        cout<< "Balance: " << balance << endl;
    }
};
int main() {
    BankAccount a;
    a.accountNumber = 2312;
    a.ownerName = "Ayman";
    a.balance = 10000;
    a.display();
    a.deposit(10);
    a.withdraw(5000);
    a.display();

    BankAccount b;
    b.accountNumber = 2313;
    b.ownerName = "ay";
    b.balance = 4000;
    b.display();
    b.deposit(1700);
    b.withdraw(500);
    b.display();
    BankAccount c;
    c.accountNumber = 2314;
    c.ownerName = "aym";
    c.balance = 6700;
    c.display();
    c.deposit(100);
    c.withdraw(8000);    
    c.display();
    return 0;
}
