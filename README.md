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
                                |
_____________________________A User_________________________
Does                            | Feels
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
                                |
                                |
```

### Resources

list of words provided by infochimps and converted to a text file.
The project for the text file is available [here](https://github.com/dwyl/english-words.git).
