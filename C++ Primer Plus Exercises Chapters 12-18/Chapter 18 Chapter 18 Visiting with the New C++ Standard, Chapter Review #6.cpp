// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Chapter Review #6, Page 1226
/*
 #include <iostream>
 template<typename T>
 void show2(double x, T& fp) {std::cout << x << " -> " << fp(x) << '\n';} 
 double f1(double x) { return 1.8*x + 32;}
 
 int main()
 {
     show2(18.0, f1);
     return 0;
 }
*/

#include <iostream>
template<typename T>
void show2(double x, T fp) {std::cout << x << " -> " << fp(x) << '\n';}
double f1(double x) { return 1.8*x + 32;}

int main()
{
    show2(18.0, [](double x){return 1.8*x + 32;});
    return 0;
}