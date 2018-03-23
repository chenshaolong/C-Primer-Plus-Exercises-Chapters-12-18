// Chapter 17 Input, Output, and Files, Programming Exercises #4, Page 1163
#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main()
{
    using namespace std;
    cout << "Open two text files for input and one for output:\n";
    cout << "Enter 1st input file's name: ";
    string file1;
    getline(cin, file1);
    cout << "Enter 2nd input file's name: ";
    string file2;
    getline(cin, file2);
    cout << "Enter output file's name: ";
    string file3;
    getline(cin, file3);
    
    ifstream fin(file1);
    if (!fin.is_open()) // failed to open file1
    {
        cout << "Could not open the file " << file1 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    char ch;
    list<char> l1;
    cout << "~~~~~~~~~~~~~~~~~~~~\n1st input file: \n";
    while (fin.get(ch) && !fin.eof())
    {
        cout << ch;
        l1.push_back(ch);
    }
    cout << endl;
    fin.close();
    
    fin.open(file2);
    if (!fin.is_open()) // failed to open file2
    {
        cout << "Could not open the file " << file2 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    list<char> l2;
    cout << "~~~~~~~~~~~~~~~~~~~~\n2nd input file: \n";
    while (fin.get(ch) && !fin.eof())
    {
        cout << ch;
        l2.push_back(ch);
    }
    cout << endl;
    fin.close();
    
    ofstream fout(file3);
    if (!fout.is_open()) // failed to open file3
    {
        cout << "Could not open the file " << file3 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    int end1 = -1;
    int end2 = -1;
    cout << "~~~~~~~~~~~~~~~~~~~~\noutput file: \n";
    while (!l1.empty() || !l2.empty())
    {
        while (l1.front() != '\n' && !l1.empty())
        {
            cout << l1.front();
            fout << l1.front();
            l1.pop_front();
        }
        if (l1.front() == '\n' && !l2.empty())
        {
            cout << " ";
            fout << " ";
            l1.pop_front();
        }
        if (l1.front() == '\n' && !l1.empty() && l2.empty())
        {
            cout << l1.front();
            fout << l1.front();
            l1.pop_front();
        }
        if (l1.empty())
            if (++end1 == 0 && !l2.empty())
            {
                cout << " ";
                fout << " ";
            }
        while (l2.front() != '\n' && !l2.empty())
        {
            cout << l2.front();
            fout << l2.front();
            l2.pop_front();
        }
        if (l2.front() == '\n')
        {
            cout << l2.front();
            fout << l2.front();
            l2.pop_front();
        }
        if (l2.empty() && !l1.empty())
            if (++end2 == 0)
            {
                cout << endl;
                fout << endl;
            }
    }
    cout << endl;
    fout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~\n";
    fout.close();
     
    cout << "Done\n";
    return 0;
}