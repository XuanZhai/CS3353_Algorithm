#ifndef FINDPATHBASE_H
#define FINDPATHBASE_H

#include <iostream>
#include <vector>
#include <chrono>


class FindPathBase{

public:
    int GraphSize;
    std::vector<std::vector<double>> Position;
    std::vector<int> ShortestPath;
    double ShortestDistance = INT_MAX;
    std::chrono::duration<double, std::milli> RunTime;

    virtual void Implement() = 0;
    void SetPosition(std::vector<std::vector<double>>&);
    void PrintOutput();
    };


#endif