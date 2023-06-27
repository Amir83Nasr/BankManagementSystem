#include <iostream>
#include <string>
#include<cstring>

using namespace std;
int main()
{
    char name[]{"Amir"};
    char family[]{"Nasrollahi"};

    const char *pname{"Amir"};
    const char *pfamily{"Nasrollahi"};

    cout << name << " " << family << endl;
    cout << pname << " " << pfamily << endl;

    const char *ptemp;
    ptemp = name;

    const char *pftemp;
    pftemp = family;

    // cout<<temp<<endl;
    if (ptemp == pftemp)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    if(strcmp(ptemp,name)!=0)
    {
        cout<<"hahaha";
    }

    return 0;
}