#include "GeneticAlgo.h"
#include <algorithm> // sort, next_permutation


using namespace std;

 void GeneticAlgo::Implement(){            // Partial referenced https://github.com/marcoscastro/tsp_genetic/blob/master/src/tsp.cpp
    cout << "\nBegin Genetic Method" << endl;
	ofstream outfile("Genetic.txt");
    chrono::high_resolution_clock::time_point Start = chrono::high_resolution_clock::now(); //High_resolution_close reference: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
    size_population = 15;
    generations = 200;
    mutation_rate = 4;
    real_size_population = 0;
    FindInitial();
    
    for(int i = 0; i < generations; i++){
        int old_size_population = real_size_population;
        if(real_size_population >= 2){
            if(real_size_population == 2){
                CrossOver(population[0].first, population[1].first);
            }
            else{
                int parent1, parent2;			
				do{
					parent1 = rand() % real_size_population;                                  // Select two random parents
					parent2 = rand() % real_size_population;
				}while(parent1 == parent2);
				
				CrossOver(population[parent1].first, population[parent2].first);             // Applying crossover in the two parents
            }
        int diff_population = real_size_population - old_size_population;

		if(diff_population == 2){
			if(real_size_population > size_population){           // Removes the two worst parents of the population
			population.pop_back();
			population.pop_back();				                  // Decrements the real_size_population in 2 units
			real_size_population -= 2;
            }
		}
		else if(diff_population == 1){
			if(real_size_population > size_population){
				population.pop_back();                            // Removes the worst parent of the population
				real_size_population--;                           // Decrements the real_size_population in the unit
				}
			}        
        }
        else{                                                          // Applying crossover in the parent
			CrossOver(population[0].first, population[0].first);	
			if(real_size_population > size_population){
				population.pop_back();                                // removes the worst parent of the population
				real_size_population--;                               // decrements the real_size_population in the unit
			}      
        }
		vector<int> vec = population[0].first;
		vec.insert(vec.begin(), 1);
		vec.push_back(1);
		ShortestPath = vec;
		ShortestDistance = population[0].second;
		//if(ShortestPath.size() > 13)
		outfile << ShortestDistance << endl;
    }
    chrono::high_resolution_clock::time_point End = chrono::high_resolution_clock::now();
    RunTime = chrono::duration<double, std::milli>(End-Start);              // High_solution_clock
	outfile.close();
    
 }


void GeneticAlgo::FindInitial(){
	vector<int> parent;
	unsigned int seed = 0;                                              // Creates the parent
	for(int i = 2; i <= GraphSize; i++){
			parent.push_back(i);
	}
	double total_cost = FindPathDistance(parent);
	
	population.push_back(make_pair(parent, total_cost));               // Inserts in the population
	real_size_population++;                                            // Increments real_size_population
	
	for(int i = 0; i < generations; i++){                                   // generates a path, but it does not include 1
		shuffle(parent.begin(), parent.end(), default_random_engine(seed)); 
		double total_cost = FindPathDistance(parent);                   // Find its cost
		
		if(!ExistsChromosome(parent)){									// checks if not exists
			population.push_back(make_pair(parent, total_cost));       // Add in population
			real_size_population++;                                    // Increments real_size_population in the unit
		}
		if(real_size_population == size_population)                    // Checks size population
			break;
	}

	sort(population.begin(), population.end(), sort_pred());            // Sort population
}


double GeneticAlgo::FindPathDistance(vector<int>& solution){            // Find the distance for a path 

    double total = 0;
    double temp = 0;

    for(int j = 0; j < solution.size() - 1; j++){
        temp = Position.at(solution.at(j) - 1).at(solution.at(j + 1) - 1);
        total = total + temp;                                   
    }

	total = total + Position.at(0).at(solution.at(0) - 1);                   // Add the distance from 1 to the first node, from the last node to 1
	total = total + Position.at(0).at(solution.at(solution.size() - 1) - 1);
    return total;
}


bool GeneticAlgo::ExistsChromosome(const vector<int> & v)
{
	for(vector<pair<vector<int>, double> >::iterator it=population.begin(); it!=population.end(); ++it)        // Checks if exists in the population
	{
		const vector<int>& vec = (*it).first;                         // Gets the vector
		if(equal(v.begin(), v.end(), vec.begin()))                   // Compares vectors
			return true;
	}
	return false;
}


