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

bool hasDuplicateDigits(int number) {
    std::vector<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (std::find(digits.begin(), digits.end(), digit) != digits.end()) {
            return true;
        }
        digits.push_back(digit);
        number /= 10;
    }
    return false;
}

int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000, 9999);

    int number = dist(gen);
    while (hasDuplicateDigits(number)) {
        number = dist(gen);
    }
    return number;
}






//========================================================================================