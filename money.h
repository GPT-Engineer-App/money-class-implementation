#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <exception>

class Money {
private:
    int first;  // номінал купюри
    int second; // кількість купюр

public:
    Money(); // конструктор за замовчуванням
    Money(int f, int s); // конструктор ініціалізації
    Money(const Money& m); // конструктор копіювання

    void Init(int f, int s);
    void Read();
    void Display() const;
    int summa() const;

    Money& operator=(const Money& m);

    friend std::istream& operator>>(std::istream& in, Money& m);
    friend std::ostream& operator<<(std::ostream& out, const Money& m);
};

#endif