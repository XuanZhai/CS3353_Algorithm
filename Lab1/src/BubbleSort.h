#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include "SortBase.h"



class BubbleSort: public SortBase {

public:
    BubbleSort();
    void Implement(std::vector<int>&) override;
    ~BubbleSort();
};


#endif