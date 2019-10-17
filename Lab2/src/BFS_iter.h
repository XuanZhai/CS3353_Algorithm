#include "SearchBase.h"


class BFS_iter: public SearchBase
{
private:

public:

    BFS_iter();
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override;  
    void GetListPaths(int, int, bool[], int[], int&);
    void GetMatrixPaths(int, int, bool[], int[], int&);
    bool FindVisit(int, std::vector<int>&);
    ~BFS_iter();
};
