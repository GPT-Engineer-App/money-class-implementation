#include "money.h"
#include <stdexcept>

Money::Money() : first(1), second(0) {}

Money::Money(int f, int s) {
    if (f != 1 && f != 2 && f != 5 && f != 10 && f != 20 && f != 50 && f != 100 && f != 200 && f != 500)
        throw std::invalid_argument("Invalid denomination");
    if (s < 0)
        throw std::invalid_argument("Negative number of bills not allowed");
    first = f;
    second = s;
}

Money::Money(const Money& m) : first(m.first), second(m.second) {}

void Money::Init(int f, int s) {
    if (f != 1 && f != 2 && f != 5 && f != 10 && f != 20 && f != 50 && f != 100 && f != 200 && f != 500)
        throw std::invalid_argument("Invalid denomination");
    if (s < 0)
        throw std::invalid_argument("Negative number of bills not allowed");
    first = f;
    second = s;
}

void Money::Read() {
    int f, s;
    std::cout << "Enter denomination: ";
    std::cin >> f;
    std::cout << "Enter number of bills: ";
    std::cin >> s;
    Init(f, s);
}

void Money::Display() const {
    std::cout << "Denomination: " << first << ", Number of bills: " << second << std::endl;
}

int Money::summa() const {
    return first * second;
}

Money& Money::operator=(const Money& m) {
    if (this != &m) {
        first = m.first;
        second = m.second;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Money& m) {
    in >> m.first >> m.second;
    m.Init(m.first, m.second);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Money& m) {
    out << "Denomination: " << m.first << ", Number of bills: " << m.second;
    return out;
}