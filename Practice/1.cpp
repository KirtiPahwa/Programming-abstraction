#include <iostream>
using namespace std;

int main()
{
    int _TV = 400;
    int _VCR = 220;
    int _remote = 35.20;
    int _CD_player = 300;
    int _tape_recorder = 150;

    int TV;
    int VCR;
    int remote;
    int CD_player;
    int tape_recorder;

    cout << "How many TV's are sold" << endl;
    cin >> TV;
    cout << "How many VC RS were sold?" << endl;
    cin >> VCR;
    cout << "How many remote controllers were sold?" << endl;
    cin >> remote;
    cout << "How many CDs were sold? " << endl;
    cin >> CD_player;
    cout << "HOw many tape_recorder were sold?" << endl;
    cin >> tape_recorder;

    int a1 = (TV * (_TV));
    int a2 = (VCR * (_VCR));
    int a3 = (remote * _remote);
    int a4 = (CD_player * (_CD_player));
    int a5 = (tape_recorder * (_tape_recorder));
    cout << "TV " << a1 << endl;
    cout << "VCR " << a2 << endl;
    cout << "Remote " << a3 << endl;
    cout << "CD_player " << a4 << endl;
    cout << "tape_recorder " << a5 << endl;
    int subtotal = a1 + a2 + a3 + a4 + a5;
    cout << "Subtotal" << subtotal << endl;
    float ans = subtotal * 8.25 / 100;
    cout << "Total amount" << ans << endl;

    return 0;
}