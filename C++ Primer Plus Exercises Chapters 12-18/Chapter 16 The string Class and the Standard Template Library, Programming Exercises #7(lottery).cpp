// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #7, Page 1073
#include <iostream>   // std::cout
#include <algorithm>  // std::sort
#include <vector>     // std::vector
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> Lotto(int n, int m);

int main()
{
    srand(time(0));
    vector<int> winners;
    cout << "Enter an integer(1~100) for the number of spots on a lottery card: ";
    int n;
    cin >> n;
    cout << "Enter an integer(1~10) for the number of spots selected at random: ";
    int m;
    cin >> m;
    winners = Lotto(n, m);
    cout << "Winning numbers:";
    for (std::vector<int>::iterator it=winners.begin(); it!=winners.end(); ++it)
        std::cout << ' ' << *it;

    cout << endl;
    return 0;
}

vector<int> Lotto(int n, int m)
{
    vector<int> lottery;
    for (int i = 1; i <= n; i++)
        lottery.push_back(i);
    /*
    cout << "Original lottery:\n";
    for (int i = 0; i < lottery.size(); i++)
        cout << lottery[i] << (i%7!=6 ? "\t" : "\n");
    cout << endl;
    */
    int random = rand()%10 + 1;
    //cout << "random: " << random << endl;
    while (random--> 0)
        random_shuffle(lottery.begin(), lottery.end());
    /*
    cout << "shuffled lottery:\n";
    for (int i = 0; i < n; i++)
        cout << lottery[i] << (i%7!=6 ? "\t" : "\n");
    cout << endl;
    */
    vector<int> win(m);
    copy(lottery.begin(), lottery.begin() + m, win.begin());
    
    return win;
}