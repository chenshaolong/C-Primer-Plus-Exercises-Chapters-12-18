// Chapter 17 Input, Output, and Files, Chapter Review #7, Page 1161
#include <iostream> 
#include <iomanip>

int main()
{
    using namespace std;
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter your hourly wage: ";
    float wage;
    cin >> wage;
    
    cout << "Enter number of hours worked: ";
    float hours;
    cin >> hours;
    
    cout << showpoint << fixed << right;
    cout << "First format: \n";
    cout << setw(30) << name << ": $" << setprecision(2)
         << setw(10) << wage << ": $" << setprecision(1)
         << setw(5) << hours << "\n";
    
    cout << "Second format: \n";
    cout << left;
    cout << setw(30) << name << ": $" << setprecision(2)
         << setw(10) << wage << ": $" << setprecision(1)
         << setw(5) << hours << "\n";

    return 0;
}