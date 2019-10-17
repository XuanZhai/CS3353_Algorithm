#include "A_star.h"
#include "iostream"


using namespace std;


A_star::A_star(/* args */){}

void A_star::ImplementList(int StartPoint,int EndPoint){
        StoredPath.clear();
        StoredExploredPath.clear();
        int n = Distance.size();

        int cost[n][n],distance[n],pred[n];
        int visited[n],count,mindistance,nextnode;
        
        auto Start = chrono::high_resolution_clock::now();

    for(int i = 0; i < n; i++)
      for(int j = 0;j < n; j++)
         if(Distance.at(i).at(j) == 0)
             cost[i][j] = 1000000;
         else
             cost[i][j] = Distance.at(i).at(j);          // Cost is the copy of Distance but the unconnected Distance is INFINITE not 0


    for(int i = 0; i < n; i++) {
      distance[i] = cost[StartPoint][i];
      pred[i]=StartPoint;
      visited[i] = 0;                                // Distance initialized with the start point's wDistance
    }                                              


   distance[StartPoint] = 0;                       // Distance to startpoint itself is always 0
   visited[StartPoint] = 1;                       // StartPoint is always visited
   StoredExploredPath.push_back(StartPoint);
   count = 1;

   while(count < GraphSize - 1) {
      mindistance = 1000000;
      for(int i = 0;i < GraphSize ;i++)
         if(distance[i] < mindistance && visited[i] == 0) {          // Find = the Closest Point
         mindistance = distance[i];
         nextnode = i;
      }
      visited[nextnode] = 1;                             // Move to the next point
      StoredExploredPath.push_back(nextnode);
      for(int i = 0; i < GraphSize; i++)
         if(!visited[i])
      if(mindistance + cost[nextnode][i] < distance[i]) {
         distance[i] = mindistance + cost[nextnode][i];           // Update closest path
         pred[i] = nextnode;
      }
      count++;
   }    

      vector<int> tempMap;
      tempMap.push_back(EndPoint);
      int j = EndPoint;
      while(j!=StartPoint) {
         j=pred[j];
         tempMap.push_back(j);
      }
      auto End = chrono::high_resolution_clock::now();
      RunTime = chrono::duration<double>(End-Start).count();
      for(int i = tempMap.size()-1; i >= 0; i--)
        StoredPath.push_back(tempMap.at(i));

}



void A_star::ImplementMatrix(int StartPoint,int EndPoint){       
        StoredPath.clear();
        StoredExploredPath.clear();
        int n = Distance.size();

        int cost[n][n],distance[n],pred[n];
        int visited[n],count,mindistance,nextnode;
        
        auto Start = chrono::high_resolution_clock::now();

    for(int i = 0; i < n; i++)
      for(int j = 0;j < n; j++)
         if(Distance.at(i).at(j) == 0)
             cost[i][j] = 1000000;
         else
             cost[i][j] = Distance.at(i).at(j);          // Cost is the copy of Distance but the unconnected Distance is INFINITE not 0


    for(int i = 0; i < n; i++) {
      distance[i] = cost[StartPoint][i];
      pred[i]=StartPoint;
      visited[i] = 0;                                // Distance initialized with the start point's Distance
    }                                              


   distance[StartPoint] = 0;                       // Distance to startpoint itself is always 0
   visited[StartPoint] = 1;                       // StartPoint is always visited
   StoredExploredPath.push_back(StartPoint);
   count = 1;

   while(count < GraphSize - 1) {
      mindistance = 1000000;
      for(int i = 0;i < GraphSize ;i++)
         if(distance[i] < mindistance && visited[i] == 0) {          // Find = the Closest Point
         mindistance = distance[i];
         nextnode = i;
      }
      visited[nextnode] = 1;                             // Move to the next point
      StoredExploredPath.push_back(nextnode);
      for(int i = 0; i < GraphSize; i++)
         if(!visited[i])
      if(mindistance + cost[nextnode][i] < distance[i]) {
         distance[i] = mindistance + cost[nextnode][i];           // Update closest path
         pred[i] = nextnode;
      }
      count++;
   }    

      vector<int> tempMap;
      tempMap.push_back(EndPoint);
      int j = EndPoint;
      while(j!=StartPoint) {
         j=pred[j];
         tempMap.push_back(j);
      }
      auto End = chrono::high_resolution_clock::now();
      RunTime = chrono::duration<double>(End-Start).count();
      for(int i = tempMap.size()-1; i >= 0; i--)
        StoredPath.push_back(tempMap.at(i));
}

A_star::~A_star(){}