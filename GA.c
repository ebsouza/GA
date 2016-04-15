/*
 * GA.c
 *
 *  Created on: Mar 4, 2016
 *      Author: ebsouza
 */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


void generatePop( int N, double population[81][N] )
{

  /* initialize random seed: */
  srand (time(NULL));

  //Parameters
  int daystreat=40; //Period of treatment
  int i; //Iterator
  double dosemax; //Maximum dose applied
  double doseaux=0; //Auxiliary variable dose
  int choose; //Choosen day

  int restri[81]; //Constraints



  //Construction of restri------------
  for ( i=0 ; i<80 ; i++)
  {
  		restri[i]=0;
  }

  for ( i=5 ; i<80 ; i+=7 )
  {
  		restri[i]=1;
  }

  for ( i=6 ; i<81 ; i+=7 )
  {
  		restri[i]=1;
  }
  //------------------------------------------

  //Generation population
  for ( i=0 ; i<N ; i++)
  {
  		dosemax = 65;
    	while ( dosemax > 0)
      {
        //Choose a position between 0 and 39
        choose = rand() % daystreat ;

        //It doesn't allow insert a dose in the weekend
        while ( restri[choose] == 1 )
        {
          choose = rand() % daystreat ;
        }

        //Set doseaux
        doseaux = dosemax * ( (double) (rand() % 100) ) / 300 ;

        //Insert dose in current solution
        population[choose][i] += doseaux ;
        dosemax -= doseaux ;

        if ( dosemax < 1)
        {
          population[choose][i]+=dosemax;
          dosemax=0;
        }
      }
  }
}


void evaluation(int N, double population[81][N])
{
	int i = 0 ;

	for ( i=0 ; i<N/2 ; i++  )
	{
		population[80][i] = ( (N/2) - i ) + 100;
	}
	for ( i=N/2 ; i<N ; i++  )
	{
		population[80][i] = i + 100;
	}
}


void evaluation1(int N, double population[81][N])
{
	int i,j;

	for ( i=0 ; i<N ; i++  )
	{
		for ( j=0 ; j<80 ; j++)
		{
			if ( population[j][i] != 0)
			{
				population[80][i]+=1;
			}
		}
	}
}

void eval1( double individual[81])
{
	int i;

	for ( i=0 ; i<80 ; i++  )
	{
		if ( individual[i] != 0)
		{
			individual[80]+=1;
		}
	}
}


void selector( int N, double population[81][N], int G, double I1[81], double I2[81] )
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
		 choose = rand() % N;
		 T[0][i] = choose; //Solution selected index
		 T[1][i] = population[80][choose]; //Solution selected radius
	 }


	 //Condition to terminate the tournament
	 while ( G>2 )
	 {
		 //Tournament
		 for ( i = 0 ; i < g ; i++)
		 {

			 //Generate two random numbers
			 random1 = rand() % G ;
			 random2 = rand() % G ;
			 while ( random1 == random2 )
			 {
				 random2 = rand() % G ;
			 }

			 //Probability variable
			 percentage = (rand() % 100 )/100 ;

			 //Let's start the tournament
			 total = T[80][random1] + T[80][random2];
			 if ( percentage < ( total - T[80][random1] )/total  )
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
	 for ( i=0 ; i<81 ; i++)
	 {
		 I1[i] = population[i][ (int)T[0][0] ];
		 I2[i] = population[i][ (int)T[0][1] ];
	 }

 }


void crossover( int N, double I1[81], double I2[81], double I3[81] )
{
	double a=0.8, b=0.2;
	int i;

	for ( i=0 ; i<5 ; i++)
	{
		if (I1[i]>I2[i])
		{
			I3[i] = a*I1[i] + b*I2[i] ;
		}
		else
		{
			I3[i] = b*I1[i] + a*I2[i] ;
		}
	}

	for ( i=5 ; i<80 ; i++)
	{
		if (I1[i]>I2[i])
		{
			I3[i] = b*I1[i] + a*I2[i] ;
		}
		else
		{
			I3[i] = a*I1[i] + b*I2[i] ;
		}
	}

}


void mutation( double I[81] )
{
	//Parameters
	int i, n;
	double sum=0;
	for ( i=0 ; i<80 ; i++)
	{
		sum+=I[i];
	}
	double diff = 65 - sum;
	double pmutation = (rand() % 100 + 1)/100 ;
	double alfa=0.25, beta=0.5;
	double donation=0;
	int restri[80];

	//Weekend constraints ------------
	for ( i=0 ; i<80 ; i++)
	{
	  	restri[i]=0;
	}

	 for ( i=5 ; i<80 ; i+=7 )
	 {
	  	restri[i]=1;
	 }

	 for ( i=6 ; i<80 ; i+=7 )
	 {
	  	restri[i]=1;
	 }


	 //Mutation process

	 if ( pmutation <= alfa )
	 {
		 //Add
		 if ( diff > 0 )
		 {
			n = rand() % 5 ;
			I[n]+=diff ;
		 }
	 }
	 else if ( pmutation > alfa && pmutation <= ( alfa + beta ) )
	 {
		 //Realoc
		 n = 5 + rand() % 75 ;
		 while ( donation == 0)
		 {
			 donation = I[n]*0.8;
			 I[n]-=donation;
			 n = 5 + rand() % 75 ;
		 }

		 n = rand() % 5 ;
		 I[n]+=donation;

	 }
	 else
	 {
		 //Turn zero
		 n = 5 + rand() % 75 ;
		 do
		 {
			 I[n]=0;
		 }while ( restri[n] != 0 );
	 }

}


void reposition( int N, int n, double population[81][N], double sons[81][n])
{
	int i, j, itr, ok, lastsol=(N-1);
	double tol=2;

	for ( i=0 ; i<n ; i++)//sons
	{
		ok=1; //allow the current reposition

		for ( j=0 ; j<N ; j++)//population
		{
			//Check the radius equality
			if ( sons[80][i] >= population[80][j] - tol  &&  sons[80][i] <= population[80][j] + tol )
			{
				itr=0;
				while ( sons[itr][i] >= population[itr][j] - tol  &&  sons[itr][i] <= population[itr][j] && itr<80 )
				{
					itr+=1;
				}

				if (itr != 79)
				{
					ok=0;
					break;
				}
			}
		}

		//When ok=1, insert a current solution
		if ( ok != 0 )
		{
			for ( itr = 0 ; itr < 80 ; itr++)
			{
				population[itr][lastsol] = sons[itr][i];
			}
			lastsol-=1;
		}
	}
}



