// Chapter 17 Input, Output, and Files, Chapter Review #6, Page 1161
#include <iostream> 
#include <iomanip>

int main()
{
    using namespace std;
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    
    cout << setw(15) << "decimal base"
         << setw(15) << "octal base"
         << setw(15) << "hexadecimal base\n";
    cout.setf(ios::showbase); // or cout << showbase;
    cout << setw(15) << n
         << hex << setw(15) << n
         << oct << setw(15) << n << endl;
    
    return 0;
}