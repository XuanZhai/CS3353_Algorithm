#include "SearchBase.h"
#include <iostream>
#include <vector>
#include <stdio.h> 
#include <math.h>   
#include <cstdio>
#include <ctime>



using namespace std;


    SearchBase::SearchBase(){}


    void SearchBase::SetWeight(std::vector<std::vector<double>>& graphweight){
        Weight = graphweight;
    }


    void SearchBase::SetDistance(std::vector<std::vector<int>>& graphdistance){
        Distance = graphdistance;
    }


    void SearchBase::SetGraph(std::vector<std::vector<int>>& newGraph){
        Graph = newGraph;
        GraphSize = Graph.size();
    }

    void SearchBase::PrintPathData(){
            cout << "Returned Path: ";
            for(int i = 0; i < StoredPath.size(); i++){
                cout << StoredPath.at(i) << " ";            
            }
            cout << "\nNumber of nodes in returned path: " << StoredPath.size() << endl;
            cout << "Total Cost of path: " << CostOfPath << endl;
            cout << "Total distance of path: " << DistanceOfPath << endl;
            cout << "Number of nodes explored in path: " << StoredExploredPath.size() << endl;
            cout << "Execution time to find path: " << setprecision(10) << RunTime << endl;
            cout << endl;
    }


    void SearchBase::FindCostOfPath(){
            double temp = 0;
            double total = 0;

            for(int j = 0; j < StoredPath.size()-1; j++){
                temp = Weight.at(StoredPath.at(j)).at(StoredPath.at(j + 1));
                total = total + temp; 
            }
            CostOfPath = total;      // Find the total cost of the path
    }


    void SearchBase::FindDistanceOfPath(){
            double total = 0;
            double temp = 0;

           for(int j = 0; j < StoredPath.size()-1; j++){
                temp = Distance.at(StoredPath.at(j)).at(StoredPath.at(j + 1));
                total = total + temp; 
            }
            DistanceOfPath = total;   // Find the total distance 
    }


    void SearchBase::FillSummaryTable(vector<vector<double>>& SummaryTable, string SearchAlgo){
        if(SearchAlgo == "DFS-Iterative"){
             SummaryTable.at(0).at(0) = SummaryTable.at(0).at(0) + StoredPath.size();
             SummaryTable.at(1).at(0) = SummaryTable.at(1).at(0) + StoredExploredPath.size();
             SummaryTable.at(2).at(0) = SummaryTable.at(2).at(0) + RunTime;
             SummaryTable.at(3).at(0) = SummaryTable.at(3).at(0) + DistanceOfPath;
             SummaryTable.at(4).at(0) = SummaryTable.at(4).at(0) + CostOfPath;   // Normalized the data
        }
        else if(SearchAlgo == "DFS-Recursive"){
             SummaryTable.at(0).at(1) = SummaryTable.at(0).at(1) + StoredPath.size();
             SummaryTable.at(1).at(1) = SummaryTable.at(1).at(1) + StoredExploredPath.size();
             SummaryTable.at(2).at(1) = SummaryTable.at(2).at(1) + RunTime;
             SummaryTable.at(3).at(1) = SummaryTable.at(3).at(1) + DistanceOfPath;
             SummaryTable.at(4).at(1) = SummaryTable.at(4).at(1) + CostOfPath;
        }
        else if(SearchAlgo == "BFS-Iterative"){
             SummaryTable.at(0).at(2) = SummaryTable.at(0).at(2) + StoredPath.size();
             SummaryTable.at(1).at(2) = SummaryTable.at(1).at(2) + StoredExploredPath.size();
             SummaryTable.at(2).at(2) = SummaryTable.at(2).at(2) + RunTime;
             SummaryTable.at(3).at(2) = SummaryTable.at(3).at(2) + DistanceOfPath;
             SummaryTable.at(4).at(2) = SummaryTable.at(4).at(2) + CostOfPath;
        }
        else if(SearchAlgo == "BFS-Recursive"){
             SummaryTable.at(0).at(3) = SummaryTable.at(0).at(3) + StoredPath.size();
             SummaryTable.at(1).at(3) = SummaryTable.at(1).at(3) + StoredExploredPath.size();
             SummaryTable.at(2).at(3) = SummaryTable.at(2).at(3) + RunTime;
             SummaryTable.at(3).at(3) = SummaryTable.at(3).at(3) + DistanceOfPath;
             SummaryTable.at(4).at(3) = SummaryTable.at(4).at(3) + CostOfPath;
        }
        else if(SearchAlgo == "Dijkstra"){
             SummaryTable.at(0).at(4) = SummaryTable.at(0).at(4) + StoredPath.size();
             SummaryTable.at(1).at(4) = SummaryTable.at(1).at(4) + StoredExploredPath.size();
             SummaryTable.at(2).at(4) = SummaryTable.at(2).at(4) + RunTime;
             SummaryTable.at(3).at(4) = SummaryTable.at(3).at(4) + DistanceOfPath;
             SummaryTable.at(4).at(4) = SummaryTable.at(4).at(4) + CostOfPath;
        }
        else if(SearchAlgo == "A_Star"){
             SummaryTable.at(0).at(5) = SummaryTable.at(0).at(5) + StoredPath.size();
             SummaryTable.at(1).at(5) = SummaryTable.at(1).at(5) + StoredExploredPath.size();
             SummaryTable.at(2).at(5) = SummaryTable.at(2).at(5) + RunTime;
             SummaryTable.at(3).at(5) = SummaryTable.at(3).at(5) + DistanceOfPath;
             SummaryTable.at(4).at(5) = SummaryTable.at(4).at(5) + CostOfPath;
        }
    }

     SearchBase::~SearchBase(){}