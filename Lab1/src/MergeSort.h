#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "SortBase.h"



class MergeSort: public SortBase{

public:
    MergeSort();
    void Implement(std::vector<int>&) override;        // function to inhert
    void MSort(std::vector<int>&, int, int);          // Seperate the list
    void Merging(std::vector<int>&, int, int, int);   // Merge the list
    ~MergeSort();
};


#endif