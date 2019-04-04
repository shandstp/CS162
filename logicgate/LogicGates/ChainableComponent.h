/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef CHAINABLECOMPONENT_H
#define CHAINABLECOMPONENT_H

#include "Component.h"

class ChainableComponent : public Component{
protected:
    Component* input;
public:

    /**
     * @brief Constructs a component that can be chained together with other components
     * @param ComponentLabel defines a label to be used for the given component
     */
    ChainableComponent(std::string ComponentLabel);

    /**
     * @brief Retrives inpunt from the next component in the chain
     * @param inputLink sets the address of the next component in the chain
     */
    void setInput(Component* inputLink);

    /**
     * @brief Prints componenet label and input information in a predefined format
     * @param padding provides the string "---" for formating purposes
     */
    void prettyPrint(std::string padding);
};

#endif // CHAINABLECOMPONENT_H
