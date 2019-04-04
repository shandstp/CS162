/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

#include "ChainableComponent.h"

class Output : public ChainableComponent{

public:

    /**
    * @brief Constructs an ouput component
    * @param outputName Defines the ouput name
    */
Output(std::string outputName);

    /**
    * @brief Reports the current ouput value
    * @return Returns true or false to indicate on or off
    */
bool getOutput() const;

};

#endif // OUTPUT_H
