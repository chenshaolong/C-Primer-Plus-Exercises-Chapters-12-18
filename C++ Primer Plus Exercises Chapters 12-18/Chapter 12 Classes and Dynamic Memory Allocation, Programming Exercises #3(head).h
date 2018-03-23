// Chapter 12 Classes and Dynamic Memory Allocation, Programming Exercises #3, Page 719
#ifndef STOCK_H_
#define STOCK_H_

class Stock
{
private:
    static const int limit = 66;
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock(); // default constructor
    Stock(const char * co, long n = 0, double pr = 0.0);
    ~Stock(); // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & s);
};

#endif
