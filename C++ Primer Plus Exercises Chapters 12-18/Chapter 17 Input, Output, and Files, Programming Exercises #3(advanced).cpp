// Chapter 17 Input, Output, and Files, Programming Exercises #3, Page 1163
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    using namespace std;
    cout << "Copy file A to file B: ";
    cout << "Enter file A's name: ";
    string fileA;
    getline(cin, fileA);
    cout << "Enter file B's name: ";
    string fileB;
    getline(cin, fileB);
    
    ifstream fin(fileA);
    if (!fin.is_open()) // failed to open file A
    {
        cout << "Could not open the file " << fileA << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    char ch;
    vector<char> vc;
    fin.get(ch);
    while (!fin.eof())
    {
        cout << ch;
        vc.push_back(ch);
        fin.get(ch);
    }
    
    if (fin.eof())
        cout << "End of file A reached.\n";
    else if (fin.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    fin.close();
    
    ofstream fout(fileB);
    if (!fout.is_open()) // failed to open file A
    {
        cout << "Could not open the file " << fileB << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    for (vector<char>::iterator it = vc.begin(); it != vc.end(); it++)
        fout << *it;
    fout.close();
    
    cout << "Done\n";
    return 0;
}