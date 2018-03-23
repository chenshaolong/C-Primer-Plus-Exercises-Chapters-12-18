// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #10, Page 1074-1075
// use command line: g++ -std=c++11 vect.cpp && ./a.out
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
struct Review
{
    std::string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool increase_rating(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool increase_price(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const shared_ptr<Review> & rr);

int main()
{
    using namespace std;
    vector<shared_ptr<Review> > books;
    Review temp;
    while (FillReview(temp))
        books.push_back(shared_ptr<Review>(new Review(temp)));
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following " << books.size() << " ratings:\n";
        cout << "Sorted by original order:\nRating\tPrice\tBook\n";
        for (auto x : books) ShowReview(x); // The Range-Based for Loop (C++11)
 
        cout << "Sorted by title:\nRating\tPrice\tBook\n";
        sort(books.begin(), books.end());
        for_each(books.begin(), books.end(), ShowReview); // Alternatively, for (auto x : books) ShowReview(x);

        cout << "Sorted by increase rating:\nRating\tPrice\tBook\n";
        sort(books.begin(), books.end(), increase_rating);
        for_each(books.begin(), books.end(), ShowReview);
        
        cout << "Sorted by decrease rating:\nRating\tPrice\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);
        
        cout << "Sorted by increase price:\nRating\tPrice\tBook\n";
        sort(books.begin(), books.end(), increase_price);
        for_each(books.begin(), books.end(), ShowReview);
        
        cout << "Sorted by decrease price:\nRating\tPrice\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);
        
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tPrice\tBook\n";
        for_each(books.begin(), books.end(), ShowReview); // Alternatively, for (auto x : books) ShowReview(x);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
        return true;
    else
        return false;
}

bool increase_rating(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else if (r1->rating == r2->rating && r1->title < r2->title)
        return true;
    else if (r1->rating == r2->rating && r1->title == r2->title && r1->price < r2->price)
        return true;
    else
        return false;
}

bool increase_price(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else if (r1->price == r2->price && r1->title < r2->title)
        return true;
    else if (r1->price == r2->price && r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl;
}
