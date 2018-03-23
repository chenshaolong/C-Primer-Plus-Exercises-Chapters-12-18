// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #1, Page 1072
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <string>       // std::string
#include <cctype>
using namespace std;

bool palindrome(const string & st);

int main()
{
    cout << "Please enter a string or q to quit: ";
    string st;
    while (getline(cin, st) && st!="q")
    {
        if (palindrome(st))
            cout << "\"" << st << "\" is a palindrome.\n";
        else
            cout << "\"" << st << "\" is not a palindrome.\n";
        cout << "Please enter a string or q to quit: ";
    }
    return 0;
}

bool palindrome(const string & st)
{
    if (st.empty())
        return false;
    else
    {
        string temp = st;
        /*
         int n = st.size();
         for (int i = 0; i < n; i++)
         temp[i] = st[n-1-i];
         */
        reverse(temp.begin(), temp.end());
        if (temp == st)
            return true;
        else
            return false;
    }
}