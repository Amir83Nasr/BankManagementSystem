//-------------- Headers --------------

#include "../Lib/Function.hpp"

#include "../Lib/Account.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

//=================================== CLASS ===========================================


//=================================== FUNCTION : 1 ===========================================
int generateRandomNumber() {
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<int> dist(1000, 9999);

    int number = dist(gen);

    return number;
}






//========================================================================================