#ifndef ALGORITHM_H
#define ALGORITHM_H



#include <iostream>

 class Algorithm{

 public:
     virtual void Loading(std::string filepath) = 0;
     virtual void Execute() = 0;
     virtual void Display() = 0;
     virtual void Stats() = 0;
     virtual void Save(std::string filepath) = 0;
 };


 #endif



 