//Chapter 14 Reusing Code in C++, Programming Exercises #1, Page 887-888
#include <iostream>
#include "head.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), years(y)
{
    ArrayInt a(y);
    ArrayInt b(y);
    for (int i = 0; i < y; ++i)
    {
        a[i] = yr[i];
        b[i] = bot[i];
    }
    pa = PairArray(a, b);
}

void Wine::GetBottles()
{
    ArrayInt a(years);
    ArrayInt b(years);
    std::cout << "Enter " << label << " for " << years << " year(s):" << std::endl;
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> a[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> b[i];
    }
    pa = PairArray(a, b);
}

int Wine::sum() const
{
    return pa.second().sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << label << std::endl;
    std::cout << "\t\t" << "Year" << "\t" << "Bottles" << std::endl;
    for (int i = 0; i < years; ++i)
        std::cout << "\t\t" << pa.first()[i] << "\t" << pa.second()[i] << std::endl;
}