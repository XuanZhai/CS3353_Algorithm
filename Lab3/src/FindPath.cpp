#include "FindPath.h"

using namespace std;


FindPath::FindPath(){
     CurrentMethod = new NaiveMethod();                // Native method is the default method
}


void FindPath::Load(vector<vector<double>>& inputPosition){
     CurrentMethod->SetPosition(inputPosition);                  // Set the Position table from main
}


void FindPath::Execute(){
     CurrentMethod->Implement();                                                            // Implement the Naive/Dynamic Programming
     CurrentMethod->PrintOutput();                                                          // Print out the path
     cout << "The runtime is " << CurrentMethod->RunTime.count() << " seconds" << endl;     // Return the time
}


void FindPath::Select(){
     delete CurrentMethod;
     CurrentMethod = new DynamicMethod();                                                 // Switch to Dynamic Programming
}


FindPath::~FindPath(){
     delete CurrentMethod;
}