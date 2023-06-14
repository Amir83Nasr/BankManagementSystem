#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class BankAccount
{
private:
    string name;
    long int accountNumber;
    float balance;

public:
    BankAccount()
    {
        name = "";
        accountNumber = 0;
        balance = 0.0;
    }
    BankAccount(string n, long int a, float b)
    {
        name = n;
        accountNumber = a;
        balance = b;
    }
    string getName() const
    {
        return name;
    }
    long int getAccountNumber() const
    {
        return accountNumber;
    }
    float getBalance() const
    {
        return balance;
    }
    void deposit(float amount)
    {
        balance += amount;
        cout << "Deposit of $" << amount << " successful\n";
    }
    void withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful\n";
        }
    }
    void display() const
    {
        cout << "Account Holder Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: $" << balance << endl;
    }
};

void addAccount()
{
    ofstream fout("accounts.txt", ios::app);
    if (!fout)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    string name;
    long int accountNumber;
    float balance;
    cout << "Enter account holder name: ";
    cin >> name;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter account balance: $";
    cin >> balance;
    BankAccount account(name, accountNumber, balance);
    fout << name << " " << accountNumber << " " << balance << endl;
    cout << "Account added successfully\n";
    fout.close();
}

void displayAccounts()
{
    ifstream fin("accounts.txt");
    if (!fin)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    BankAccount account;
    while (fin >> account)
    {
        account.display();
        cout << endl;
    }
    fin.close();
}

void deposit()
{
    ifstream fin("accounts.txt");
    if (!fin)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    ofstream fout("temp.txt");
    if (!fout)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    long int accountNumber;
    float amount;
    bool found = false;
    cout << "Enter account number: ";
    cin >> accountNumber;
    while (fin >> account)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            cout << "Enter amount to deposit: $";
            cin >> amount;
            account.deposit(amount);
        }
        fout << account.getName() << " " << account.getAccountNumber() << " " << account.getBalance() << endl;
    }
    if (!found)
    {
        cout << "Account not found\n";
    }
    fin.close();
    fout.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

void withdraw()
{
    ifstream fin("accounts.txt");
    if (!fin)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    ofstream fout("temp.txt");
    if (!fout)
    {
        cerr << "Error: could not open file\n";
        return;
    }
    long int accountNumber;
    float amount;
    bool found = false;
    cout << "Enter account number: ";
    cin >> accountNumber;
    while (fin >> account)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            account.withdraw(amount);
        }
        fout << account.getName() << " " << account.getAccountNumber() << " " << account.getBalance() << endl;
    }
    if (!found)
    {
        cout << "Account not found\n";
    }
    fin.close();
    fout.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

int main()
{
    int choice;
    do
    {
        cout << "\nWelcome to the Bank Management System\n";
        cout << "\nChoose an option:\n";
        cout << "1. Add Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            cout << "Thank you for using the Bank Management System\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}