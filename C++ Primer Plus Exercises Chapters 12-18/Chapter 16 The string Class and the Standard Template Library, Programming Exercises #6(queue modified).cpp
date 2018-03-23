// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #6, Page 1073
// hangman.cpp -- some string methods
#include <iostream>   // std::cout
#include <algorithm>  // std::sort
#include <queue>      // std::queue
#include <string>     // std::string
#include <cstdlib>    // for rand() and srand()
#include <ctime>      // for time()
#include <cmath>
using namespace std;
const int MIN_PER_HR = 60;
const int N = 100;

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

bool newcustomer(double x); // is there a new customer?
double ave_wait_time(const int & qs,const int & hours,const double & perhour);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(time(0)); // random initializing of rand()
    
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    
    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;
    
    cout << "Ente the average number of customers per hour: ";
    double perhour; // average # of arrival per hour
    cin >> perhour;
    
    ave_wait_time(qs, hours, perhour);
    cout << "Done!\n";
    return 0;
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
    queue<Customer> line; // line queue holds up to qs people
    // simulation will run 1 cycle per minute
    double cyclelimit = MIN_PER_HR * hours; // # of cycles
    double min_per_cust = MIN_PER_HR / perhour; // average time between arrivals
    double total_average_wait_time = 0;
    int i = N;
    while (i-->0)
    {
        Customer temp; // new customer data
        int wait_time = 0; // time until autoteller is free
        double turnaways = 0; // turned away by full queue
        double customers = 0; // joined the queue
        double served = 0; // served during the simulation
        double sum_line = 0; // cumulative line length
        double line_wait = 0; // cumulative time in line
        double average_queue_size = 0;
        double average_wait_time = 0;
        
        // running the simulation
        int cycle;
        for (cycle = 0; cycle <cyclelimit; cycle++)
        {
            int time = cycle + (N - i) * cyclelimit;
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.size()==qs)
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(time);  // time = time of arrival
                    line.push(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.empty())
            {
                temp = line.front();
                line.pop(); // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += time - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.size();
        }
  
        average_queue_size = sum_line / cyclelimit;
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