// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Chapter Review #7, Page 1227
#include <iostream>
#include <array>
const int Size = 5;
template<typename T>
void sum(std::array<double,Size> a, T fp) { for(auto pt = a.begin(); pt != a.end(); ++pt) fp(*pt); }

int main()
{
    double total = 0.0;
    //Adder ad(total);
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c,[&](double x) { total += x; }); // or sum(temp_c,[&total](double x) { total += x; });
    std::cout << "total: " << total << '\n';
    return 0;
}