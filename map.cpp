#include <iostream>

using namespace std;

int main(){


    int numRows = 16;
    int numCols = 34;
    char map[15][33] = {0};

            for(int row = 0; row < numRows; row++){
                for(int col = 0; col < numCols; col++){

                    //external frame
                    if (row == 0 || col == 0 || col == numCols-1 || row == numRows-1 ){
                        map[row][col] = '#';
                        //internal frame
                    } else if ((row == 5 || row == 10) && (col >= 11 && col <= 22)){
                        map[row][col] = '#';
                    }else if ((col == 11 || col == 22) && (row >= 5 && row <= 10)){
                        map[row][col] = '#';
                    }else if ((col == 17) && (row <= 5 || row >= 10)){
                        map[row][col] = '#';
                    }else if ((row == 8) && (col <= 11 || col >= 22)){
                        map[row][col] = '#';
                    }else{
                        map[row][col] = ' ';
                    }
                    
                    /* else if (row == 6 && col <= 6 || row == 6 && col ){
                        map[row][col] = ' ';
                     } */
            

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