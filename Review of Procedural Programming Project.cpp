// RoShamBo Subproject

#include <iostream>
#include <random>
using namespace std;

int userChoiceCheck(int& x);
int victoryCheck(int x, int y);
void scoreUpdate(int x);


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>  dist(1, 3);   //RNG Establishment. Kept separate to prevent hyper-establishment

    int roShamBoChoice = 0;
    cout << "Hello! Ready to Ro, Sham, and Bo?(1 for Rock, 2 for Paper, 3 for Scissors, 4 to end the game)\n";

    do {
        userChoiceCheck(roShamBoChoice);
        int botChoice = dist(gen);  //Random Number, Move to Function
        if (roShamBoChoice != 4) {
            cout << victoryCheck(botChoice, roShamBoChoice) << endl;    //This couts the 0, 1, and 2 you're seeing, doofus. Don't forget
        }
    } while (roShamBoChoice != 4);

    cout << "GAME OVER!" << endl;
    return 0;
}

int userChoiceCheck(int& x) {
    do {
        cout << endl;
        cout << "Your Pick: ";
        cin >> x;
    } while (x > 4 || x<1);
    return x;
}

int victoryCheck(int x, int y) {  // Checks the User and the Bots choices, and returns 0 for Draw, 1 for Bot Win, and 2 for user win
    if (y == 4) {
        //Ends victoryCheck if you ended the game
    }
    else {
        if (x == y) {
            cout << "Draw! You both chose the same!" << endl;
            return 0;
        }
        if (x == 1 && y == 2) {
            cout << "You chose Paper, RoShamBot chose Rock! You Win!" << endl;
            return 2;
        }
        if (x == 1 && y == 3) {
            cout << "You chose Scissors, RoShamBot chose Rock! RoShamBot Wins!" << endl;
            return 1;
        }
        if (x == 2 && y == 1) {
            cout << "You chose Rock, RoShamBot chose Paper! RoShamBot Wins!" << endl;
            return 1;
        }
        if (x == 2 && y == 3) {
            cout << "You chose Scissors, RoShamBot chose Paper! You Win!" << endl;
            return 2;
        }
        if (x == 3 && y == 1) {
            cout << "You chose Rock, RoShamBot chose Scissors! You Win!" << endl;
            return 2;
        }
        if (x == 3 && y == 2) {
            cout << "You chose Paper, RoShamBot chose Scissors! RoShamBot Wins!" << endl;
            return 1;
        }

    }
}