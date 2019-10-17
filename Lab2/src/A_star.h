#include <iostream>
#include <vector>
#include "SearchBase.h"


class A_star: public SearchBase
{
private:
    /* data */
public:
    A_star(/* args */);
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override; 
    ~A_star();
};
