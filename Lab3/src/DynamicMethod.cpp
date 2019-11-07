#include "DynamicMethod.h"


using namespace std;


 void DynamicMethod::Implement(){
    unsigned long int pastnode = 1;           // Number of branch
    unsigned long int travelstart = 0;
    for(int a = 2; a < GraphSize; a++){
        pastnode = pastnode * a + 1;          //  Number of child * number of branch in each child + head. Choose unsigned long int because pastnode will increase factorially
    }
    Totaltraveled = new int[pastnode];     // Create a array to store those branches
    vector<int> Untraveled;
    for (int i = 0; i < GraphSize; i++){
        Untraveled.push_back(i + 1);       // Untravel Nodes 1,2,3......
    }

    cout << "Begin Dynamic Method..." << endl;

    chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); // High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
    ShortestDistance =  FindShortestPath(1, Untraveled, travelstart);         
    chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double>(End-Start);       

    Untraveled.erase(Untraveled.begin());
    ShortestPath.push_back(1);                // Start at 1
    FindNodes(0, pastnode - 1, Untraveled);   // Find the exact path for the shortest distance
    ShortestPath.push_back(1);                // End at 1
    delete Totaltraveled;
}


double DynamicMethod::FindShortestPath(int End, std::vector<int> untraveled, unsigned long int& travelnum){  // Dynamic method reference
    for(int a = 0; a < untraveled.size(); a++){                                             //https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/ 
        if(untraveled.at(a) == End){
            untraveled.erase(untraveled.begin() + a);
            break;
        }
    }

    if(untraveled.size() == 0){
        return Position.at(End - 1).at(0);
    }
    else{
        double totaldist = INT_MAX;
        int node = 0;
        for(int i = 0; i < untraveled.size(); i++){
            double tempdist = FindShortestPath(untraveled.at(i), untraveled,  travelnum);
            if(totaldist > ( tempdist + Position.at(untraveled.at(i) - 1).at(End - 1) )){
                totaldist = ( tempdist + Position.at(untraveled.at(i) - 1).at(End - 1) );
                node = untraveled.at(i);
            }
        }
        Totaltraveled[travelnum] = node;        // Push the shortest point of the branch to the array
        travelnum++;                            // Increment how many branch achieved so far
        return totaldist;
    }
}


void DynamicMethod::FindNodes(int Start, int End, std::vector<int>& Remain){
    if(Remain.size() == 0){
        return;
    }
    else{
        int head = Totaltraveled[End];         // Find the head
        ShortestPath.push_back(head);          // Head becomes the previous achieved point
        int i;
        for(i = 0; i < Remain.size(); i++){
            if(Remain.at(i) == head){
                Remain.erase(Remain.begin() + i);   // If visited, erased the point
                break;
            }
        }
        int Newstart =  Start + (End - Start) / (Remain.size() + 1) * i;
        int Newend = Newstart + (End - Start)/ (Remain.size() + 1) - 1;   // Reset the start and end part of the segment
        FindNodes(Newstart, Newend, Remain);   
        return;
    }
}
