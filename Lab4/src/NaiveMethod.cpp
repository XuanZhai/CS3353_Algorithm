#include "NaiveMethod.h"


using namespace std;

void NaiveMethod::Implement(){               // Naive Solution
    cout << "\nBegin Naive Method..." << endl;
    chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); //High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/

    bool visited[GraphSize];                    // An array to store visit trigger for each number
    int  lastloop[GraphSize];                  // And array to store the last the number for the for loop, so if a number is poped back, we can keep on the last number's loop
    for (int i = 0; i < GraphSize; i++){
        visited[i] = false;
        lastloop[i] = 0;
    }

    vector<int> CurrentPath;
    CurrentPath.push_back(1);
    visited[0] = true;
    int i = 0;
    int newNum = 0;

    while(CurrentPath.size() != 0){                                     // Use while loop to go through all the permutations of points
        int last = CurrentPath.at(CurrentPath.size() - 1);
        i = lastloop[last - 1];

            for(i; i < GraphSize; ++i){
                int newNum = i + 1;
                lastloop[last - 1]++;

                if( newNum == 1 && CurrentPath.size() == GraphSize){     // If Reach the solution, compare it and find another one
                    CurrentPath.push_back(1);
                    ShortCompare(CurrentPath);
                    CurrentPath.pop_back();
                }

                else if( visited[newNum - 1] == false ){                // If a node is not visited,  push to the list
                CurrentPath.push_back(newNum);
                last = newNum;
                i = -1;
                visited[newNum - 1] = true;
            }
        }

        CurrentPath.pop_back();

        visited[last - 1 ] = false;   // If run through all the numbers at the current position, pop it and step back to change the last digit 
        lastloop[last - 1] = 0;
    }
      chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
      RunTime = chrono::duration<double, std::milli>(End-Start);  // high_solution_clock reference:

}


void NaiveMethod::ShortCompare(vector<int>& newPath){             // Compare a new path with the shortest path
    double tempDistance = FindPathDistance(newPath);              // If the cost is smaller, update the path
    if(tempDistance < ShortestDistance){
        ShortestDistance = tempDistance;
        ShortestPath = newPath;
    }
}


double NaiveMethod::FindPathDistance(std::vector<int>& inputPath){     // Find the total distance for a given path
    double total = 0;
    double temp = 0;

    for(int j = 0; j < inputPath.size() - 1; j++){
        temp = Position.at(inputPath.at(j) - 1).at(inputPath.at(j + 1) - 1);
        total = total + temp;                                   
    }
    return total;
}