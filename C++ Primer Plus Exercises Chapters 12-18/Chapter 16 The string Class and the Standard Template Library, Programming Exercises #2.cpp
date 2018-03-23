// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #2, Page 1072
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <string>       // std::string
#include <cctype>       // tolower, isalpha
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
        int n = st.size();
        string temp1;
        for (int i = 0; i < n; i++)
            if (isalpha(st[i]))
                temp1.push_back(tolower(st[i]));
        string temp2 = temp1;
        reverse(temp2.begin(), temp2.end());
        if (temp1 == temp2)
            return true;
        else
            return false;
    }
}