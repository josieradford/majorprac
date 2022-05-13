#include <iostream>
#include <string>

using namespace std;

int main(){
    int numRooms = 1;
    int numCols = 14;
    int numRows = 7;
    //char *map;


    /*
    switch (numRooms){
        case 1:
            numCols = 14;
            numRows = 7;
            break;
    }
    */

    //map = new char[numRows*numCols];
    
    char map[14][7] = {0};

    //fill map
    //border

    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1){
                map[row][col] = '_';
            } else {
                map[row][col] = ' ';
            }
            

        }
    }
    

    //print map
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            cout << map[row][col];
        }
        cout << endl;
    }
    

}