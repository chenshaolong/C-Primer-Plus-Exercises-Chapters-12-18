// Chapter 13 Class Inheritance, Programming Exercises #1, Page 795-796
// base class
#ifndef CD_H_
#define CD_H_

class Cd   // represents a CD disk
{
private:
    char performers[50];
    char label[20];
    int selections; // number of selections
    double playtime; // playing time in minutes
public:
    Cd(const char * s1,const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    Cd & operator=(const Cd & d);
};

//derived class
class Classic : public Cd
{
private:
    char work [80]; // primary work on the CD
public:
    Classic(const char * w,const char * s1,const char * s2, int n, double x);
    Classic(const char * w, const Cd & d);
    Classic(const Classic & c);
    Classic();
    ~Classic();
    virtual void Report() const; // reports all Classic data
    Classic & operator=(const Classic & c);
};

#endif