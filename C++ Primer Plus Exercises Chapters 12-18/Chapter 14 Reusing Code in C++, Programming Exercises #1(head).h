//Chapter 14 Reusing Code in C++, Programming Exercises #1, Page 887-888
#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}

template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    std::string label;
    int years;
    PairArray pa;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y) : label(l), years(y), pa(ArrayInt(y), ArrayInt(y)) { }
    const std::string & Label() const { return label; }
    void GetBottles();
    int sum() const;
    void Show() const;
};

#endif