// Chapter 17 Input, Output, and Files, Programming Exercises #6, Page1164-1165
// emp.h -- header file for abstr_emp class and children
#ifndef EMP_H
#define EMP_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum classkind{Employee, Manager, Fink, Highfink};

class abstr_emp
{
private:
    string fname; // abstr_emp's first name
    string lname; // abstr_emp's last name
    string job;
public:
    abstr_emp();
    abstr_emp(const string & fn, const string & ln, const string & j);
    //abstr_emp(const abstr_emp & e);
    virtual void ShowAll() const; // labels and shows all data
    virtual void SetAll(); // prompts user for values
    virtual void WriteAll(ofstream & fout) const;
    friend ostream & operator<<(ostream & os, const abstr_emp & e);
    //just displays first and last name
    virtual ~abstr_emp() = 0; // virtual base class
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const string & fn, const string & ln, const string & j);
    //employee(const employee & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(ofstream & fout) const;
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof; // number of abstr_emps managed
protected:
    int InChargeOf() const { return inchargeof; } // output
    int & InChargeOf(){ return inchargeof; } // input
public:
    manager();
    manager(const string & fn, const string & ln, const string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(ofstream & fout) const;
};

class fink: virtual public abstr_emp
{
private:
    string reportsto; // to whom fink reporks
protected:
    const string ReportsTo() const { return reportsto; }
    string & ReportsTo(){ return reportsto; }
public:
    fink();
    fink(const string & fn, const string & ln, const string & j, const string & rpo);
    fink(const abstr_emp & e, const string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(ofstream & fout) const;
};

class highfink: public manager, public fink // management fink
{
public:
    highfink();
    highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
    highfink(const abstr_emp & e, const string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(ofstream & fout) const;
};

#endif