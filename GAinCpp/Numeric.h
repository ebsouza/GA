/*
 * Numeric.h
 *
 *  Created on: May 27, 2016
 *      Author: rngd1
 */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

#ifndef NUMERIC_H_
#define NUMERIC_H_

#define totalpop 10
#define totalnewpop 10
#define length 5

class Numeric {
public:
	Numeric();
	virtual ~Numeric();

	//Generate population
	void generatePop();

	//Evaluation
	//TODO

	//Selection
	//TODO

	//Crossover
	//TODO

	//Mutation
	//TODO

	//Reposition
	//TODO

	//Auxiliary
	void exportPop(); //Export a csv file with population

	double getValue(int i, int j); // Get a value of i,j element

	void sortPopulation(); // Sort by last element in a row

private:

	double population[length][totalpop] ;
	double newpopulation[length][totalnewpop] ;
	double I1[length], I2[length], I3[length];

};

#endif /* NUMERIC_H_ */
