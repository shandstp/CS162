/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef INPUT_H
#define INPUT_H

#include"Component.h"

class Input : public Component{
private:
    bool value;
public:

    /**
     * @brief Constructs an input component
     * @param inputName Defines the name of the input to be constructed
     */
    Input(std::string inputName);

    /**
     * @brief Sets the input to either on or off
     * @param newValue Used to set input value by passing a true or false value
     */
    void setValue(bool newValue);

    /**
     * @brief Returns the input value as an Output value
     * @return Returns true or false to indicate and output on or off
     */
    bool getOutput() const;
};

#endif // INPUT_H
