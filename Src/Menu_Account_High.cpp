//-------------- Headers --------------

#include "../Lib/Menu.hpp"

#include "../Lib/Function.hpp"

#include "../Lib/Account.hpp"

#include <iostream>

using namespace std;

//=================================== MENU : ACCOUNT =======================================

void menu_account_high(int actNum)
{
    char input;
    int actNumber;
    int num;

    do
    {
        intro();

        cout << endl;
        cout << "\n\n\n\t MENU : Account";

        cout << "\n\n\t1) Deposit                          --                  Afzayesh Seporde (1";
        cout << "\n\n\t2) Make Transaction                 --                  Tarakonesh (2";
        cout << "\n\n\t3) Transaction List                 --                  List Tarakonesh Ha (3";

        cout << "\n\n\t------------------------------------------------------------------------------";

        cout << "\n\n\t0) RETURN                           --                  BAZGASHT (0";
        cout << "\n\n\n\tSelect Your Option (0-3) : ";

        cin >> input;
        cout << endl;

        switch (input)
        {
        case '1':
            // deposit_withdraw();
            break;

        case '2':

            break;

        case '3':

            break;

        case '0':
            //system("clear");
            system("CLS"); //? Clear : in Windows

            cout << "\n\n\t\t\t\tWelcome Back to Main Menu\n\n";

            menu();
            break;

        default:
            cout << "Select Your Option (0-6) : ";
            break;
        }

        cout << "\n\n"
             << "==============================================" << endl;

        //system("read -n1 -p ' ' key"); //? Pause : in MacOS
        system("pause"); //? Pause : in Windows

        //system("clear");
        system("CLS"); //? Clear : in Windows

    } while (input != '0');
}

//========================================================================================
