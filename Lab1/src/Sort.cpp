#include "Sort.h"

using namespace std;

Sort::Sort(){

}


Sort::Sort(int Datatp, int Sorttp){
    DataType = Datatp;                             // Set datatype and algorithm
    SortType = Sorttp;
}


void Sort::Loading(string FileName){
     ifstream inputfile(FileName);
     if(!inputfile){
         cout << "ERROR on Input File" << endl;
         exit(0);
     }
     while (!inputfile.eof())
     {
         int temp;
         inputfile >> temp;
         NumberList.push_back(temp);                 // Read File
     }
     NumberList.pop_back();                        // Pop the last blank space
     inputfile.close();
     
}

void Sort::Execute(){

    if(SortType == 0){
        BubbleSort newBubble;
        elements.push_back(&newBubble);          // Push to Bubble Sort
    }
    else if(SortType == 1){
        InsertSort newInsert;
        elements.push_back(&newInsert);
    }
    else{
        MergeSort newMerge;
        elements.push_back(&newMerge);
    }

    for (SortBase* pointer: elements){
        auto t1 = chrono::high_resolution_clock::now();
        pointer->Implement(NumberList);                                    // Sorting
        auto t2 = chrono::high_resolution_clock::now();
        result = chrono::duration<double, milli>(t2-t1).count();
        }
}

void Sort::Display(){
    if( NumberList.size() == 10){
    for (int i = 0; i < NumberList.size(); i++)
    cout << i + 1 << ": " << NumberList.at(i) << endl;       // Display the sorted list
    }
}

void Sort::Stats(){
            if(SortType == 0)
            cout << "Bubble Sort for ";
            else if (SortType == 1)
            cout << "Insertion Sort for ";
            else
            cout << "Merge Sort for ";
            if (DataType == 0)
            cout << "Random File ";
            else if (DataType == 1)
            cout << "Reversed File ";
            else if (DataType == 2)
            cout << "Unique File ";
            else
            cout << "Partial Sorted File ";
            cout << "took " << result  << "ms" << endl;         //Print the name and time

}


void Sort::Save(string filepath){
    size_t position = filepath.find(".txt"); 
    string basepath = filepath.substr(0, (position));
    ofstream savefile(basepath + "-Sorted.txt");             // Use substring to reset the sorted file name
    if(!savefile){
        cout << "Problem on saving file" << endl;
        exit(0);
    }
    for (int i = 0; i < NumberList.size(); i++){
        savefile << NumberList.at(i) << endl;              // Print sorted array to the file
    }
    savefile.close();

    ofstream SortResult("SortResult.txt",ios_base::app);
    if(!SortResult){
        cout << "Problem on saving file" << endl;
        exit(0);
    } 
            SortResult << "File Size: " << NumberList.size() << endl;
            if(SortType == 0)
            SortResult << "Bubble Sort for ";
            else if (SortType == 1)
            SortResult << "Insertion Sort for ";
            else
            SortResult << "Merge Sort for ";
            if (DataType == 0)
            SortResult << "Random File ";          
            else if (DataType == 1)
            SortResult << "Reversed File ";
            else if (DataType == 2)
            SortResult << "Unique File ";
            else
            SortResult << "Partial Sorted File ";
            SortResult << "took " <<result  << "ms" << endl;         //Print the name and time to the file
            SortResult.close();

}


Sort::~Sort(){

}