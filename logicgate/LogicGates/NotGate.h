/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef NOTGATE_H
#define NOTGATE_H

#include "ChainableComponent.h"

class NotGate : public ChainableComponent{
public:

    /**
     * @brief Constructs a component which simply reverses any input it receives
     */
    NotGate();

    /**
     * @brief Reports the current ouput value
     * @return Returns true or false to indicate on or off
     */
    bool getOutput() const;
};

#endif // NOTGATE_H
