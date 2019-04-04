#include <iostream>

using namespace std;

void printMap(char floor, int starRow, int startCol){
     for(int i = 0; i < starRow; i++){
         for(int j = 0; j < startCol; j++){
             cout << floor[i][j];
         }
     }
}

void contaminate(char floor[10][10], int startRow, int startCol){
    if(startRow < 0 || startCol < 0 || startRow >= 10 || startCol >= 10){
        return;
    }
    if(floor[startRow][startCol] != ' '){
        return;
    }
    floor[startRow][startCol] = '.';

    //printMap(floor, 10, 10);

    contaminate (floor, startRow, startCol-1);
    contaminate (floor, startRow, startCol+1);
    contaminate (floor, startRow-1, startCol);
    contaminate (floor, startRow+1, startCol);
}

int main()
{
    char floor[10][10] = {' '};

    //printMap(floor, 10, 10);

    cout << "Enter row & col with space between:" << endl;
    int row = 0;
    int col = 0;
    cin >> row >> col;
    contaminate(floor, row, col);

    return 0;
}
