/*
 ============================================================================
 Name        : GA.c
 Author      : ebsouza
 Version     : alfa
 Copyright   : Free to use
 Description : Genetic Algorithm for a specific problem in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "GA.h"

int main(void) {

	//Variables to loops
	int i, j;
	int g, r;

	//Parameters
	int N=256;//Solutions in population
	int n=10;//Solutions generated in GA process
	int gerac=300;//Number of generations

	//Structures
	double population[81][N], sons[81][n];
	double I1[81], I2[81], I3[81];

	//Generating initial population
	generatePop( N, population );

	//Evaluation( Only to test )
	evaluation1 ( N, population );

	//Sort
	sort ( N, population);

	//Worst a solution


	//Generation loop
	for (g=0; g<gerac ; g++)
	{
		//Reproduction loop
		for (r=0; r<n; r++)
		{
			//Tournment selection
			//
			//Crossover
			//
			//Fix a solution*
			//
			//Mutation
			//
			//Realocation*
		}

		//Evaluate new solutions
		//
		//Insert new solution generated in population
	}






	//
	//Save info*
	//
	//Change the mutation*
	//
	//Stop condition
	//
	//Save*

	//End generation loop
	//
	//Plot the population



	//-------------------Export area---------------------
	FILE *file;
	file = fopen("/home/rngd1/workspace/GA/src/test.csv","w");
	for (i=0; i<81; i++)
	{
		for (j=0; j<N; j++)
		{
			fprintf(file, "%f  ", population[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	file=0;


	return 0;
}
