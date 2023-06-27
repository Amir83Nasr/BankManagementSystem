//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Customer.hpp"

#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

#include <random>
#include <algorithm>

using namespace std;

//=================================== CLASS ===========================================
void Account::set_Aname(const char *name)
{
    for (size_t i = 0; i < strlen(name); i++)
    {
        Aname[i] = name[i];
    }
}
const char *Account::get_Aname() const
{
    return Aname;
}

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
    //"============================================
    //"  Account no.                    Balance
    //"============================================
    cout << "  " << left << setw(14) << Aname << setw(20) << Anumber << setw(12) << Abalance << endl;
}

//=================================== FUNCTION : 1 ===========================================
int generateRandomNumber()
{
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<int> dist(1000, 9999);

    int number = dist(gen);

    return number;
}

void Account::create_account(int Anum, const char *name)
{
    Anumber = Anum;
    set_Aname(name);

    cout << "\nEnter The Balance : ";
    cin >> Abalance;

    cout << "\n\n ===== Account Created ... =====";
}

//=================================== FUNCTION : 2 ===========================================

void write_account(const char *name)
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
        break;
    }
    inFile.close();

    fstream outFile;
    outFile.open("../Data/Account.dat", ios::binary | ios::out | ios::app);

    if (find == false)
    {
        Account newAccount;

        newAccount.create_account(actNumber, name);
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

void display_all_account(const char *name)
{
    Account account;

    ifstream inFile("../Data/Account.dat", ios::binary);
    
    if (!inFile)
    {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "============================================\n";
    cout << "  Account no.                    Balance    \n";
    cout << "============================================\n";

    // Read from both files independently
    while (inFile.read((char*)&account, sizeof(Account)))
    {
        if(strcmp(account.get_Aname(), name) == 0)
        {
        account.report_acc();
        }
    }

    inFile.close();
}


//=================================== FUNCTION : 3 ===========================================

void display_all_account_all()
{
    Account account;

    ifstream inFile("../Data/Account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "=====================================================\n";
    cout << "  Name           Account num.             Balance\n";
    cout << "======================================================\n";

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

    fstream inFile("../Data/Account.dat", ios::binary | ios::in);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (!inFile.eof() && find == false)
    {
        if (accountSend.get_Anumber() == AnumSend || accountRec.get_Anumber() == AnumRec)
        {
            find = true;
            break;
        }
    }
    inFile.close();

    fstream outFile("../Data/Account.dat", ios::binary | ios::out);
    while (!outFile.eof() && find == true)
    {
        accountSend.show_account();

        cout << "\n\nEnter The amount to be Send : ";
        cin >> amount;

        if (accountSend.get_Anumber() == AnumSend)
        {
            accountSend.draw(amount);

            long int pos1 = (-1) * (sizeof(Account));
            outFile.seekp(pos1, ios::cur);
            outFile.write((char *)&accountSend, sizeof(Account));
        }

        if (accountRec.get_Anumber() == AnumRec)
        {
            accountRec.deposit(amount);

            long int pos2 = (-1) * (sizeof(Account));
            outFile.seekp(pos2, ios::cur);
            outFile.write((char *)&accountRec, sizeof(Account));
        }

        cout << "\n\n\t Record Updated";
    }
    outFile.close();

    if (find == false)
    {
        cout << "\n\t\t Record Not Found !!!";
    }
}

//=================================== FUNCTION : 8 ===========================================

bool login_account(int accNum)
{
    bool login{false};
    int number;
    
    number = accNum;


    // cout << "Enter your Account Number : ";
    // cin >> accNumber;

    Account account;

    ifstream inFile("../Data/Account.dat");
    while (inFile.read((char *)&account, sizeof(Account)))
    {
        if (account.get_Anumber() == number)
        {
            login = true;
            break;
        }
        
    }

    if (login == true)
    {
        cout << "\n\t\tLogin was successful ...";
        return true;
    }
    else
    {
        cout << "\n\t\tAccount Number Not Found !!!\n";
        return false;
    }
}

//========================================================================================