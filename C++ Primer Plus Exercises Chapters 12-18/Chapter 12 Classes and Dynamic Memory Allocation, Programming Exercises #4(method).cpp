// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #4, Page 719-720
// Stack member functions
#include <iostream>
#include "head.h"

Stack::Stack(int n)  // creates stack with n elements
{
    if (n != MAX)
        std::cout << "constructor is called here\n";
    else
        std::cout << "default constructor is called here\n";
    pitems = new Item [n];
    size = top = 0;
}

Stack::Stack(const Stack & st)
{
    std::cout << "copy constructor is called here\n";
    top = st.top + 1;
    size = top;
    pitems = new Item [size];
    for (int i=0; i < size; i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    std::cout << "destructor is called here\n";
    delete [] pitems;
}

bool Stack::isempty() const
{
    return (size == 0 && top == 0);
}

bool Stack::isfull() const
{
    return (size == MAX && top == MAX);
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        size = top;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        size = top;
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack & st)
{
    std::cout << "Assignment operator = is used here\n";
    if (this == &st)  // object assigned to itself
        return *this;  // all done
    delete [] pitems;
    size = top = st.top;
    pitems = new Item [size];
    for (int i=0; i < size; i++)
        pitems[i] = st.pitems[i];
    return *this;
}