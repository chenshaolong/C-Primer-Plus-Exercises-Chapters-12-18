// Chapter 17 Input, Output, and Files, Programming Exercises #1, Page 1163
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter a series of characters which includes character $:\n";
    while (cin >> ch)  // cin >> ch skips over wihte spaces
    {
        if (ch == '$')
            break;
        else
        {
            count++;
            cout << ch;
        }
    }
    cout << "\nnumber of characters before $: " << count << endl;
    cout << "next input character: " << ch << endl;
    cout << "Conclusion: cin >> ch skips over wihte spaces\n";
    while (cin.get() != '\n')
        continue;
    
    cout << "~~~~~~~~~~~~~~~~~~~\n";
    
    count = 0;
    cout << "Enter a series of characters which includes character $:\n";
    while(cin.peek() != '$')
    {
        cin.get(ch); // cin.get(ch) reads wihte spaces
        if (ch == '$')
            break;
        else
        {
            count++;
            cout << ch;
        }
    }
    
    cout << "\nnumber of characters before $: " << count << endl;
    cin.get(ch);
    cout << "next input character: " << ch << endl;
    cout << "Conclusion: cin.get(ch) reads wihte spaces\n";
    
    
    return 0;
}
