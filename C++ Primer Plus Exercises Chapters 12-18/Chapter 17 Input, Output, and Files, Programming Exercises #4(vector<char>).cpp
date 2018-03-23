// Chapter 17 Input, Output, and Files, Programming Exercises #4, Page 1163
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    vector<char> v1;
    cout << "~~~~~~~~~~~~~~~~~~~~\n1st input file: \n";
    while (fin.get(ch) && !fin.eof())
    {
        cout << ch;
        v1.push_back(ch);
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
    
    vector<char> v2;
    cout << "~~~~~~~~~~~~~~~~~~~~\n2nd input file: \n";
    while (fin.get(ch) && !fin.eof())
    {
        cout << ch;
        v2.push_back(ch);
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
    while (!v1.empty() || !v2.empty())
    {
        while (v1[0] != '\n' && !v1.empty()) // v1[0] = v1.front();
        {
            cout << v1[0]; // cout << v1.front();
            fout << v1[0]; // fout << v1.front();
            v1.erase(v1.begin());
        }
        if (v1[0] == '\n' && !v2.empty())
        {
            cout << " ";
            fout << " ";
            v1.erase(v1.begin());
        }
        if (v1[0] == '\n' && !v1.empty() && v2.empty())
        {
            cout << v1[0];
            fout << v1[0];
            v1.erase(v1.begin());
        }
        if (v1.empty())
            if (++end1 == 0 && !v2.empty())
            {
                cout << " ";
                fout << " ";
            }
        while (v2[0] != '\n' && !v2.empty())
        {
            cout << v2[0];
            fout << v2[0];
            v2.erase(v2.begin());
        }
        if (v2[0] == '\n')
        {
            cout << v2[0];
            fout << v2[0];
            v2.erase(v2.begin());
        }
        if (v2.empty() && !v1.empty())
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