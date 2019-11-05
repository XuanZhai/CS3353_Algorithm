#include "DynamicMethod.h"


using namespace std;


void DynamicMethod::SetTable(){
    for(int i = 0; i < GraphSize + 1; i++){
        vector<vector<int>> bigvector;
        for(int j = 0; j < GraphSize + 1; j++){
            vector<int> smallvector;
            bigvector.push_back(smallvector);
        }
        memotable.push_back(bigvector);
    }
}


void DynamicMethod::Implement(){

    SetTable();

    vector<int> visited;
    for (int j = 0; j < GraphSize + 1; j++){
        visited.push_back(false);
    }
    visited.at(0) = true;

    for (int i = 0; i < Graph.at(1).size(); i++){
        vector <int> temp1 = FindShortestPath(1, Graph.at(1).at(i), visited, GraphSize);
        if(temp1.size() > 1){
            vector <int> temp2;
            temp2.push_back(Graph.at(1).at(i));
            temp2.push_back(1);
            double tempDistance = FindPathDistance(temp1) + FindPathDistance(temp2);
            if(tempDistance <= ShortestDistance){
                temp1.push_back(1);
                ShortestPath = temp1;
                ShortestDistance = tempDistance;
            }
        }
    }
}


vector<int> DynamicMethod::FindShortestPath(int Start, int End, vector<int> visit, int Listlength){
    visit.at(Start) = true;
    visit.at(End) = true;
    vector<int> newPath;

     if(memotable.at(Start).at(End).size() == Listlength){
         bool Ontable = true;
         for(int a = 0; a < memotable.at(Start).at(End).size(); a++){
             if(visit.at(memotable.at(Start).at(End).at(a)) == true)
                Ontable = false;
        if(Ontable == true)
            return memotable.at(Start).at(End);
     }
     }

    for(int i = 0; i < Graph.at(Start).size(); i++){
        if(End == Graph.at(Start).at(i) && Listlength == 2){
            newPath.push_back(Start);
            newPath.push_back(End);
             memotable.at(Start).at(End) = newPath;
            return newPath;
        }
    }

    int dist = INT_MAX;
    vector<int> temp1;

    for(int j = 0; j < Graph.at(Start).size(); j++){

        if(visit[Graph.at(Start).at(j)] == false){    
            temp1 =  FindShortestPath(Graph.at(Start).at(j), End, visit, (Listlength - 1));

            if(temp1.size() > 1){
                memotable.at(Graph.at(Start).at(j)).at(End) = temp1;
                vector<int> temp2;
                temp2.push_back(Start);
                temp2.push_back(Graph.at(Start).at(j));

                if ( ((FindPathDistance(temp1) +  FindPathDistance(temp2)) < dist)){
                    newPath = temp1;
                    dist = (FindPathDistance(temp1) +  FindPathDistance(temp2));
                }
            }
        }
    }

    newPath.insert(newPath.begin() , Start);

    if(newPath.size() > 1)
    memotable.at(Start).at(End) = newPath;

    return newPath;
}