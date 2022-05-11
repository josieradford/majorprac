#ifndef PERSON_H
#define PERSON_H

#include "Player.h"
#include <string>
using namespace std;

class Person : protected Player{ //protected carries over everything but private
    private:
    //records whether the current turn is a final accusation
    bool finalAccusation;

    //count how many guesses the player has made
    int guessCount;
        
    public:
        // virtual make accusation function
        void makeAccusation(int maxGuesses); 

        // virtual change location function
        void changeLocation();
       


};
#endif