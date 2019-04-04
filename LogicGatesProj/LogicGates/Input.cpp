/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <string>

using namespace std;

#include "Input.h"


Input::Input(string inputName)
    :Component(inputName){}

void Input::setValue(bool newValue){
    value = newValue;
}

bool Input::getOutput() const{
    return value;
}
