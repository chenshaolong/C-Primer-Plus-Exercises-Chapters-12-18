// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Chapter Review #2, Page 1225-1226
#include <iostream>
using namespace std;

double up(double x) { return 2.0* x;}
void r1(const double &rx) {cout << "const double & rx\n";}
void r1(double &rx) {cout << "double & rx\n";}
void r2(double &rx) {cout << "double & rx\n";}
void r2(double &&rx) {cout << "double && rx\n";}
void r3(const double &rx) {cout << "const double & rx\n";}
void r3(double &&rx) {cout << "double && rx\n";}

int main()
{
    double w = 10.0;
    cout <<"test overloaded function r1:\n";
    r1(w); // r1(double &rx)
    r1(w+1); // r1(const double &rx)
    r1(up(w)); // r1(const double &rx)
    
    cout <<"test overloaded function r2:\n";
    r2(w); // r2(double &rx)
    r2(w+1); // r2(double &&rx)
    r2(up(w)); // r2(double &&rx)

    cout <<"test overloaded function r3:\n";
    r3(w); // r3(const double &rx)
    r3(w+1); // r3(double &&rx)
    r3(up(w)); // r3(double &&rx)
    
    cout << "Conclusion: In short, a non-const lvalue parameter matches an lvalue argument, a non-const rvalue parameter matches an rvalue argument, and a const lvalue parameter can match either an lvalue or an rvalue argument, but the compiler will prefer the first two choices, if available.\n";
    
    return 0;
}