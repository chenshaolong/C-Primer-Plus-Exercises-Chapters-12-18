// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #5, Page 720
// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
const int MIN_PER_HR = 60;
const int N = 1000;
const double threshold = 1.0;
const double epsilon = 0.01;

class Customer
{ private:
    long arrive;  // arrival time for customer
    int processtime;  // processing time for customer
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node { Item item; struct Node * next;};
    enum {Q_SIZE = 10};
    // private class members
    Node * front; // pointer to front of Queue
    Node * rear;  // pointer to rear of Queue
    int items;    // current number of items in Queue
    const int qsize;  // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator=(const Queue & q) { return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item); // remove item from front
};

bool newcustomer(double x); // is there a new customer?
double ave_wait_time(const int & qs,const int & hours,const double & perhour);

#endif