/**
  * @brief Assignment 3 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include <iomanip>

using namespace std;

#include "Page.h"

int main()
{
   Page page1("http://page1");
   Page page2("http://page2");
   Page page3("http://page3");
   Page page4("http://page4");

    page1.addLink(&page2);
    page1.addLink(&page3);

    page2.addLink(&page3);

    page3.addLink(&page1);

    page4.addLink(&page1);
    page4.addLink(&page3);

   Page *currentPage = &page1;
   int chance;
   for(int i = 0; i < 10000; i++){
       chance = rand() % 100 + 1;
       if(chance <= 15){
           int newPage = rand() % 4 + 1;
           if(newPage == 1){
               currentPage = &page1;
           }
           else if(newPage == 2){
               currentPage = &page2;
           }
           else if(newPage == 3){
               currentPage = &page3;
           }
           else if(newPage == 4){
               currentPage = &page4;
           }
       }
       else if(chance >= 16){
           currentPage = currentPage->getRandomLink();
       }
       currentPage->visit();
   }

   double pg1percent = page1.getNumVisits();
   double pg2percent = page2.getNumVisits();
   double pg3percent = page3.getNumVisits();
   double pg4percent = page4.getNumVisits();

  cout << fixed << setprecision(2) << "page1" << " " << pg1percent / 100 << endl;
  cout << fixed << setprecision(2) <<  "page2" << " " << pg2percent / 100 << endl;
  cout << fixed << setprecision(2) <<  "page3" << " " << pg3percent / 100 << endl;
  cout << fixed << setprecision(2) <<  "page4" << " " << pg4percent / 100 << endl;
}
