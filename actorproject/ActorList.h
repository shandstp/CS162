/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#ifndef ACTORLIST_H
#define ACTORLIST_H

#include "Actor.h"

class ActorList
{
public:
    /**
     * @brief Creates list of actors by reading in text file
     */
    ActorList();

    /**
     * @brief Creates a list of actors by performing a deep copy of another list of actors
     * @param otherList Defines the list of actors to be copied
     */
    ActorList(const ActorList& otherList);

    /**
     * @brief Retrieves the address of an actor, indicated by index number
     * @param n Defines the index number to be used
     * @return Returns the address of the specified actor
     */
    Actor* getActorByIndex(int n) const;

    /**
     * @brief Destroys arrays on the heap which are no longer needed
     */

    ~ActorList();


private:
    int numActors;
    Actor *actors;
};

#endif // ACTORLIST_H
