#include <iostream>
#include <vector>
#include "SearchBase.h"


class Dijkstra: public SearchBase
{
private:

public:
    Dijkstra(/* args */);
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override; 
    ~Dijkstra();
};

