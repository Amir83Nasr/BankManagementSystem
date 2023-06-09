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








//========================================================================================