/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include <string>

using namespace std;

#include "Component.h"

Component::Component(string conponentLabel) {
    label = conponentLabel;
}
void Component::prettyPrint(string padding){
    cout << padding << label << " : " << getOutput() << endl;
}
