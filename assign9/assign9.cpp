/**
  * @brief Assignment 9 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const int NUM_GAMES = 10;
const int NUM_STATS = 5;
const int NUM_PLAYERS = 3;

enum catgeory{COMP, ATT, YARDS, TD, INT};

struct Name{string first; string last;};
struct Players{Name name; int scores[NUM_GAMES][NUM_STATS];};

/**
 * @brief Reads player name and stats from file and store them in a struct
 * @param record passes an empty struct into the function
 */
void readPlayerStats(Players record[NUM_PLAYERS]) {
    ifstream myfile;
    myfile.open ("QBInfo.txt");
    int numRecords;
    myfile >> numRecords;

    for(int i = 0; i < NUM_PLAYERS; i++){
            myfile >> record[i].name.first;
            myfile >> record[i].name.last;
            for(int j = 0; j < NUM_GAMES; j++){
                for(int k = 0; k < NUM_STATS; k++){
                    myfile >> record[i].scores[j][k];
                }
            }
    }
}

/**
 * @brief Reports the statistics of the chosen quarter back over a 10 game period
 * @param record passes the struct containing player information to the function
 * @param choice passes the users choice of quarter back to the function
 */
void printPlayerStats(Players record[], int choice){
        cout << record[choice].name.first << " ";
        cout << record[choice].name.last << endl;
        for(int i = 0; i < NUM_GAMES; i++){
            for(int j = 0; j < NUM_STATS; j++){
                cout << setw(12) << left << record[choice].scores[i][j];
            }
            cout << endl;
        }
    }
/**
 * @brief Reports the sum of the statistics for the chosen quarter back over a 10 game period
 * @param record passes the struct containing player information to the function
 * @param choice passes the users choice of quarter back to the function
 */
void printPlayerTotals(Players record[], int choice){
    int sum[NUM_STATS] = {0};
    int col = 0;
    cout << record[choice].name.first << " ";
    cout << record[choice].name.last << endl;
    while(col < NUM_STATS){
        for(int row = 0; row < NUM_GAMES; row++){
            sum[col] = sum[col] + record[choice].scores[row][col];
        }
        col++;
    }

    for(int k = 0; k < NUM_STATS; k++){
        cout << sum[k] << " ";
    }
    cout << endl;
}
/**
 * @brief Reports the passer rating for the chosen quarter back over a 10 game period
 * @param record passes the struct containing player information to the function
 * @param choice passes the users choice of quarter back to the function
 */
void printPasserRating(Players record[], int choice){
    int stats[NUM_STATS] = {0};
    int col = 0;
    cout << record[choice].name.first << " ";
    cout << record[choice].name.last << endl;
    while(col < NUM_STATS){
        for(int row = 0; row < NUM_GAMES; row++){
            stats[col] = stats[col] + record[choice].scores[row][col];
        }
        col++;
    }
    double a, b, c, d = 0;
    a = (stats[COMP] / stats[ATT] - 0.3) * 5;
    b = (stats[YARDS] / stats[ATT] - 3) * .25;
    c = (stats[TD] / stats[ATT]) * 20;
    d = 2.375 - ((stats[INT] / stats[ATT]) * 25);

    double passerRating = (a + b + c + d) / 0.06;

    cout << passerRating << endl;

    }

int main()
{

    Players player[NUM_PLAYERS];

    readPlayerStats(player);
    int choice = 0;
    int playerChoice = 0;

    do{
        cout << "1: Print Player" << endl << "2: Print Player Stats" << endl
        << "3: Print Passer Ratings" << endl << "4: Exit" << endl;

        cin >> choice;

        if(choice == 1){
            cout << "Please enter a player number between 1 and 3" << endl;
            cin >> playerChoice;
            printPlayerStats(player, playerChoice - 1);
        }
        else if(choice == 2){
            cout << "Please enter a player number between 1 and 3" << endl;
            cin >> playerChoice;
            printPlayerTotals(player, playerChoice - 1);
        }
        else if(choice == 3){
            cout << "Please enter a player number between 1 and 3" << endl;
            cin >> playerChoice;
            printPasserRating(player, playerChoice - 1);
        }

    }
    while(choice != 4);


    return 0;
}

