#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <vector>
#include "SortBase.h"



class InsertSort: public SortBase{

public:
    InsertSort();
    void Implement(std::vector<int>&) override;
    ~InsertSort();
};


#endif