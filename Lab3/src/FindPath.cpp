#include "FindPath.h"

using namespace std;


FindPath::FindPath(){
     CurrentMethod = new NaiveMethod();
}


void FindPath::Load(vector<vector<int>>& inputGraph, vector<vector<double>>& inputPosition){
     CurrentMethod->SetGraph(inputGraph);
     CurrentMethod->SetPosition(inputPosition);
}


void FindPath::Execute(){
     chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); //High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
     CurrentMethod->Implement();
     chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
     CurrentMethod->RunTime = chrono::duration<double, milli>(End-Start);  // high_solution_clock reference:
     cout << "short distance " << CurrentMethod->ShortestDistance << endl;
     cout << "short path: ";
     for(int i = 0; i < CurrentMethod->ShortestPath.size(); i++)
     cout << CurrentMethod->ShortestPath.at(i) << " ";
     cout << endl;
     cout << "The runtime is " << CurrentMethod->RunTime.count() << " millisecond" << endl;
}




void FindPath::Select(){
     delete CurrentMethod;
     CurrentMethod = new DynamicMethod();
}


void FindPath::Save(){
    
}


FindPath::~FindPath(){
     delete CurrentMethod;
}