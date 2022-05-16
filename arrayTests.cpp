#include <iostream>
#include <string>

using namespace std;
//TRYING TO CODE A MAP GRAPHIC

int main(){
    int numRooms = 1;
    int numRows =7;
    int numCols = 14;
    //char *map;

/*
    
    switch (numRooms){
        case 1:
            //char map[7][14] = {0};
            numCols = 14;
            numRows = 7;
            break;

        case 2:
            //char map2[7][27] = {0};
            numRows =7;
            numCols = 27;
            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( col == 13 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map2[row][col] = '#';
                    } else {
                        map2[row][col] = ' ';
                    }
                }
            }
            break;

        case 3:
            //char map2[7][40] = {0};
            numCols = 40;
            numRows = 7;
            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( col == 26 || col == 13 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map2[row][col] = '#';
                    } else {
                    map2[row][col] = ' ';
                    }

                }
            }
            break;

        case 4:
            numRows = 13;
            numCols = 27;
            //char map2[13][27] = {0};

            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( row == 6 ||col == 26 || col == 13 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map2[row][col] = '#';
                    } else {
                        map2[row][col] = ' ';
                     }
            

                }
            }
            break;
        
        case 5:
        


    }
    */
    

   numRows = 15;
    numCols = 33;
    char map2[14][33] = {0};

            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( row == 6 ||col == 12 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map2[row][col] = '#';
                    } else {
                        map2[row][col] = ' ';
                     }
            

                }
            }

 


    //print map
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            cout << map2[row][col];
        }
        cout << endl;
    }
    

}