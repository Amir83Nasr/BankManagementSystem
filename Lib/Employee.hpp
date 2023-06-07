#pragma once

//-------------- Headers --------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Customer.hpp"

using namespace std;

//===============================================

class Employee : public Customer
{
protected:
    string Ename;
    int Enumber;

public:
    int get_Enumber()
    {
        return Enumber;
    }
};

//===============================================