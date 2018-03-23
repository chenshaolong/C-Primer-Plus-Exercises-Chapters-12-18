// Chapter 13 Class Inheritance, Programming Exercises #3, Page 796-798
// inheritance, friends, and DMA
#include <iostream>
#include <cstring>
#include "head.h"

int main()
{
    using std::cout;
    using std::endl;
    
    Port p1("alpha", "tawny", 88);
    Port p2("beta", "ruby", 66);
    VintagePort vp("gamma", 99, "The Noble", 2017);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << vp << endl;
    cout << "======================\n\n";
    
    cout << "Using object directly:\n";
    p1.Show(); // use Port method
    p2.Show(); // use Port method
    vp.Show(); // use VintagePort method
    cout << "======================\n\n";
    
    cout << "Using type Port * pointer to objects:\n";
    Port * pt;
    pt = &p1;
    pt->Show(); // use Port method
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    pt = &vp;
    pt->Show(); // use VintagePort method
    cout << "======================\n\n";
    
    cout << "Using type Port & reference to objects:\n";
    Port & rs1 = p2;
    cout << rs1 << endl;
    rs1.Show(); // use Port method
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    Port & rs2 = vp;
    cout << rs2 << endl;
    rs2.Show(); // use VintagePort method
    cout << "======================\n\n";
    
    cout << "Testing assignment:\n";
    Port copy1;
    copy1 = p1;
    cout << copy1 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    VintagePort copy2;
    cout << "Testing if default VintagePort object member style = \"vintage\":\n";
    cout << copy2 << endl;
    copy2 = vp;
    cout << copy2 << endl;
    cout << "======================\n\n";
    
    
    cout << "Testing operator+=:\n";
    cout << "Before: " << p1 << endl;
    p1 += 8;
    cout << "After: " << p1 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Before: " << vp << endl;
    vp += 1;
    cout << "After: " << vp << endl;
    cout << "======================\n\n";
    
    cout << "Testing operator-=:\n";
    cout << "Before: " << p2 << endl;
    p2 -= 6;
    cout << "After: " << p2 << endl;
    cout << "Before: " << vp << endl;
    vp -= 2;
    cout << "After: " << vp << endl;
    cout << "======================\n\n";
    
    cout << "Done.\n";
    return 0;
}