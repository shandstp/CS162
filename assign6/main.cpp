/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include "creditfunctions.h"

using namespace std;

/**
 * @brief Prompts user to input credit card number and retrives input from the console
 * @param prompt takes in a string as a parameter
 * @return returns input from the console as a string
 */

string getInput(const string& prompt)
{
    cout << prompt;
    string input;
    cin >> input ;
    return input;
}

int main()
{
    string card_number = getInput("Enter card number: ");
    bool validity = isValid(card_number);
    string card_type = getCardType(card_number);

    if(validity == true)
        cout << "Valid number, ";
    else cout << "Not a valid number, ";

    cout << card_type << endl;

    return 0;
}
