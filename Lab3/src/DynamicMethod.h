#ifndef DYNAMICMETHOD_H
#define DYNAMICMETHOD_H


#include "FindPathBase.h"



class DynamicMethod: public FindPathBase {
      
public: 
      void SetTable();
      std::vector<std::vector<std::vector<int>>> memotable; 
      void Implement() override;
      std::vector<int> FindShortestPath(int, int, std::vector<int>, int);

};


#endif