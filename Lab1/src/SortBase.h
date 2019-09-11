#ifndef SORTBASE_H
#define SORTBASE_H


#include <iostream>
#include <vector>

 class SortBase{

 public:
     virtual void Implement(std::vector<int>&) = 0;         // Same function for all sort method
 };


 #endif