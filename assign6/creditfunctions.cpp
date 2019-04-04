/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include "creditfunctions.h"

using namespace std;

int charToInt(char digit)
{
    int int_value = digit - 48;
    return int_value;
}

int doubleDigitValue(int number)
{
    number = number + number;
    if(number > 9)
    {
        int first_digit = number / 10;
        int second_digit = number % 10;
        number = first_digit + second_digit;
    }
    return number;
}

int sumOfDigits(const string& cardNumber)
{
    int size = static_cast<int>(cardNumber.length());
    int single_number;
    int sum = 0;
    int j = 1;
    for(int i = size; i > 0; i--)
    {
        single_number = charToInt(cardNumber.at(i - 1));
        if(j == 2)
        {
            single_number = doubleDigitValue(single_number);
            j = 0;
        }
        sum = sum + single_number;
        ++j;
    }
    return sum;
}

bool isValid(const string& cardNumber)
{
    if(sumOfDigits(cardNumber) % 10 == 0)
        return true;
    else return false;
}

string getCardType(const string& cardNumber)
{
    string type;
    int first_digit = charToInt(cardNumber.at(0));
    int second_digit = charToInt(cardNumber.at(1));

    if(first_digit == 4)
    {
        type = "Visa";
    }
    else if(first_digit == 5)
    {
        type = "MasterCard";
    }
    else if(first_digit == 3 && (second_digit == 4 || second_digit == 7))
    {
        type = "American Express";
    }
    else type = "unkown issuer";
    return type;

}
