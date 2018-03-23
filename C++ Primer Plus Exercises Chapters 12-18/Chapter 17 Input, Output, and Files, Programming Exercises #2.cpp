// Chapter 17 Input, Output, and Files, Programming Exercises #2, Page 1163
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    cout << "Enter a filename: ";
    string filename;
    getline(cin, filename);
    ofstream fout(filename);
    cout << "Enter a series charachers or q to <quit>:\n";
    char ch;
    while ((ch = cin.get()) != 'q')
        fout << ch;
    fout.close();
    
    fout.open(filename, ios::out | ios::app);
    cout << "Append a series charachers to the existing file: " << filename << ", or q to <quit>:\n";
    while ((ch = cin.get()) != 'q')
        fout << ch;
    fout.close();
    return 0;
}
