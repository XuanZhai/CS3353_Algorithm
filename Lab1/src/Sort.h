#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "Algorithm.h"
#include "SortBase.h"
#include "BubbleSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include <fstream>
#include <string.h>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>


class Sort: public Algorithm
{
private:
    std::vector<int> NumberList;              // A list of number we read from file
    int  SortType = 0;                       // Which Algorithm it is 
    int  DataType = 0;                      // Which DataType it is
    double result = 0;                   // Store the time result
public:
    std::vector<SortBase*> elements;       // All the Sort Algorithm
    Sort();
    Sort(int,int);
    virtual void Loading(std::string) override;
    virtual void Execute() override;
    virtual void Stats() override;
    virtual void Display() override;
    virtual void Save(std::string) override;
    ~Sort();
};

#endif //
