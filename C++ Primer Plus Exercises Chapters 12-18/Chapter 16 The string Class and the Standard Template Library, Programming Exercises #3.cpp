// Chapter 16 The string Class and the Standard Template Library, Programming Exercises #3, Page 1072
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::tolower;
    using std::string;
    using std::vector;
    using std::ifstream;
    std::srand(std::time(0));
    
    ifstream fin; // fin an ifstream object
    string filename;
    //cout << "Please enter the filename(guess.txt)\n";
    //cin >> filename;
    fin.open("guess.txt");
    if (!fin.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    vector<string> wordlist;
    string st;
    int count = 0;
    while(fin >> st)
        if (st!= " " && st!= "\t" && st!= "\n")
        {
            wordlist.push_back(st);
            count++;
        }
    if (fin.eof())
        cout << "End of file reached.\n";
    else if (fin.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    fin.close();
    
    if (count == 0)
        cout << "No data imported. Game over.\n";
    else
    {
        cout << "There are " << count << " words to guess.\n";
        char play;
        cout << "Will you play a word game? <y/n> ";
        cin >> play;
        play = tolower(play);
        while (play == 'y' && count > 0)
        {
            string target = wordlist[std::rand() % count];
            int length = target.length();
            string attempt(length, '-');
            string badchars;
            int guesses = 6;
            cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
            cout << "Your word: " << attempt << endl;
            while (guesses > 0 && attempt != target)
            {
                char letter;
                cout << "Guess a letter: ";
                cin >> letter;
                if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
                {
                    cout << "You already guessed that. Try again.\n";
                    continue;
                }
                int loc = target.find(letter);
                if (loc == string::npos)
                {
                    cout << "Oh, bad guess!\n";
                    --guesses;
                    badchars += letter; // add to string
                }
                else
                {
                    cout << "Good guess!\n";
                    attempt[loc]=letter;
                    // check if letter appears again
                    loc = target.find(letter, loc + 1);
                    while (loc != string::npos)
                    {
                        attempt[loc]=letter;
                        loc = target.find(letter, loc + 1);
                    }
                }
                cout << "Your word: " << attempt << endl;
                if (attempt != target)
                {
                    if (badchars.size() > 0)
                        cout << "Bad choices: " << badchars << endl;
                    cout << guesses << " bad guesses left\n";
                }
            }
            if (guesses > 0)
                cout << "That's right!\n";
            else
                cout << "Sorry, the word is " << target << ".\n";
            cout << "Will you play another? <y/n> ";
            cin >> play;
            play = tolower(play);
        }
    }
    cout << "Bye\n";
    
    return 0;
}