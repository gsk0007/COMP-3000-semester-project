# COMP 3000 semester project

## Competitive terminal hangman

by Samuel Koser and Kennedy Edwards
 
### Description

Here is a project we developed as mini project in C++.
It is a competitive game of hangman that allows creation
of a user profile and top score tracking.


### Functions

```
class Player{
    public:
        randomWord() - chooses a random word from a file for player to guess

        checkGuess() - checks the letter that was guessed if it is in the word, then outputs the letter or an error based on guess

        getScore() - gets the score of the player

        getTime() - tracks the time the player takes to guess the word

        playGame() - allows user to start playing a game
    private:
        string username;
        int score;
        double time;
}

int hangman() 
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
