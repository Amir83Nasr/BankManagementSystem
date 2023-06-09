#pragma once

//-------------- Headers --------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//===============================================

class Account
{
protected:
    int Anumber;
    int Abalance;
public:
    int get_Anumber();
    int get_Abalance();
    void create_account(int Anum);
    void show_account();
    void deposit(int x);
    void draw(int x);
    void report_acc();
};

//===============================================