// Chapter 13 Class Inheritance, Programming Exercises #1, Page 795-796
#include<iostream>
#include "head.h"

//base class methods
Cd::Cd(const char * s1,const char * s2, int n, double x)
{
    std::cout << "Cd constructor is called here for: " << s1 << std::endl;
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::cout << "Cd copy constructor is called here for: " << d.performers << std::endl;
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    std::strcpy(performers, "Nobody");
    std::strcpy(label, "Nothing");
    selections = 0;
    playtime = 0;
    std::cout << "Cd default constructor is called here for: " << performers << std::endl;
}

Cd::~Cd()
{
    std::cout << "Cd destructor is called here for: " << performers << std::endl;
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime in minutes: " << playtime << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~\n";
}

Cd & Cd::operator=(const Cd & d)
{
    std::cout << "assignment operator = is called here for: " << d.performers << std::endl;
    if (this == &d)
        return *this;
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//derived class methods
Classic::Classic(const char * w,const char * s1,const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    std::cout << "Classic constructor1 is called here for: " << w << std::endl;
    std::strcpy(work,w);
}

Classic::Classic(const char * w, const Cd & d) : Cd(d)
{
    std::cout << "Classic constructor2 is called here for: " << w << std::endl;
    std::strcpy(work,w);
}

Classic::Classic(const Classic & c) : Cd(c)// invoke base class copy constructor
{
    std::cout << "Classic copy constructor is called here for: " << c.work << std::endl;
    std::strcpy(work,c.work);
}

Classic::Classic() : Cd()
{
    std::strcpy(work, "None");
    std::cout << "Classic default constructor is called here for: " << work << std::endl;
}

Classic::~Classic()
{
    std::cout << "Classic destructor is called here for: " << work << std::endl;
}

void Classic::Report() const
{
    std::cout << "Primary work: " << work << std::endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c)
{
    std::cout << "assignment operator = is called here for: " << c.work << std::endl;
    if (this == &c)
        return *this;
    Cd::operator=(c); // copy base portion
    std::strcpy(work, c.work);
    return *this;
}