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
    char Aname[31];
    int Anumber;
    int Abalance;

    int CAnumber;
public:
    void set_Aname(const char* name);
    void set_CAnumber(int);
    const char* get_Aname() const;
    int get_Anumber();
    int get_CAnumber();
    int get_Abalance();
    void create_account(int Anum, const char* name);
    void show_account();
    void deposit(int x);
    void draw(int x);
    void report_acc();
    void report_Cacc(int);
};

//===============================================