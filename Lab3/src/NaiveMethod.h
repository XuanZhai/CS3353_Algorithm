#ifndef NAIVEMETHOD_H
#define NAIVEMETHOD_H

#include "FindPathBase.h"



class NaiveMethod: public FindPathBase {
      
public: 
      void Implement() override;
      std::vector<int> FindShortestPath(int, int, std::vector<int>, int);
};


#endif
