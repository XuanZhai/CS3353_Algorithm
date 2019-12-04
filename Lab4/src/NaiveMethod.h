#ifndef NAIVEMETHOD_H
#define NAIVEMETHOD_H

#include "FindPathBase.h"



class NaiveMethod: public FindPathBase {      // Interited from the base
      
public: 
      void Implement() override;
      double FindPathDistance(std::vector<int>&);
      void ShortCompare(std::vector<int>&);
};


#endif
