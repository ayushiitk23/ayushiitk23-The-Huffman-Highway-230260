#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Transaction {
private:
    string date;
    double amount;

public:
    Transaction(string d, double a) : date(d), amount(a) {}

    string getDate() const { return date; }
    double getAmount() const { return amount; }
};

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    string address;
    string accountType;
    double funds;
    vector<Transaction> transactionHistory;
    vector<string> loanHistory;

public:
    Account(int number, string name, string addr, string type, double fund) :
        accountNumber(number), accountHolderName(name), address(addr), accountType(type), funds(fund) {}

    virtual void deposit(double amount) {
        funds += amount;
        transactionHistory.push_back(Transaction(getCurrentDate(), amount));
    }

    virtual void withdraw(double amount) {
        if (funds >= amount) {
            funds -= amount;
            transactionHistory.push_back(Transaction(getCurrentDate(), -amount));
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    virtual void updateAccountInformation(string newName, string newAddress) {
        accountHolderName = newName;
        address = newAddress;
    }

    virtual void viewPassbook() const {
        cout << "Transaction History:" << endl;
        for (const Transaction& transaction : transactionHistory) {
            cout << "Date: " << transaction.getDate() << ", Amount: Rs " << transaction.getAmount() << endl;
        }
    }

    virtual void searchTransactionHistory(string date, double amount) const {
        cout << "Transactions on " << date << " with amount Rs " << amount << ":" << endl;
        for (const Transaction& transaction : transactionHistory) {
            if (transaction.getDate() == date && transaction.getAmount() == amount) {
                cout << "Date: " << transaction.getDate() << ", Amount: Rs " << transaction.getAmount() << endl;
            }
        }
    }

    static string getCurrentDate() {
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        return to_string(currentTime->tm_mday) + "/" + to_string(currentTime->tm_mon + 1) + "/" + to_string(currentTime->tm_year + 1900);
    }

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    string getAddress() const { return address; }
    string getAccountType() const { return accountType; }
    double getFunds() const { return funds; }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int number, string name, string addr, double fund) :
        Account(number, name, addr, "Savings", fund) {}
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int number, string name, string addr, double fund) :
        Account(number, name, addr, "Current", fund) {}
};

int main() {
    SavingsAccount acc1(123456, "Ayush", "IITK", 1000.0);
    CurrentAccount acc2(654321, "Aryan", "IITK", 2000.0);

    acc1.deposit(500.0);
    acc1.withdraw(200.0);
    acc1.updateAccountInformation("Harshit Agarwal", "IITK");

    acc1.viewPassbook();
    acc1.searchTransactionHistory("28/5/2024", 500.0);

    acc2.deposit(1000.0);
    acc2.withdraw(500.0);

    acc2.viewPassbook();
    acc2.searchTransactionHistory("27/5/2024", 500.0);

    return 0;
}
