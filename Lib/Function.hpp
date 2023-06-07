#pragma once

//-------------- Headers --------------

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//======================= ADMIN ========================

bool login_admin();

//---------------------- EMPLOYEE -------------------------

bool login_employee(int);

void write_customer();

void modify_customer(int);

void delete_customer(int);

void display_one_customer(int);

void display_all_customer();

//---------------------- CUSTOMER -------------------------

bool login_customer(int);

void deposit_withdraw(int, int);

//---------------------- ACCOUNT -------------------------

//===============================================