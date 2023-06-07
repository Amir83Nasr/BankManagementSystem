//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//=================================== CLASS ===========================================

void Customer::create_customer(int Cnum)
{

    Cnumber = Cnum;

    cout << "\nEnter The Name of The Customer : ";
    cin.ignore();
    cin.get(Cname, 30);
    // getline(cin, Cname);

    cout << "\nEnter The Balance : ";
    cin >> Cbalance;

    cout << "\n\n ===== Customer Created ... =====";
}


void Customer::show_customer()
{
    cout << "\nCustomer Number : " << Cnumber << endl;

    cout << "\nCustomer Holder Name : " << Cname << endl;

    cout << "\nBalance amount : " << Cbalance << endl;

    cout << "\n------------------------------------------\n";
}

void Customer::modify()
{
    cout << "\nThe Customer Number" << Cnumber;

    cout << "\n\nEnter The Name of The Customer Holder : ";
    cin.ignore();
    cin.get(Cname, 30);
    // getline(cin,Cname);
    cout << "\nEnter The Amount : ";
    cin >> Cbalance;
}

void Customer::deposit(int x)
{
    Cbalance += x;
}

//=================================== FUNCTION : 1 ===========================================

void write_customer()
{
    bool find = false;

    Customer account;

    int accNumber;

    cout << "Enter Your Account Number: ";
    cin >> accNumber;

    fstream inFile("../Data/Customer.dat", ios::binary | ios::in);
    while (inFile.read((char *)&account, sizeof(Customer)))
    {
        if (account.get_Cnumber() == accNumber)
            find = true;
    }
    inFile.close();

    fstream outFile;
    outFile.open("../Data/Customer.dat", ios::binary | ios::out | ios::app);

    if (find == false)
    {
        Customer newAccount;

        newAccount.create_customer(accNumber);
        outFile.write((char *)&newAccount, sizeof(Customer));
    }
    else
    {
        cout << "\n\nCustomer number exist ..." << endl;
    }

    outFile.close();
}

//=================================== FUNCTION : 2 ===========================================

void modify_customer(int accNumber)
{
    bool find = false;

    Customer account;

    fstream File("../Data/Customer.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&account, sizeof(Customer)) && find == false)
    {
        if (account.get_Cnumber() == accNumber)
        {
            account.show_customer();

            cout << "\n\nEnter The New Details of Customer : " << endl;
            account.modify();

            long int pos = (-1) * (sizeof(Customer));
            File.seekp(pos, ios::cur);

            File.write((char *)&account, sizeof(Customer));
            cout << "\n\n\t Record Updated ...";

            find = true;
        }
    }
    File.close();

    if (find == false)
    {
        cout << "\n\n Record Not Found ...";
    }
}

//=================================== FUNCTION : 3 ===========================================

void delete_customer(int accNumber)
{
    Customer account;

    ifstream inFile;
    ofstream outFile;

    inFile.open("../Data/Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    outFile.open("../Data/Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);

    while (inFile.read((char *)&account, sizeof(Customer)))
    {
        if (account.get_Cnumber() != accNumber)
        {
            outFile.write((char *)&account, sizeof(Customer));
        }
    }
    inFile.close();
    outFile.close();

    remove("../Data/Customer.dat");
    rename("../Data/Temp.dat", "../Data/Customer.dat");

    cout << "\n\n\tRecord Deleted ...";
}

//=================================== FUNCTION : 4 ===========================================

void display_one_customer(int accNumber)
{
    Customer account;

    bool find = false;

    ifstream inFile("../Data/Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\nBALANCE DETAILS\n";

    while (inFile.read((char *)&account, sizeof(Customer)))
    {
        if (account.get_Cnumber() == accNumber)
        {
            account.show_customer();
            find = true;
            break;
        }
    }
    inFile.close();

    if (find == false)
    {
        cout << "\n\nAccount number does not exist";
    }
}

//=================================== FUNCTION : 5 ===========================================

void display_all_customer()
{
    Customer account;

    ifstream inFile("../Data/Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "  Account no.           Name             Balance\n";
    cout << "====================================================\n";

    while (inFile.read((char *)&account, sizeof(Customer)))
    {
        account.report();
    }
    inFile.close();
}

//=================================== FUNCTION : 6 ===========================================

void deposit_withdraw(int acNumber, int option)
{
    int amount{};

    bool find = false;

    Customer account;

    fstream File;
    File.open("../Data/Customer.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&account, sizeof(Customer)) && find == false)
    {
        if (account.get_Cnumber() == acNumber)
        {
            account.show_customer();

            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSITE AMOUNT ";
                cout << "\n\nEnter The amount to be (deposited) : ";
                cin >> amount;

                account.deposit(amount);
            }

            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be (withdraw) : ";
                cin >> amount;

                account.draw(amount);
            }

            long int pos = (-1) * (sizeof(Customer));
            File.seekp(pos, ios::cur);

            File.write((char *)&account, sizeof(Customer));
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

//=================================== FUNCTION : 7 ===========================================

bool login_customer(int cinNum)
{
    bool login{false};
    int accNumber;

    accNumber = cinNum;

    // cout << "Enter your Account Number : ";
    // cin >> accNumber;

    Customer account;

    ifstream inFile("../Data/Customer.dat");
    while (inFile.read((char *)&account, sizeof(Customer)))
    {
        if (account.get_Cnumber() == accNumber)
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