#include <iostream>

using namespace std;
class Player
{
public:
    string name;
    int matchCount;
    int wins;
    int loose;
    Player()
    {
        cout << "Default constructor of Player" << endl;
    }
    float playerRating()
    {
        float rating = (wins / (float)matchCount) * 100;
        return rating;
    }
    void display()
    {
        cout << "Players name is: " << name << " matchCount: " << matchCount << " wins : " << wins << " loose: " << loose << endl;
    }
};
class batsman : public Player
{
public:
    int innings;
    int not_outs;
    int runs;
    batsman()
    {
        cout << "Default constructor of batsman" << endl;
    }
    float average()
    {
        float res = (float)runs / (innings - not_outs);
        return res;
    }
};
class Bowler : public Player
{
public:
    int over;
    int wider;
    int no_ball;
    Bowler()
    {
        cout << "Default constructor of bowler" << endl;
    }
    void display2()
    {
        cout << "Bowler over " << over << " wider " << wider << endl;
    }
};

int main()
{
    Bowler obj1;
    obj1.name = "Sachin";
    obj1.display2();

    return 0;
}