//-------------- Headers --------------

#include "../Lib/Menu.hpp"

#include "../Lib/Function.hpp"

#include "../Lib/Admin.hpp"
#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>

using namespace std;

//=================================== INTRO =======================================

void intro()
{
    cout << "\n\t            BANK MANAGEMENT SYSTEM -- Created by (Pol-Pull-Pol) team\n\n";
}

//------------------------------------ MENU ----------------------------------------

void menu()
{
    char input;
    int number;

    do
    {
        intro();

        cout << endl;
        cout << "\n\n\n\t MAIN MENU";

        cout << "\n\n\t1) Admin                          --                    Modir (1";
        cout << "\n\n\t2) Employee                       --                    Karmand (2";
        cout << "\n\n\t3) Customer                       --                    Moshtari (3";

        cout << "\n\n\t-------------------------------------------------------------------";

        cout << "\n\n\t0) EXIT                           --                    KHORUJ (0";
        cout << "\n\n\n\tSelect Your Option (0-3) : ";

        cin >> input;
        cout << endl;

        switch (input)
        {
        case '1':
            if (login_admin() == false)
            {
                break;
            }

            system("read -n1 -p ' ' key"); //? Pause : in MacOS
                                           // system("pause"); //? Pause : in Windows

            system("clear"); //? Clear : in MacOS
                             // system("CLS"); //? Clear : in Windows
            menu_admin();
            break;

        case '2':
            cout << "\n\t\tEnter your Employee Number : ";
            cin >> number;

            if (login_employee(number) == false)
            {
                break;
            }

            system("read -n1 -p ' ' key"); //? Pause : in MacOS
                                           // system("pause"); //? Pause : in Windows

            system("clear"); //? Clear : in MacOS
                             // system("CLS"); //? Clear : in Windows
            menu_employee(number);
            break;

        case '3':
            cout << "\n\t\tEnter your Customer Number : ";
            cin >> number;

            if (login_customer(number) == false)
            {
                break;
            }

            system("read -n1 -p ' ' key"); //? Pause : in MacOS
                                           // system("pause"); //? Pause : in Windows

            system("clear"); //? Clear : in MacOS
                             // system("CLS"); //? Clear : in Windows
            menu_customer(number);
            break;

        case '0':
            cout << "\n\n\tThanks for using bank management system";
            cout << "\n\n"
                 << "==============================================" << endl;
            exit(0);
            break;

        default:
            cout << "Select Your Option (0-3) : ";
            break;
        }

        cout << "\n\n"
             << "==============================================" << endl;

        system("read -n1 -p ' ' key"); //? Pause : in MacOS
        // system("pause"); //? Pause : in Windows

        system("clear");
        // system("CLS"); //? Clear : in Windows

    } while (input != '0');
}

//==================================================================================
