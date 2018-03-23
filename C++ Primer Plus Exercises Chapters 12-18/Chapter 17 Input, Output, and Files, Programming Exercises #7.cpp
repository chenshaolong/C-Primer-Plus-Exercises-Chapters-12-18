// Chapter 17 Input, Output, and Files, Programming Exercises #7, Page1165-1166
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // for for_each
#include <cstdlib> // for size_t
using namespace std;

void ShowStr(const string & st) { cout << st << endl; }
void GetStrs(ifstream & is, vector<string> & vs);
class Store
{
private:
    ofstream & fout; // has to be ofstream & fout rather than ofstream fout
public:
    Store(ofstream & out): fout(out) {} //has to be Store(ofstream & out) rather than Store(ofstream out)
    void operator()(const string & str);
};

int main()
{
    
    vector<string> vostr;
    string temp;
    
    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin,temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    
    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    
    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
     
    return 0;
}

void Store::operator()(const string & str)
{
    size_t len = str.size();
    fout.write((char*)&len, sizeof(size_t));
    fout.write(str.data(), len);
}

void GetStrs(ifstream & fin, vector<string> & vs)
{
    size_t len;
    char * str;
    while (fin.read((char *)&len, sizeof(size_t)))
    {
        str = new char[len];
        fin.read(str, len);
        //str[len + 1] = 0;
        vs.push_back(str);
    }
    delete [] str;
}