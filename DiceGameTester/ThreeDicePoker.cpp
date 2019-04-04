#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include "ThreeDicePoker.h"

ThreeDicePoker::ThreeDicePoker(){}

int ThreeDicePoker::getDieValue(int dieNumber){
    return dice[dieNumber].getValue();
}

void ThreeDicePoker::rollDie(int number){
    dice[number].setValue(rand() % 6 + 1);
}

void ThreeDicePoker::rollAll(){
    for(int i = 0; i < 3; i++){
        dice[i].setValue(rand() % 6 + 1);
    }
}

void ThreeDicePoker::setDie(int dieNumber, int value){
    dice[dieNumber].setValue(value);
}

int ThreeDicePoker::getScore(){
    std::vector<int> sorted;
    for(int i = 0; i < 3; i++){
        sorted.push_back(dice[i].getValue());
    }
    std::sort(sorted.begin(), sorted.begin() + 3);

    if(sorted.at(0) == sorted.at(1) && sorted.at(1) == sorted.at(2)){
        return 1000;
    }
    else if(sorted.at(0) + 1 == sorted.at(1) && sorted.at(1) + 1 == sorted.at(2)){
        return 400;
    }
    else if(sorted.at(0) == sorted.at(1) && sorted.at(1) != sorted.at(2)){
        return sorted.at(1) * 40;
    }
    else if(sorted.at(0) == sorted.at(2) && sorted.at(2) != sorted.at(1)){
        return sorted.at(2) * 40;
    }
    else if(sorted.at(1) == sorted.at(2) && sorted.at(2) != sorted.at(0)){
        return sorted.at(2) * 40;
    }
    else if(sorted.at(0) != sorted.at(1) && sorted.at(1) != sorted.at(2)){
        return sorted.at(2) * 10;
    }
    return 0;
}
