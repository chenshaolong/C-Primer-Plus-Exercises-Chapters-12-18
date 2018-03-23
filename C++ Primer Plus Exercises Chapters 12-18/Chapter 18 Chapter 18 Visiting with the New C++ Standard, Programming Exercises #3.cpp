// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Programming Exercises #3, Page 1228
#include <iostream>
#include <string>
using namespace std;
static long double total = 0;

void reset() { total = 0; }

// definition for 1 parameter
template<typename T>
long double sum_values(const T& value)
{
    total += value;
    return total;
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
    total += value;
    sum_values(args...);
    return total;
}

int main()
{
    cout << sum_values(1 , 2, 3, 4, 5 , 6, 7, 8.8, 9L) << endl;
    reset();
    cout << sum_values('A' , 1 , 2, 3, 4, 5 , 6.6 , 7, 8, 9L) << endl;
    
    return 0;
}