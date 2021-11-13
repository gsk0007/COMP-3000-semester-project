#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cstring>
#include <algorithm>
#include "HangmanFunc.h"
#include "Score.h"
using namespace std;

class Player
{
public:
    // chooses a random word from a file for player to guess
    string randomWord(vector<string> wordVec);

    // checks the letter that was guessed against the word. If it is in the word, then it adds it to correctGuesses,
    // if not, it adds it to incorrectGuesses this also updates the board
    void checkGuess(string testWord, char guess, int &guessCounter, char board[8][6], int letterLoc[50], vector<char> &lettersGuessed, char wordDisplay[50]);

    // gets the score of the player
    void getHighScores();

    // tracks the time the player takes to guess the word
    double getTime();

    // plays the game
    void playGame(vector<string> testWord);

    // resets the game
    void resetGame();

    // sets the score of the player
    void scoreSave();

private:
    // Variables
    time_t endTime, startTime;
    string username;
    int score, wordCounter = 0, guessCounter = 0, temp, diceRoll;
    double time;
    bool wordSolve = false;
    char guess, scoreChoice;
    vector<char> lettersGuessed;
    // vector to hold the scores
    vector<ScoreClass> scoresVec;
    char wordDisplay[50];
    int letterLoc[50];
    // initializes the board
    char board[8][6] = {{' ', '_', '_', '_', '_', ' '},
                        {' ', '|', ' ', ' ', '|', ' '},
                        {' ', '|', ' ', ' ', ' ', ' '},
                        {' ', '|', ' ', ' ', ' ', ' '},
                        {' ', '|', ' ', ' ', ' ', ' '},
                        {' ', '|', ' ', ' ', ' ', ' '},
                        {' ', '|', ' ', ' ', ' ', ' '},
                        {'_', '|', '_', '_', '_', '_'}};
};

// ___________________ playGame ___________________________
// Does most of the work of the game. It takes in a vector of words and then
// chooses a random word from the vector to play the game with. It handles getting
// user input and then calls the other functions to play the game.
void Player::playGame(vector<string> words)
{
    // Get start time
    std::time(&startTime);
    // Initialize arrays for later use
    for (int i = 0; i < 50; i++)
    {
        letterLoc[i] = 0;
        wordDisplay[i] = '_';
    }
    // get a random word from the vector
    string testWord = randomWord(words);

    while (guessCounter < 8 && !wordSolve)
    {
        for (int i = 0; i < 50; i++)
        {
            letterLoc[i] = 0;
        }

        // Get the guess from the user
        cout << "Enter a letter: ";
        cin >> guess;
        tolower(guess);
        // Check if a guessed letter is in the word
        checkGuess(testWord, guess, guessCounter, board, letterLoc, lettersGuessed, wordDisplay);

        // Prints the board
        cout << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << board[i][0] << setw(1) << board[i][1] << setw(1) << board[i][2] << setw(1) << board[i][3] << setw(1) << board[i][4] << setw(1) << board[i][5] << endl;
        }

        // Prints the word with spaces and correctly guessed letters
        cout << "Word with correct letters: ";
        for (int i = 0; i < testWord.length() - 1; i++)
        {
            cout << wordDisplay[i];
        }
        cout << endl;

        // Prints the letters guessed
        cout << "Letters guessed: ";
        for (int i = 0; i < lettersGuessed.size(); i++)
        {
            cout << lettersGuessed[i] << " ";
        }
        cout << endl;
        // Checks if the word is solved
        wordCounter = 0;
        for (int i = 0; i < testWord.length(); i++)
        {
            if (wordDisplay[i] == testWord[i])
            {
                wordCounter++;
            }
        }

        // If the game is over, the loop will end. Depending on whether you solved the word or not, the output will be different
        if (wordCounter == testWord.length() - 1)
        {
            wordSolve = true;
            score = getTime() / wordCounter;
            cout << "Congratulations! You won!" << endl
                 << "You scored: " << score << endl
                 << endl
                 << "Would you like to save your score? y/n" << endl;
            cin >> scoreChoice;
            if (scoreChoice == 'y' || scoreChoice == 'Y')
            {
                scoreSave();
            }

            //cin.getline(username, 256);
        }
        else if (guessCounter == 8)
        {
            cout << "You lost! The word was " << testWord << endl;
        }
    }
}

// ___________________ checkGuess ___________________________
// Checks if the guess is in the word using the hangman() function
// After checking the guess, the correct letters and or incorrect letters are recorded
void Player::checkGuess(string testWord, char guess, int &guessCounter, char board[8][6], int letterLoc[50], vector<char> &lettersGuessed, char wordDisplay[50])
{
    // Check if a guessed letter is in the word
    int temp = guessCounter;
    guessCounter = hangman(testWord, guess, guessCounter, board, letterLoc);

    // If the guess is not in the word, then add to the guess vector
    if (guessCounter > temp)
    {
        lettersGuessed.push_back(guess);
    }
    // If the guess is in the word, then update the array with the correct letters
    else if (guessCounter == temp)
    {
        for (int i = 0; i < 50; i++)
        {
            if (letterLoc[i] == 1)
            {
                wordDisplay[i] = guess;
            }
        }
    }
}

