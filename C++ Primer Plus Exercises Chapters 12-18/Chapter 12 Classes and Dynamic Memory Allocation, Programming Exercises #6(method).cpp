// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #6, Page 720
// queue.cpp -- Queue and Customer methods
#include <iostream>
#include "head.h"
#include <cstdlib>  // (or stdlib.h) for rand()

// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL; // or nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL) // while queue is not yet empty
    {
        temp =front; // save address of front item
        front = front->next; // reset pointer to next item
        delete temp; // delete former front
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node; // create node
    // on failure, new throws std::bad_alloc exception
    add->item = item; // set node pointers
    add->next = NULL; // or nullptr;
    items++;
    if (front == NULL) // if queue is empty
        front = add; // place item at front
    else
        rear->next = add; // else place at rear
    rear = add; // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

double ave_wait_time(const int & qs,const int & hours,const double & perhour)
{
    using namespace std;
    
    Queue line1(qs);  // line queue holds up to qs people
    Queue line2(qs);
    
    // simulation will run 1 cycle per minute
    double cyclelimit = MIN_PER_HR * hours; // # of cycles
    double min_per_cust = MIN_PER_HR / perhour; // average time between arrivals
    double total_average_wait_time = 0;
    int i = N;
    while (i-->0)
    {
        Item temp; // new customer data
        
        double turnaways = 0; // turned away by full queue
        double customers = 0; // joined the queue
        
        int wait_time1 = 0; // time until autoteller is free
        int wait_time2 = 0;
        double served = 0; // served during the simulation
        double sum_line = 0; // cumulative line length
        double line_wait = 0; // cumulative time in line
        //double average_queue_size = 0;
        double average_wait_time = 0;
        
        // running the simulation
        int cycle;
        for (cycle = 0; cycle <cyclelimit; cycle++)
        {
            int time = cycle + (N - i) * cyclelimit;
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(time); // time = time of arrival
                    if (line1.queuecount() < line2.queuecount())
                        line1.enqueue(temp); // add newcomer to line 0
                    else
                        line2.enqueue(temp); // add newcomer to line 1
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp); // attend next customer
                wait_time1 = temp.ptime(); // for wait_time minutes
                line_wait += time - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line += line1.queuecount();
            
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp); // attend next customer
                wait_time2 = temp.ptime(); // for wait_time minutes
                line_wait += time - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line2.queuecount();
        }
        
        average_wait_time = line_wait / served;
        total_average_wait_time += average_wait_time;
        
        /*
        // reporting rsults
        if (customers > 0)
        {
            //cout << "===========================\n";
            cout << "customers accepted: " << customers << endl;
            cout << "customers served: " << served << endl;
            cout << "turnaways: " << turnaways << endl;
            cout << "sum_line: " << sum_line << endl;
            cout << "line_wait: " << line_wait << endl;
            cout << "average queue size: ";
            cout.precision(3);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << average_queue_size << endl;
            cout << perhour << " customer(s), ";
            cout << "average wait time: " << average_wait_time << " minutes\n";
        }
        else
            cout << "No customers!\n";
         */
    }
    cout.precision(3);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    double mean_wait_time = total_average_wait_time / N;
    cout << (int) perhour << " customer(s), ";
    cout << "average wait time: " << mean_wait_time << " minutes\n";
    
    return mean_wait_time;
}