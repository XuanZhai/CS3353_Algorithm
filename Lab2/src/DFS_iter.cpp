#include "DFS_iter.h"
#include <stack>
#include <iostream>


using namespace std;


DFS_iter::DFS_iter(/* args */){}


void DFS_iter::ImplementList(int StartPoint ,int EndPoint){
    
    RunTime = 0;
    StoredPath.clear();
    StoredExploredPath.clear();

     auto Start = chrono::high_resolution_clock::now();
     vector<int> Path;
     stack<vector<int>> newque; 

     Path.push_back(StartPoint);
     newque.push(Path);

     while (newque.size() != 0){
        Path = newque.top(); 

        newque.pop(); 
        int EndPath = Path[Path.size() - 1]; 
        StoredExploredPath.push_back(EndPath);

        if(EndPath == EndPoint){
           vector<int> temp;
           for (int i = 0; i < Path.size(); i++)  
            temp.push_back(Path.at(i));

            StoredPath = temp;
            auto End = chrono::high_resolution_clock::now();
            RunTime = chrono::duration<double>(End-Start).count();  // high_solution_clock reference:
        
            return;
        }

        for(int j = 0; j < Graph.at(EndPath).size(); j++){
            if(FindVisit(Graph.at(EndPath).at(j), Path) == false) {
                vector<int> newPath(Path); 
                newPath.push_back(Graph.at(EndPath).at(j));
                newque.push(newPath);     
            }
        }

     }
     
}

bool DFS_iter::FindVisit(int target, vector<int>& path){
    int size = path.size(); 
    for (int i = 0; i < size; i++)  
        if (path[i] == target)  
            return true;  
    return false; 
}


void DFS_iter::ImplementMatrix(int StartPoint ,int EndPoint){

    RunTime = 0;
    StoredPath.clear();
    StoredExploredPath.clear();

    auto Start = chrono::high_resolution_clock::now();
    vector<int> Path;
    stack<vector<int>> newque; 

    Path.push_back(StartPoint);
    newque.push(Path);

    while (newque.size() != 0){
        Path = newque.top(); 

        newque.pop(); 
        int EndPath = Path[Path.size() - 1]; 
        StoredExploredPath.push_back(EndPath);

         if(EndPath == EndPoint){
            vector<int> temp;
            for (int i = 0; i < Path.size(); i++)  
            temp.push_back(Path.at(i));

            StoredPath = temp;
            auto End = chrono::high_resolution_clock::now();
            RunTime = chrono::duration<double>(End - Start).count();  // high_solution_clock reference:
        
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



DFS_iter::~DFS_iter(){}