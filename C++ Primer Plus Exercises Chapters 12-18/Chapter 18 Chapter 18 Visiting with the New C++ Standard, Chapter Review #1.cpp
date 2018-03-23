// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Chapter Review #1, Page 1124
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

class Z200
{
private: int j;
    char ch;
    double z;
public:
    Z200() {}
    Z200(int jv, char chv, double zv) : j(jv), ch(chv), z(zv) { cout << "constructor is called here\n"; }
    friend ostream & operator<<(ostream & os, const Z200 & z);
};
double sum(std::initializer_list<double> il);

int main()
{
    double x{8.8};
    cout << x << endl;
    std::string s = {"What a bracing effect!"};
    cout << s << endl;
    int k = {99}; // int k(99);
    cout << k << endl;
    Z200 zip{200,'Z',0.675}; // Z200 zip = {200,'Z',0.675};
    cout << zip;
    
    std::vector<int> ai{3, 9, 4, 7, 1}; // std::vector<int> ai = {3, 9, 4, 7, 1}
    for (auto pt = ai.begin(); pt != ai.end(); ++pt)
    {
        if (pt != --ai.end())
            cout << *pt << " ";
        else
            cout << *pt << "\n";
    }
    
    double total = sum({2.5,3.1,4});
    cout << total << endl;
    
    string conclusion{"C++11 extends the applicability of the brace-enclosed list (list-initialization) so that it can be used with all built-in types and with user-defined types (that is, class objects).The list can be used either with or without the = sign"};
    cout << conclusion << endl;

    return 0;
}

ostream & operator<<(ostream & os, const Z200 & z)
{
    os << z.j << ", " << z.ch << ", " << z.z << endl;
    return os;
}

double sum(std::initializer_list<double> il)
{
    double tot = 0;
    for (auto p = il.begin(); p !=il.end(); p++)
        tot += *p;
    return tot;
}