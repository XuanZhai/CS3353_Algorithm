#ifndef SEARCHBASE_H
#define SEARCHBASE_H


#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>      // std::setprecision
#include <ratio>
#include <chrono>

 class SearchBase{

 private:

 public:

    std::vector<std::vector<double>> Weight;
    std::vector<std::vector<int>> Distance;
    std::vector<std::vector<int>> Graph;
    std::vector<int> StoredPath;
    std::vector<int> StoredExploredPath; 
    double CostOfPath;
    float RunTime;
    double DistanceOfPath;
    int GraphSize;
    int PathFounded;

     SearchBase();
     virtual void ImplementList(int,int) = 0;  
     virtual void ImplementMatrix(int,int) = 0;
     void SetWeight(std::vector<std::vector<double>>&);
     void SetDistance(std::vector<std::vector<int>>&);
     void SetGraph(std::vector<std::vector<int>>&);
     void FindCostOfPath();
     void FindDistanceOfPath();
     void PrintPathData();
     void FillSummaryTable(std::vector<std::vector<double>>&, std::string);
     ~SearchBase();
 };


 #endif

