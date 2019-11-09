#ifndef ALGORITHM_H
#define ALGORITHM_H



#include <iostream>
#include <vector>
#include <chrono>

 class Algorithm{

 public:
     virtual void Load(std::vector<std::vector<double>>&) = 0;
     virtual void Execute() = 0;
     virtual void Select() = 0;
 };


 #endif
