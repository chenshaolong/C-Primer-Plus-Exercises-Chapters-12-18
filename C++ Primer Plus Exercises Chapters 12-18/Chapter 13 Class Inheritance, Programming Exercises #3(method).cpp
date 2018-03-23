// Chapter 13 Class Inheritance, Programming Exercises #3, Page 796
// dma class methods
#include "head.h"
#include <cstring>

// abstract base class(ABC)
ABCDMA::ABCDMA(const char * l, int r)
{
    std::cout << "ABCDMA constructor is called here for: " << l << std::endl;
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

ABCDMA::ABCDMA(const ABCDMA & rs)
{
    std::cout << "ABCDMA copy constructor is called here for: " << rs.label << std::endl;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

ABCDMA::~ABCDMA()
{
    std::cout <<"ABCDMA destructor is called here for: ";
    labelname();
    delete [] label;
}

ABCDMA & ABCDMA::operator=(const ABCDMA & rs)
{
    std::cout <<"assginment operator= is used here for ABCDMA class: " << rs.label << std::endl;
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void ABCDMA::show()
{
    labelname();
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

std::ostream & operator<<(std::ostream & os, const ABCDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

// baseDMA methods
baseDMA::baseDMA(const char * l, int r) : ABCDMA(l,r)
{
    std::cout << "baseDMA constructor is called here for: " << l << std::endl;
}

baseDMA::baseDMA(const ABCDMA & rs) : ABCDMA(rs)
{
    std::cout << "baseDMA copy constructor1 is called here for: ";
    labelname();
}

baseDMA::baseDMA(const baseDMA & rs) : ABCDMA(rs)
{
    std::cout << "baseDMA copy constructor2 is called here for: ";
    labelname();
}

baseDMA::~baseDMA()
{
    std::cout <<"~baseDMA destructor is called here for: ";
    labelname();
}

void baseDMA::show()
{
    ABCDMA::show();
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    std::cout <<"assginment operator= is used here for baseDMA class: ";
    labelname();
    if (this == &rs)
        return *this;
    ABCDMA::operator=(rs); // copy base portion
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << (const ABCDMA &) rs;
    return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABCDMA(l, r)
{
    std::cout << "lacksDMA class constructor1 is called here for: " << l << std::endl;
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const ABCDMA & rs) : ABCDMA(rs)
{
    std::cout << "lacksDMA class constructor2 is called here for: ";
    labelname();
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & ls) : ABCDMA(ls) // invoke base class copy constructor
{
    std::cout << "lacksDMA class copy constructor is called here for: ";
    labelname();
    std::strcpy(color, ls.color);
}

lacksDMA & lacksDMA::operator=(const lacksDMA & ls)
{
    if (this == &ls)
        return *this;
    ABCDMA::operator=(ls); // copy base portion
    std::strcpy(color, ls.color);
    return * this;
}

lacksDMA::~lacksDMA()
{
    std::cout << "lacksDMA class destructor is called here for: ";
    labelname();
}

void lacksDMA::show()
{
    ABCDMA::show();
    std::cout << "Color: " << color << std::endl;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const ABCDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) : ABCDMA(l, r)
{
    std::cout << "hasDMA class constructor1 is called here for: " << l << std::endl;
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const ABCDMA & rs) : ABCDMA(rs)
{
    std::cout << "hasDMA class constructor2 is called here for: ";
    labelname();
    std::cout << std::endl;
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : ABCDMA(hs) // invoke base class copy constructor
{
    std::cout << "hasDMA class copy constructor is called here for: ";
    labelname();
    std::cout << std::endl;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    std::cout << "hasDMA class destructor is called here for: ";
    labelname();
    std::cout << std::endl;
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    std::cout << "assginment operator= is used here for hasDMA class: ";
    labelname();
    std::cout << std::endl;
    if (this == &hs)
        return *this;
    ABCDMA::operator=(hs); // copy base portion
    delete [] style; // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void hasDMA::show()
{
    ABCDMA::show();
    std::cout << "style: " << style << std::endl;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const ABCDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}