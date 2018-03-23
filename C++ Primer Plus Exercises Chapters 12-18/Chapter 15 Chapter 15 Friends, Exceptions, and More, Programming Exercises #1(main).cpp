// Chapter 15 Chapter 15 Friends, Exceptions, and More, Programming Exercises #1, Page 964
//use_tv.cpp -- using the Tv and Remote classes
#include <iostream>
#include "head.h"

int main()
{
    using std::cout;
    cout << "\nHere is info:\n";
    Tv s36;
    cout << "Initial settings for 36\" TV:\n";
    s36.settings();
   
    Remote grey;
    cout << "Initial settings for Remote grey:\n";
    grey.show_state();
    cout << "================================\n";
    
    s36.onoff();
    s36.chanup();
    cout << "\nAdjusted settings for 36\" TV:\n";
    s36.settings();
    
    grey.set_chan(s36, 88);
    grey.volup(s36);
    grey.volup(s36);
    cout << "\n36\" settings after using remote:\n";
    s36.settings();
    cout << "================================\n";
    
    s36.toggle_mode(grey);
    cout << "\nAdjusted settings for Remote grey:\n";
    grey.show_state();
    s36.toggle_mode(grey);
    cout << "\nAnother adjusted settings for Remote grey:\n";
    grey.show_state();
    cout << "================================\n";
    
    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58,28);
    cout << "\n58\" settings:\n";
    s58.settings();
    cout << "================================\n";
    
    Remote red = grey;
    cout << "Initial settings for Remote red:\n";
    red.show_state();
    s58.toggle_mode(red);
    cout << "\nAdjusted settings for Remote grey:\n";
    red.show_state();
    
    cout << "Done\n\n";
    return 0;
}