// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #2, Page 964
// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <exception>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const char * s = "Exception: hmean(), invalid arguments: a = -b.\nTry again. Enter next set of numbers <q to quit>:\n") : logic_error(s) { }
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const char * s = "Exception: gmean(), arguments should be >= 0.\nSorry, you don't get to play any more.\n") : logic_error(s) { }
};