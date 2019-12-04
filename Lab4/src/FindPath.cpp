#include "FindPath.h"

using namespace std;


FindPath::FindPath(){
     CurrentMethod = new TabuSearch();                // Tabu Search method is the default method
     numNode = 0;
}


void FindPath::Load(string filename){
     vector<vector<double>> tempPosition;
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
         tempcolumn.push_back(xaxis);                  // We have a temp graph which each row is the axis
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
                    +   pow( (tempPositionGraph.at(j).at(1) - tempPositionGraph.at(k).at(1)), 2)
                    +   pow( (tempPositionGraph.at(j).at(2) - tempPositionGraph.at(k).at(2)), 2);
               temp = sqrt(temp);
               tempcolumn.push_back(temp);
          }
          tempPosition.push_back(tempcolumn);          // We create a n by n matrix which Position(a,b) is the distance from a+1 to b+1
     }
     CurrentMethod->SetPosition(tempPosition);              // Set the Position table
     numNode = NodeNum;
}


void FindPath::Execute(){
     CurrentMethod->Implement();                                                                   // Implement the Method of solving TSP
     CurrentMethod->PrintOutput();                                                                // Print out the path
     cout << "The runtime is " << CurrentMethod->RunTime.count() << " milliseconds" << endl;     // Return the time
}


void FindPath::Select(int node){
     delete CurrentMethod;
     if(node == 0){
          CurrentMethod = new GeneticAlgo();                                                 // Switch to Genetic Algorithm
     }
     else if(node == 1){
          CurrentMethod = new DynamicMethod();                                               // Switch to Dynamic Programming
     }
     else if(node == 2){
          CurrentMethod = new NaiveMethod();                                                 // Switch to Naive Method
     }
}


FindPath::~FindPath(){
     delete CurrentMethod;
}