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

#define totalpop 100
#define totalnewpop 20
#define length 5

class Numeric {
public:
	Numeric();
	virtual ~Numeric();

	//Generate population
	void generatePop();

	//Evaluation
	void evaluation( int opt ); // 0 - population ; 1 - I1 & I2 ; 2 - I

	//Selection
	void tournment( int G );

	//Crossover
	void crossover();

	//Mutation
	void mutation();

	//Reposition
	void reposition();

	//Auxiliary
	void exportPop(); //Export a csv file with population

	double getValue(int i, int j); // Get a value of i,j element

	void sortPopulation(); // Sort by fitness value

	void updateNewpopulation(int index); //Insert a solution "I" in "newpopulation" structure

private:

	double population[length+1][totalpop] ;
	double newpopulation[length+1][totalnewpop] ;
	double I[length+1], I1[length+1], I2[length+1];

};

#endif /* NUMERIC_H_ */
