// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #3, Page 964
// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
//#include <exception>
//#include <stdexcept>

class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double val1, double val2, const char * s = "Exception: hmean(), invalid arguments: a = -b.\nTry again. Enter next set of numbers <q to quit>: ") : v1(val1), v2(val2), logic_error(s) { }
    void report() { std::cout << "function name: hmean(), values used: " << v1 << ", " << v2 << "\n"; }
};

class bad_gmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_gmean(double val1, double val2, const char * s = "Exception: gmean(), arguments should be >= 0.\nSorry, you don't get to play any more.\n") : v1(val1), v2(val2), logic_error(s) { }
    void report() { std::cout << "function name: gmean(), values used: " << v1 << ", " << v2 << "\n"; }
};