#include "money.h"
#include <iostream>

int main() {
    try {
        Money m1;
        m1.Read();
        std::cout << m1 << std::endl;
        std::cout << "Total amount: " << m1.summa() << std::endl;

        Money m2(100, 3);
        std::cout << m2 << std::endl;
        std::cout << "Total amount: " << m2.summa() << std::endl;

        Money m3 = m2;
        std::cout << m3 << std::endl;
        std::cout << "Total amount: " << m3.summa() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}