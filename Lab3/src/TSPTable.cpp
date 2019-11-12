#include "TSPTable.h"


TSPTable::TSPTable(){
    TotalHeight = 0;
}


TSPTable::TSPTable(const TSPTable& newTable){
    TotalHeight = newTable.TotalHeight;
    Table = newTable.Table;
    GlobalPosition = newTable.GlobalPosition;
    Untraveled = newTable.Untraveled;
}


TSPTable TSPTable::operator= (const TSPTable & newTable){
    TotalHeight = newTable.TotalHeight;
    Table = newTable.Table;
    GlobalPosition = newTable.GlobalPosition;
    Untraveled = newTable.Untraveled;
    return *this;
}


TSPTable::TSPTable(int newHeight, std::vector<int>& newUntraveled, const std::vector<std::vector<double>>& newPosition){
    for(int i = 0; i < newHeight; i++){
        std::vector<TSPTableNode> tempTable; 
        Table.push_back(tempTable);
    }
    TotalHeight = newHeight;
    Untraveled = newUntraveled;
    GlobalPosition = newPosition;
}


void TSPTable::BuildTable(){
    for (int a = 0; a < Untraveled.size(); a++){
        TSPTableNode NewNode(a + 2, GlobalPosition);
        NewNode.FindTotal();                          // In the first layer of the table, each member is from i to 1 (i = 2, 3, 4...) and has no middle path
        Table.at(0).push_back(NewNode);               // We fill the first layer of table
    }
    for (int i = 0; i < (TotalHeight - 2); i++){       // We use a for loop to fill the table from the second layer to the last second layer
        FillTable(Table.at(i), Table.at(i + 1));
    }
}


void TSPTable::FillTable(std::vector<TSPTableNode>& UpList, std::vector<TSPTableNode>& DownList){
    for (int a = 0; a < UpList.size(); a++){           // For each member in the upper layer

        std::vector<int> newpath = UpList.at(a).Path;  
        newpath.insert(newpath.begin(),  UpList.at(a).Id);  // We create a new list for the lower layer like if the upper is (2{3}), the path for the lower layer will be {2,3}     

        for (int i = 0; i < Untraveled.size(); i++){            
            if(OnPath(Untraveled.at(i), newpath) == false){              // For each number that the number has not traveled,
                TSPTableNode NewNode(Untraveled.at(i), GlobalPosition);      // We create a new node for them we with that id 
                NewNode.Path = newpath;                               
                NewNode.Pathtotal = UpList.at(a).Total;               // The path total is the upper list's total
                NewNode.FindTotal();                                 // We use a function to find the node's total
                CompareNode(NewNode, DownList);                     // We find a proper position for the new node on the lower layer
             }
         }
     }
}


TSPTableNode TSPTable::FindAnswer(){                            // A function to fill the last layer of the table
    TSPTableNode NewNode(1, GlobalPosition);                   // Since it starts at 1, so the id is 1
    double shortest = INT_MAX;
    for(int a = 0; a < Table.at(TotalHeight - 2).size(); a++){          // For all the nodes on the last second layer
        double localshortest = GlobalPosition.at(Table.at(TotalHeight - 2).at(a).Id - 1).at(0) + Table.at(TotalHeight - 2).at(a).Total; // Return the distance from 1 to the node's path
        if(localshortest < shortest){                                  // If we find a shorter path
            NewNode.Total = localshortest;
            NewNode.Pathtotal = Table.at(TotalHeight - 2).at(a).Total;                // We update the data in the newnode
            std::vector<int> temppath;
            temppath =Table.at(TotalHeight - 2).at(a).Path;
            temppath.insert(temppath.begin(), Table.at(TotalHeight - 2).at(a).Id);
            NewNode.Path = temppath;
        }
    }
    Table.at(TotalHeight - 1).push_back(NewNode);                // Fill the last layer
    return NewNode;                                            
}


bool TSPTable::OnPath(int target, std::vector<int>& List){          // A function to test whether a number is in the vector 
    if(List.size() == 0){
        return false;
    }

    for(int i = 0; i < List.size(); i++){
        if(List.at(i) == target)
            return true;
    }
    return false;
}


void TSPTable::CompareNode(TSPTableNode& newNode, std::vector<TSPTableNode>& List){     // A function to compare a new TSPTable node with the lower layer
    bool bigtrigger = true;

    for(int i = 0; i < List.size(); i++){                                // For each member in the lower layer
        if(List.at(i).Id == newNode.Id){                                 // If they have the same id and path (path may be different in order)
            bool smalltrigger = true;
            for(int j = 0; j < newNode.Path.size(); j++){
                if(OnPath(newNode.Path.at(j), List.at(i).Path) == false){
                    smalltrigger = false;
                    break;
                }
            }

            if(smalltrigger == true){
                if(newNode.Total < List.at(i).Total){
                    List.at(i) = newNode;                          // If the newnode has shorter distance, update the node on the lower layer
                    return;
                }
                else{
                    bigtrigger = false;                          // If the newnode has larger distance, we won't put it into the layer
                }
            }
        }
    }

    if(bigtrigger == true){
        List.push_back(newNode);                                // If there is no such node, we push the newnode to the last
    }
}

TSPTable::~TSPTable(){}