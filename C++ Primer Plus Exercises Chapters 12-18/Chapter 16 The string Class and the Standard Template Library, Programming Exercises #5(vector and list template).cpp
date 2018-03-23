// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #5, Page 1073
// hangman.cpp -- some string methods
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <list>       // std::list
#include <vector>       // std::vector
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
    vector<T> redarr(n);
    copy(ar, ar + n,redarr.begin());
    typedef typename std::vector<T>::iterator iterator;
    for (iterator it = redarr.begin(); it != redarr.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    cout << "sorted array:\n";
    sort(redarr.begin(), redarr.end()); // vector has to use this nonmember function
    //redarr.sort();  // vector can't use this member function
    for (int i = 0; i < redarr.size(); i++)
        cout << redarr[i] << " ";
    cout << endl;
    
    cout << "reduced array:\n";
    list<T> lredarr(n);                              // switch to list to use unique() function to removes
    copy(redarr.begin(), redarr.end(),lredarr.begin()); // all but the first element from every consecutive
    lredarr.unique();                                   // group of equal elements in the container
    redarr.resize(lredarr.size());                      // switch back to vector
    copy(lredarr.begin(), lredarr.end(),redarr.begin());
    for (auto x : redarr) cout << x << " ";
    return redarr.size();
}