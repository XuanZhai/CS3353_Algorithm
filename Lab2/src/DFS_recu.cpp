#include "DFS_recu.h"
#include <iostream>

using namespace std;


DFS_recu::DFS_recu(/* args */){}


void DFS_recu::ImplementList(int StartPoint,int EndPoint){
    
    
    StoredPath.clear();
    StoredExploredPath.clear();
    vector<int> tempExploredList;

     auto Start = chrono::high_resolution_clock::now();
     bool visit[GraphSize]; 
     int path[GraphSize];
     int index = 0;

      for (int i = 0; i < GraphSize; i++) 
        visit[i] = false; 

    GetListPaths(StartPoint, EndPoint, visit, path, index, tempExploredList); 
    auto End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double>(End-Start).count();  // high_solution_clock reference:
}


void DFS_recu::GetListPaths(int src, int dest, bool visited[], int path[], int& pathindex, vector<int>& tempExploredList){
    
    visited[src] = true; 
    tempExploredList.push_back(src);
    path[pathindex] = src; 
    pathindex++; 

    if (src == dest) 
    { 
        vector<int> temp;
        for (int i = 0; i < pathindex; i++) 
            temp.push_back(path[i]);
            StoredPath = temp;   
            StoredExploredPath = tempExploredList;
    } 


    else { 
     for(int i = 0; i <  Graph.at(src).size(); i++){
        if(!visited[Graph.at(src).at(i)])
        GetListPaths(Graph.at(src).at(i), dest, visited, path, pathindex, tempExploredList); 
     }
    } 
 
}






void DFS_recu::ImplementMatrix(int StartPoint,int EndPoint){

         vector<int> tempExploredList;
         StoredPath.clear();
         StoredExploredPath.clear();

         auto Start = chrono::high_resolution_clock::now();
         bool visit[GraphSize]; 
         int path[GraphSize];
         int index = 0;

      for (int i = 0; i < GraphSize; i++) 
        visit[i] = false; 

    GetMatrixPaths(StartPoint, EndPoint, visit, path, index, tempExploredList);
    auto End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double>(End-Start).count();  // high_solution_clock reference:
   
}


void DFS_recu::GetMatrixPaths(int src, int dest, bool visited[], int path[], int& pathindex, vector<int>& tempExploredList){
    visited[src] = true; 
    tempExploredList.push_back(src);
    path[pathindex] = src; 
    pathindex++; 

    if (src == dest) { 
        vector<int> temp;

    for (int i = 0; i<pathindex; i++) 
      temp.push_back(path[i]);
      StoredPath = temp; 
      StoredExploredPath = tempExploredList;
    } 

     else { 
           for(int i = 0; i < Graph.at(src).size(); i++){
               if(!visited[i] && Graph.at(src).at(i) != 0)
               GetMatrixPaths(i , dest, visited, path, pathindex, tempExploredList); 
           }
    } 

}


DFS_recu::~DFS_recu(){}