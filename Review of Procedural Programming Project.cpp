// RoShamBo Subproject

#include <iostream>
#include <random>
using namespace std;

int userChoiceCheck(int& x); //Validates the User's choice and if it fell within acceptable bounds
int victoryCheck(int x, int y); //Compares the User and RoShamBot choices, picking out a winner
void scoreUpdate(int x, int& y, int& z); //Updates the score of the User or RoShamBot, depending on who won
void declareVictory(int x, int y); //Compares the User and RoShamBot scores and declares a victory


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>  dist(1, 3);   //RNG Establishment. Kept separate to prevent hyper-establishment

    int roShamBoChoice = 0, userScore = 0, roShamBotScore = 0;
    cout << "Hello! Ready to Ro, Sham, and Bo?(1 for Rock, 2 for Paper, 3 for Scissors, 4 to end the game)\n";

    do {
        userChoiceCheck(roShamBoChoice);
        int botChoice = dist(gen);  //Random Number Generator
        if (roShamBoChoice != 4) {
            scoreUpdate(victoryCheck(botChoice, roShamBoChoice), roShamBotScore, userScore);
        }
    } while (roShamBoChoice != 4);

    cout << endl;
    cout << "GAME OVER!" << endl;
    declareVictory(userScore, roShamBotScore);
    return 0;
}

void declareVictory(int x, int y) {
    cout << "User Score: " << x << "       RoShamBot Score: " << y << endl;
    if (x > y) {
        cout << "You have Won! Congrats!" << endl;
    }
    else if (x < y) {
        cout << "RoShamBot has Won! Congrats?" << endl;
    }
    else {
        cout << "There is a draw? Yay?" << endl;
    }
}

void scoreUpdate(int x, int& y, int& z) {
    if (x == 0) {
        //Do nothing
    }
    else if (x == 1){
        ++y;
    }
    else {
        ++z;
    }
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
        return 3;
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
    return 3;
}