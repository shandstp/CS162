/**
 * @brief Assignment 3 Problem 1
 * @author Travis Shands
 */

#include <iostream>
#include <string>
using namespace std;

#include "Page.h"

Page::Page(){
    url = "";
    visits = 0;
    usedLinks = 0;
    for(int i = 0; i < 3; i++){
        links[i] = nullptr;
    }
}

Page::Page(string newUrl){
    url = newUrl;
    visits = 0;
    usedLinks = 0;
    for(int i = 0; i < 3; i++){
        links[i] = nullptr;
    }
}

string Page::getURL() const{
    return url;
}

int Page::getNumLinks() const {
    return usedLinks;
}

Page* Page::getRandomLink() const{
    Page* randLink;
    int linkNumber = rand() % usedLinks;
    if(usedLinks < 1){
        randLink = nullptr;
    }
    else if(usedLinks >= 1){
        randLink = links[linkNumber];
    }

    return randLink;
}

void Page::addLink(Page *other){
    links[usedLinks] = other;
    usedLinks++;
}

void Page::visit(){
    visits++;
}

int Page::getNumVisits() const{
    return visits;
}
