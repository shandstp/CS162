/**
  * @brief Assignment 8 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

stringstream input ;

struct storageUnit{
    int x;
    int y;
};

/**
 * @brief Constructs a wall for mitigating the spread of radiation
 * @param floor The array on which the wall is built
 * @param x Indicates the source of the radiation
 * @param y Indicates the source of the radiation
 */
void buildWall(char floor[10][10], int x, int y){
    if(x == 0 && y == 0){
        return;
    }
    if(floor[x][y] != '+'){
        cout << "Cannot place a wall here, location is already in use or does not exist" << endl;
        cin >> x >> y;
        buildWall(floor, x, y);
    }
    else {
        floor[x][y] = '/';
        cin >> x >> y;
        buildWall(floor, x, y);
    }
}

/**
 * @brief Constructs a map through which radiation is spreading
 * @param floor The array on which everything else is based
 * @param x Indicates the source of the radiation
 * @param y Indicates the source of the radiation
 */
void buildMap(char floor[10][10], int& x, int& y){
    for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
           floor[i][j] = '+';
       }
    }
    floor[x][y] = 'U';

    cout << "Enter wall locations (x y), followed by 0 0 to indicate end of input: " << endl;
    int startX, startY;
    cin >> startX >> startY;
    buildWall(floor, startX, startY);
}

/**
 * @brief printMap Prints the current map
 * @param floor The array on which everything else is based
 */
void printMap(char floor[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << floor[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Determines the spread of radiation throughout the map
 * @param floor The array on which everything else is based
 * @param startX Indicates the source of the radiation
 * @param startY Indicates the source of the radiation
 * @param count Counts the number of spaces that are irradiated
 * @return Returns the number of spaces that are irradiated
 */
int contaminate(char floor[10][10], int startX, int startY, int &count){
    if(startX < 0 || startY < 0 || startX >= 10 || startY >= 10){
        return 0;
    }
    if(floor[startX][startY] == 'U'){
        floor[startX][startY] = '+';
    }
    if(floor[startX][startY] != '+'){
        return 0;
    }

    else {
    floor[startX][startY] = 'C';
    count++;
    //printMap(floor);
    cout << endl;

    contaminate(floor, startX, startY - 1, count);
    contaminate(floor, startX, startY + 1, count);
    contaminate(floor, startX - 1, startY, count);
    contaminate(floor, startX + 1, startY, count);

    contaminate(floor, startX - 1, startY - 1, count);
    contaminate(floor, startX - 1, startY + 1, count);
    contaminate(floor, startX + 1, startY - 1, count);
    contaminate(floor, startX + 1, startY + 1, count);

    }
    return count;
}

/**
 * @brief Determines if the area is safe for human occupation
 * @param floor The array on which everything is based
 * @param x Indicates the source of the radiation
 * @param y Indicates the source of the radiation
 * @param safe Returns true if the area outside the containment is safe
 * @return Returns true or false
 */
bool isSafe(char floor[10][10], int x, int y, bool &safe){
    if(x < 0 || y < 0 || x >= 10 || y >= 10){
        return safe;
    }
    if(floor[0][y] == 'C' || floor[x][0] == 'C' || floor[10][y] == 'C' || floor[x][10] == 'C'){
        safe = false;
    }
    else {
        isSafe(floor, x + 1, y, safe);
        isSafe(floor, x, y + 1, safe);
    }
    return safe;
}

int main()
{
    char floorMap[10][10] = {{0}};
    storageUnit unit;

    cout << "Enter contaminated location (x y): " << endl;
    cin >> unit.x >> unit.y;

    buildMap(floorMap, unit.x, unit.y);

    int count = 0;
    int contamination = contaminate(floorMap, unit.x, unit.y, count);
    printMap(floorMap);
    cout << "Contaminated area: " << contamination <<endl;


    bool safe = true;

    if(isSafe(floorMap, 0, 0, safe) == false){
        cout << "Not safe!" << endl;
    }
    else cout << "Safe!" << endl;



    return 0;
}
