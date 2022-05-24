#ifndef Computer_H
#define Computer_H

#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

class Computer : public Player{ //protected carries over everything but private
    private:
    //records whether the current turn is a final accusation
    bool finalAccusation;
    //count how many guesses the player has made
    int guessCount;
    int maxGuesses;
    //determine difficulty level
    int difficulty;
    //string * compLastGuess;
    string * Accusation;

    bool cbool0, cbool1, cbool2, cbool3, cbool4;

    fstream file0;
    fstream file1;
    fstream file2;

    public:
    Computer();
    Computer(int _maxGuesses); //uses to initialise maxGuesses
    void makeAccusation(); //virtual from Player.h
    string * getAccusation(); // virtual from Player.h
    void changeLocation(); //virtual from Player.h

    // determine the level of difficulty
    void setDifficulty();
    int getDifficulty();
    //void DifficultyLevel(int difficulty);

    int randomNum();

    //~Computer();
};
#endif