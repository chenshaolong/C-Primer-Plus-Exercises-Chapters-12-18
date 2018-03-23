//Chapter 14 Reusing Code in C++, Programming Exercises #3, Page 888
// QueueTp2.cpp -- testing the QueueTp class
#include <iostream>
#include "queuetp.h"
#include "worker.h"
using namespace std;
const int SIZE = 5;

int main()
{
    QueueTp<Worker *> lolas(SIZE); // create an empty QueueTp
    lolas.process();
    
    QueueTp<Worker *> copy = QueueTp<Worker *>(lolas);
    copy.process();
    
    QueueTp<Worker *> assign = lolas;
    assign.process();

    std::cout << "Bye\n";
    return 0;
}