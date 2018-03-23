// Chapter 17 Input, Output, and Files, Programming Exercises #6, Page1164-1165
// pe14-5.cpp
// useemp1.cpp -- using the abstr_emp classes
/*
 employee em("Trip", "Harris", "Thumper");
 manager ma("Amorphia", "Spindragon", "Nuancer", 5);
 fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
 highfink hf("Jack", "Spraw", "Actor", "Curly Kew", 8);
 */
#include <iostream>
#include <fstream>
#include "head.h"
using namespace std;
const int MAX = 10;
const char * file = "employees";
static int i = 0;

int main(void)
{
    abstr_emp * pc[MAX];
    ifstream fin; // show initial contents
    fin.open(file);
    if (fin.is_open())
    {
        if (!fin.eof())
        {
            cout << "Here are the current contents of the " << file << " file:\n";
            char ch;
            while (!fin.eof())
            {
                fin.get(ch);
                cout << ch;
            }
        }
        else
            cout << file << " is empty\n";
    }
    fin.close();
    
    ofstream fout(file, ios_base::out | ios_base::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }
    cout << "Please choose the type of data to add:\n";
    cout << "0)Employee   1)Manager   2)Fink   3)Highfink   4)quit\n";
    int classtype;
    while((cin >> classtype) && i < MAX) // newline separates int from data
    {
        if (classtype == 4)
            break;
        switch(classtype)
        {
            case Employee : pc[i] = new employee;
                break;
            case Manager : pc[i] = new manager;
                break;
            case Fink : pc[i] = new fink;
                break;
            case Highfink : pc[i] = new highfink;
                break;
        }
        pc[i]->SetAll();
        pc[i]->WriteAll(fout);
        i++;
        cout << "Please choose the type of data to add:\n";
        cout << "0)Employee   1)Manager   2)Fink   3)Highfink   4)quit\n";
    }
    for (int j=0; j <i; j++)
        delete pc[j];
    fin.clear();
    fout.close();
    
    fin.clear(); // not required for some implementations, but won't hurt
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the " << file << " file:\n";
        char ch;
        while (!fin.eof())
        {
            fin.get(ch);
            cout << ch;
        }
    }
    fin.close();
    cout << "Done.\n";
    
    
    return 0;
}