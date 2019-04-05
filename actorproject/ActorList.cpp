/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include "ActorList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

ActorList::ActorList(){
    ifstream myfile("actors.txt");
    if(!myfile.is_open()){
        cout << "Cannot open file!";
        exit(0);
    }
        myfile >> numActors;
        //shared_ptr<Actor> Actor (new actors);
        actors = new Actor[numActors];

        for(int i = 0; i < numActors; i++){
            string lastName;
            string firstName;
            int birthYear;
            myfile >> lastName >> firstName >> birthYear;

            actors[i] = Actor(lastName, firstName, birthYear);
        }
        if(!myfile.good()){
            cout << "Cannot read file!!";
        }
        myfile.close();
}

ActorList::ActorList(const ActorList& otherList){
    numActors = otherList.numActors;
    actors = new Actor[otherList.numActors];
    for(int i = 0; i < otherList.numActors; i++){
        actors[i] = otherList.actors[i];
    }
}

Actor* ActorList::getActorByIndex(int n) const{
    return &actors[n];
}

ActorList::~ActorList(){
    delete [] actors;
}
