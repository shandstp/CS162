/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <string>

using namespace std;

#include "Output.h"

Output::Output(string outputName)
    :ChainableComponent(outputName){}

bool Output::getOutput() const{
    return input->getOutput();
}
