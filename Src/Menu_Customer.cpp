//-------------- Headers --------------

#include "../Lib/Menu.hpp"

#include "../Lib/Function.hpp"

#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>

using namespace std;

//=================================== MENU : CUSTOMER =======================================

void menu_customer(int cinNum)
{
    Customer customer;
    char input;
    int num;
    int actNum;
    const char *name;

    int cstNumber = cinNum;

    fstream inFile("../Data/Customer.dat", ios::binary | ios::in);
    while (inFile.read((char *)&customer, sizeof(Customer)))
    {
        if (customer.get_Cnumber() == cstNumber)
            name = customer.get_Cname();
    }
    inFile.close();

    do
    {
        intro();

        cout << endl;
        cout << "\n\n\n\t MENU : CUSTOMER";

        // cout << "\n\n\t1) Depsit Amount                    --                  Afzayesh Vajh (1"; //? for the employee. rather not put it in admin
        // cout << "\n\n\t2) Withdraw Amount                  --                  Bardasht Vajh (2";
        // cout << "\n\n\t3) Make Transaction                 --                  Enteghal Vajh (3";  //? for the user in account section
        // cout << "\n\n\t4) Balance Enquiry                  --                  Estelam Mojodi (4"; //? for the user in account section
        cout << "\n\n\t5) Modify The user                     --                  Eslah Karbar (5";
        cout << "\n\n\t6) Choose account                      --                  Entekhab Hesab (6";

        cout << "\n\n\t------------------------------------------------------------------------------";

        cout << "\n\n\t0) RETURN                           --                  BAZGASHT (0";
        cout << "\n\n\n\tSelect Your Option (0-5) : ";

        cin >> input;
        cout << endl;

        switch (input)
        {
        case '1':
            // deposit_withdraw(cstNumber, 1);
            // break;

        case '2':
            //     deposit_withdraw(cstNumber, 2);
            //     break;

        case '3':

            // break;

        case '4':
            // display_one_customer(cstNumber);
            // break;

        case '5':
            modify_customer(cstNumber);
            break;

        case '6':
            display_all_account(cstNumber);
            cout << "\n\n\tEnter the Account number : ";
            cin >> actNum;
            if (login_account(actNum) == false)
            {
                break;
            }

            system("read -n1 -p ' ' key"); //? Pause : in MacOS
            // system("pause"); //? Pause : in Windows

            system("clear"); //? Clear : in MacOS
            // system("CLS"); //? Clear : in Windows

            menu_account(actNum,cstNumber);
            break;

        case '0':
            system("clear");
            // system("CLS"); //? Clear : in Windows

            cout << "\n\n\t\t\t\tWelcome Back to Main Menu\n\n";

            menu();

            break;

        default:
            cout << "Select Your Option (0-5) : ";
            break;
        }

        cout << "\n\n"
             << "======================================================" << endl;

        system("read -n1 -p ' ' key"); //? Pause : in MacOS
        // system("pause"); //? Pause : in Windows

        system("clear"); //? Clear : in MacOS
        // system("CLS"); //? Clear : in Windows

    } while (input != '0');
}

//========================================================================================