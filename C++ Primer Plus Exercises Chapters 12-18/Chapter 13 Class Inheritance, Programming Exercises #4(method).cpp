// Chapter 13 Class Inheritance, Programming Exercises #4, Page 796-798
#include <iostream>
#include <cstring>
#include "head.h"

// base class methods
Port::Port(const char * br,const char * st, int b)
{
    if (strcmp(br, "none")==0 && strcmp(st, "none")==0 && b == 0)
        cout << "Port class default constructor is called here\n";
    else
        cout << "Port class constructor is called here\n";
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p) // copy constructor
{
    cout << "Port class copy constructor is called here\n";
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    cout << "Port class assignment operator= is called here\n";
    if (this == &p)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}
    
Port & Port::operator+=(int b) // adds b to bottles
{
    cout << "Port class increment operator+= is called here\n";
    bottles += b;
    return *this;
}
    
Port & Port::operator-=(int b) // subtracts b from bottles, if available
{
    cout << "Port class decrement operator-= is called here\n";
    if (bottles >= b)
        bottles -= b;
    else
        cout << "you can't subtract more than you have. Operation is cancelled.\n";
    return *this;
}
        
void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}
        
ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// derived base class methods
VintagePort::VintagePort() : Port()
{
    cout << "PoVintagePort class default constructor is called here\n";
    nickname = new char[strlen("nobody") + 1];
    strcpy(nickname, "nobody");
    year = 0;
}
        
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b)
{
    cout << "PoVintagePort class constructor is called here\n";
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    cout << "PoVintagePort class copy constructor is called here\n";
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
        
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    cout << "PoVintagePort class assignment operator= is called here\n";
    if (this == &vp)
        return *this;
    Port::operator=(vp); // copy base portion
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
        
void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}
        
ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}
