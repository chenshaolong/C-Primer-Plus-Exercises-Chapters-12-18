// Chapter 17 Input, Output, and Files, Programming Exercises #3, Page 1163
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
    
    ifstream fin1(file1);
    if (!fin1.is_open()) // failed to open file1
    {
        cout << "Could not open the file " << file1 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    ifstream fin2(file2);
    if (!fin2.is_open()) // failed to open file2
    {
        cout << "Could not open the file " << file2 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    ofstream fout(file3);
    if (!fout.is_open()) // failed to open file3
    {
        cout << "Could not open the file " << file3 << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    cout << "~~~~~~~~~~~~~~~~~~~~\n";
    char ch;
    int end = -1;
    while (!fin1.eof() || !fin2.eof())
    {
        while ((ch = fin1.get())!= '\n' && !fin1.eof())
        {
            cout << ch;
            fout << ch;
        }
        if (ch == '\n' && !fin2.eof())
        {
            cout << " ";
            fout << " ";
        }
        if (fin1.eof())
            if (++end == 0 && !fin2.eof())
            {
                cout << " ";
                fout << " ";
            }
        while ((ch = fin2.get())!= '\n' && !fin2.eof())
        {
            cout << ch;
            fout << ch;
        }
        cout << endl;
        fout << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~\n";

    fin1.close();
    fin2.close();
    fout.close();
    
    cout << "Done\n";
    return 0;
}