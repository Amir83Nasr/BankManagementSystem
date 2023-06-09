#pragma once

//-------------- Headers --------------

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//======================= ADMIN ========================

bool login_admin();

void write_employee();

void modify_employee(int);

void delete_employee(int);

void display_one_employee(int);

void display_all_employee();

//---------------------- EMPLOYEE -------------------------

bool login_employee(int, int);

void write_customer();

void modify_customer(int);

void delete_customer(int);

void display_one_customer(int);

void display_all_customer();

//---------------------- CUSTOMER -------------------------

bool login_customer(int, int);

void deposit_withdraw(int, int);

//---------------------- ACCOUNT -------------------------

int generateRandomNumber();

void write_account();

void display_all_account();

void transaction(int, int);

//===============================================