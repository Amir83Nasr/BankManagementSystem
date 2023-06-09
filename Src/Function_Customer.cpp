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

    int Anum = generateRandomNumber();

    cout << "\nEnter The Name of The Customer : ";
    cin.ignore();
    cin.get(Cname, 30);
    // getline(cin, Cname);

    cout << "\nEnter the password of the Customer : ";
    cin >> Cpassword;

    write_account(Cname);

    cout << "\n\n ===== Customer Created ... =====";
}


void Customer::show_customer()
{
    cout << "\nCustomer Number : " << Cnumber << endl;

    cout << "\nCustomer Holder Name : " << Cname << endl;

    show_account();

    // cout << "\nBalance amount : " << Cbalance << endl;

    cout << "\n------------------------------------------\n";
}

void Customer::modify()
{
    cout << "\nThe Customer Number" << Cnumber;

    cout << "\n\nEnter The Name of The Customer Holder : ";
    cin.ignore();
    cin.get(Cname, 30);

    cout << "\n\nEnter the new Password for the customer : ";
    cin >> Cpassword;
    // getline(cin,Cname);
    // cout << "\nEnter The Amount : ";
    // cin >> Cbalance;
}

void Account::deposit(int x)
{
    Abalance += x;
}

void Account::draw(int x)
{
    Abalance -= x;
}

void Customer::report()
{
    // "  Customer no.           Name             Pass "
        cout << "  " << left << setw(14) << Cnumber << setw(26) << Cname << setw(12) << Cpassword << endl;
}

//--------------- Get & Set -----------------

int Customer::get_Cnumber()
{
    return Cnumber;
}

// int Customer::get_Cbalance()
// {
//     return Cbalance;
// }

int Customer::get_Cpassword()
{
    return Cpassword;
}

const char* Customer::get_Cname() const
{
    return Cname;
}

//=================================== FUNCTION : 1 ===========================================

void write_customer()
{
    bool find = false;

    Customer customer;

    int cstNumber;

    // cout << "Enter Your Customer Number: ";
    // cin >> cstNumber;

    cstNumber = generateRandomNumber();

    fstream inFile("../Data/Customer.dat", ios::binary | ios::in);
    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        if (customer.get_Cnumber() == cstNumber)
            find = true;
    }
    inFile.close();

    fstream outFile;
    outFile.open("../Data/Customer.dat", ios::binary | ios::out | ios::app);

    if (find == false)
    {
        Customer newCustomer;

        newCustomer.create_customer(cstNumber);
        outFile.write((char *)&newCustomer, sizeof(Customer));
        cout << "\n\nYour Customer Number is : " << cstNumber;
    }
    else
    {
        cout << "\n\nCustomer number exist ..." << endl;
    }

    outFile.close();
}

//=================================== FUNCTION : 2 ===========================================

void modify_customer(int cstNumber)
{
    bool find = false;

    Customer customer;

    fstream File("../Data/Customer.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&customer, sizeof(Customer)) && find == false)
    {
        if (customer.get_Cnumber() == cstNumber)
        {
            customer.show_customer();

            cout << "\n\nEnter The New Details of Customer : " << endl;
            customer.modify();

            long long int pos = (-1) * (sizeof(Customer));
            File.seekp(pos, ios::cur);

            File.write((char *)&customer, sizeof(Customer));
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

void delete_customer(int cstNumber)
{
    Customer customer;

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

    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        if (customer.get_Cnumber() != cstNumber)
        {
            outFile.write((char *)&customer, sizeof(Customer));
        }
    }
    inFile.close();
    outFile.close();

    remove("../Data/Customer.dat");
    rename("../Data/Temp.dat", "../Data/Customer.dat");

    cout << "\n\n\tRecord Deleted ...";
}

//=================================== FUNCTION : 4 ===========================================

void display_one_customer(int cstNumber)
{
    Customer customer;

    bool find = false;

    ifstream inFile("../Data/Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\nBALANCE DETAILS\n";

    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        if (customer.get_Cnumber() == cstNumber)
        {
            customer.show_customer();
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
    Customer customer;

    ifstream inFile("../Data/Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "=====================================================\n";
    cout << "  Customer no.           Name             Balance\n";
    cout << "======================================================\n";

    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        customer.report();
    }
    inFile.close();
}

//=================================== FUNCTION : 6 ===========================================

void deposit_withdraw(int actNumber, int option)
{
    int amount{};

    bool find = false;

    Account account;

    fstream File;
    File.open("../Data/Account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&account, sizeof(Account)) && find == false)
    {
        if (account.get_Anumber() == actNumber)
        {
            account.show_account();

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

            long long int pos = (-1) * (sizeof(Customer));
            File.seekp(pos, ios::cur);

            File.write((char *)&account, sizeof(Account));
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

// void transaction(int AnumSend, int AnumRec)
// {
//     int amount{};

//     bool find = false;

//     Account accountSend;
//     Account accountRec;

//     fstream File;
//     File.open("../Data/Account.dat", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be open !! Press any Key...";
//         return;
//     }

//     while (File.read((char *)&accountSend, sizeof(Account)) && File.read((char *)&accountRec, sizeof(Account)) && find == false)
//     {
//         if (accountSend.get_Anumber() == AnumSend && accountRec.get_Anumber() == AnumRec)
//         {
//             accountSend.show_account();

//             // cout << "\n\n\tTO DEPOSITE AMOUNT ";
//             cout << "\n\nEnter The amount to be Send : ";
//             cin >> amount;

//             accountSend.draw(amount);
//             accountRec.deposit(amount);
        

//             long int pos1 = (-1) * (sizeof(Account));
//             File.seekp(pos1, ios::cur);
//             long int pos2 = (-1) * (sizeof(Account));
//             File.seekp(pos2, ios::cur);

//             File.write((char *)&accountSend, sizeof(Account));
//             File.write((char *)&accountRec, sizeof(Account));
//             cout << "\n\n\t Record Updated";

//             find = true;
//         }
//     }
//     File.close();

//     if (find == false)
//     {
//         cout << "\n\t\t Record Not Found !!!";
//     }

// }

//=================================== FUNCTION : 8 ===========================================

bool login_customer(int cinNumPass, int cinNum)
{
    bool login{false};
    int cstPassword;
    int cstNumber;

    cstPassword = cinNumPass;
    cstNumber = cinNum;

    // cout << "Enter your Account Number : ";
    // cin >> accNumber;

    Customer customer;

    ifstream inFile("../Data/Customer.dat");
    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        if ((customer.get_Cpassword() == cstPassword) && (customer.get_Cnumber() == cstNumber))
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