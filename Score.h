#include <string>
using namespace std;

class ScoreClass
{
public:
    // default constructor
    ScoreClass();
    // constructor with parameters
    ScoreClass(string getName, int getScore)
    {
        name = getName;
        score = getScore;
    };
    int getScore() { return score; };
    string getUsername() { return name; };

private:
    string name;
    int score;
};