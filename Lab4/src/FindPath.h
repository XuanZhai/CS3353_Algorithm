#ifndef FINDPATH_H
#define FINDPATH_H


#include <chrono>
#include "Algorithm.h"
#include "FindPathBase.h"
#include "TabuSearch.h"
#include "GeneticAlgo.h"
#include "NaiveMethod.h"
#include "DynamicMethod.h"

class FindPath: public Algorithm{


private:

public:
    FindPathBase* CurrentMethod;
    int numNode;                              // How many city(node) in the graph

    FindPath();
    void Load(std::string) override;
    void Execute() override;
    void Select(int) override;
    ~FindPath();
};

#endif
