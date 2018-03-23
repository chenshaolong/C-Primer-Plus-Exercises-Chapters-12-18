// Chapter 13 Class Inheritance, Programming Exercises #3, Page 796
// inheritance, friends, and DMA
#include <iostream>
#include <cstring>
#include "head.h"
const int CLIENTS = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    ABCDMA * p_clients[CLIENTS];
    //const char * temp_label[3] ={"AAA", "BBB", "CCC"};
    char * temp_label;
    int temp_rating;
    char kind;
    
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's label: ";
        std::string str;
        getline(cin, str);
        temp_label = &str[0];
        cout << "Enter client's rating with an interger: ";
        cin >> temp_rating;
        cout << "Enter 0, 1 or 2 for: \n"
             << "0) baseDMA      1)lacksDMA      2)hasDMA\n";
        while (cin >> kind && (kind != '0' && kind != '1' && kind != '2'))
            cout << "Enter 0, 1 or 2: ";
        switch (kind)
        {
            case '0':
            {
                p_clients[i] = new baseDMA(temp_label, temp_rating);
                p_clients[i]->show();
                // cout << (const baseDMA &) *p_clients[i];
                delete p_clients[i]; // free memory
                cout << "~~~~~~~~~~~~~~~~~~~~\n";
                break;
            }
            case '1':
            {
                const char temp_color[40] = "Red";
                //cout <<"Enter client's color: ";
                //cin.getline(temp_color, 100);
                p_clients[i] = new lacksDMA(temp_color, temp_label, temp_rating);
                p_clients[i]->show(); // cout << (const lacksDMA &) *p_clients[i];
                delete p_clients[i]; // free memory
                cout << "~~~~~~~~~~~~~~~~~~~~\n";
                break;
            }
            case '2':
            {
                const char * temp_style = "Blue & Country";
                //cout <<"Enter client's style: ";
                //cin.get(temp_style, 100);
                //getline(cin, temp_style);
                p_clients[i] = new hasDMA(temp_style, temp_label, temp_rating);
                p_clients[i]->show(); // cout << (const hasDMA &) *p_clients[i];
                delete p_clients[i]; // free memory
                cout << "~~~~~~~~~~~~~~~~~~~~\n";
                break;
            }
        }
        while (cin.get() != '\n')
            continue;
    }
    
    cout << "Done.\n";
    return 0;
}