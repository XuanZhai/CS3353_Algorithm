#include <iostream>
#include "Algorithm.h"
#include "Sort.h"

using namespace std;


int main(int argc, char* argv[]){

   for(int i = 0; i < 4; i ++){                                                // For each Data types
       for(int j = 0; j < 3; j ++){                                           // For each Algorithms
        for(int k = 0; k < 4; k++){
           Sort newSort(i,j);                                                // Create a object
           string namelist = "MakeData/List " + to_string(k) + "-" + to_string(i) + ".txt";    // We can set the data size we want to sort
           newSort.Loading(namelist);                          
           newSort.Execute();                 
           newSort.Display();
           newSort.Stats();
           newSort.Save(namelist);
        }
       }
   }
    return 0;
}