#include "SearchBase.h"
#include <vector>



class BFS_recu: public SearchBase
{
private:

    // int PathFounded;
  //  std::vector<std::vector<int>> StoredListPath;
   // std::vector<std::vector<int>> StoredMatrixPath;
public:

    BFS_recu();
    void ImplementList(int,int) override;
    void ImplementMatrix(int,int) override;   
    void GetListPaths(int, int, bool[], int[], int&, std::vector<int>&);
    void GetMatrixPaths(int, int, bool[], int[], int&, std::vector<int>&);
    ~BFS_recu();
};
