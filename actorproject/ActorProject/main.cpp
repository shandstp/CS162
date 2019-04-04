/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#include <iostream>

#include "Movie.h"
#include "ActorList.h"

using namespace std;

int main()
{
    //Load our master list of actors
    ActorList mainActorList;

    //Do stuff...

    Movie movie1("Space Wars", 3);
    Movie movie2("The Breakup", 2);

    movie1.addActor(mainActorList.getActorByIndex(1));
    movie1.addActor(mainActorList.getActorByIndex(2));
    movie1.addActor(mainActorList.getActorByIndex(3));
    movie2.addActor(mainActorList.getActorByIndex(0));
    movie2.addActor(mainActorList.getActorByIndex(2));

    movie1.print();
    movie2.print();

    mainActorList.getActorByIndex(2)->setFirstName("Voltron");

    movie1.print();
    movie2.print();

    ActorList newActorList = mainActorList;

    newActorList.getActorByIndex(0)->setFirstName("Goku");

    cout << newActorList.getActorByIndex(0)->getInfo() << endl;
    cout << mainActorList.getActorByIndex(0)->getInfo() << endl;


    return 0;
}

