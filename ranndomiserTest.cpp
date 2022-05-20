#include <iostream>
#include <time.h>
#include <string>

using namespace std;


int main(){
    srand ( time(NULL) );
    string RoomSet[5] = {"Garden", "Ballroom", "Library", "Conservatory", "Kitchen"};
    int RandIndex = rand() % 5; //Generates random number between 0 and 4



    cout << RoomSet[RandIndex];




    return 0;
}