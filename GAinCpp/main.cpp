//============================================================================
// Name        : Genetic Algorithm
// Author      : ebsouza
// Version     :
// Copyright   : 
// Description : Genetic Algorithm for a specific problem - Alfa Version
//============================================================================

#include <iostream>
#include "Numeric.h"
using namespace std;

int main() {
	cout << "--------Start--------" << endl;

	//Variables to loops
	int i, j;
	int g, r;

	//Parameters
	int G=16;//First tournament group, it need to be power of two
	int gerac=5;//Number of generations
	int ktclysm=0, tol=100, repop=4; //Cataclysm event

	//Structures
	double radiusInfo[gerac];

	Numeric sol;

	sol.generatePop();

	sol.sortPopulation();

	sol.exportPop();

	cout << "--------End--------" << endl;

	return 0;
}
