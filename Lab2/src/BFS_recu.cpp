#include "BFS_recu.h"
#include <iostream>

using namespace std;


BFS_recu::BFS_recu(/* args */){}


void BFS_recu::ImplementList(int StartPoint,int EndPoint){

    PathFounded = 0;
    StoredPath.clear();
    StoredExploredPath.clear();
    vector<int> tempExploredList;

     auto t1 = chrono::high_resolution_clock::now();
     bool visit[GraphSize]; 
     int path[GraphSize];
     int index = 0;

      for (int i = 0; i < GraphSize; i++) 
        visit[i] = false; 

    GetListPaths(StartPoint, EndPoint, visit, path, index, tempExploredList); 
    auto t2 = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double>(t2-t1).count();  // high_solution_clock reference:

}


void BFS_recu::GetListPaths(int src, int dest, bool visited[], int path[], int& pathindex, vector<int>& tempExploredList){
    
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
      PathFounded++;    
    } 


    else { 
     for(int i = 0; i <  Graph.at(src).size(); i++){
        if(!visited[Graph.at(src).at(i)])
        GetListPaths(Graph.at(src).at(i), dest, visited, path, pathindex, tempExploredList); 
     }
    } 

}






void BFS_recu::ImplementMatrix(int StartPoint,int EndPoint){

      //  RunTime = 0;
        PathFounded = 0;
        StoredPath.clear();
        StoredExploredPath.clear();
        vector<int> tempExploredList;

         auto t1 = chrono::high_resolution_clock::now();
         bool visit[GraphSize]; 
         int path[GraphSize];
         int index = 0;

      for (int i = 0; i < GraphSize; i++) 
        visit[i] = false; 

    GetMatrixPaths(StartPoint, EndPoint, visit, path, index, tempExploredList); 
    auto t2 = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double>(t2-t1).count();  // high_solution_clock reference:
   
}


void BFS_recu::GetMatrixPaths(int src, int dest, bool visited[], int path[], int& pathindex, vector<int>& tempExploredList){
    visited[src] = true; 
    tempExploredList.push_back(src);
    path[pathindex] = src; 
    pathindex++; 

    if (src == dest) { 
       vector<int> temp;

      for (int i = 0; i < pathindex; i++) 
          temp.push_back(path[i]);
          StoredPath = temp; 
          StoredExploredPath = tempExploredList;
          PathFounded++;  
    } 

     else { 
           for(int i = 0; i < Graph.at(src).size(); i++){
               if(!visited[i] && Graph.at(src).at(i) != 0)
               GetMatrixPaths(i, dest, visited, path, pathindex, tempExploredList); 
           }
    } 

}


BFS_recu::~BFS_recu(){}