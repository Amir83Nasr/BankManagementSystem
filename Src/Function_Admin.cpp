//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Admin.hpp"
#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//=================================== CLASS ===========================================

//=================================== FUNCTION : 1 ===========================================

const string Admin::admPassword = "Amir83Nasr";

bool login_admin()
{
    Admin admin;
    string admNumber;

    cout << "\n\t\tEnter The Admin Password : ";
    cin >> admNumber;

    if (admNumber == admin.get_admPassword())
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