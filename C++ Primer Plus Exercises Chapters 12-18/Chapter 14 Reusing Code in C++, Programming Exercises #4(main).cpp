// Chapter 14 Reusing Code in C++, Programming Exercises #4, Page 888
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "head.h"
const int SIZE = 3;

int main()
{
    srand(time(0));
    
    Person * lolas[SIZE];
    
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the person category:\n"
        << "g: gunslinger   p: poker player\n"
        << "b: bad dude     q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'g': lolas[ct] = new Gunslinger;
                break;
            case 'p': lolas[ct] = new PokerPlayer;
                break;
            case 'b': lolas[ct] = new BadDude;
                break;
        }
        cin.get();
        lolas[ct]->Set();
        cout << endl;
    }
    
    cout << "\nHere is your staff:\n";
    cout << "=====================\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        lolas[i]->Show();
        cout << endl;
    }
    cout << "=====================\n";
    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    return 0;
}

