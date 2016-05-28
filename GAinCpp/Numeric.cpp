/*
 * Numeric.cpp
 *
 *  Created on: May 27, 2016
 *      Author: rngd1
 */

#include "Numeric.h"
#include <stdio.h>


Numeric::Numeric()
{
}

Numeric::~Numeric()
{
}

void Numeric::generatePop()
{
	int i,j;
	for ( j=0 ; j<totalpop; j++ )
	{
		for ( i=0 ; i<length ; i++ )
		{
			population[i][j]= rand() % 100;
		}
	}
}

void Numeric::exportPop()
{
	int i,j;

	FILE *file;
	file = fopen("/home/rngd1/population.csv","w");
	for (i=0; i<length; i++)
	{
		for (j=0; j<totalpop; j++)
		{
			fprintf(file, "%f  ", population[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	file=0;
}

double Numeric::getValue(int i, int j)
{
	return population[i][j];
}

void Numeric::sortPopulation()
{
	//Insertion sort
	int i=0;
	for ( i=0 ; i<totalpop ; i++)
	{
		int j=0;
		int elected = population[length-1][i];
		double aux[length];

		for ( j=0 ; j<length ; j++)
		{
			aux[j]=population[j][i];
		}

		int z = i - 1 ;

		while ( z>=0  &&  elected<population[length-1][z] )
		{
			for ( j=0 ; j<length ; j++  )
			{
				population[j][z+1] = population[j][z] ;
			}
			z = z-1;
		}

		for ( j=0 ; j<length ; j++  )
		{
			population[j][z+1] = aux[j] ;
		}

	}

}

