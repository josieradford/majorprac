#ifndef PERSON_H
#define PERSON_H

#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Person : public Player{ //protected carries over everything but private
    private:
    //records whether the current turn is a final accusation
    bool finalAccusation;
    //count how many guesses the player has made
    int guessCount;
    int maxGuesses;

    public:
    Person();
    Person(int _maxGuesses); //uses to initialise maxGuesses

    void makeAccusation(); //virtual from Player.h

    void changeLocation(); //virtual from Player.h
    void setDifficulty();

    string * getAccusation();
    int getDifficulty();
    
    ~Person();
};
#endif