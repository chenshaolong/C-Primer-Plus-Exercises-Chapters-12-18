// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #4, Page 719-720
// stack2.cpp -- testing the Stack class
#include <iostream>
#include <cctype> // or ctype.h
#include "head.h"
using namespace std;

int main()
{
    Stack st1; // create an empty stack
    st1.process();
    cout << st1;
    
    const int n = 2;
    Stack st[n] = {6, 8};
    for (int i = 0; i < n; i++)
    {
        st[i].process();
        cout << st[i];
    }
    
    st1 = Stack(st[0]);
    cout << st1;
    
    st1 = st[1];
    cout << st1;
    
    cout << "Bye\n";
    return 0;
}