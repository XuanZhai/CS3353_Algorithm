#include "NaiveMethod.h"


using namespace std;


void NaiveMethod::Implement(){
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


vector<int> NaiveMethod::FindShortestPath(int Start, int End, vector<int> visit, int Listlength){
    visit.at(Start) = true;
    visit.at(End) = true;
    vector<int> newPath;

    for(int i = 0; i < Graph.at(Start).size(); i++){
        if(End == Graph.at(Start).at(i) && Listlength == 2){
            newPath.push_back(Start);
            newPath.push_back(End);
            return newPath;
        }
    }

    int dist = INT_MAX;
    vector<int> temp1;

    for(int j = 0; j < Graph.at(Start).size(); j++){

        if(visit[Graph.at(Start).at(j)] == false){    
            temp1 =  FindShortestPath(Graph.at(Start).at(j), End, visit, (Listlength - 1));

            if(temp1.size() > 1){
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
    return newPath;
}




// void NaiveMethod::Implement(){
//     chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); //High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/

//     bool visited[GraphSize];
//     int  lastloop[GraphSize];
//     for (int i = 0; i < GraphSize; i++){
//         visited[i] = false;
//         lastloop[i] = 0;
//     }

//     vector<int> CurrentPath;
//     CurrentPath.push_back(1);
//     visited[0] = true;
//     int i = 0;
//     int newNum = 0;

//     while(CurrentPath.size() != 0){
//         int last = CurrentPath.at(CurrentPath.size() - 1);
//         i = lastloop[last - 1];

//             for(i; i < Graph.at(last).size(); ++i){

//                 int newNum = Graph.at(last).at(i);
//                 lastloop[last - 1 ]++;

//                 if( newNum == 1 && CurrentPath.size() == GraphSize){
//                     CurrentPath.push_back(1);
//                     ShortCompare(CurrentPath);
//                     CurrentPath.pop_back();
//                 }

//                 else if( visited[newNum - 1] == false ){
//                 CurrentPath.push_back(newNum);
//                 last = newNum;
//                 i = -1;
//                 visited[newNum - 1] = true;
//             }
//         }

//         CurrentPath.pop_back();

//         visited[last - 1 ] = false;
//         lastloop[last - 1] = 0;
//     }

//       chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
//       RunTime = chrono::duration<double, milli>(End-Start);  // high_solution_clock reference:

// }