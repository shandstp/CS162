/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#ifndef CREDITFUNCTIONS_H
#define CREDITFUNCTIONS_H

using namespace std;

/**
 * @brief turns a char like '1' into the number it represents (1).
 * @param digit character to be converted to an integer.
 * @return the integer that is represented by the digit character.
 */

int charToInt(char digit);

/**
 * @brief takes in a number and doubles its value according to the rule for a doubled digit in the Luhn algorithm.
 * @param number the value that is to be doubled.
 * @return the doubled value of number or the sum of its digits.
 */

int doubleDigitValue(int number);

/**
 * @brief takes in a credit card number and returns its sum according to the Luhn algorithm.
 * @param cardNumber the credit card number that is to procressed according to the Luhn algorithm.
 * @return the sum of the credit card number according to the Luhn algorithm.
 */

int sumOfDigits(const string& cardNumber);

/**
 * @brief returns a true or false value indicating if the card number is potentially valid according to the Luhn algorithm.
 * @param cardNumber the credit card number to be evaluated for validity.
 * @return true or false according to the rules of the Luhn algorithm.
 */

bool isValid(const string& cardNumber);

/**
 * @brief returns a string indicating whether the card number is a Visa, MasterCard, American Express, or Unknown.
 * @param cardNumber
 * @return
 */

string getCardType(const string& cardNumber);

#endif // CREDITFUNCTIONS_H
