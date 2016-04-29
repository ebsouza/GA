/*
 * SecondaryFunctions.c
 *
 *  Created on: Apr 1, 2016
 *      Author: rngd1
 */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "GA.h"

void sort( int N, double population[81][N] )
{
	//Insertion sort
	int i=0;
	for ( i=0 ; i<N ; i++)
	{
		int j=0;
		int elected = population[80][i];
		double aux[81];

		for ( j=0 ; j<81 ; j++)
		{
			aux[j]=population[j][i];
		}

		int z = i - 1 ;

		while ( z>=0  &&  elected<population[80][z] )
		{
			for ( j=0 ; j<81 ; j++  )
			{
				population[j][z+1] = population[j][z] ;
			}
			z = z-1;
		}

		for ( j=0 ; j<81 ; j++  )
		{
			population[j][z+1] = aux[j] ;
		}

	}

}


void popwrost( int N, int value , double population[81][N] )
 {
	 int i=0;
	 int i1=0;//Solution radius equals value
	 int m=(N-2);//Reference to solution that will suffer mutation
	 int c1=0;//Reference to solution that will be replaced
	 double I[81]; //Aux solution dummy

	 //Discover solution with radius less than value
	 while ( population[80][i] < value )
	 {
		 i+=1;
	 }
	 i1=i;

	 //Replace all solutions with radius less than "value"
	 while ( c1<i1 )
	 {
		 //Mutation process of solution with radius greater than "value"
		 for (i=0; i<81 ; i++)
		 {
			 I[i]=population[i][m];
		 }
		 for (i=0; i<3 ;i++)
		 {
			 mutation(I);
		 }
		 eval1(I);

		 //Next solution to be modified
		 c1+=1;

		 //Choose another solution to suffer mutation
		 m-=1;

		 //Warranty that only solutions with radius greater than value will be modified
		 if ( m == i1 )
		 {
			 m = N-1;
		 }
	 }
 }


void repair( double I[81] )
{
	int i;
	double diff, sum=0;

	for ( i=0 ; i<80 ; i++)
	{
		sum+=I[i];
	}
	diff = sum - 65;

	//It happens only if diff > 0
	if ( diff > 0 )
	{
		//For all position between 0 and 80
		for ( i=79 ; i>=0 ; i-- )
		{
			//If this position isn't a null value
			if ( I[i]>0  )
			{
				double a=I[i];
				if ( I[i] < diff )
				{
					diff-=I[i];
					I[i]=0;
				}
				else
				{
					I[i]-=diff;
					break;
				}
			}
		}
	}

}


void realocn( double I[81] )
{
	int i, random;
	double a=0;
	for ( i=0 ; i<80 ; i++)
	{
		if ( I[i]<0.5 )
		{
			random = rand() % 5 ;
			a=I[i];
			I[random]+=a;
			I[i]=0;
		}
	}
}

void cataclysm( int N, double population[81][N], int repop)
{
	int i, j, n = N/repop;

	double newpopulation[81][n];
	generatePop( n, newpopulation );
	evaluation1( n, newpopulation );

	//Insert newpopulation into population
	for ( i=0 ; i< n ; i++)
	{
		for (j=0 ; j<81 ; j++)
		{
			population[j][N-1-i] = newpopulation[j][i];
		}
	}

	//Sort
	sort(n,population);


}
