#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include "FindPathBase.h"
#include <bits/stdc++.h> 



class TabuSearch: public FindPathBase {      // Interited from the base

private:
      int TabuList[5][2];              
      int currentTabu;                       // Current pointed location on the Tabu list
      int ReShuffle;                         // An trigger if the method is in the local minimum
      std::vector<int> LocalShortPath;      // Current shortest path, may not be the global minimum
      double LocalShortDistance;
      std::vector<std::vector<int>> MovingList;   // Swipping elements which can produce neighborhood
      std::vector<double>  MovingDistance;

public: 
      TabuSearch();
      void Implement() override;
      void FindRandom();
      void FindNeighborhood();
      std::vector<int> SwapPath(std::vector<int>&, int, int);
      double FindPathDistance(std::vector<int>&);
      bool OnTabuList(std::vector<int>&);

};


#endif
