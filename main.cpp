#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class to store customer details
class Customer {
    public:
        string name;

        Customer() {
            name = "";
        }

        Customer(string n) {
            name = n;
        }
};

// Base class for bank accounts
class Account {
    public:
        int accountNumber;
        double balance;

        Account() {
            accountNumber = 0;
            balance = 0.0;
        }

        Account(int accNo, double bal) {
            accountNumber = accNo;
            balance = bal;
        }

        // Standard deposit logic
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
            } else {
                cout << "Invalid amount!" << endl;
            }
        }

        // Standard withdrawal logic
        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        }

        // Helper to check if ID matches
        bool matchesId(int id) {
            return accountNumber == id;
        }

        void display() {
            cout << "Acc No: " << accountNumber << " | Balance: $" << fixed << setprecision(2) << balance << endl;
        }
};

// Derived class for Savings Accounts with interest rates
class SavingsAccount : public Account {
    public:
        double interestRate;

        SavingsAccount() {
            interestRate = 0.0;
        }

        SavingsAccount(int a, double b, double r) {
            accountNumber = a;
            balance = b;
            interestRate = r;
        }

        // Overridden display for Savings type
        void display() {
            cout << "Type: Savings | ";
            Account::display();
        }
};

// Derived class for Current Accounts with overdraft features
class CurrentAccount : public Account {
    public:
        double overdraftLimit;

        CurrentAccount() {
            overdraftLimit = 0.0;
        }

        CurrentAccount(int a, double b, double l) {
            accountNumber = a;
            balance = b;
            overdraftLimit = l;
        }

        // Overridden withdraw to handle overdraft limit
        void withdraw(double amount) {
            if (amount > 0 && amount <= (balance + overdraftLimit)) {
                balance -= amount;
                cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
            } else {
                cout << "Overdraft limit exceeded!" << endl;
            }
        }

        void display() {
            cout << "Type: Current | ";
            Account::display();
        }
};

// Management class to handle account operations
class Bank {
    private:
        Customer customers[100];
        SavingsAccount savings[100];
        CurrentAccount currents[100];
        int sCount, cCount, nextAccountNumber;

        // Search functions to find account indices
        int findSavings(int id) {
            for (int i = 0; i < sCount; i++)
                if (savings[i].matchesId(id)) return i;
            return -1;
        }

        int findCurrent(int id) {
            for (int i = 0; i < cCount; i++)
                if (currents[i].matchesId(id)) return i;
            return -1;
        }

    public:
        Bank() {
            sCount = cCount = 0;
            nextAccountNumber = 1001;
        }

        // logic to create new accounts
        void openAccount() {
            int type;
            double bal;
            string name;

            cout << "\n--- Select Account Type ---\n1. Savings\n2. Current\nChoice: ";
            cin >> type;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Initial Balance: $";
            cin >> bal;

            if (type == 1) {
                customers[sCount] = Customer(name);
                savings[sCount] = SavingsAccount(nextAccountNumber, bal, 5.0);
                cout << "Savings Account Created! ID: " << nextAccountNumber << endl;
                sCount++;
            } else if (type == 2) {
                customers[cCount] = Customer(name);
                currents[cCount] = CurrentAccount(nextAccountNumber, bal, 1000.0);
                cout << "Current Account Created! ID: " << nextAccountNumber << endl;
                cCount++;
            } else {
                cout << "Invalid type selected!\n";
                return;
            }
            nextAccountNumber++;
        }

        // logic for processing deposits
        void deposit() {
            int accNo;
            double amount;
            cout << "Account No: ";
            cin >> accNo;
            cout << "Amount: $";
            cin >> amount;

            int s = findSavings(accNo), c = findCurrent(accNo);
            if (s != -1) {
                savings[s].deposit(amount);
            } 
            else if (c != -1) {
                currents[c].deposit(amount);
            } 
            else {
                cout << "Account not found!\n";
            }
        }

        // logic for processing withdrawals
        void withdraw() {
            int accNo;
            double amount;
            cout << "Account No: ";
            cin >> accNo;
            cout << "Amount: $";
            cin >> amount;

            int s = findSavings(accNo), c = findCurrent(accNo);
            if (s != -1) 
                savings[s].withdraw(amount);
            else if (c != -1) 
                currents[c].withdraw(amount);
            else 
                cout << "Account not found!\n";
        }

        // Display individual balance info
        void checkBalance() {
            int accNo;
            cout << "Account No: ";
            cin >> accNo;

            int s = findSavings(accNo), c = findCurrent(accNo);
            if (s != -1) {
                cout << "Holder: " << customers[s].name << "\n";
                savings[s].display();
            } 
            else if (c != -1) {
                cout << "Holder: " << customers[c].name << "\n";
                currents[c].display();
            } 
            else {
                cout << "Account not found!\n";
            }
        }

        // List all registered accounts
        void displayAll() {
            if (sCount == 0 && cCount == 0) {
                cout << "No accounts found!\n";
                return;
            }
            cout << "\n--- ALL ACCOUNTS ---\n";
            for (int i = 0; i < sCount; i++) {
                cout << customers[i].name << "\n";
                savings[i].display();
                cout << "-----------------------\n";
            }
            for (int i = 0; i < cCount; i++) {
                cout << customers[i].name << "\n";
                currents[i].display();
                cout << "-----------------------\n";
            }
        }
};

int main() {
    Bank bank;
    int choice;
    cout << "==================================\n     BANK MANAGEMENT SYSTEM     \n==================================\n";

    // Main program loop
    do {
        cout << "\n--- MAIN MENU ---\n1. Open Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display All\n6. Exit\nChoice: ";

        // Handle non-integer input to prevent infinite loops
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: 
                bank.openAccount(); break;
            case 2: 
                bank.deposit(); break;
            case 3: 
                bank.withdraw(); break;
            case 4:
                bank.checkBalance(); break;
            case 5: 
                bank.displayAll(); break;
            case 6: 
                cout << "Thank you for banking with us!\n"; break;
            default: 
                cout << "Invalid choice!\n";
        }
    } 
    while (choice != 6);

    return 0;
}
