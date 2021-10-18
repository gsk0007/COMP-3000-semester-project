# COMP 3000 semester project

## Competitive terminal hangman

by Samuel Koser and Kennedy Edwards

### Description

Here is a project we developed as mini project in C++.
It is a competitive game of hangman that allows creation
of a user profile and top score tracking. Along with single
player, the game offers a competitive mode where players can
take turns guessing the same word.

### Functions

```
class Player{
    public:
        randomWord() - chooses a random word from a file for player to guess

        checkGuess() - checks the letter that was guessed if it is in the word, then outputs the letter or an error based on guess

        trackLetters() - keeps tracks of letters guessed, then outputs a list of remaining letters

        getScore() - gets the score of the player

        getTime() - tracks the time the player takes to guess the word
    private:
        string username;
        int score;
        double time;
}
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
    I want to play a game with  |   What is the word?
    a friend                    |
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
    Chooses between singleplayer|   took to solve the word
    and multiplayer             |
                                |
                                |
                                |
                                |
```

### Resources

A list of words provided by infochimps and converted to a text file.
The project for the text file is available [here](https://github.com/dwyl/english-words.git).
