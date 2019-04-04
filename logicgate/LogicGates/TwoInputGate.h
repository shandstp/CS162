/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H

#include <string>

#include "ChainableComponent.h"


//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};


class TwoInputGate : public ChainableComponent{
private:
    LogicOperation gateType;
    Component* input2;
public:

    /**
     * @brief Constructs components which can receive two inputs
     * @param gateOperator Defines the component as an AND, OR, or XOR gate
     */
    TwoInputGate(LogicOperation gateOperator);

    /**
     * @brief Creates a second input to be used with the two input gate
     * @param Sets the input on or off
     */
    void setInput2(Component* inputLink);

    /**
     * @brief Prints componenet label and input information in a predefined format
     * @param padding provides the string "---" for formating purposes
     */
    void prettyPrint(std::string padding);

    /**
    * @brief Reports the current ouput value
    * @return Returns true or false to indicate on or off
    */
    bool getOutput() const;
};


#endif // TWOINPUTGATE_H
