#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Transaction
{
    public:
        string type;
        double amount;

        Transaction(string t, double a)
        {
            type = t;
            amount = a;
        }
};

class Account
{
    protected:
        int accountNumber;
        string holderName;
        string phone;
        string address;
        string status;
        double balance;

        vector<Transaction> transactions;

    public:
        Account(int accNo, string name, string ph, string addr, double bal)
        {
            accountNumber = accNo;
            holderName = name;
            phone = ph;
            address = addr;
            balance = bal;
            status = "Active";
        }

        virtual string getType() = 0;

        int getAccountNumber()
        {
            return accountNumber;
        }

        double getBalance()
        {
            return balance;
        }

        string getName()
        {
            return holderName;
        }

        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
                transactions.push_back(Transaction("Deposit", amount));

                cout << "\nAmount Deposited Successfully!\n";
            }
            else
            {
                cout << "\nInvalid Amount!\n";
            }
        }

        virtual void withdraw(double amount)
        {
            if (amount <= balance)
            {
                balance -= amount;

                transactions.push_back(Transaction("Withdrawal", amount));

                cout << "\nWithdrawal Successful!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
        }

        void transfer(Account *receiver, double amount)
        {
            if (amount <= balance)
            {
                balance -= amount;
                receiver->balance += amount;

                transactions.push_back(Transaction("Transfer Sent", amount));
                receiver->transactions.push_back(Transaction("Transfer Received", amount));

                cout << "\nTransfer Successful!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
        }

        void showBalance()
        {
            cout << "\nCurrent Balance: Rs. " << balance << endl;
        }

        void showTransactions()
        {
            cout << "\n===== Transaction History =====\n";

            if (transactions.empty())
            {
                cout << "No Transactions Found!\n";
            }
            else
            {
                for (int i = 0; i < transactions.size(); i++)
                {
                    cout << i + 1 << ". "
                        << transactions[i].type
                        << " - Rs. "
                        << transactions[i].amount << endl;
                }
            }
        }

        void modifyAccount()
        {
            cin.ignore();

            cout << "\nEnter New Name: ";
            getline(cin, holderName);

            cout << "Enter New Phone: ";
            getline(cin, phone);

            cout << "Enter New Address: ";
            getline(cin, address);

            cout << "\nAccount Updated Successfully!\n";
        }

        void display()
        {
            cout << left
                << setw(15) << accountNumber
                << setw(20) << holderName
                << setw(15) << getType()
                << setw(15) << balance
                << setw(15) << status
                << endl;
        }

        virtual ~Account()
        {
            }
};

class SavingsAccount : public Account
{
    public:
        SavingsAccount(int accNo, string name, string ph, string addr, double bal)
            : Account(accNo, name, ph, addr, bal)
        {
        }

        string getType()
        {
            return "Savings";
        }
};

class CurrentAccount : public Account
{
    public:
        CurrentAccount(int accNo, string name, string ph, string addr, double bal)
            : Account(accNo, name, ph, addr, bal)
        {
        }

        string getType()
        {
            return "Current";
        }
};

class Bank
{
    private:
        vector<Account *> accounts;
        int nextAccountNumber = 1001;

    public:
        void createAccount()
        {
            int choice;
            string name, phone, address;
            double depositAmount;

            cout << "\n1. Savings Account";
            cout << "\n2. Current Account";
            cout << "\nChoose Account Type: ";
            cin >> choice;

            cin.ignore();

            cout << "Enter Holder Name: ";
            getline(cin, name);

            cout << "Enter Phone Number: ";
            getline(cin, phone);

            cout << "Enter Address: ";
            getline(cin, address);

            cout << "Enter Initial Deposit: ";
            cin >> depositAmount;

            Account *acc;

            if (choice == 1)
            {
                acc = new SavingsAccount(nextAccountNumber, name, phone, address, depositAmount);
            }
            else
            {
                acc = new CurrentAccount(nextAccountNumber, name, phone, address, depositAmount);
            }

            accounts.push_back(acc);

            cout << "\nAccount Created Successfully!";
            cout << "\nAccount Number: " << nextAccountNumber << endl;

            nextAccountNumber++;
        }

        Account *findAccount(int accNo)
        {
            for (int i = 0; i < accounts.size(); i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    return accounts[i];
                }
            }

            return NULL;
        }

        void depositMoney()
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account *acc = findAccount(accNo);

            if (acc != NULL)
            {
                cout << "Enter Amount: ";
                cin >> amount;

                acc->deposit(amount);
            }
            else
            {
                cout << "\nAccount Not Found!\n";
            }
        }

        void withdrawMoney()
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account *acc = findAccount(accNo);

            if (acc != NULL)
            {
                cout << "Enter Amount: ";
                cin >> amount;

                acc->withdraw(amount);
            }
            else
            {
                cout << "\nAccount Not Found!\n";
            }
        }

        void transferMoney()
        {
            int senderNo, receiverNo;
            double amount;

            cout << "\nEnter Sender Account Number: ";
            cin >> senderNo;

            cout << "Enter Receiver Account Number: ";
            cin >> receiverNo;

            Account *sender = findAccount(senderNo);
            Account *receiver = findAccount(receiverNo);

            if (sender != NULL && receiver != NULL)
            {
                cout << "Enter Transfer Amount: ";
                cin >> amount;

                sender->transfer(receiver, amount);
            }
            else
            {
                cout << "\nInvalid Account Number!\n";
            }
        }

        void balanceInquiry()
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account *acc = findAccount(accNo);

            if (acc != NULL)
            {
                acc->showBalance();
                acc->showTransactions();
            }
            else
            {
                cout << "\nAccount Not Found!\n";
            }
        }

        void modifyAccount()
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account *acc = findAccount(accNo);

            if (acc != NULL)
            {
                acc->modifyAccount();
            }
            else
            {
                cout << "\nAccount Not Found!\n";
            }
        }

        void deleteAccount()
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accounts.size(); i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    if (accounts[i]->getBalance() == 0)
                    {
                        delete accounts[i];

                        accounts.erase(accounts.begin() + i);

                        cout << "\nAccount Deleted Successfully!\n";
                    }
                    else
                    {
                        cout << "\nBalance Must Be Zero Before Deletion!\n";
                    }
                    return;
                }
            }
            cout << "\nAccount Not Found!\n";
        }

        void listAccounts()
        {
            cout << "\n================ ALL ACCOUNTS ================\n\n";
            cout << left
                << setw(15) << "Acc Number"
                << setw(20) << "Holder Name"
                << setw(15) << "Type"
                << setw(15) << "Balance"
                << setw(15) << "Status"
                << endl;
            cout << "-------------------------------------------------------------------\n";

            for (int i = 0; i < accounts.size(); i++)
            {
                accounts[i]->display();
            }
        }

        ~Bank()
        {
            for (int i = 0; i < accounts.size(); i++)
            {
                delete accounts[i];
            }
        }
};

int main()
{
    Bank bank;
    int choice;
    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Transfer Money";
        cout << "\n5. Balance Inquiry";
        cout << "\n6. Modify Account";
        cout << "\n7. Delete Account";
        cout << "\n8. List All Accounts";
        cout << "\n9. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.depositMoney();
            break;

        case 3:
            bank.withdrawMoney();
            break;

        case 4:
            bank.transferMoney();
            break;

        case 5:
            bank.balanceInquiry();
            break;

        case 6:
            bank.modifyAccount();
            break;

        case 7:
            bank.deleteAccount();
            break;

        case 8:
            bank.listAccounts();
            break;

        case 9:
            cout << "\nThank You For Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}
