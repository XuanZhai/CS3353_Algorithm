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


void CreatePosition(vector<vector<double>>& Position, string filename){
     ifstream infile(filename);
     int NodeNum = 0;
     vector<vector<double>> tempPositionGraph;          // First we use a n by 3 temp graph to read data from the file
     if(!infile){
         exit(0);
     }
     vector<double> zerocolumn;
     while(!infile.eof()){
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
        NodeNum++;
    }
    infile.close();


    for(int j = 0; j < NodeNum; j++ ){
        vector<double> tempcolumn;
        for(int k = 0; k < NodeNum; k++){
            double temp = 0;
            temp =   pow( (tempPositionGraph.at(j).at(0) - tempPositionGraph.at(k).at(0)), 2)
                 + pow( (tempPositionGraph.at(j).at(1) - tempPositionGraph.at(k).at(1)), 2)
                 + pow( (tempPositionGraph.at(j).at(2) - tempPositionGraph.at(k).at(2)), 2);
            temp = sqrt(temp);
            tempcolumn.push_back(temp);
        }
        Position.push_back(tempcolumn);          // We create a n by n matrix which Position(a,b) is the distance from a+1 to b+1
    }
}


int main(int argc, char* argv[]){

    vector<vector<double>> NodePosition;
    int NodeIndex;


    CreatePosition(NodePosition,  "positions.txt");

    Algorithm* newAlgo = new FindPath();

     for (int i = 0; i < 2; i++){
         newAlgo->Load(NodePosition);
         newAlgo->Execute();
         newAlgo->Select();
         newAlgo->Save();
     }


    delete newAlgo;
    return 0;
}