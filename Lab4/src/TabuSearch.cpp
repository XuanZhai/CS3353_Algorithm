#include "TabuSearch.h"


using namespace std;


TabuSearch::TabuSearch(){
    ReShuffle = 0;
    LocalShortDistance = INT_MAX;
}

void TabuSearch::Implement(){                                          // Tabu Search Solution
    cout << "Begin Tabu Search Method" << endl;
	ofstream outfile("Tabu.txt");
    ofstream outglobal("TabuGlobal.txt");
    chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); //High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
    FindRandom();
    for(int a = 0; a < 200; a++){                                     // Number of Iteration / Generation
        if(ReShuffle >= 50){                                     
            FindRandom();                                            // Jump out of local minimum and reset the path
            ReShuffle = 0;
        }
        FindNeighborhood();                                          // Find Neighborhood to fill the movinglist
        for(int i = 0; i < MovingList.size(); i++){
            if(!OnTabuList(MovingList.at(i))){                       // If the moving choice is not on the tabu list
                if(currentTabu == 4){                                // Since the tabu list size is 5, if the current combination is the 4th,  
                    currentTabu = 0;                                 // the next will replace the first combination on the tabu list
                }
                TabuList[currentTabu][0] = MovingList.at(i).at(0);
                TabuList[currentTabu][1] = MovingList.at(i).at(1);    // Write the current swipping combination into the tabu list
                currentTabu++;
                LocalShortPath = SwapPath(LocalShortPath,MovingList.at(i).at(0), MovingList.at(i).at(1));
                LocalShortDistance = LocalShortDistance + MovingDistance.at(i);
                if(LocalShortDistance < ShortestDistance){            // If the new path is shorter than the global, update the global path 
                    ShortestDistance = LocalShortDistance;
                    ShortestPath = LocalShortPath;
                    ReShuffle = 0;
                }
                else{
                    ReShuffle++;
                }
                break;
            }
            else if(OnTabuList(MovingList.at(i)) && (LocalShortDistance + MovingDistance.at(i) < ShortestDistance)){    // Aspiration criterion
                LocalShortPath = SwapPath(LocalShortPath,MovingList.at(i).at(0), MovingList.at(i).at(1));
                LocalShortDistance = LocalShortDistance + MovingDistance.at(i);
                ShortestDistance = LocalShortDistance;
                ShortestPath = LocalShortPath;
                ReShuffle = 0;
                break;
            }
        }
        if(ReShuffle != 0){
            ReShuffle++;
        }
        //if(ShortestPath.size() > 13)
    outfile << LocalShortDistance << endl;                    // We set the distance as the fitness
    outglobal << ShortestDistance << endl;
    }
    chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double, std::milli>(End-Start);                              // high_solution_clock reference:
    outfile.close();
    outglobal.close();

}



void TabuSearch::FindRandom(){
    for(int a = 0; a < 5; a++){                                          // Resset the Tabu list
        for(int i = 0; i < 2; i++)
            TabuList[a][i] = 0;
    }
    currentTabu = 0;

    LocalShortPath.clear();
    LocalShortDistance = 0;                                            // Reset the local path
    for(int i = 2; i <= GraphSize; i++){
        LocalShortPath.push_back(i);
    }
    std::random_shuffle(LocalShortPath.begin(), LocalShortPath.end());        // Shuffle to create a random path
    LocalShortPath.insert(LocalShortPath.begin(), 1);
    LocalShortPath.push_back(1);
    LocalShortDistance = FindPathDistance(LocalShortPath);                          
    if(ReShuffle == 0){
        ShortestPath = LocalShortPath;
        ShortestDistance = LocalShortDistance;                           // If it is the initialization, we need to update the global minimum
    }
}


void TabuSearch::FindNeighborhood(){                  // The moving list is sorted based on the distance change from low to high (and negative to positive)
    MovingDistance.clear();
    MovingList.clear();
    for(int a = 1; a < GraphSize - 1; a++){
        for(int i = a + 1; i < GraphSize; i++){
            vector<int> tempswap;
            vector<int> SwapedPath;
            tempswap.push_back(LocalShortPath.at(a));
            tempswap.push_back(LocalShortPath.at(i));
            SwapedPath = SwapPath(LocalShortPath, LocalShortPath.at(i), LocalShortPath.at(a));
            double DistanceChange =  FindPathDistance(SwapedPath) - FindPathDistance(LocalShortPath);
            if(MovingDistance.size() == 0){
                MovingDistance.push_back(DistanceChange);
                MovingList.push_back(tempswap);
            }
            else{
                bool inserted = false;
                for(int j = 0; j < MovingDistance.size(); j++){
                    if(MovingDistance.at(j) > DistanceChange){
                        MovingDistance.insert(MovingDistance.begin() + j, DistanceChange);
                        MovingList.insert(MovingList.begin() + j, tempswap);
                        inserted = true;
                        break;
                    }
                }
                if(inserted == false){
                    MovingList.push_back(tempswap);
                    MovingDistance.push_back(DistanceChange);
                }
            }
        }
    }  
}



vector<int> TabuSearch::SwapPath(std::vector<int>& Path, int a, int b){            //  Swap a and b in the Path
    vector<int> temp = Path;
    for(int i = 0; i < temp.size(); i++){
        if(temp.at(i) == a)
            temp.at(i) = b;
        else if (temp.at(i) == b)
            temp.at(i) = a;
    }
    return temp;
}


double TabuSearch::FindPathDistance(std::vector<int>& inputPath){     // Find the total distance for a given path
    double total = 0;
    double temp = 0;

    for(int j = 0; j < inputPath.size() - 1; j++){
        temp = Position.at(inputPath.at(j) - 1).at(inputPath.at(j + 1) - 1);
        total = total + temp;                                   
    }
    return total;
}


bool TabuSearch::OnTabuList(std::vector<int>& newPair){                     // Check whether the pair(use a vectoer there) is in the Tabu list
     for(int i = 0; i < 5; i++){     
        if(TabuList[i][0] == newPair.at(0) && TabuList[i][1] == newPair.at(1))
            return true;
        else if (TabuList[i][0] == newPair.at(1) && TabuList[i][1] == newPair.at(0))
            return true;
     }
     return false;
}