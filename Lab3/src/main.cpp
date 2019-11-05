#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Algorithm.h"
#include "FindPath.h"


using namespace std;


void CreateList(vector<vector<int>>& StoredGraph, string filename){
    int Index = 0;

    ifstream infile(filename);
         if(!infile){
         cout << "Error Load File" << endl;
         exit(0);
     }

     while(!infile.eof()){
         int ListHead;
         char FirstComma;
         vector<int> tempset;  

         infile >> ListHead;
         infile >> FirstComma;        // Get the index

        string templine;
        getline(infile,templine);      // Take all its child as a string line first
        istringstream iss(templine);
        string token;
    
        if(StoredGraph.size() == 0){
        StoredGraph.push_back(tempset);
        }

         while(getline(iss, token, ',')) {     // using istringstream to split number with comma
         tempset.push_back(atoi(token.c_str()));
        }
         StoredGraph.push_back(tempset);         // Store the adjacency list
     }
     infile.close();
}


bool MatchGraph(vector<vector<int>>& Graph, int a, int b){
    for(int i = 0; i < Graph.at(a).size(); i++){
        if(b == Graph.at(a).at(i))
        return true;
    }
    return false;
}


void CreatePosition(vector<vector<int>>& Graph, vector<vector<double>>& Position, int NodeNum, string filename){
     ifstream infile(filename);
     vector<vector<double>> tempPositionGraph;          // First we use a n by 3 temp graph to read data from the file
     if(!infile){
         exit(0);
     }
     vector<double> zerocolumn;
     for(int i = 0; i < NodeNum; i++){
        vector<double> tempcolumn;
        int index = 0;
        double xaxis = 0;
        double yaxis = 0;
        double zaxis = 0;
        char temp = 0;
        infile >> index;
        infile >> temp;
        infile >> xaxis;
        infile >> temp;
        infile >> yaxis;
        infile >> temp;
        infile >> zaxis;
        tempcolumn.push_back(xaxis);                  // We have a temp graph which each row is the axises
        tempcolumn.push_back(yaxis);
        tempcolumn.push_back(zaxis);
        tempPositionGraph.push_back(tempcolumn);
        zerocolumn.push_back(0);
    }
    infile.close();

    zerocolumn.push_back(0);
    Position.push_back(zerocolumn);       // Again, we use a n by n matrix to build the distance 


    for(int j = 0; j < NodeNum; j++ ){
        vector<double> tempcolumn;
        tempcolumn.push_back(0);
        for(int k = 0; k < NodeNum; k++){
              double temp = 0;
        temp =   pow( (tempPositionGraph.at(j).at(0) - tempPositionGraph.at(k).at(0)), 2)
               + pow( (tempPositionGraph.at(j).at(1) - tempPositionGraph.at(k).at(1)), 2)
               + pow( (tempPositionGraph.at(j).at(2) - tempPositionGraph.at(k).at(2)), 2);
        temp = sqrt(temp);
        if(MatchGraph(Graph, (j + 1), (k + 1)))
        tempcolumn.push_back(temp);
        else
        tempcolumn.push_back(0);
        }
        Position.push_back(tempcolumn);
    }
}


int main(int argc, char* argv[]){

    vector<vector<int>> NodeList;
    vector<vector<double>> NodePosition;
    int NodeIndex;


    CreateList(NodeList, "graph.txt");
    NodeIndex = NodeList.size() - 1;
    CreatePosition(NodeList, NodePosition, NodeIndex, "positions.txt");

    Algorithm* newAlgo = new FindPath();

    for (int i = 0; i < 2; i++){
        newAlgo->Load(NodeList, NodePosition);
        newAlgo->Execute();
        newAlgo->Select();
        newAlgo->Save();
    }


    delete newAlgo;


    return 0;
}