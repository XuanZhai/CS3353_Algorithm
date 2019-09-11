#include "BubbleSort.h"

using namespace std;


BubbleSort::BubbleSort(){

}


void BubbleSort::Implement(vector<int>& ListNum){

    int ListSize = ListNum.size();
    for (int i = 0; i < ListSize-1; i++)
        for(int j = 0; j < (ListSize - i - 1); j++){
            if(ListNum.at(j) > ListNum.at(j + 1))           // Swap each round until fully sorted
                swap(ListNum.at(j + 1), ListNum.at(j));
        }
    
    
}


BubbleSort::~BubbleSort(){

}