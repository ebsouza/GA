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
	int G=16;//First tournament group, it need to be power of two
	int gerac=5;//Number of generations
	int ktclysm=0, tol=100, repop=4; //Cataclysm event

	//Statistics
	double radiusInfo[gerac];

	//Start the optimization process
	cout << "--------Start--------" << endl;
	
	Numeric sol;

	sol.generatePop();

	sol.sortPopulation();

	sol.exportPop();

	cout << "--------End--------" << endl;

	return 0;
}
