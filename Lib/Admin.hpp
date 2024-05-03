#pragma once

//-------------- Headers --------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Employee.hpp"
#include "Customer.hpp"
#include "Account.hpp"

using namespace std;

//===============================================

class Admin : public Employee
{
private:
    static const string admPassword;

public:
    static string get_admPassword()
    {
        return admPassword;
    }
};

//===============================================