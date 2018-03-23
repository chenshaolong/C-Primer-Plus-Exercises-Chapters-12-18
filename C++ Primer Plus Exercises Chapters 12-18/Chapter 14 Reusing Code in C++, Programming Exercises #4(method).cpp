// Chapter 14 Reusing Code in C++, Programming Exercises #4, Page 888
#include "head.h"

// Person methods
Person::~Person() {}

void Person::Set()
{
    cout << "Enter First name: ";
    getline(cin, firstname);
    cout << "Enter Last name: ";
    getline(cin, lastname);
}

void Person::Show() const
{
    cout << "First Name: " << firstname << endl;
    cout << "Last Name: " << lastname << endl;
}

// Gunslinger methods
void Gunslinger::Set()
{
    Person::Set();
    cout << "Enter draw time: ";
    cin >> drawtime;
    cout << "Enter No. of notches: ";
    cin >> notches;
}

void Gunslinger::Show() const
{
    cout << "Catogery: Gunslinger\n";
    Person::Show();
    cout << "Draw time: " << drawtime << endl;
    cout << "No. of notches on the gunslinger’s gun: " << notches << endl;
}

// PokerPlayer methods
void PokerPlayer::Set()
{
    Person::Set();
}

void PokerPlayer::Show() const
{
    cout << "Catogery: PokerPlayer\n";
    Person::Show();
    cout << "Card value: " << Draw() << endl;
}

// PokerPlayer methods
void BadDude::Set()
{
    Gunslinger::Set();
}

void BadDude::Show() const
{
    cout << "Catogery: BadDude\n";
    Person::Show();
    cout << "Draw time: " << Gdraw() << endl;
    cout << "No. of notches on the gunslinger’s gun: " << Notch() << endl;
    cout << "Next card value: " << Cdraw() << endl;
}