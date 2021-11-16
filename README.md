# COMP 3000 semester project

## Competitive terminal hangman

by Samuel Koser and Kennedy Edwards
 
### Description

Here is a project we developed as mini project in C++.
It is a competitive game of hangman that allows creation
of a user profile and top score tracking.


### Functions

```
class Player
{
public:
    randomWord() - chooses a random word from a file for player to guess

    checkGuess() - checks the letter that was guessed if it is in the word, then outputs the letter or an error based on guess

    getHighScores() - Reads all scores out of score file and displays the top 5

    getTime() - tracks the time the player takes to guess the word

    playGame() - allows user to start playing a game

    resetGame() - resets all private variables for Player object so another game can be played

    scoreSave() - adds newest score to the vector of scores, sorts the vector so the highest score is on top, and saves all scores to the score file
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
    char board[8][6];
}

class ScoreClass
{
public:
    ScoreClass() - default constructor

    ScoreClass(string getName, int getScore) - constructor with parameters
    {
        name = getName;
        score = getScore;
    };
    
    getScore() { return score; } - returns score
    
    string getUsername() { return name; } - returns name

private:
    string name;
    int score;
};

int hangman() - Checks guess and updates game board accordingly
```

### Database

Words for the game to use are stored in a text file.
The top scores of all time and the player that
scored that score are stored in another file.

### Empathy map

A 5-step process for creating empathy maps that describe
user characteristics at the start of a UX design process.

```
Says                            | Thinks
                                |
    I want to play a game       |   How long is word?
                                |
    I want to be the fastest    |   What is the word?
                                |
                                |   What letter should I guess?
                                |
                                |
                                |
                                |
                                |
                                |
_____________________________A User_________________________
Does                            | Feels
                                |
                                |
    Guesses a letter            |   Satisfied with how fast
                                |   the word is solved
    Chooses to play a game      |   
                                |   Upset with how long it
                                |   took to solve the word
                                |
                                |
                                |
                                |
                                |
```

### Resources

A list of words provided by infochimps and converted to a text file.
The project for the text file is available [here](https://github.com/dwyl/english-words.git).
