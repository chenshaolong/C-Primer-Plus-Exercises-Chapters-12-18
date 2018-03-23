// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #4, Page 1073
#include <iostream>     // std::cout
#include <list>         // std::list
using namespace std;
int reduce(long ar[], int n);

int main()
{
    long arr[] = {1, 7, 2, 3, 6, 5, 6, 6, 8, 4, 2, 1, 6};
    long n = sizeof(arr) / sizeof(long);
    
    int no = reduce(arr, n);
    cout << "\nNo. of unique items in the list: " << no << endl;
    cout << "Bye\n";
    
    return 0;
}

int reduce(long ar[], int n)
{
    cout << "original array:\n";
    list<long> redarr(n);
    copy(ar, ar + n,redarr.begin());
    for (list<long>::iterator it = redarr.begin(); it != redarr.end(); it++)
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
    /*
     for (int i = 0; i < redarr.size(); i++)
     cout << redarr[i] << " "; // list can not access elements using operator[]()
     */
    return redarr.size();
}