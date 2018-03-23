// Chapter 13 Class Inheritance, Programming Exercises #3, Page 796
// inheritance and dynamic memory allocation
#ifndef ABC_H_
#define ABC_H_
#include <iostream>

// abstract base class(ABC) using DMA
class ABCDMA
{
private:
    char * label;
    int rating;
public:
    ABCDMA(const char * l = "null", int r = 0);
    ABCDMA(const ABCDMA & rs);
    virtual ~ABCDMA();
    ABCDMA & operator=(const ABCDMA & rs);
    void labelname() { std::cout << label << std::endl; }
    virtual void show() = 0; // pure virtual function, which is nencessary for abstract base class creation
    friend std::ostream & operator<<(std::ostream & os, const ABCDMA & rs);
};

// derived class using DMA
class baseDMA : public ABCDMA
{
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const ABCDMA & rs);
    baseDMA(const baseDMA & rs);
    ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    virtual void show();
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public ABCDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const ABCDMA & rs);
    lacksDMA(const lacksDMA & ls);
    lacksDMA & operator=(const lacksDMA & rs);
    ~lacksDMA();
    virtual void show();
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public ABCDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const ABCDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    virtual void show();
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif