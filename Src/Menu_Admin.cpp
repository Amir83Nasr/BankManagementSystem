//-------------- Headers --------------

#include "../Lib/Menu.hpp"

#include "../Lib/Function.hpp"

#include "../Lib/Admin.hpp"
#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>

using namespace std;

//=================================== MENU : ADMIN =======================================

void menu_admin()
{
    char input;
    int cstNumber;
    int empNumber;

    do
    {
        intro();

        cout << endl;
        cout << "\n\n\n\t MENU : ADMIN";

        cout << "\n\n\t1) New Employee                     --                  Ejad Karmand (1";
        cout << "\n\n\t2) Delete Employee                  --                  Hazf Karmand (2";
        cout << "\n\n\t3) One Employee List                --                  List Yek Karmand (3";
        cout << "\n\n\t4) All Employees List               --                  List Tamam Karmandan (4";

        cout << "\n\n\t-------------------------------------------------------------------------------";

        cout << "\n\n\t5) New Customer                     --                  Ejad Moshtari (5";
        cout << "\n\n\t6) Delete Customer                  --                  Hazf Moshtari (6";
        cout << "\n\n\t7) One Customer List                --                  List Yek Moshtari (7";
        cout << "\n\n\t8) All Customers List               --                  List Tamam Moshtari (8";
        cout << "\n\n\t9) All Account List                 --                  List Tamam Account (9)";

        cout << "\n\n\t------------------------------------------------------------------------------";

        cout << "\n\n\t0) RETURN                           --                  BAZGASHT (0";
        cout << "\n\n\n\tSelect Your Option (0-8) : ";

        cin >> input;
        cout << endl;

        switch (input)
        {
        case '1':
            write_employee();
            break;

        case '2':
            cout << "\n\n\tEnter The Employee Number : ";
            cin >> empNumber;
            delete_employee(empNumber);
            break;

        case '3':
            cout << "\n\n\tEnter The Employee Number : ";
            cin >> empNumber;
            display_one_employee(empNumber);
            break;

        case '4':
            display_all_employee();
            break;        

        case '5':
            write_customer();
            break;

        case '6':
            cout << "\n\n\tEnter The Customer Number : ";
            cin >> cstNumber;
            delete_customer(cstNumber);
            break;

        case '7':
            cout << "\n\n\tEnter The Customer Number : ";
            cin >> cstNumber;
            display_one_customer(cstNumber);
            break;

        case '8':
            display_all_customer();
            break;

        case '9':
            display_all_account_all();
            break;
        case '0':
            // system("clear");
            system("CLS"); //? Clear : in Windows

            cout << "\n\n\t\t\t\tWelcome Back to Main Menu\n\n";

            menu();
            break;

        default:
            cout << "Select Your Option (0-8) : ";
            break;
        }

        cout << "\n\n"
             << "==============================================" << endl;

        // system("read -n1 -p ' ' key"); //? Pause : in MacOS
        system("pause"); //? Pause : in Windows

        // system("clear");
        system("CLS"); //? Clear : in Windows

    } while (input != '0');
}

//========================================================================================