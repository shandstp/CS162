/**
  * @brief Assignment 6 Problem 1
  * @author Travis Shands
  */

#ifndef MOVIE_H
#define MOVIE_H

#include "Actor.h"

class Movie
{
public:

    /**
     * @brief Creates a basic movie object
     */
    Movie();

    /**
     * @brief Creates movie object using the inputs given
     * @param theTitle Defines the title of the movie
     * @param numberActors Defines the number of actors who play in the movie
     */
    Movie(string theTitle, int numberActors);

    /**
     * @brief Destroys arrays on the heap which are no longer needed
     */
    ~Movie();

    /**
     * @brief Prints the title of a given movie and the names of its actors
     */
    void print() const;

    /**
     * @brief Adds and actor object to the next available spot in the movie's actor array
     * @param person Names the actor to be added
     */
    void addActor(Actor* person);

private:
    string title;
    Actor** actors;
    int numActors;
    int maxActors;
};

#endif // MOVIE_H
