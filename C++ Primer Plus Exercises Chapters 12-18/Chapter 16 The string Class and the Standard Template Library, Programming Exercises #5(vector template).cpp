// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #5, Page 1073
// hangman.cpp -- some string methods
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
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
    for (int i = 0; i < redarr.size(); i++)
        cout << redarr[i] << " ";
    cout << endl;
    
    cout << "sorted array:\n";
    sort(redarr.begin(), redarr.end()); // vector has to use this nonmember function
    //redarr.sort();  // vector can't use this member function
    for (int i = 0; i < redarr.size(); i++)
        cout << redarr[i] << " ";
    cout << endl;
    
    cout << "reduced array:\n";
    T temp = redarr[0];
    typedef typename std::vector<T>::iterator iterator;
    for (iterator it = redarr.begin(); it != redarr.end()-1; it++)
    {
        if (temp == *(it+1))
        {
            redarr.erase(it+1);  
            it--;
        }
        else
            temp = *(it+1);
    }
    for (int i = 0; i < redarr.size(); i++)
        cout << redarr[i] << " ";
    
    return redarr.size();
}