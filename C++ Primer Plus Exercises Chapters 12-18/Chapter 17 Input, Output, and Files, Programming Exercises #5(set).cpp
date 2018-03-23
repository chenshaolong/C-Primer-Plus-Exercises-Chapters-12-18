// Chapter 17 Input, Output, and Files, Programming Exercises #5, Page 1163
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    ofstream fout;
    cout << "Please enter a list of Mat's friends’ names or quit to <quit>:\n";
    string name;
    getline(cin, name);
    //fout.open("mat.dat");
    fout.open("mat");
    int count = -1;
    while (name != "quit")
    {
        if (++count==0)
        {
            fout << name;
            getline(cin, name);
        }
        else
        {
            fout << endl << name;
            getline(cin, name);
        }
    }
    fout.close();
    
    cout << "Please enter a list of Pat's friends’ names or quit to <quit>:\n";
    getline(cin, name);
    //fout.open("pat.dat");
    fout.open("pat");
    count = -1;
    while (name != "quit")
    {
        if (++count==0)
        {
            fout << name;
            getline(cin, name);
        }
        else
        {
            fout << endl << name;
            getline(cin, name);
        }
    }
    fout.close();
    
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "outcome read from file:\n";
    set<string> Mat;
    cout << "Mat's friends:\n";
    //ifstream fin("mat.dat");
    ifstream fin("mat");
    while (!fin.eof())
    {
        getline(fin, name);
        Mat.insert(name);
        cout << name << endl;
    }
    fin.close();

    set<string> Pat;
    cout << "Pat's friends:\n";
    //fin.open("pat.dat");
    fin.open("pat");
    while (!fin.eof())
    {
        getline(fin, name);
        Pat.insert(name);
        cout << name << endl;
    }
    fin.close();
    
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "outcome displaying after sorting:\n";
    ostream_iterator<string, char> out(cout, "\n");
    cout << "Mat's friends:\n";
    copy(Mat.begin(), Mat.end(), out);
    cout << "Pat's friends:\n";
    copy(Pat.begin(), Pat.end(), out);

    cout << "Mat's or Pat's friends:\n";
    set<string> All;
    //fout.open("matnpat.dat");
    fout.open("matnpat");
    //insert_iterator<set<string> > insert_it(All, All.begin());
    //set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_it);
    set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string> >(All, All.begin()));
    for (auto x : All)
    {
        cout << x << "\n";
        fout << x << "\n";
    }
    fout.close();
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";
    
    
    return 0;
}
   