//Chapter 14 Reusing Code in C++, Programming Exercises #2, Page 888
// using Wine class with private inheritance
#include <iostream>
#include "head.h"

int main ( void )
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    

    Wine holding(lab, yrs); // store label, years, give arrays yrs elements
    holding.GetBottles();   // solicit input for year, bottle count
    holding.Show();         // display object contents
    
  
    const int YRS = 3;
    int y[YRS] = {1987, 1988, 2016};
    int b[YRS] = { 82, 1127, 1211};
    // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red",YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()  // use Label() method;
         << ": " << more.sum() << endl;           // use sum() method
    cout << "Bye\n";

    return 0;
}