#include "FindPathBase.h"

using namespace std;


void FindPathBase::SetGraph(vector<vector<int>>& inputGraph){
    Graph = inputGraph;
    GraphSize = inputGraph.size() - 1;
}


void FindPathBase::SetPosition(vector<vector<double>>& inputPosition){
    Position = inputPosition;
}


void FindPathBase::ShortCompare(vector<int>& newPath){
    double tempDistance = FindPathDistance(newPath);
    if(tempDistance < ShortestDistance){
        ShortestDistance = tempDistance;
        ShortestPath = newPath;
    }
}


double FindPathBase::FindPathDistance(std::vector<int>& inputPath){
    double total = 0;
    double temp = 0;

    for(int j = 0; j < inputPath.size()-1; j++){
        temp = Position.at(inputPath.at(j)).at(inputPath.at(j + 1));
        total = total + temp; 
    }
    return total;
}


void FindPathBase::PrintOutput(){
     cout << "short distance " << ShortestDistance << endl;
     for(int i = 0; i < ShortestPath.size(); i++)
     cout << ShortestPath.at(i) << " ";
     cout << endl;
}