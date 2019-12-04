#ifndef GENETICALGO_H
#define GENETICALGO_H


#include "FindPathBase.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>                                                            // Pair
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <bits/stdc++.h>                                                   // Shuffle
typedef std::pair<std::vector<int>, double> my_pair;
using namespace std;



class GeneticAlgo: public FindPathBase {
      
public: 
      int size_population;
      int mutation_rate;
      int generations;
      int real_size_population;
      std::vector< my_pair > population;                                                 // Each element is a pair: vector and total cost
      void Implement() override;
      void FindInitial();
      double FindPathDistance(std::vector<int>& solution);                               // Find path distance
      bool ExistsChromosome(const std::vector<int> & v);                                 // Checks if exists the chromosome
      void CrossOver(std::vector<int>&, std::vector<int>&);                              // Makes the crossover
      void Mutation(std::vector<int>&, std::vector<int>&);                              // Makes the mutation
      void InsertBinarySearch(std::vector<int>& child, double total_cost);               // uses Binary search to insert

};


// Sort vector with pair
struct sort_pred
{
	bool operator()(const my_pair& firstElem, const my_pair& secondElem)
	{
		return firstElem.second < secondElem.second;
	}
};


#endif

