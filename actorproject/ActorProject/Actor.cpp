/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include "Actor.h"

#include <sstream>

Actor::Actor()
{
    firstName = "?";
    lastName = "?";
    birthYear = 0;
}


Actor::Actor(const string& fName, const string& lName, int bYear)
{
    firstName = fName;
    lastName = lName;
    birthYear = bYear;
}

Actor::~Actor(){
}

void Actor::setFirstName(const string& newName) {
    firstName = newName;
}

string Actor::getInfo() const {
    //use stringstream to build up output
    stringstream ss("");
    ss << lastName << ", " << firstName << " (" << birthYear << ")";
    return ss.str();  //convert to string to return
}
