/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#ifndef ACTOR_H
#define ACTOR_H

#include <string>
using namespace std;


class Actor
{
public:
    //Creates actor with name "?", "?" and birth year 0
    Actor();
    Actor(const string& fName, const string& lName, int bYear);
    ~Actor();

    void setFirstName(const string& newName);

    //Returns string containing info about this actor
    string getInfo() const;

private:
    string firstName;
    string lastName;
    int birthYear;
};

#endif // ACTOR_H
