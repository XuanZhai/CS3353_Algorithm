#include "TSPTableNode.h"




TSPTableNode::TSPTableNode(){
    Id = 0;
    Total = 0;
    Pathtotal = 0;
}


TSPTableNode::TSPTableNode(const TSPTableNode& newNode){
    Id = newNode.Id;
    Total = newNode.Total;
    Pathtotal = newNode.Pathtotal;
    Path = newNode.Path;
    LocalPosition = newNode.LocalPosition;
} 

TSPTableNode TSPTableNode::operator= (const TSPTableNode& newNode){
    Id = newNode.Id;
    Total = newNode.Total;
    Pathtotal = newNode.Pathtotal;
    Path = newNode.Path;
    LocalPosition = newNode.LocalPosition;
    return *this;
}


TSPTableNode::TSPTableNode(int Newid, std::vector<std::vector<double>>& GlobalPosition){
    Id = Newid;
    LocalPosition = GlobalPosition;
    Total = 0;
    Pathtotal = 0;
}


void TSPTableNode::FindTotal(){                                    // A function to create new total
    if(Path.size() == 0){
        Total = LocalPosition.at(Id - 1).at(0);                   // For the nodes on the second layer, there is no path for them so the distance is from id to 1
    }
    else{
        Total = Pathtotal + LocalPosition.at(Id - 1).at(Path.at(0) - 1);   // Else the total is from id to the first member in the list + the distance in the Path
    }
}


TSPTableNode::~TSPTableNode(){}