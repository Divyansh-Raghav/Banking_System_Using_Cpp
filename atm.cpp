#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constant for conversion rate (1 USD = 83 INR)
const double USD_TO_INR = 83.0;

class Account {
private:
    int accountNumber;
    int pin;
    double balance;  // Balance in USD
    vector<string> transactionHistory;

public:
    Account(int accNum, int p, double bal) : accountNumber(accNum), pin(p), balance(bal) {}

    int getAccountNumber() { return accountNumber; }
    bool verifyPin(int enteredPin) { return pin == enteredPin; }
    
    // Get balance in INR
    double getBalanceInINR() { return balance * USD_TO_INR; }

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposit: $" + to_string(amount));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrawal: $" + to_string(amount));
            return true;
        }
        return false;
    }

    void displayTransactionHistory() {
        for (const string &transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

class ATM {
private:
    vector<Account> accounts;

public:
    ATM(const vector<Account> &accs) : accounts(accs) {}

    Account* authenticateUser(int accountNumber, int pin) {
        for (Account &account : accounts) {
            if (account.getAccountNumber() == accountNumber && account.verifyPin(pin)) {
                return &account;
            }
        }
        return nullptr;
    }

    void displayMenu() {
        cout << "1. Balance Inquiry (INR)" << endl;
        cout << "2. Deposit (USD)" << endl;
        cout << "3. Withdraw (USD)" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Exit" << endl;
    }

    void run() {
        int accountNumber, pin;
        cout << "Enter your account number: ";
        cin >> accountNumber;
        cout << "Enter your PIN: ";
        cin >> pin;

        Account* userAccount = authenticateUser(accountNumber, pin);
        if (userAccount) {
            int choice;
            do {
                displayMenu();
                cin >> choice;
                processTransaction(choice, userAccount);
            } while (choice != 5);
        } else {
            cout << "Invalid account number or PIN!" << endl;
        }
    }

    void processTransaction(int choice, Account* userAccount) {
        double amount;
        switch (choice) {
            case 1:
                cout << "Balance: ₹" << userAccount->getBalanceInINR() << endl;
                break;
            case 2:
                cout << "Enter amount to deposit (in USD): ";
                cin >> amount;
                userAccount->deposit(amount);
                cout << "Deposit successful!" << endl;
                break;
            case 3:
                cout << "Enter amount to withdraw (in USD): ";
                cin >> amount;
                if (userAccount->withdraw(amount)) {
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                break;
            case 4:
                cout << "Transaction History:" << endl;
                userAccount->displayTransactionHistory();
                break;
            case 5:
                cout << "Thank you for using the ATM!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    vector<Account> accounts = {
        Account(123456, 1234, 500.0),  // Balance in USD
        Account(234567, 2345, 1000.0),
        Account(345678, 3456, 1500.0)
    };

    ATM atm(accounts);
    atm.run();

    return 0;
}
