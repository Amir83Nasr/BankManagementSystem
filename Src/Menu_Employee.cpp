//-------------- Headers --------------

#include "../Lib/Menu.hpp"

#include "../Lib/Function.hpp"

#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>

using namespace std;

//=================================== MENU : EMPLOYEE =======================================

void menu_employee(int cinNum)
{

    char input;
    int cstNumber;

    int empNumber = cinNum;

    do
    {
        intro();

        cout << endl;
        cout << "\n\n\n\t MENU : EMPLOYEE";

        cout << "\n\n\t1) New Customer                     --                  Ejad Moshtari (1";
        cout << "\n\n\t2) Delete Customer                  --                  Hazf Moshtari (2";
        cout << "\n\n\t3) One Customer List                --                  List Yek Moshtari (3";
        cout << "\n\n\t4) All Customers List               --                  List Tamam Moshtari (4";
        cout << "\n\n\t5) Choose Customer                  --                  Entekhap Moshtari(5";

        cout << "\n\n\t------------------------------------------------------------------------------";

        cout << "\n\n\t0) RETURN                           --                  BAZGASHT (0";
        cout << "\n\n\n\tSelect Your Option (0-5) : ";

        cin >> input;
        cout << endl;

        switch (input)
        {
        case '1':
            write_customer();
            break;

        case '2':
            cout << "\n\n\tEnter The Customer Number : ";
            cin >> cstNumber;
            delete_customer(cstNumber);
            break;

        case '3':
            cout << "\n\n\tEnter The Customer Number : ";
            cin >> cstNumber;
            display_one_customer(cstNumber);
            break;

        case '4':
            display_all_customer();
            break;

        case '5':

            break;

        case '0':
            system("clear");
            // system("CLS"); //? Clear : in Windows

            cout << "\n\n\t\t\t\tWelcome Back to Main Menu\n\n";

            menu();
            break;

        default:
            cout << "Select Your Option (0-3) : ";
            break;
        }

        cout << "\n\n"
             << "==============================================" << endl;

        system("read -n1 -p ' ' key"); //? Pause : in MacOS
        // system("pause"); //? Pause : in Windows

        system("clear"); //? Clear : in MacOS
        // system("CLS"); //? Clear : in Windows

    } while (input != '0');
}

//========================================================================================