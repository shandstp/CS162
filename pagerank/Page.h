/**
  * @brief Assignment 3 Problem 1
  * @author Travis Shands
  */

#ifndef PAGE_H
#define PAGE_H

#include <string>

class Page{
private:
    std::string url;
    int visits;
    Page* links[3];
    int usedLinks;

public:

    /**
     * @brief Constructs a basic page with defaul parameters
     */
    Page();

    /**
     * @brief Construcsts a basic page with a URL define at creation
     * @param urlValue
     */
    Page(std::string urlValue);

    /**
     * @brief Retrieves the URL of a given page
     * @return Returns a URL of the page
     */
    std::string getURL() const;

    /**
     * @brief Determines the number of links referenced on a given page
     * @return Returns the number links on the page
     */
    int getNumLinks() const;

    /**
     * @brief Randomly choses a link from those available on a given page
     * @return Returns the chosen page
     */
    Page* getRandomLink () const;

    /**
     * @brief Adds a given link to the next available slot in a page's link list
     * @param other Names the page that is to be added to the link list
     */
    void addLink(Page* other);

    /**
     * @brief "Visits" a given page and increments the counter accordingly
     */
    void visit();

    /**
     * @brief Determines the total number of times that a given page has been visited
     * @return Returns an integer representing the number of times the page has been visited
     */
    int getNumVisits() const;
};

#endif // PAGE_H
