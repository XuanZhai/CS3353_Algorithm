#include <iostream>
#include "Algorithm.h"
#include "FindPath.h"



using namespace std;



int main(int argc, char* argv[]){

    Algorithm* newAlgo = new FindPath();

     for (int i = 0; i < 4; i++){
         newAlgo->Load("positions.txt");
         newAlgo->Execute();
         newAlgo->Select(i);
     }

    delete newAlgo;

    return 0;
}