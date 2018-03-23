// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #8, Page 1073
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    set<string> Mat;
    cout << "Please enter a list of Mat's friends’ names or quit to <quit>:\n";
    string name;
    getline(cin, name);
    while (name != "quit")
    {
        Mat.insert(name);
        getline(cin, name);
    }
    
    set<string> Pat;
    cout << "Please enter a list of Pat's friends’ names or quit to <quit>:\n";
    getline(cin, name);
    while (name != "quit")
    {
        Pat.insert(name);
        getline(cin, name);
    }
    
    ostream_iterator<string, char> out(cout, " ");
    cout << "Mat's friends: ";
    copy(Mat.begin(), Mat.end(), out);
    cout << endl;
    
    cout << "Pat's friends: ";
    for (set<string>::iterator it = Pat.begin(); it != Pat.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    cout << "Mat's or Pat's friends:\n";
    set<string> All;
    set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string> >(All, All.begin()));
    for (auto x : All) cout << x << " ";
    cout << endl;
    
    cout << "Mat's and Pat's friends:\n";
    set<string> Common;
    insert_iterator<set<string> > it(Common, Common.begin());
    set_intersection(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), it);
    copy(Common.begin(), Common.end(), out);
    cout << endl;
    
    cout << "Mat's but not Pat's friends:\n";
    set_difference(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), out);
    cout << endl;
    
    cout << "Pat's but not Mat's friends:\n";
    set_difference(Pat.begin(), Pat.end(), Mat.begin(), Mat.end(), out);
    cout << endl;
    
    return 0;
}
   