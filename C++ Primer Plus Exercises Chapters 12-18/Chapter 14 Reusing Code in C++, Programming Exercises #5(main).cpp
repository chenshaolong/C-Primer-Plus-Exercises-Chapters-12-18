// Chapter 14 Reusing Code in C++, Programming Exercises #5, Page 888-891
// pe14-5.cpp
// useemp1.cpp -- using the abstr_emp classes
#include <iostream>
#include "head.h"
using namespace std;

int main(void)
{
    employee em("Trip", "Harris", "Thumper"); cout << em << endl;
    em.ShowAll();
    cout << "=====================\n";

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    cout << "=====================\n";

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    cout << "=====================\n";
    
    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    //cout << "New recruitment:\n";
    cout << "=====================\n";
    
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "=====================\n";
    
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
    {
        tri[i]->ShowAll();
        cout << "~~~~~~~~~~~~~\n";
    }
    
    return 0;
}