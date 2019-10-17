#include <iostream>
#include "Algorithm.h"
#include <fstream>
#include "Search.h"
#include <vector>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>  




using namespace std;


int FindNumberofGraphNode(string filename){    // This Funtion just return the number of index in the graph
    ifstream infile(filename);
     if(!infile){
         cout << "Error Load File" << endl;
         exit(0);
     }
    
    string tempLine;
    int NumOfNode = 0;

    while (!infile.eof()){
    getline(infile,tempLine);
    NumOfNode++;
   }
   infile.close();
   return NumOfNode;
}

void CreateGraph(vector<vector<int>>& AList, vector<vector<int>>& AMatrix, string filename, int NumNode){
     ifstream infile(filename);                // We take two raw adjacency list and adjacency matrix 
     if(!infile){
         cout << "Error Load File" << endl;
         exit(0);
     }

     for(int i = 0; i < NumNode; i++){
         int Listhead;
         char FirstComma;
         infile >> Listhead;
         infile >> FirstComma;        // Get the index

         string templine;
         getline(infile,templine);      // Take all its child as a string line first
         istringstream iss(templine);
         string token;
        vector<int> tempset;      



        if(AList.size() == 0){
        AList.push_back(tempset);
        }

         while(getline(iss, token, ',')) {     // using istringstream to split number with comma
         tempset.push_back(atoi(token.c_str()));
        }
        AList.push_back(tempset);         // Store the adjacency list
     }
     infile.close();


     for(int i = 0; i < AList.size(); i++){   // Create a n+1 by n+1 graph for adjacency matrix
        vector<int> tempcolumn;
        for(int j = 0; j < AList.size(); j++){    // We set n+1 instead of n because we want to leave graph[0] away


            bool exist = false;
            for(int k = 0; k < AList.at(i).size(); k++){
                if(AList.at(i).at(k) == j){    // Example: if x is linked with y
                tempcolumn.push_back(1);       // matrix[x][y] is 1
                exist = true;
                break;
                }
            }


            if(exist == false){
         tempcolumn.push_back(0);                // Otherwise is 0
          }
        }      
        AMatrix.push_back(tempcolumn);
     }
}



void CreateWeight(vector<vector<double>>& StoredWeightGraph, int NumberofNode, string filename){
    
    for(int i = 0; i < NumberofNode+1; i++){          // We use a n by n graph to store the weight
        vector<double> tempcolumn;
        for(int j = 0; j < NumberofNode+1; j++)
        tempcolumn.push_back(0);
        StoredWeightGraph.push_back(tempcolumn);
    }


     ifstream infile(filename);
     if(!infile){
         exit(0);
     }
    while (!infile.eof())
    {
        int src, dest;
        double weight;
        char tempcomma;
        infile >> src;
        infile >> tempcomma;
        infile >> dest;
        infile >> tempcomma;
        infile>> weight;
        StoredWeightGraph.at(src).at(dest) = weight;   // Similar to the way we used to create the matrix
    }                                                  // We just put the weight into the graph's points
    infile.close();
}


void CreateDistance(vector<vector<int>>& StoredDistanceGraph,vector<vector<double>>& StoredWeightGraph, string filename){
          ifstream infile(filename);
          vector<vector<int>> tempDistanceGraph;          // First we use a n by 3 temp graph to read data from the file
     if(!infile){
         exit(0);
     }
     vector<int> zerocolumn;
    while (!infile.eof()){
        vector<int> tempcolumn;
        int index = 0;
        int xaxis = 0;
        int yaxis = 0;
        int zaxis = 0;
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
        tempDistanceGraph.push_back(tempcolumn);
        zerocolumn.push_back(0);
    }
    infile.close();

    zerocolumn.push_back(0);
    StoredDistanceGraph.push_back(zerocolumn);       // Again, we use a n by n matrix to build the distance 
                                                        //DistanceGraph[x][y] loads the distance from x to y
    for(int i = 0; i < tempDistanceGraph.size(); i++){
        vector<int> tempcolumn;
        tempcolumn.push_back(0);
        for(int j = 0; j < tempDistanceGraph.size(); j++){
        double temp = 0;
        temp =   pow( (tempDistanceGraph.at(i).at(0) - tempDistanceGraph.at(j).at(0)), 2)
               + pow( (tempDistanceGraph.at(i).at(1) - tempDistanceGraph.at(j).at(1)), 2)
               + pow( (tempDistanceGraph.at(i).at(2) - tempDistanceGraph.at(j).at(2)), 2);
        temp = sqrt(temp);
        if(StoredWeightGraph.at(i+1).at(j+1) != 0)
        tempcolumn.push_back(temp);
        else
        tempcolumn.push_back(0);
        }
        StoredDistanceGraph.push_back(tempcolumn);
    }
}



int main(int argc, char* argv[]){
   Algorithm* newAlgh = new Search();

    vector<vector<int>> Path;

    int NumofNode = FindNumberofGraphNode("graph.txt");

    if(argc != 3){                                    // If no command line argument
    srand((unsigned)time(NULL));                            // Set random

    for(int i = 0; i < 100; i++){
        int tempsrc = rand()%NumofNode + 1;
        int tempdest = rand()%NumofNode + 1;
         while(tempdest == tempsrc){
        tempdest = rand()%NumofNode + 1;              // If src is equal to the dest
       }
       vector<int> tempvector;
       tempvector.push_back(tempsrc);
       tempvector.push_back(tempdest);
       Path.push_back(tempvector);
     }

    }
    else{
       int src = atoi(argv[1]);
       int dest = atoi(argv[2]);
       if(src != dest){
       vector<int> tempvector;
       tempvector.push_back(src);
       tempvector.push_back(dest);
       Path.push_back(tempvector);
       }
       else{
           cout << "Start Point cannot be the End Point" << endl;
           exit(0);
       }
       
    }

    vector<vector<int>> AdjList;
    vector<vector<int>> AdjMatrix;
    CreateGraph(AdjList,AdjMatrix, "graph.txt", NumofNode);

    vector<vector<double>> GraphWeight;
    CreateWeight(GraphWeight,NumofNode, "weights.txt");

    vector<vector<int>> GraphDistance;
    CreateDistance(GraphDistance, GraphWeight, "positions.txt");

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 6; k++){
              if(j == 0){
              newAlgh->Load(j, AdjList, GraphWeight, GraphDistance);
              }
              else{
              newAlgh->Load(j, AdjMatrix, GraphWeight, GraphDistance);
              }
              newAlgh->Execute(Path.at(i).at(0), Path.at(i).at(1));
              newAlgh->Stats();
              newAlgh->Select(k);    // Pass a variable to change the algorithm
            }
        }
    }
    newAlgh->Save();          // Save data to a txt file
    return 0;
}



