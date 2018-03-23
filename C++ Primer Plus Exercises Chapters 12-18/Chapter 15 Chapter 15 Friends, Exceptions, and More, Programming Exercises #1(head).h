// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #1, Page 964
// tv.h -- Tv and Remote classes
#ifndef TV_H_
#define TV_H_

class Remote;  // forward declaration

class Tv
{
public:
    friend class Remote; // Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    enum {Normal, Interactive};
    Tv(int s = Off, int mc = 125);
    void onoff();
    bool ison() const;
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode();
    void set_input();
    void settings() const; // display all settings
    void toggle_mode(Remote & r);
private:
    int state;        // on or off
    int volume;       // assumed to be digitized
    int maxchannel;   // maximum number of channels
    int channel;      // current channel setting
    int mode;         // broadcast or cable
    int input;        // TV or DVD
};

class Remote
{
private:
    int mode; // controls broadcast or cable
    int state; // normal or interactive
public:
    friend class Tv;
    Remote(int m = Tv::Antenna, int s = Tv::Normal) : mode(m), state(s) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) {t.onoff();}
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}
    void show_state();
};

inline void Remote::show_state()
{
    std::cout << "Remote mode is " << (mode == Tv::Antenna? "antenna" : "cable");
    std::cout << "\nRemote state is " << (state == Tv::Normal? "normal\n" : "interactive\n");
}

#endif