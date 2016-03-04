/*
 * GA.c
 *
 *  Created on: Mar 4, 2016
 *      Author: ebsouza
 */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


//Geração da população inicial
void generatePop( int N, double population[81][N] )
{

  /* initialize random seed: */
  srand (time(NULL));

  //Inicialização
  int diastrat=40; //Máximo de dias de tratamento
  int lin=81,col=N; //Linhas e colunas de population
  int i; //Iterador
  int restri[81]; //Restrição de não aplicação nos finais de semana
  double dosemax; //Dose máxima aplicada
  double doseaux=0; //Dose auxiliar
  int choose; //Dia escolhido

  //Restrição aos finais de semana------------
  for ( i=0 ; i<81 ; i++)
  {
  		restri[i]=0;
  }

  for ( i=5 ; i<81 ; i+=7 )
  {
  		restri[i]=1;
  }

  for ( i=6 ; i<81 ; i+=7 )
  {
  		restri[i]=1;
  }
  //------------------------------------------

  //Construção da população
  for ( i=0 ; i<N ; i++)
  {
  		dosemax = 65;
    	while ( dosemax > 0)
      {
        //Escolhe um dia entre 1 a 40
        choose = rand() % diastrat + 1;

        //Não permite que o fim de semana seja escolhido
        while ( restri[choose] == 1 )
        {
          choose = rand() % diastrat + 1;
        }

        //Determinação da dose auxiliar
        doseaux = dosemax * ( (double) (rand() % 100) ) / 300 ;

        //Atribuição da dose na população
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

//Função avaliação
void evaluation(int N, double population[81][N])
{
	int i = 0 ;
	//int t = N/2 ;
	for ( i=0 ; i<N/2 ; i++  )
	{
		population[80][i] = ( (N/2) - i ) + 100;
	}
	for ( i=N/2 ; i<N ; i++  )
	{
		population[80][i] = i + 100;
	}
}

//Ordenação
void sort( int N, double population[81][N] )
{
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
