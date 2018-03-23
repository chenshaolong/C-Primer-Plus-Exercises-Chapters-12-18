// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #1, Page 964
// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "head.h"

Tv::Tv(int s, int mc) : state(s), volume(6), maxchannel(mc), channel(2), mode(Cable), input(TV) {}

void Tv::onoff() {state ^= 1;}

bool Tv::ison() const {return state == On;}

void Tv::set_mode() {mode = (mode == Antenna)? Cable : Antenna;}

void Tv::set_input() {input = (input == TV)? DVD : TV;}

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV? "TV" : "DVD") << endl;
    }
}

void Tv::toggle_mode(Remote & r)
{
    if (state == On)
        r.state = (r.state == Normal)? Interactive : Normal; // or r.state ^= 1;
}