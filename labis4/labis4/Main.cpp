#include <iostream>
#include <cmath>
#include <clocale>
#include "Polinom.h"

int main()
{
    Polinom objPolinom;

    int n1, hlobal1;
    std::cout << "degree of polinom:\n";
    std::cin >> n1;
    if (n1 > 9) {
        std::cout << "Error! too big degree";
        exit(-1);
    }
    objPolinom.koeff1(n1);
}
