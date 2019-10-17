#include "SearchBase.h"
#include <vector>



class DFS_recu: public SearchBase
{
private:


public:

    DFS_recu();
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override;   
    void GetListPaths(int, int, bool[], int[], int&, std::vector<int>&);
    void GetMatrixPaths(int, int, bool[], int[], int&, std::vector<int>&);
    ~DFS_recu();
};
