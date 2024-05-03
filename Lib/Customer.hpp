#pragma once

//-------------- Headers --------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Account.hpp"

using namespace std;

//===============================================

class Customer : public Account
{
protected:
    char Cname[31];
    // string Cname;
    int Cnumber;
    int Cpassword;

    // double Cbalance;

public:
    void create_customer(int Cpass);
    // {
    //     Cnumber = Cnum;

    //     cout << "\nEnter The Name of The Customer : ";
    //     cin.ignore();
    //     cin.get(Cname, 30);
    //     // getline(cin, Cname);

    //     cout << "\nEnter The Balance : ";
    //     cin >> Cbalance;

    //     cout << "\n\n ===== Customer Created ... =====";
    // }

    void show_customer();
    // {
    //     cout << "\nCustomer Number : " << Cnumber << endl;

    //     cout << "\nCustomer Holder Name : " << Cname << endl;

    //     cout << "\nBalance amount : " << Cbalance << endl;

    //     cout << "\n------------------------------------------\n";
    // }

    void modify();
    // {
    //     cout << "\nThe Customer Number" << Cnumber;

    //     cout << "\n\nEnter The Name of The Customer Holder : ";
    //     cin.ignore();
    //     cin.get(Cname, 30);
    //     getline(cin,Cname);

    //     cout << "\nEnter The Amount : ";
    //     cin >> Cbalance;
    // }

    //------------------------------------------------------------------

    // void deposit(int x);
    // { // function to accept amount and add to balance amount
    //     Cbalance += x;
    // }

    // void draw(int x);
    // { // function to accept amount and subtract from balance amount
    //     Cbalance -= x;
    // }

    void report();
    // {
    //     // "  Account no.           Name             Balance "
    //     //cout << "  " << left << setw(14) << Cnumber << setw(26) << Cname << setw(12) << Cbalance << endl;
    // }

    //--------------- Get & Set -----------------

    int get_Cnumber();
    // {
    //     return Cnumber;
    // }

    // int get_Cbalance();
    // {
    //     return Cbalance;
    // }

    int get_Cpassword();

    const char *get_Cname() const;
};

//===============================================