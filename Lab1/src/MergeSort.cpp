#include "MergeSort.h"

using namespace std;


MergeSort::MergeSort(){

}

void MergeSort::Implement(vector<int>& ListNum){
    int ListSize = ListNum.size();
    int left = 0;
    int right = ListSize- 1;          // Set left and right trigger
    MSort(ListNum, left, right);
}

void MergeSort::MSort(vector<int>& ListNum, int left, int right){
    if (left < right) { 
        int middle = left+ (right - left) / 2; 
 
        MSort(ListNum, left, middle);             // Seperate the left part
        MSort(ListNum, middle + 1, right);        // Seoerate the right part
  
        Merging(ListNum, left, middle, right); 
    } 
}

void MergeSort::Merging(vector<int>& ListNum, int left, int middle, int right){
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    vector<int> tempL;
    vector<int> tempR;             // Create two temp array
  
    for (i = 0; i < n1; i++) 
        tempL.push_back(ListNum.at(left+i));       // Copy the left part to array
    for (j = 0; j < n2; j++) 
         tempR.push_back(ListNum.at(middle + 1+ j));  // Copy the right part to array
  

    i = 0; 
    j = 0; 
    k = left;                         // Set left and middle
    while (i < n1 && j < n2) 
    { 
       if(tempL.at(i) <= tempR.at(j))
        { 
            ListNum.at(k) = tempL.at(i);  //Sort the left and right parts and put them back to the list
            i++; 
        } 
        else
        { 
           ListNum.at(k) = tempR.at(j);
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
       ListNum.at(k) = tempL.at(i);        //Since each part is already sorted, we just put them back
        i++;  
        k++; 
    } 
  
    while (j < n2) 
    { 
       ListNum.at(k) = tempR.at(j);
        j++; 
        k++; 
    } 
}


MergeSort::~MergeSort(){

}