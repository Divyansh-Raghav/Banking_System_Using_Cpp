#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNum, string accName, double initialBalance) : accountNumber(accNum), accountHolderName(accName), balance(initialBalance) {}

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of ₹" << amount << " successful. New balance: ₹" << balance << endl;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of ₹" << amount << " successful. New balance: ₹" << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance! Current balance: ₹" << balance << endl;
            return false;
        }
    }

    bool transfer(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            cout << "Transferred ₹" << amount << " to Account " << toAccount.getAccountNumber() << endl;
            return true;
        } else {
            cout << "Transfer failed due to insufficient funds!" << endl;
            return false;
        }
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

class BankingSystem {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1001;

public:
    void createAccount() {
        string name;
        double initialDeposit;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter initial deposit: ₹";
        cin >> initialDeposit;

        Account newAccount(nextAccountNumber, name, initialDeposit);
        accounts.push_back(newAccount);

        cout << "Account created successfully! Your account number is " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    Account* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void depositToAccount() {
        int accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        Account *acc = findAccount(accNum);
        if (acc) {
            cout << "Enter amount to deposit: ₹";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdrawFromAccount() {
        int accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        Account *acc = findAccount(accNum);
        if (acc) {
            cout << "Enter amount to withdraw: ₹";
            cin >> amount;
            acc->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void transferBetweenAccounts() {
        int fromAccNum, toAccNum;
        double amount;

        cout << "Enter your account number: ";
        cin >> fromAccNum;

        cout << "Enter recipient's account number: ";
        cin >> toAccNum;

        Account *fromAccount = findAccount(fromAccNum);
        Account *toAccount = findAccount(toAccNum);

        if (fromAccount && toAccount) {
            cout << "Enter amount to transfer: ₹";
            cin >> amount;
            fromAccount->transfer(*toAccount, amount);
        } else {
            cout << "One or both accounts not found!" << endl;
        }
    }

    void displayAccountDetails() {
        int accNum;
        cout << "Enter account number: ";
        cin >> accNum;

        Account *acc = findAccount(accNum);
        if (acc) {
            acc->displayDetails();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void displayMenu() {
        cout << "------------------- Online Banking System -------------------" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    depositToAccount();
                    break;
                case 3:
                    withdrawFromAccount();
                    break;
                case 4:
                    transferBetweenAccounts();
                    break;
                case 5:
                    displayAccountDetails();
                    break;
                case 6:
                    cout << "Thank you for using the Online Banking System!" << endl;
                    break;
                default:
                    cout << "Invalid option! Please try again." << endl;
            }

            cout << endl;
        } while (choice != 6);
    }
};

int main() {
    BankingSystem bankingSystem;
    bankingSystem.run();

    return 0;
}
