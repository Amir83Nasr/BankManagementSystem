//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Admin.hpp"
#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//=================================== CLASS ===========================================

//=================================== FUNCTION : 1 ===========================================

bool login_admin()
{
    string admNumber;
    string admPassword{"Amir83Nasr"};

    cout << "\n\t\tEnter The Admin Password : ";
    cin >> admNumber;

    if (admNumber == admPassword)
    {
        cout << "\n\t\tLogin was successful ...\n";
        return true;
    }
    else
    {
        cout << "\n\t\tLogin was not successful ...\n";
        return false;
    }
}

//========================================================================================