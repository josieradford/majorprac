#ifndef PERSON_H
#define PERSON_H

#include "Player.h"
#include <string>
using namespace std;

class Person : protected Player{ //protected carries over everything but private
    private:
        
    public:
        // virtual make accusation function
        void makeAccusation(string Weapon, string Murderer, string Location); 

        // virtual change location function
        void changeLocation(string Location);
       


};
#endif