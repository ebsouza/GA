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
#include "SecondaryFunctions.h"

int main(void) {

	//Variables to loops
	int i, j;
	int g, r;

	//Parameters
	int N=256;//Solutions in population
	int n=10;//Solutions generated in GA process
	int G=16;//First tournament group, it need to be power of two
	int gerac=50;//Number of generations
	int ktclysm=0, tol=100, repop=4; //Cataclysm event

	//Structures
	double population[81][N], sons[81][n];
	double I1[81], I2[81], I3[81];
	double radiusInfo[gerac];
	double newpopulation[81][N/repop];

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
			selector( N, population, G, I1, I2 );

			//Crossover
			crossover( N, I1, I2, I3 );

			//Fix a solution*
			repair( I3 );

			//Mutation
			mutation( I3 );

			//Realocation*
			realocn( I3 );

			//Insert "I3" in "sons"
			for ( i=0 ; i<80 ; i++)
			{
				sons[i][r]=I3[i];
			}
		}

		//Evaluate new solutions
		evaluation1 ( n, sons );

		//Insert new solution generated in population
		reposition( N, n, population, sons ) ;

		//Sort
		sort( N, population);

		//Save the population best radius
		radiusInfo[g]=population[80][0];


		if (g>2)
		{
			//Cataclysm
			if ( radiusInfo[g-1] == radiusInfo[g])
			{
				ktclysm+=1;
			}
			else
			{
				ktclysm=0;
			}


			//Condition to start cataclysm
			if ( ktclysm==tol )
			{
				cataclysm( N, N/repop, population, newpopulation );
				ktclysm=0;
			}
		}

	}



	//-------------------Export area---------------------

	//Last population
	FILE *file;
	file = fopen("~/workspace/GA/src/population.csv","w");
	for (i=0; i<81; i++)
	{
		for (j=0; j<N; j++)
		{
			fprintf(file, "%f  ", population[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);

	//RadiusInfo
	file = fopen("~/workspace/GA/src/radius.csv","w");
	for (i=0; i<gerac; i++)
	{
		fprintf(file, "%f  \n", radiusInfo[i]);
	}
	fclose(file);

	//delete file;
	file=0;


	return 0;
}
