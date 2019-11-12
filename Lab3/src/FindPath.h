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

    FindPath();
    void Load(std::string) override;
    void Execute() override;
    void Select() override;
    ~FindPath();
};

#endif
