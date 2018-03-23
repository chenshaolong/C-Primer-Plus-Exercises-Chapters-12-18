// Chapter 13 Class Inheritance, Programming Exercises #4, Page 796-798
// inheritance and dynamic memory allocation
#ifndef PORT_H_
#define PORT_H_
#include <iostream> 
using namespace std;

// base class
class Port
{
private:
    char * brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
public:
    Port(const char * br = "none",const char * st = "none", int b = 0);
    Port(const Port & p); // copy constructor
    virtual ~Port() { cout << "Port class destructor is called here\n"; delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b); // adds b to bottles
    Port & operator-=(int b); // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

// derived class
class VintagePort : public Port // style necessarily = "vintage"
{
private:
    char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year; // vintage year
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { cout << "VintagePort class destructor is called here\n"; delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif