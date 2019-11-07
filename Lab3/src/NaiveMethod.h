#ifndef NAIVEMETHOD_H
#define NAIVEMETHOD_H

#include "FindPathBase.h"



class NaiveMethod: public FindPathBase {
      
public: 
      void Implement() override;
      double FindPathDistance(std::vector<int>&);
      void ShortCompare(std::vector<int>&);
};


#endif
