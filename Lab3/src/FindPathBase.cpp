#include "FindPathBase.h"

using namespace std;


void FindPathBase::SetPosition(vector<vector<double>>& inputPosition){
    Position = inputPosition;
    GraphSize = inputPosition.size();                                    // Set the Position table and its size
}


void FindPathBase::PrintOutput(){
     cout << "short distance " << ShortestDistance << endl;
     cout << "short path: ";
     for(int i = 0; i < ShortestPath.size(); i++)
     cout << ShortestPath.at(i) << " ";
     cout << endl;
}