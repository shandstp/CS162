/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include "Movie.h"

Movie::Movie(){}

Movie::Movie(string theTitle, int numberActors){
    title = theTitle;
    actors = new Actor*[numberActors];
    numActors = 0;
    maxActors = numberActors;
}

Movie::~Movie(){
    delete [] actors;
}

void Movie::print() const{
    cout << title << " ";
    for(int i = 0; i < numActors; i++){
        cout << actors[i]->getInfo() << " ";
    }
    cout << endl;
}

void Movie::addActor(Actor* person){
    actors[numActors] = person;
    ++numActors;
}
