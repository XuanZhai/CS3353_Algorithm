#include "SearchBase.h"


class DFS_iter: public SearchBase
{
private:

   // int PathFounded;
   // std::vector<std::vector<int>> StoredListPath;
   // std::vector<std::vector<int>> StoredMatrixPath;

public:

    DFS_iter();
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override;  
    void GetListPaths(int, int, bool[], int[], int&);
    void GetMatrixPaths(int, int, bool[], int[], int&);
    bool FindVisit(int, std::vector<int>&);
    ~DFS_iter();
};