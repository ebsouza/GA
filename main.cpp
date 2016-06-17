//============================================================================
// Name        : Genetic Algorithm
// Author      : ebsouza
// Version     :
// Copyright   : 
// Description : Genetic Algorithm
//============================================================================

#include <iostream>
#include "Numeric.h"
using namespace std;

int main() {
	
	//Variables to loops
	int i, j;
	int g, r;

	//Parameters
	int G=32;//First tournament group, it need to be power of two
	int gerac=100;//Number of generations

	//Statistics
	double fitnessInfo[gerac];

	//Start the optimization process
	cout << "--------Start--------" << endl;
	
	Numeric sol;

	sol.generatePop();

	sol.evaluation(0);

	sol.sortPopulation();

	//Generation loop
	for (g=0; g<gerac ; g++)
	{
		//Reproduction loop
		for (r=0; r<totalnewpop; r++)
		{
			//Tournment selection
			sol.tournment(G);

			//Crossover
			sol.crossover();

			//Eval the new solution
			sol.evaluation(2);

			//Mutation
			sol.mutation();

			//Insert a new solution in newpopulation structure
			sol.updateNewpopulation(r);

		}

		//Reposition
		sol.reposition();

		//Store best fitness
		fitnessInfo[g]=sol.getValue(length,0);
	}

	//See best fitness in every generation
	for (i=0;i<gerac;i++)
	{
		cout<<fitnessInfo[i]<<endl;
	}

	//See all population fitness
	for (i=0;i<totalpop;i++)
	{
		cout<< sol.getValue(length,i)<<endl;
	}

	cout << "--------End--------" << endl;

	return 0;
}
