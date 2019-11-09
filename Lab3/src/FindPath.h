#ifndef FINDPATH_H
#define FINDPATH_H


#include <chrono>
#include "Algorithm.h"
#include "FindPathBase.h"
#include "NaiveMethod.h"
#include "DynamicMethod.h"

class FindPath: public Algorithm{


private:

public:
    FindPathBase* CurrentMethod;
    std::vector<std::vector<double>> Position;

    FindPath();
    void Load(std::vector<std::vector<double>>&) override;
    void Execute() override;
    void Select() override;
    ~FindPath();
};

#endif
