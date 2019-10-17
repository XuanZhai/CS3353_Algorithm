#include "Algorithm.h"
#include "SearchBase.h"
#include <vector>
#include "BFS_iter.h"
#include "DFS_recu.h"
#include "BFS_recu.h"
#include "DFS_iter.h"
#include "Dijkstra.h"
#include "A_star.h"

//#ifdef Search
//#define Search


class Search: public Algorithm
{
private:
    int FileType;
    bool ChangeFile;
    std::string GraphName;
    std::string AlgorithmName;
    int BeginPoint;
    int EndPoint;

    std::vector<std::vector<double>> ListSummaryTable;
    std::vector<std::vector<double>> MatrixSummaryTable;
    std::vector<std::vector<int>> Graph;
    std::vector<std::vector<double>> WeightGraph;
    std::vector<std::vector<int>> DistanceGraph;
    SearchBase* newBase;
public:
    Search();
    void Load(int,std::vector<std::vector<int>>&, std::vector<std::vector<double>>&, std::vector<std::vector<int>>&) override;
    virtual void Execute(int,int) override;
    void Display()override;
    void Stats() override;
    void Select(int) override;
    void Save() override;
    ~Search();
};

//#endif