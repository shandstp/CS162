/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <string>

using namespace std;

#include "ChainableComponent.h"

ChainableComponent::ChainableComponent(string ComponentLabel)
    :Component(ComponentLabel){}

void ChainableComponent::setInput(Component* inputLink){
    input = inputLink;
}

void ChainableComponent::prettyPrint(string padding){
    Component::prettyPrint(padding);
    if(input != nullptr){
        input->prettyPrint(padding + "---");
    }
}
