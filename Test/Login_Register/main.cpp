#include <iostream>
#include <fstream>

using namespace std;

class Person
{
private:
    char name[30];
    char password[10];

public:
    void show()
    {
        cout << "Name : " << name << endl;
        cout << "Password : " << password << endl;
    }
};

int main()
{

    char input;
    char password[10];

    do
    {

        cout << "1) Login" << endl;
        cout << "2) Register" << endl;
        cout << "0) Exit" << endl;
        cout << "------------------------" << endl;

        cout << endl;

        switch (input)‍‍
        {
        case '1':
            // Login();
            break;

        case '2':
            // Register();
            break;

        case '0':

            break;

        default:
            cout << "Enter a number between (0 ~ 2) : ";
            break;
        }

    } while (input != '0');

    return 0;
}