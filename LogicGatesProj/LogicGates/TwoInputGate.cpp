/**
  * @brief Assignment 4 Problem 1
  * @author Travis Shands
  */

#include <string>
#include <cassert>

using namespace std;

#include "TwoInputGate.h"


TwoInputGate::TwoInputGate(LogicOperation gateOperator)
    :ChainableComponent(LOGIC_LABELS[gateOperator])
{
    gateType = gateOperator;
}

void TwoInputGate::setInput2(Component* inputLink){
    input2 = inputLink;
}

void TwoInputGate::prettyPrint(string padding){
    ChainableComponent::prettyPrint(padding);
    input2->prettyPrint(padding + "---");
}

bool TwoInputGate::getOutput() const{
    bool output;
    assert(input != nullptr || input2 != nullptr);
    if(gateType == AND){
        if(input->getOutput() == true && input2->getOutput() == true){
            output = true;
        }
        else output = false;
    }
    if(gateType == OR){
        if(input->getOutput() == true || input2->getOutput() == true){
            output = true;
        }
        else output = false;
    }
    if(gateType == XOR){
        if(input->getOutput() != input2->getOutput() &&
                (input->getOutput() == true || input2->getOutput() == true)){
            output = true;
        }
        else output = false;
    }

    return output;
}
