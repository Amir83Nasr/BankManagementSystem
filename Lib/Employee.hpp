#pragma once

//-------------- Headers --------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Customer.hpp"
#include "Account.hpp"

using namespace std;

//===============================================

class Employee : public Customer
{
protected:
    char Ename[31];
    int Enumber;

public:
    void create_employee(int Enum);
    void show_employee();
    void modify();
    void report();

    int get_Enumber();

};

//===============================================