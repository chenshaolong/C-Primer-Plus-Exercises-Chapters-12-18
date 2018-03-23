// Chapter 18 Chapter 18 Visiting with the New C++ Standard, Programming Exercises #3, Page 1228
#include <iostream>
#include <list>
//#include <iterator> // not necessary
//#include <algorithm> // not necessary

auto lambda = [](int n) {std::cout << n << " ";};

int main()
{
    using std::list;
    using std::cout;
    using std::endl;
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(yadayada); // Alternatively, list<int> etcetera = yadayada;
    // C++11 can use the following instead
    //list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    //list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), lambda);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), lambda);
    cout << endl;
    
    cout << "Original lists after sorting:\n";
    yadayada.sort();
    for_each(yadayada.begin(), yadayada.end(), lambda);
    cout << endl;
    etcetera.sort();
    for_each(etcetera.begin(), etcetera.end(), lambda);
    cout << endl;
    
    yadayada.remove_if([](const int & v) { return v > 100; });
    int cutoff = 200;
    etcetera.remove_if([&](const int & v) { return v > cutoff; });
    // or etcetera.remove_if([=](const int & v) { return v > cutoff; }); // explanation at Page 1204
    // or etcetera.remove_if([&cutoff](const int & v) { return v > cutoff; }); // explanation at Page 1204
    cout <<"Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), lambda);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), lambda);
    cout << endl;
    return 0;
}