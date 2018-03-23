//Chapter 14 Reusing Code in C++, Programming Exercises #3, Page 888
// QueueTp.h -- class declaration for the QueueTp ADT
#ifndef QueueTp_H_
#define QueueTp_H_
#include "worker.h"
#include <iostream>
#include <cctype> // or ctype.h

//template <typename T> std::ostream & operator<<(std::ostream & os, const T & st);

template <typename Type>
class QueueTp
{
private:
    enum {MAX = 6};   // constant specific to class
    int size;         // QueueTp class size
    int top;          // index for top QueueTp item
    Type * pitems;    // holds QueueTp items
public:
    QueueTp(int n = MAX);   // creates QueueTp with n elements
    QueueTp(const QueueTp & st);
    ~QueueTp();
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == size; }
    // push() returns false if QueueTp already is full, true otherwise
    bool push(const Type & item); // add item to QueueTp
    // pop() returns false if QueueTp already is empty, true otherwise
    bool pop(Type & item); // pop top into item
    QueueTp & operator=(const QueueTp & st);
    void process();
    void display() const;
    friend std::ostream & operator<<(std::ostream & os, const QueueTp & st)
    {
        for (int i = 0; i < st.size; i++)
        {
            os << "#" << i + 1 << ": ";
            st.pitems[i]->Show();
            os << std::endl;
        }
        return os;
    }
};

template <typename Type>
QueueTp<Type>::QueueTp(int n) : size(n), top(0) // creates QueueTp with n elements
{
    if (n != MAX)
        std::cout << "constructor is called here\n";
    else
        std::cout << "default constructor is called here\n";
    pitems = new Type [n];
}

template <typename Type>
QueueTp<Type>::QueueTp(const QueueTp<Type> & st)
{
    std::cout << "copy constructor is called here\n";
    size = st.size;
    top = st.top;
    pitems = new Type [size];
    for (int i=0; i < size; i++)
        pitems[i] = st.pitems[i];
}

template <typename Type>
QueueTp<Type>::~QueueTp()
{
    std::cout << "destructor is called here\n";
    std::cout << "QueueTp class size = " << size << std::endl;
    std::cout << "No. of items in QueueTp class = " << top << std::endl;
    delete [] pitems;
}

template <typename Type>
bool QueueTp<Type>::push(const Type & item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

template <typename Type>
bool QueueTp<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = pitems[0];
        for (int i = 0; i < top; i++)
            pitems[i] = pitems[i+1];
        top--;
        return true;
    }
    else
        return false;
}

template <typename Type>
QueueTp<Type> & QueueTp<Type>::operator=(const QueueTp<Type> & st)
{
    std::cout << "Assignment operator = is used here\n";
    if (this == &st)  // object assigned to itself
        return *this;  // all done
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Type [size];
    for (int i=0; i < size; i++)
        pitems[i] = st.pitems[i];
    return *this;
}

template <typename Type>
void QueueTp<Type>::process()
{
    using namespace std;
    char ch;
    Type po;
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
            case 'a':
            {
                if (this->isfull())
                    cout << "QueueTp already full\n";
                else
                {
                    cout << "Enter the employee category:\n";
                    cout << "w: waiter   s: singer   t: singing waiter\n";
                    char choice;
                    cin >> choice;
                    while (strchr("wst", choice) == NULL)
                    {
                        cout << "Please enter a w, s, or t: ";
                        cin >> choice;
                    }
                    switch(choice)
                    {
                        case 'w': po = new Waiter;
                            break;
                        case 's': po = new Singer;
                            break;
                        case 't': po = new SingingWaiter;
                            break;
                    }
                    po->Set();
                    this->push(po);
                }
                break;
            }
            case 'P':
            case 'p':
            {
                if (this->isempty())
                    cout << "QueueTp already empty\n";
                else
                {
                    this->pop(po);
                    cout << "PO item: ";
                    po->Show();
                    cout << " popped\n";
                }
                break;
            }
        }
        cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    }
    cout << "Processing is done\n------------------\n";
    //cout << *this << endl;  // this lead to an error(libc++abi.dylib: Pure virtual function called!)
    this->display();
    
    delete po;
}

template <typename Type>
void QueueTp<Type>::display() const
{
    std::cout << "\nHere is your staff:\n===================\n";
    for (int i = 0; i < top; i++)
    {
        std::cout << "#" << i + 1 << ": ";
        pitems[i]->Show();
        std::cout << std::endl;
    }
    std::cout << "Displaying is done\n===================\n";
}

#endif