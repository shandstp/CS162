/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <string>
#include <cassert>

using namespace std;

#include "NotGate.h"



NotGate::NotGate()
    :ChainableComponent("NOT"){}

bool NotGate::getOutput() const {
    bool output;
    assert(input != nullptr);
    if(input->getOutput() == true){
        output = false;
    }
    else if(input->getOutput() == false){
        output = true;
    }
    return output;
}
