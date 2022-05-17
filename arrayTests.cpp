#include <iostream>
#include <string>

using namespace std;
//TRYING TO CODE A MAP GRAPHIC

int main(){
    int numRooms = 0;
    int numRows = 0;
    int numCols = 0;
    char *map;
    
    cin >> numRooms;
    
    switch (numRooms){
        case 1:
            //char map[7][14] = {0};
            numCols = 14;
            numRows = 7;            
            
            map = new char[numCols*numRows];
            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map[row+col] = '#';
                    } else {
                        map[row+col] = ' ';
                    }
                }
            }
        break;            

        case 2:
            //char map[7][27] = {0};
            numRows =7;
            numCols = 27;

            map = new char[numCols*numRows];
            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( col == 13 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map[row+col] = '#';
                    } else {
                        map[row+col] = ' ';
                    }
                }
            }
            break;

        case 3:
            //char map[7][40] = {0};
            numCols = 40;
            numRows = 7;

            map = new char[numCols*numRows];
            for(int row = 0; row < numRows; row++){
                //frame
                for(int col = 0; col < numCols; col++){
                    if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map[row+col] = '#';
                    } else {
                        map[row+col] = ' ';
                    }

                }
            }
            break;

        case 4:
            numRows = 13;
            numCols = 27;
            //char map[13][27] = {0};

            map = new char[numCols*numRows];
            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){
                    if ( row == 6 ||col == 26 || col == 13 || row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map[row+col] = '#';
                    } else {
                        map[row+col] = ' ';
                     }
            

                }
            }
            break;
        
        case 5:
            break;
        


    }

    
    /*
   numRows = 15;
    numCols = 33;
    char map2[14][33] = {0};

            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){

                    //external frame
                    if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map2[row][col] = '#';
                        //internal frame
                    } else if (row == 6 && col <= 6 || row == 6 && col ){
                        map2[row][col] = ' ';
                     }
            

                }
            }


        char map[7][14] = {0};
        numCols = 14;
        numRows = 7;
    
*/

    //print map
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            cout << map[row+col];
        }
        cout << endl;
    }
    
    delete[] map;
}