#ifndef TSPTABLENODE_H
#define TSPTABLENODE_H

#include <iostream>
#include <vector>


class TSPTableNode
{
private:

public:

    int Id;
    std::vector<int> Path;
    double Pathtotal;
    double Total;
    std::vector<std::vector<double>> LocalPosition;

    TSPTableNode();
    TSPTableNode(const TSPTableNode&); 
    TSPTableNode operator =(const TSPTableNode&);
    TSPTableNode(int, std::vector<std::vector<double>>&);

    void FindTotal();

    ~TSPTableNode();
};


#endif
