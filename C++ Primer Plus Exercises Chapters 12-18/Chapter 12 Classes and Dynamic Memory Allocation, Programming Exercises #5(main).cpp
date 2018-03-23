// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #5, Page 720
// bank.cpp -- using the Queue interface
// compile with queue.cpp
// test for qs = 10, hours = 100
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <cmath>
#include "head.h"

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
    
    /*
    cout << "Ente the average number of customers per hour: ";
    double perhour; // average # of arrival per hour
    cin >> perhour;
    */
    
    double perhour = 1.0; // average # of arrival per hour
    double optimal_time = 0;
    for (perhour = 1.0; std::abs(optimal_time - threshold) > epsilon; perhour++)
        optimal_time = ave_wait_time(qs, hours, perhour);
    
    perhour--;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Conclusion: number of customers per hour that leads to "
    << "an average wait time  of " << threshold << " minute(s) (~" << optimal_time
    << " minute(s)) for maximum size of queue = " << qs
    <<" and the number of simulation hours = " << hours
    << " is: " << (int) perhour << endl;

    
    cout << "Done!\n";
    return 0;
}