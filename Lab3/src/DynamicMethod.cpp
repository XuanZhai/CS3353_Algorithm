#include "DynamicMethod.h"


using namespace std;

 void DynamicMethod::Implement(){
     vector<int> NeedTraveled;
     for(int i = 0; i < GraphSize - 1; i++){
         NeedTraveled.push_back(i + 2);               // Start from 2, like if we have 5 nodes, the Needtraveled will be 2,3,4,5 
     }

    cout << "\nBegin Dynamic Method..." << endl;
    chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); 

    TSPTable newTable(GraphSize, NeedTraveled, Position);   // Create A table
    newTable.BuildTable();                                 // Fill out the table
    ShortestDistance = newTable.FindAnswer().Total;
    ShortestPath = newTable.FindAnswer().Path;

    ShortestPath.insert(ShortestPath.begin(), 1);
    ShortestPath.push_back(1);

    chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double, std::milli>(End-Start);    
 }