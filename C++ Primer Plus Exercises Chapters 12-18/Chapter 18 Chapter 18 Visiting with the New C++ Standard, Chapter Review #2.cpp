// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Chapter Review #2, Page 1224-1225
#include <iostream>
using namespace std;

double up(double x) { return 2.0* x;}
void r1(const double &rx) {cout << rx << endl;}
void r2(double &rx) {cout << rx << endl;}
void r3(double &&rx) {cout << rx << endl;}

int main()
{
    double w = 10.0;
    cout <<"test void r1(const double &rx) {cout << rx << endl;}\n";
    r1(w); // r1(w) is valid, and the argument rx refers to w
    r1(w+1); // r1(w+1) is valid, and the argument rx refers to a temporary initialized to the value of w+1
    r1(up(w)); // r1(up(w)) is valid, and the argument rx refers to a temporary initialized to the return value of up(w).
    cout << "Conclusion: In general, if an lvalue is passed to a const lvalue reference parameter, the parameter is initialized to the lvalue. If an rvalue is passed to the function, a const lvalue reference parameter refers to a temporary copy of the value.\n";
    cout <<"~~~~~~~~~~~~~~~~\n";
   
    cout <<"test void r2(double &rx) {cout << rx << endl;}\n";
    r2(w); // r2(w) is valid, and the argument rx refers to w
    //r2(w+1); // r2(w+1) is an error because w+1 is an rvalue
    //r2(up(w)); // r2(up(w)) is an error because the return value of up(w) is an rvalue
    cout <<"~~~~~~~~~~~~~~~~\n";
    
    cout <<"test void r3(double &&rx) {cout << rx << endl;}\n";
    //r3(w); // r3(w) is an error because an rvalue reference cannot refer to an lvalue, such as w
    r3(w+1); // r3(w+1) is valid, and rx refers to the temporary value of the expression w+1
    r3(up(w)); // r3(up(w)) is valid, and rx refers to the temporary return value of up(w)
    cout << "Conclusion: In general, if an lvalue is passed to a non-const lvalue reference parameter, the parameter is initialized to the lvalue. But a non-const lvalue reference parameter can’t accept an rvalue function argument.\n";
    cout <<"~~~~~~~~~~~~~~~~\n";
    
    return 0;
}