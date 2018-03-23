// Chapter 17 Input, Output, and Files, Chapter Review #8, Page 1162
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int ct1 = 0;
    cin >> ch;
    while (ch != 'q')
    {
        ct1++;
        cin >> ch;
        cout << ch;
    }
    cout << endl;
    cout << "~~~~~~~~~\n";
    
    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q')
    {
        ct2++;
        cin.get(ch);
        cout << ch;
    }
    cout << endl;
    
    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";
    
    return 0;
}
