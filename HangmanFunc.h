#include <string>
using namespace std;

//__________________________ Hangman Function __________________________
// checks if the guess is in the word and updates the board accordingly
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
    if (guessFlag == false)
    {
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
