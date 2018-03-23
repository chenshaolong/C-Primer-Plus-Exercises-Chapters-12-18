// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Programming Exercises #2, Page 1227-1228
#include <iostream>
#include <string>
using namespace std;

class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(string q, string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};

int main()
{
    cout << "object one: \n";
    Cpmv one = Cpmv("q", "z");
    one.Display();
    cout << "~~~~~~~~~~~~\n\n";
    
    cout << "object two: \n";
    Cpmv two("qq", "zz");
    two.Display();
    cout << "~~~~~~~~~~~~\n\n";
    
    cout << "object three: \n";
    Cpmv three(two);
    three.Display();
    cout << "~~~~~~~~~~~~\n\n";
    
    cout << "object four: \n";
    Cpmv four = one + two;
    four.Display();
    cout << "~~~~~~~~~~~~\n\n";
    
    cout << "object five: \n";
    Cpmv five(three + four);
    five.Display();
    cout << "~~~~~~~~~~~~\n\n";
    
    return 0;
}

Cpmv::Cpmv()
{
    cout << "default constructor is called here\n";
    pi = new Info;
    pi = nullptr;
}

Cpmv::Cpmv(string q, string z)
{
    cout << "constructor is called here\n";
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    cout << "copy constructor is called here\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
    cout << "move constructor is called here\n";
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    cout << "destructor is called here\n";
    cout << "delete object: \n";
    Display();
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    cout << "copy assignmeng operator is called here\n";
    if (this==&cp)
        return *this;
    pi = new Info;
    pi = cp.pi;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    cout << "move assignmeng operator is called here\n";
    if (this==&mv)
        return *this;
    pi = new Info;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    Cpmv temp = Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
    return temp;
}

void Cpmv::Display() const
{
    cout << "qcode: " << pi->qcode << endl;
    cout << "zcode: " << pi->zcode << endl;
}