void GeneticAlgo::CrossOver(vector<int>& parent1, vector<int>& parent2){                // Order Crossover Operator 

    int newsize = parent1.size();                                      // Since the path does not have 1, it should be smaller than the graphsize  
	int child1[GraphSize - 1], child2[GraphSize - 1];
	bool visit1[GraphSize - 1], visit2[GraphSize - 1];
	vector<int> vchild1, vchild2;
	
	for(int i = 0; i < newsize; i++){
		visit1[i] = false;
		visit2[i] = false;
		child1[i] = 0;
		child2[i] = 0;
	}
	
	int point1 = rand() % (newsize);                                  // Generates random points to substring
	int point2 = rand() % (newsize - point1) + point1;
	
	if(point1 == point2){											// Adjusts the points if they are equal
	 	if(point1 - 1 > 1)
	 		point1--;
	 	else if(point2 + 1 < GraphSize - 1)
	 		point2++;
	 	else{
	 		int point = rand() % 10 + 1;                          // number in the range 1 to 10
	 		if(point <= 5)
	 			point1--;
	 		else
	 			point2++;
	 	}
	}

	for(int i = point1; i < point2; i++){
		child1[i] = parent1[i];
		child2[i] = parent2[i];
		visit1[parent1[i] - 2] = true;
		visit2[parent2[i] - 2] = true;                   // Children should have the substring we choose
	}
	vector<int> temp1;
	for(int i = point2; i < newsize; i++){               // Fill the rest of the child 1 based on the idea of Order Crossover
		temp1.push_back(parent1.at(i));
	}
	for(int i = 0; i < point2; i++){
		temp1.push_back(parent1.at(i));
	}

	for(int i = point2; i < newsize; i++){
		for(int j = 0; j < temp1.size(); j++){
			if(visit2[temp1.at(j)-2] == false){
				child2[i] = temp1.at(j);
				visit2[temp1.at(j)-2] = true;
				break;
			}
		}
	}
	for(int i = 0; i < point2; i++){
		for(int j = 0; j < temp1.size(); j++){
			if(visit2[temp1.at(j)-2] == false){
				child2[i] = temp1.at(j);
				visit2[temp1.at(j)-2] = true;
				break;
			}
		}
	}

	vector<int> temp2;                              // Fill the rest of the child 2 based on the idea of Order Crossover
	for(int i = point2; i < newsize; i++){
		temp2.push_back(parent2.at(i));
	}
	for(int i = 0; i < point2; i++){
		temp2.push_back(parent2.at(i));
	}
	for(int i = point2; i < newsize; i++){
		for(int j = 0; j < temp2.size(); j++){
			if(visit1[temp2.at(j)-2] == false){
				child1[i] = temp2.at(j);
				visit1[temp2.at(j)-2] = true;
				break;
			}
		}
	}
	for(int i = 0; i < point2; i++){
		for(int j = 0; j < temp2.size(); j++){
			if(visit1[temp2.at(j)-2] == false){
				child1[i] = temp2.at(j);
				visit1[temp2.at(j)-2] = true;
				break;
			}
		}
	}

	for(int i = 0; i < newsize; i++){                   // Transform the children from int array to vector 
		vchild1.push_back(child1[i]);
		vchild2.push_back(child2[i]);
	}

	Mutation(vchild1,vchild2);
}


void GeneticAlgo::Mutation(std::vector<int>& child1, std::vector<int>& child2){                              // Make a mutation: change of two genes
	int mutation = rand() % 100 + 1;                                                                        // Random number in [1,100]
	if(mutation <= mutation_rate){                                                                        // Checks if the random number <= mutation rate	
		int index_gene1, index_gene2;
		index_gene1 = rand() % (GraphSize - 2) + 1;
		index_gene2 = rand() % (GraphSize - 2) + 1;		

		int aux = child1[index_gene1];																	// makes for child1
		child1[index_gene1] = child1[index_gene2];
		child1[index_gene2] = aux;
		
		aux = child2[index_gene1];                                                                      // makes for child2
		child2[index_gene1] = child2[index_gene2];
		child2[index_gene2] = aux;
	}
	
	double total_cost_child1 = FindPathDistance(child1);
	double total_cost_child2 = FindPathDistance(child2);
	

	if(!ExistsChromosome(child1)){
		InsertBinarySearch(child1, total_cost_child1);                                               // Uses binary search to insert
		real_size_population++;                                                                     // Increments the real_size_population
	}
	
	if(!ExistsChromosome(child2)){
		InsertBinarySearch(child2, total_cost_child2);                                          // Uses binary search to insert
		real_size_population++;                                                                // Increments the real_size_population
	}
}


void GeneticAlgo::InsertBinarySearch(vector<int>& child, double total_cost)
{
	int imin = 0;
	int imax = real_size_population - 1;
	
	while(imax >= imin){
		int imid = imin + (imax - imin) / 2;
		
		if(total_cost == population[imid].second){
			population.insert(population.begin() + imid, make_pair(child, total_cost));
			return;
		}
		else if(total_cost > population[imid].second)
			imin = imid + 1;
		else
			imax = imid - 1;
	}
	population.insert(population.begin() + imin, make_pair(child, total_cost));
}