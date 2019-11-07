#ifndef DYNAMICMETHOD_H
#define DYNAMICMETHOD_H


#include "FindPathBase.h"



class DynamicMethod: public FindPathBase {
      
public: 
      std::vector<int> totaltraveled; 
      void Implement() override;
      double FindShortestPath(int, std::vector<int>, unsigned long int&);
      void FindNodes(int, int, std::vector<int>&);
      int* Totaltraveled;

};


#endif