// ___________________ randomWord ___________________________
// gets a random word from the vector of all words
string Player::randomWord(vector<string> wordVec)
{
    //diceRoll = distribution(generator);  // generates number in the range 1..370103
    return wordVec[rand() % 370102];
};

// ___________________ resetGame ___________________________
// resets the game variables so that the player can play again
void Player::resetGame()
{
    // restting variables
    score = 0;
    time = 0;
    wordCounter = 0;
    wordSolve = false;
    guessCounter = 0;
    for (int i = 0; lettersGuessed.size(); i++)
    {
        lettersGuessed.pop_back();
    }
    // Initialize arrays for later use
    for (int i = 0; i < 50; i++)
    {
        letterLoc[i] = 0;
        wordDisplay[i] = '_';
    }
    // Copy of the blank board
    const char boardReset[8][6] = {{' ', '_', '_', '_', '_', ' '},
                                   {' ', '|', ' ', ' ', '|', ' '},
                                   {' ', '|', ' ', ' ', ' ', ' '},
                                   {' ', '|', ' ', ' ', ' ', ' '},
                                   {' ', '|', ' ', ' ', ' ', ' '},
                                   {' ', '|', ' ', ' ', ' ', ' '},
                                   {' ', '|', ' ', ' ', ' ', ' '},
                                   {'_', '|', '_', '_', '_', '_'}};
    // Copy the boardReset array to the board array
    for (int i = 0; i < 6; i++)
    {
        strncpy(board[i], boardReset[i], sizeof(boardReset[1]));
    }
}

// ___________________ getTime ___________________________
// Returns the time in seconds since the start of the game
double Player::getTime()
{
    // Get end time
    std::time(&endTime);
    // Calculate time
    return difftime(endTime, startTime);
}

// ___________________ scoreSave ___________________________
// If user decides to save their score, this function will be called
// It will ask for the username and save the score to the file after sorting all the scores for the highscore
void Player::scoreSave()
{
    // Get the previous scores
    ifstream scoreFile;
    string userLine, scoreLine;
    int scoreInt;
    char tempLine;
    scoreFile.open("scores.txt");
    if (scoreFile.is_open())
    {
        while (scoreFile.good())
        {
            // get username and score from file
            getline(scoreFile, userLine, ',');
            getline(scoreFile, scoreLine, '\n');
            scoreInt = stoi(scoreLine);
            // create new score object and add to vector of all scores
            ScoreClass temp(userLine, scoreInt);
            scoresVec.push_back(temp);
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    scoreFile.close();

    // Get the username
    cout << "Enter your username: ";
    cin >> username;

    // Create a new score object
    ScoreClass newScore(username, score);
    // Add the new score to the vector
    scoresVec.push_back(newScore);

    // Sort the vector
    for (int i = 0; i < scoresVec.size(); i++)
    {
        for (int j = 0; j < scoresVec.size() - 1; j++)
        {
            if (scoresVec[j].getScore() > scoresVec[j + 1].getScore())
            {
                ScoreClass temp = scoresVec[j + 1];
                scoresVec[j + 1] = scoresVec[j];
                scoresVec[j] = temp;
            }
        }
    }

    // Write the vector to the file
    ofstream scoreFileWrite;
    scoreFileWrite.open("scores.txt");
    if (scoreFileWrite.is_open())
    {
        for (int i = 0; i < scoresVec.size(); i++)
        {
            if(i == scoresVec.size() - 1)
            {
                scoreFileWrite << scoresVec[i].getUsername() << "," << scoresVec[i].getScore();
            }
            else
            {
                scoreFileWrite << scoresVec[i].getUsername() << "," << scoresVec[i].getScore() << endl;
            }

            //scoreFileWrite << scoresVec[i].getUsername() << "," << scoresVec[i].getScore() << endl;
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    scoreFileWrite.close();
}

// ___________________ getHighScore ___________________________
void Player::getHighScores(){
    // Get the previous scores
    ifstream scoreFileRead;
    string userLine, scoreLine;
    int scoreInt;
    char tempLine;
    if(scoresVec.size() == 0)
        {
        scoreFileRead.open("scores.txt");
        if (scoreFileRead.is_open())
        {
            while (scoreFileRead.good())
            {
                // get username and score from file
                getline(scoreFileRead, userLine, ',');
                getline(scoreFileRead, scoreLine, '\n');
                scoreInt = stoi(scoreLine);
                // create new score object and add to vector of all scores
                ScoreClass temp(userLine, scoreInt);
                scoresVec.push_back(temp);
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        scoreFileRead.close();
    }

    // Print the vector
    for (int i = 0; i < scoresVec.size() && i < 5 ; i++)
    {
        cout << scoresVec[i].getUsername() << " " << scoresVec[i].getScore() << endl;
    }
};
