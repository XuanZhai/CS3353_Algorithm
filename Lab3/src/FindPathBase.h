#ifndef FINDPATHBASE_H
#define FINDPATHBASE_H

#include <iostream>
#include <vector>
#include <chrono>


class FindPathBase{

public:
    int GraphSize;
    std::vector<std::vector<int>> Graph;
    std::vector<std::vector<double>> Position;
    std::vector<int> ShortestPath;
    double ShortestDistance = INT_MAX;
    std::chrono::duration<double> RunTime;

    virtual void Implement() = 0;
    void SetGraph(std::vector<std::vector<int>>&);
    void SetPosition(std::vector<std::vector<double>>&);
    void PrintOutput();
    void ShortCompare(std::vector<int>&);
    double FindPathDistance(std::vector<int>&);
    };


#endif