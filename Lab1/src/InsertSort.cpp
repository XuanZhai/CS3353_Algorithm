#include "InsertSort.h"

using namespace std;


InsertSort::InsertSort(){

}


void InsertSort::Implement(vector<int>& ListNum){

    int j = 0;
    int target = 0;          
    int ListSize = ListNum.size();
     for (int i = 1; i < ListSize; i++) {    // Target that needs to put
         target = ListNum.at(i);  
         j = i - 1;  
  
     while (j >= 0 && ListNum.at(j) > target){
            ListNum.at(j + 1) = ListNum.at(j);   // Keep finding its sorted location
            j = j - 1;
     }   
         ListNum.at(j + 1) = target;    // Insert the target in
     }  
    
}


InsertSort::~InsertSort(){

}