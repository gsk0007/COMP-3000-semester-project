#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"

using namespace std;

// todo testing

int main()
{
    // create object of class Player
    Player player;
    // Bool for game loop
    bool play = true;
    // Int for menu choice
    int menuChoice;
    // Temp variable for end of game
    char temp;
    // Random number generator stuff
    srand((int)time(0));
    // Initialize vector of words
    vector<string> words;
    ifstream file("words_alpha.txt");
    string line;

    // Read in words from file and store in vector
    if (file.is_open())
    {
        while (file.good())
        {
            getline(file, line);
            words.push_back(line);
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    file.close();

    while (play)
    {
        // Menu for player to interact with
        cout << "Welcome to Hangman!" << endl
             << "1. Play Game" << endl
             << "2. Highscores" << endl
             << "3. Quit" << endl;
        // Get menu choice
        cin >> menuChoice;
        // Switch statement for menu choice
        switch (menuChoice)
        {
        case 1:
            // Play game
            player.resetGame();
            player.playGame(words);
            break;
        case 2:
            // Highscores
            player.getHighScores();
            break;
        case 3:
            // Quit
            play = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        cout << "Do you want to play again? y/n" << endl;
        cin >> temp;
        if (temp == 'n' || temp == 'N')
        {
            play = false;
        }
    }
}


