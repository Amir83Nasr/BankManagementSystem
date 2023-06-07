//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//=================================== CLASS ===========================================

//=================================== FUNCTION : 1 ===========================================

bool login_employee(int cinNum)
{
    bool login{false};
    int empNumber;

    empNumber = cinNum;

    // cout << "Enter you Employee Number : ";
    // cin >> empNumber;

    Employee employee;

    ifstream inFile("../Data/Employee.dat");
    while (inFile.read((char *)&employee, sizeof(Employee)))
    {
        if (employee.get_Enumber() == empNumber)
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
        cout << "\n\t\tEmployee Number Not Found !!!";
        return false;
    }
}

//========================================================================================