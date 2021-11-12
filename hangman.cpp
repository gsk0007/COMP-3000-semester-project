#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//todo Timer for highscore, store highsore in file with name, get random word from file
class Player
{
public:
    string randomWord(); // chooses a random word from a file for player to guess
    bool checkGuess(); // checks the letter that was guessed if it is in the word, then outputs the letter or an error based on guess
    string trackLetters(); // keeps tracks of letters guessed, then outputs a list of remaining letters
    int getScore(); // gets the score of the player
    double getTime(); // tracks the time the player takes to guess the word
    void playGame(); // plays the game
private:
    string username;
    int score;
    double time;
};

int hangman(string word, char guess, int &manCounter, char board[8][6], int letterLoc[50]);

// Variables for testing (will be removed later)
string testWord = "abouchement";

int main()
{
Player player;
player.playGame();
}

// ___________________Member Functions___________________________
void Player::playGame(){
    // Variables
    int wordCounter = 0;
    bool wordSolve = false;
    int guessCounter = 0, temp;
    char guess;
    vector<char> lettersGuessed;
    char wordDisplay[50];
    int letterLoc[50];
    // Initialize arrays for later use
    for(int i = 0; i < 50; i++)
    {
        letterLoc[i] = 0;
        wordDisplay[i] = '_';
    }
    // Initialize the board
    char board[8][6] = {{' ','_','_','_','_',' '},
                        {' ','|',' ',' ','|',' '},
                        {' ','|',' ',' ',' ',' '},
                        {' ','|',' ',' ',' ',' '},
                        {' ','|',' ',' ',' ',' '},
                        {' ','|',' ',' ',' ',' '},
                        {' ','|',' ',' ',' ',' '},
                        {'_','|','_','_','_','_'}};

    while(guessCounter < 8 && !wordSolve){
        for(int i = 0; i < 50; i++)
        {
            letterLoc[i] = 0;
        }

        // Get the guess from the user
        cout << "Enter a letter: ";
        cin >> guess;

        // Check if a guessed letter is in the word
        temp = guessCounter;
        guessCounter = hangman(testWord, guess, guessCounter, board, letterLoc);

        // If the guess is not in the word, then add to the guess vector
        if (guessCounter > temp){
            lettersGuessed.push_back(guess);
        }
        // If the guess is in the word, then update the array with the correct letters
        else if(guessCounter == temp){
            for(int i = 0; i<50; i++){
                if(letterLoc[i] == 1){
                    wordDisplay[i] = guess;
                }
            }
        }
         
        // Prints the board
        cout << endl;
        for (int i = 0; i < 8; i++)
        {
            cout <<  board[i][0] << setw(1) <<  board[i][1] << setw(1) <<  board[i][2] << setw(1) <<  board[i][3] << setw(1) <<  board[i][4] << setw(1) <<  board[i][5] << endl;
        }

        // Prints the word with spaces and correclty guessed letters
        cout << "Word with correct letters: ";
        for (int i = 0; i < testWord.length(); i++)
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

        // If the word is solved, the loop will end
        if (wordCounter == testWord.length())
        {
            wordSolve = true;
            cout << "Congratulations! You won!";
        }
    }
}

//__________________________ Functions __________________________
int hangman(string word, char guess, int &manCounter, char board[8][6], int letterLoc[50])
{
    // initialize variable for checking if the letter is in the word
    bool guessFlag = false;
    // check if the letter is in the word
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guess)
        {
            guessFlag = true;
            letterLoc[i] = 1;
        }
    }
    // if the letter is not in the word, then the board will be updated
    if(guessFlag == false){
        manCounter++;
        switch (manCounter)
        {
        case 1:
            board[2][4] = 'O';
            break;
        case 2:
            board[3][4] = '|';
            break;
        case 3:
            board[3][4] = '|';
            break;
        case 4:
            board[3][3] = '/';
            break;
        case 5:
            board[3][5] = '\\';
            break;
        case 6:
            board[4][4] = '|';
            break;
        case 7:
            board[5][3] = '/';
            break;
        case 8:
            board[5][5] = '\\';
            break;
        default:
            break;
        }
    }
    // if guess is wrong, index mancounter and return to signify a wrong guess
    return manCounter;
};
