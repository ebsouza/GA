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

void Numeric::evaluation( int opt )
{
	double fitness;
	int i,j;
	switch ( opt )
	{
		//Eval population
		case 0:
			for ( i=0 ; i<totalpop ; i++)
			{
				fitness = population[0][i] + 2*population[3][i] + 10 ;
				population[length][i] = fitness ;
			}
			break;
		//Eval I1 & I2
		case 1:
			fitness = I1[0] + 2*I1[3] + 10 ;
			I1[length] = fitness ;

			fitness = I2[0] + 2*I2[3] + 10 ;
			I2[length] = fitness ;
			break;
		//Eval I
		case 2:
			fitness = I[0] + 2*I[3] + 10 ;
			I[length] = fitness ;
			break;
	}
}

void Numeric::crossover()
{
	int i;
	for ( i=0 ; i< length ; i++)
	{
		I[i]=(I1[i] + I2[i])/2 ;
	}
}

void Numeric::tournment(int G)
{
	 int i=0;

	 //Variables
	 int random1;
	 int random2;
	 int choose;
	 int g=G/2;
	 double percentage;
	 double total;

	 //Structure
	 double T[2][G];
	 double AUX[2][g];

	 //Select some solutions from population
	 for ( i=0 ; i<G ; i++)
	 {
		 choose = rand() % totalpop;
		 T[0][i] = choose; //Solution selected index
		 T[1][i] = population[length][choose]; //Solution selected radius
	 }
	 //Condition to terminate the tournament
	 while ( G>2 )
	 {
		 //Tournament
		 for ( i = 0 ; i < g ; i++)
		 {
			 //Generate two random numbers
			 random1 = rand() % 2*g ;
			 random2 = rand() % 2*g ;
			 while ( random1 == random2 )
			 {
				 random2 = rand() % G ;
			 }

			 //Probability variable
			 percentage = (double)(rand() % 100 )/100 ;
			 //Let's start the tournament
			 total = T[1][random1] + T[1][random2];
			 if ( percentage < ( total - T[1][random1] )/total  )
			 {
				 AUX[0][i] = T[0][random1];
				 AUX[1][i] = T[1][random1];
			 }
			 else
			 {
				 AUX[0][i] = T[0][random2];
				 AUX[1][i] = T[1][random2];
			 }
		 }

		 //Replacement of solutions in T structure
		 for ( i=0; i<g ; i++)
		 {
			 T[0][i] = AUX[0][i] ;
			 T[1][i] = AUX[1][i] ;
		 }

		 G=G/2;
		 g=g/2;

	}

	 //Selected solutions
	 for ( i=0 ; i<length ; i++)
	 {
		 I1[i] = population[i][ (int)T[0][0] ];
		 I2[i] = population[i][ (int)T[0][1] ];
	 }
}

void Numeric::mutation()
{
	int i;

	//seed
	srand( time( NULL ) );

	//random number
	double random = (double)( rand() % 101 )/100 ;

	for ( i=0 ; i< length ; i++)
	{
		if ( random < 0.4)
		{
			I[i] = rand() % 50;
		}
	}

}

void Numeric::reposition()
{
	//totalpop must be greater than totalnewpop
	int i,j, k = totalpop - totalnewpop ;
	for ( i=0 ; i<totalnewpop ; i++ )
	{
		for ( j=0 ; j<length ; j++)
		{
			population[j][i+k]=newpopulation[j][i];
		}
	}

	sortPopulation();
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

