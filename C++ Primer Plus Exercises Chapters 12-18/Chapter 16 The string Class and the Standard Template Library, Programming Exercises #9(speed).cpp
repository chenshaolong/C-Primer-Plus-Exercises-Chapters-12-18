// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #9, Page 1074
#include <iostream>
#include <vector>    // std::vector
#include <list>      // std::list
#include <algorithm> // sort (RandomAccessIterator first, RandomAccessIterator last);
#include <cstdlib>   // srand(), rand()
#include <ctime>     // describes clock() function, clock_t type and time()
#include <iterator>  // std::iterator
using namespace std;
const int N = 1000000;
void show(int x) { cout << x << " "; }
int main()
{
    srand(time(0));
    
    vector<int> vi0;
    int n = N;
    while (n-->0)
        vi0.push_back(rand()%100 + 1);
    /*
    ostream_iterator<int, char> out(cout, " ");
    copy(vi0.begin(), vi0.end(), out);
    cout << endl;
    */
    
    vector<int> vi(vi0);
    /*
    for_each(vi.begin(), vi.end(), show);
    cout << endl;
    */
    
    list<int> li(vi0.size());
    copy(vi0.begin(), vi0.end(), li.begin());
    /*
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
        cout << *it << " ";
    cout << endl;
    */
    
    cout << "Speed test for sorting a vector container: ";
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC;
    cout << " s" << endl;
    
    cout << "Speed test for sorting a list container: ";
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC;
    cout << " s" << endl;
    
    cout << "Speed test for combined operation: ";
    copy(vi0.begin(), vi0.end(), li.begin()); // reset li to the unsorted contents of vi0
    start = clock();
    copy(li.begin(), li.end(), vi.begin());   // copy li to vi
    sort(vi.begin(), vi.end());               // sort vi
    copy(vi.begin(), vi.end(), li.begin());   // copy the result back to li
    //copy(li.begin(), li.end(), out);
    //cout << endl;
    end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC;
    cout << " s" << endl;

    return 0;
}
   