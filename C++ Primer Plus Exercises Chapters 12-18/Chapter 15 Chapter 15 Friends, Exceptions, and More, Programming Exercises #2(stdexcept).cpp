// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #2, Page 964
//error4.cpp – using exception classes
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "stdexcept.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;
    
    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x,y);
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (std::logic_error & e)
        // or catch (std::exception & e), because logic_error class is derived from exception class
        {                   // start of catch block
            cout << e.what();
            if (x == -y)
                continue;
            else
                break;
        } // end of catch block
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}