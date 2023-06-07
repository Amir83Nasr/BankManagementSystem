//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Employee.hpp"
#include "../Lib/Customer.hpp"
#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//=================================== CLASS ===========================================

void Employee::create_employee(int Enum)
{
    Enumber = Enum;

    cout << "\nEnter The Name of The Employee : ";
    cin.ignore();
    cin.get(Ename, 30);
    // getline(cin, Cname);

    cout << "\n\n ===== Employee Created ... =====";
}

void Employee::show_employee()
{
    cout << "\nEmployee Number : " << Enumber << endl;

    cout << "\nEmployee Holder Name : " << Ename << endl;

    cout << "\n------------------------------------------\n";
}

void Employee::modify()
{
    cout << "\nThe Employee Number" << Enumber;

    cout << "\n\nEnter The Name of The Employee Holder : ";
    cin.ignore();
    cin.get(Ename, 30);
    // getline(cin,Cname);
}

void Employee::report()
{
    // "  Account no.           Name   "
    cout << "  " << left << setw(14) << Enumber << setw(26) << Ename << endl;
}




int Employee::get_Enumber(){
    return Enumber;
}

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

//============================= Funciton : 2=====================================

void write_employee()
{
    bool find = false;

    Employee employee;

    int empNumber;

    cout << "Enter Your Employee Number: ";
    cin >> empNumber;

    fstream inFile("../Data/Employee.dat", ios::binary | ios::in);
    while (inFile.read((char *)&employee, sizeof(employee)))
    {
        if (employee.get_Enumber() == empNumber)
            find = true;
    }
    inFile.close();

    fstream outFile;
    outFile.open("../Data/Employee.dat", ios::binary | ios::out | ios::app);

    if (find == false)
    {
        Employee newEmployee;

        newEmployee.create_employee(empNumber);
        outFile.write((char *)&newEmployee, sizeof(Employee));
    }
    else
    {
        cout << "\n\nEmployee number exist ..." << endl;
    }

    outFile.close();
}

//=================================== FUNCTION : 3 ===========================================

void modify_employee(int empNumber)
{
    bool find = false;

    Employee employee;

    fstream File("../Data/Employee.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (File.read((char *)&employee, sizeof(Employee)) && find == false)
    {
        if (employee.get_Enumber() == empNumber)
        {
            employee.show_employee();

            cout << "\n\nEnter The New Details of Employee : " << endl;
            employee.Employee::modify();

            long int pos = (-1) * (sizeof(Employee));
            File.seekp(pos, ios::cur);

            File.write((char *)&employee, sizeof(Employee));
            cout << "\n\n\t Record Updated ...";

            find = true;
        }
    }
    File.close();

    if (find == false)
    {
        cout << "\n\n Record Not Found ...";
    }
}

//=================================== FUNCTION : 4 ===========================================

void delete_employee(int empNumber)
{
    Employee employee;

    ifstream inFile;
    ofstream outFile;

    inFile.open("../Data/Employee.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    outFile.open("../Data/Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);

    while (inFile.read((char *)&employee, sizeof(Employee)))
    {
        if (employee.get_Cnumber() != empNumber)
        {
            outFile.write((char *)&employee, sizeof(Employee));
        }
    }
    inFile.close();
    outFile.close();

    remove("../Data/Employee.dat");
    rename("../Data/Temp.dat", "../Data/Employee.dat");

    cout << "\n\n\tRecord Deleted ...";
}

//=================================== FUNCTION : 5 ===========================================

void display_one_employee(int empNumber)
{
    Employee employee;

    bool find = false;

    ifstream inFile("../Data/Employee.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\nEmployee DETAILS\n";

    while (inFile.read((char *)&employee, sizeof(Employee)))
    {
        if (employee.get_Enumber() == empNumber)
        {
            employee.show_employee();
            find = true;
            break;
        }
    }
    inFile.close();

    if (find == false)
    {
        cout << "\n\nAccount number does not exist";
    }
}

//=================================== FUNCTION : 6 ===========================================

void display_all_employee()
{
    Employee employee;

    ifstream inFile("../Data/Employee.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "\n\n\t\tEmployee LIST\n\n";
    cout << "=======================================\n";
    cout << "  Account no.           Name    \n";
    cout << "========================================\n";

    while (inFile.read((char *)&employee, sizeof(Employee)))
    {
        employee.report();
    }
    inFile.close();
}

