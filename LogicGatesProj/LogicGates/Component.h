/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component{
private:
    std::string label;
public:

    /**
     * @brief Provides a framework for the construction of various components
     * @param conponentLabel Provides an interface by which derived components may be labeled
     */
    Component(std::string conponentLabel);

    /**
     * @brief Pure virtual function which allows derived components to receive input from their chained components
     * @return returns input received from chained component
     */
    virtual bool getOutput() const = 0;

    /**
     * @brief Prints componenet label and input information in a predefined format
     * @param padding provides the string "---" for formating purposes
     */
    virtual void prettyPrint(std::string padding);
};

#endif // COMPONENT_H
