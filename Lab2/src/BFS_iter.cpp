#include "BFS_iter.h"
#include <queue>
#include <iostream>
#include <list>


using namespace std;


BFS_iter::BFS_iter(/* args */){}


void BFS_iter::ImplementList(int StartPoint ,int EndPoint){

    
    RunTime = 0;
    PathFounded = 0;
    StoredPath.clear();
    StoredExploredPath.clear();

    // auto t1 = chrono::high_resolution_clock::now();

     queue<vector<int>> newque; 
     vector<int> Path;
     Path.push_back(StartPoint);
     newque.push(Path);

     while (newque.size() != 0){
         Path = newque.front(); 

        newque.pop(); 
        int EndPath = Path.at(Path.size() - 1); 
       // StoredExploredPath.push_back(EndPath);

        if(EndPath == EndPoint){
            StoredPath = Path;
            PathFounded++;
        //    auto t2 = chrono::high_resolution_clock::now();
          //  RunTime = chrono::duration<double, nano>(t2-t1).count();  // high_solution_clock reference:     
            return;
        }

        for(int j = 0; j < Graph.at(EndPath).size(); j++){
            if(FindVisit(Graph.at(EndPath).at(j), Path) == false) {
                vector<int> newPath = Path; 
                newPath.push_back(Graph.at(EndPath).at(j));
                newque.push(newPath);     
            }
        }

     }
}

bool BFS_iter::FindVisit(int target, vector<int>& path){
    int size = path.size(); 
    for (int i = 0; i < size; i++)  
        if (path[i] == target)  
            return true;  
    return false; 
}


void BFS_iter::ImplementMatrix(int StartPoint ,int EndPoint){

    RunTime = 0;
    PathFounded = 0;
    StoredPath.clear();
    StoredExploredPath.clear();

    auto t1 = chrono::high_resolution_clock::now();
    vector<int> Path;
    queue<vector<int>> newque; 

    Path.push_back(StartPoint);
    newque.push(Path);

    while (newque.size() != 0){
        Path = newque.front(); 

        newque.pop(); 
        int EndPath = Path[Path.size() - 1]; 
        StoredExploredPath.push_back(EndPath);

         if(EndPath == EndPoint){
            vector<int> temp;
            for (int i = 0; i < Path.size(); i++)  
            temp.push_back(Path.at(i));

            StoredPath = temp;
            PathFounded++;
            auto t2 = chrono::high_resolution_clock::now();
            RunTime = chrono::duration<double>(t2-t1).count();  // high_solution_clock reference:
            return;
        }
        for(int j = 0; j < Graph.at(EndPath).size(); j++){
            if(FindVisit(j, Path) == false && Graph.at(EndPath).at(j) == 1) {
            vector<int> newPath(Path); 
            newPath.push_back(j);
            newque.push(newPath);  
            }
        }
    }
}  



BFS_iter::~BFS_iter(){}
