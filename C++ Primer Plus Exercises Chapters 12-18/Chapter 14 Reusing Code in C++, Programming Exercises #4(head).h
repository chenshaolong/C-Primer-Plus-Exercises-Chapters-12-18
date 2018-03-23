// Chapter 14 Reusing Code in C++, Programming Exercises #4, Page 888
#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string firstname;
    string lastname;
public:
    Person(string fn= "null", string ln = "null"): firstname(fn), lastname(ln) { }
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int notches;
protected:
    int Notch() const { return notches; }
public:
    Gunslinger(string fn= "null", string ln = "null", double dt = 0, int n = 0) : Person(fn, ln), drawtime(dt), notches(n) { }
    Gunslinger(const Person & pr, double dt = 0, int n = 0) : Person(pr), drawtime(dt), notches(n) { }
    //Gunslinger(const Gunslinger & pr) : Person(pr), Gunslinger(pr) { }
    double Draw() const { return drawtime; }
    void Set();
    void Show() const;
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(string fn= "null", string ln = "null") : Person(fn, ln) { }
    PokerPlayer(const Person & pr) : Person(pr) { }
    //PokerPlayer(const PokerPlayer & pr) : Person(pr) { }
    int Draw() const { return (std::rand() % 53 + 1); }
    void Set();
    void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(string fn= "null", string ln = "null", double dt = 0, int n = 0) : Person(fn, ln), Gunslinger(fn, ln, dt, n), PokerPlayer(fn, ln) { }
    BadDude(const Person & pr, double dt = 0, int n = 0) : Person(pr), Gunslinger(pr, dt, n), PokerPlayer(pr) { }
    BadDude(const Gunslinger & pr) : Person(pr),Gunslinger(pr), PokerPlayer(pr) { }
    //BadDude(const PokerPlayer & pr, double dt = 0, int n = 0) : Person(pr),Gunslinger(pr, dt, n), PokerPlayer(pr) { }
    double Gdraw() const { return Gunslinger::Draw(); }
    int Cdraw() const { return (std::rand() % 53 + 1); }
    void Set();
    void Show() const;
};

#endif