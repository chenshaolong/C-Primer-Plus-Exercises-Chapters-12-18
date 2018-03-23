//Chapter 14 Reusing Code in C++, Programming Exercises #2, Page 888
#include <iostream>
#include "head.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : std::string(l), years(y)
{
    ArrayInt a(y);
    ArrayInt b(y);
    for (int i = 0; i < y; ++i)
    {
        a[i] = yr[i];
        b[i] = bot[i];
    }
    (PairArray &)(*this) = PairArray(a, b);
}

void Wine::GetBottles()
{
    ArrayInt a(years);
    ArrayInt b(years);
    std::cout << "Enter " << Label() << " for " << years << " year(s):" << std::endl;
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> a[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> b[i];
    }
    (PairArray &)(*this) = PairArray(a, b);
}

int Wine::sum() const
{
    return PairArray::second().sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << Label() << std::endl;
    std::cout << "\t\t" << "Year" << "\t" << "Bottles" << std::endl;
    for (int i = 0; i < years; ++i)
        std::cout << "\t\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
}