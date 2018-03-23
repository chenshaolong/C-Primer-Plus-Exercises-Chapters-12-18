// Chapter 17 Input, Output, and Files, Programming Exercises #6, Page1164-1165
#include <iostream>
#include "head.h"

// abstr_emp methods
abstr_emp::abstr_emp() : fname("null"), lname("null"), job("null") { }

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j) : fname(fn), lname(ln), job(j) { }

abstr_emp::~abstr_emp() { }

void abstr_emp::ShowAll() const // labels and shows all data
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    cin.get();
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

void abstr_emp::WriteAll(ofstream & fout) const
{
    fout << "First name: " << fname << endl;
    fout << "Last name: " << lname << endl;
    fout << "Job: " << job << endl;
}


ostream & operator<<(ostream & os, const abstr_emp & e) //just displays first and last name
{
    os << "First name: " << e.fname << endl;
    os << "Last name: " << e.lname << endl;
    return os;
}

// abstr_emp methods
employee::employee() : abstr_emp() { }

employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j) { }

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::WriteAll(ofstream & fout) const
{
    fout << "Type: Employee\n";
    abstr_emp::WriteAll(fout);
}

// manager methods
manager::manager() : abstr_emp(), inchargeof(0) { }

manager::manager(const string & fn, const string & ln, const string & j, int ico) :  abstr_emp(fn, ln, j), inchargeof(ico) { }

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) { }

manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) { }

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "No. of abstr_emps managed: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter No. of abstr_emps managed: ";
    cin >> inchargeof;
}

void manager::WriteAll(ofstream & fout) const
{
    fout << "Type: Manager\n";
    abstr_emp::WriteAll(fout);
    fout << "No. of abstr_emps managed: " << inchargeof << endl;
}

// fink methods
fink::fink() : abstr_emp(), reportsto("null") { }

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo) { }

fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) { }

fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) { }

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter to whom fink reports: ";
    getline(cin, reportsto);
}

void fink::WriteAll(ofstream & fout) const
{
    fout << "Type: Fink\n";
    abstr_emp::WriteAll(fout);
    fout << "Reports to: " << reportsto << endl;
}

// highfink methods
highfink::highfink():abstr_emp(), manager(), fink() { }

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) { }

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) { }

highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f) { }

highfink::highfink(const manager & m, const string & rpo) : abstr_emp(m), manager(m), fink(m, rpo) { }

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) { }

void highfink::ShowAll() const
{
    fink::ShowAll();
    cout << "No. of abstr_emps managed: " << InChargeOf() << endl;
}

void highfink::SetAll()
{
    fink::SetAll();
    cout << "Enter No. of abstr_emps managed: ";
    cin >> InChargeOf();
}

void highfink::WriteAll(ofstream & fout) const
{
    fout << "Type: Highfink\n";
    fink::WriteAll(fout);
    fout << "No. of abstr_emps managed: " << InChargeOf() << endl;
}