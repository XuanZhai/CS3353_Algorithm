#ifndef TSPTABLE_H
#define TSPTABLE_H

#include <iostream>
#include "TSPTableNode.h"



class TSPTable{

private:
    int TotalHeight;
    std::vector<int> Untraveled;
    std::vector<std::vector<TSPTableNode>> Table;
    std::vector<std::vector<double>> GlobalPosition;
public:

    TSPTable();
    TSPTable(const TSPTable&);
    TSPTable operator =(const TSPTable&);
    TSPTable(int, std::vector<int>&, const std::vector<std::vector<double>>&);
    bool OnPath(int, std::vector<int>&);
    void BuildTable();
    void FillTable(std::vector<TSPTableNode>&, std::vector<TSPTableNode>&);
    TSPTableNode FindAnswer();
    void CompareNode(TSPTableNode&, std::vector<TSPTableNode>&);

    ~TSPTable();
};


#endif
