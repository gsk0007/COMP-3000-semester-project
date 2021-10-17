# COMP 3000 semester project

## Competitive terminal hangman

by Samuel Koser and Kennedy Edwards

### Description

Here is a project we developed as mini project in C++.
It is a competitive game of hangman that allows creation
of a user profile and top score tracking.

### Functions
randomWord() - generates a random word from a file for player to guess
checkGuess() - checks the letter that was guessed if it is in the word
    outputs the letter or an error based on guess
trackLetters() - keeps tracks of letters guessed outputs a list 
    of remaining letters
getScore() - gets the score of the player
getTime() - tracks the time the player takes to guess the word
```
class Player{
    public:
        int getScore();
        double getTime();
        void randomWord();
    private:
        int score;
        double time;
}
```

### Database

Words for the game to use are stored in a text file. 
The top scores of all time are stored in another file.

### Empathy map

A 5-step process for creating empathy maps that describe
user characteristics at the start of a UX design process.

```
Says                            | Thinks
                                |
    Enter guess                 |   How long is word?
                                |
                                |
                                |
                                |
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
    Checks for letter in word   |
                                |
                                |
                                |
                                |
                                |
                                |
                                |
                                |
                                |
```

### Resources

list of words provided by infochimps and converted to a text file.
The project for the text file is available [here](https://github.com/dwyl/english-words.git).
