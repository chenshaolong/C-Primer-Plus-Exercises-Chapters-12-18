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

void Stack::process()
{
    using namespace std;
    char ch;
    Item po;
    cout << "Processing is started\n---------------------\n";
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                cin >> po;
                if (this->isfull())
                    cout << "stack already full\n";
                else
                    this->push(po);
                break;
            case 'P':
            case 'p': if (this->isempty())
                cout << "stack already empty\n";
            else
            {
                this->pop(po);
                cout << "PO #" << po << " popped\n";
            }
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    }
    cout << "Processing is done\n------------------\n";
}

std::ostream & operator<<(std::ostream & os, const Stack & st)
{
    for (int i = 0; i < st.size; i++)
        os << "#" << i << ": " << st.pitems[i] << std::endl;
    return os;
}