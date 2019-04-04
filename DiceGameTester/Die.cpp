#include <random>
#include <ctime>
#include "Die.h"

Die::Die(){
    numSides = 6;
    value = rand() % 6 + 1;
}

Die::Die(int number){
    numSides = number;
    value = rand() % number + 1;
}

void Die::setValue(int forceValue){
    value = forceValue;
}

int Die::getValue(){
    return value;
}

void Die::roll(){
    value = rand() % numSides + 1;
}
