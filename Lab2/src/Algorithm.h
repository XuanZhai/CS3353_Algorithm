#ifndef ALGORITHM_H
#define ALGORITHM_H



#include <iostream>
#include <vector>

 class Algorithm{

 public:
     virtual void Load(int,std::vector<std::vector<int>>&, std::vector<std::vector<double>>&, std::vector<std::vector<int>>&) = 0;
     virtual void Execute(int,int) = 0;
     virtual void Display() = 0;
     virtual void Stats() = 0;
     virtual void Select(int) = 0;
     virtual void Save() = 0;
 };


 #endif



 