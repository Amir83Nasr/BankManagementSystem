//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

//=================================== CLASS ===========================================

int Account::get_Abalance()
{
    return Abalance;
}

int Account::get_Anumber()
{
    return Anumber;
}

void Account::show_account()
{
    // cout << "\nCustomer Number : " << Cnumber << endl;

    // cout << "\nCustomer Holder Name : " << Cname << endl;

    cout << "\nAccount Number : " << Anumber << endl;

    cout << "\nBalance amount : " << Abalance << endl;

    cout << "\n------------------------------------------\n";
}

void Account::report_acc()
{
    // "  Account no.           Balance"
    cout << "  " << left << setw(14) << Anumber << setw(12) << Abalance << endl;
}

//=================================== FUNCTION : 1 ===========================================
int generateRandomNumber() {
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<int> dist(1000, 9999);

    int number = dist(gen);

    return number;
}

void Account::create_account(int Anum)
{
    Anumber = Anum;

    cout << "\nEnter The Balance : ";
    cin >> Abalance;

    cout << "\n\n ===== Account Created ... =====";
}

//=================================== FUNCTION : 2 ===========================================

void write_account()
{
    bool find = false;

    Account account;

    int actNumber;

    // cout << "Enter Your Customer Number: ";
    // cin >> cstNumber;

    actNumber = generateRandomNumber();

    fstream inFile("../Data/Account.dat", ios::binary | ios::in);
    while (inFile.read((char *)&account, sizeof(Account)))
    {
        if (account.get_Anumber() == actNumber)
            find = true;
    }
    inFile.close();

    fstream outFile;
    outFile.open("../Data/Account.dat", ios::binary | ios::out | ios::app);

    if (find == false)
    {
        Account newAccount;

        newAccount.create_account(actNumber);
        outFile.write((char *)&newAccount, sizeof(Account));
        cout << "\n\nYour Account Number is : " << actNumber;
    }
    else
    {
        cout << "\n\nAccount number exist ..." << endl;
    }

    outFile.close();
}

//=================================== FUNCTION : 3 ===========================================

void display_all_account()
{
    Account account;

    ifstream inFile("../Data/Account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "============================================\n";
    cout << "  Account no.               Balance     \n";
    cout << "============================================\n";

    while (inFile.read((char *)&account, sizeof(Account)))
    {
        account.report_acc();
    }
    inFile.close();
}

//=================================== FUNCTION : 4 ===========================================

void transaction(int AnumSend, int AnumRec)
{
    int amount{};

    bool find = false;

    Account accountSend;
    Account accountRec;

    fstream File;
    File.open("../Data/Account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&accountSend, sizeof(Account)) && File.read((char *)&accountRec, sizeof(Account)) && find == false)
    {
        if (accountSend.get_Anumber() == AnumSend && accountRec.get_Anumber() == AnumRec)
        {
            accountSend.show_account();

            // cout << "\n\n\tTO DEPOSITE AMOUNT ";
            cout << "\n\nEnter The amount to be Send : ";
            cin >> amount;

            accountSend.draw(amount);
            accountRec.deposit(amount);
        

            long int pos1 = (-1) * (sizeof(Account));
            File.seekp(pos1, ios::cur);
            long int pos2 = (-1) * (sizeof(Account));
            File.seekp(pos2, ios::cur);

            File.write((char *)&accountSend, sizeof(Account));
            File.write((char *)&accountRec, sizeof(Account));
            cout << "\n\n\t Record Updated";

            find = true;
        }
    }
    File.close();

    if (find == false)
    {
        cout << "\n\t\t Record Not Found !!!";
    }

}





//========================================================================================