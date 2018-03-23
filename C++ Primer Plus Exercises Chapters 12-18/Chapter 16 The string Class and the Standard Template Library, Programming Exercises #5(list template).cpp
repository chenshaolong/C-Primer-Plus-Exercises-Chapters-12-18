// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #5, Page 1073
// hangman.cpp -- some string methods
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <list>       // std::list
#include <string>       // std::string
using namespace std;
template <class T>
int reduce(T ar[], int n);

int main()
{
    long arr[] = {1, 7, 2, 3, 6, 5, 6, 6, 8, 4, 2, 1, 6};
    long n = sizeof(arr) / sizeof(long);
    int no = reduce(arr, n);
    cout << "\nNo. of unique items in the list: " << no << endl;
    
    string st[] = {"C++", "C++", "Love", "Shaolong", "Love", "Love", "LuoMeng", "Love", "C++"};
    n = sizeof(st) / sizeof(string);
    no = reduce(st, n);
    cout << "\nNo. of unique items in the list: " << no << endl;
    
    cout << "Bye\n";
    
    return 0;
}

template <class T>
int reduce(T ar[], int n)
{
    cout << "original array:\n";
    list<T> redarr(n);
    copy(ar, ar + n,redarr.begin());
    typedef typename std::list<T>::iterator iterator;
    for (iterator it = redarr.begin(); it != redarr.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    cout << "sorted array:\n";
    //sort(redarr.begin(), redarr.end()); // list can not use this nonmember function
    redarr.sort();  // list should use this member function
    for (auto x : redarr) cout << x << " ";
    cout << endl;
    
    cout << "reduced array:\n";
    redarr.unique();
    for (auto x : redarr) cout << x << " ";

    return redarr.size();
}