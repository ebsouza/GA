/*
 ============================================================================
 Name        : GA.c
 Author      : ebsouza
 Version     : alfa
 Copyright   : Free to use
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "GA.h"

int main(void) {

	int i, j;

	//Parâmetros
	int N=256;//Tamanho da população
	int n=10;//Número de filhos gerados
	int gerac=300;//Número de gerações

	//Estruturas
	double population[81][N];
	for ( i=0; i<81; i++)
	{
		for ( j=0; j<N; j++)
		{
			population[i][j]=0;
		}
	}

	double I1[81], I2[81];

	//Geração da população inicial
	generatePop( N, population );

	for (  i = 0 ; i<40 ; i++)
	{
		//printf( "%d  -  %f ,  \n", i , population[i][1]);
		//printf("%d",1);
	}

	//Avaliação(Inválida, somente teste)
	evaluation1 ( N, population );

	for (  i = 0 ; i<N ; i++)
	{
		printf( "eval %f , \n", population[80][i] );
	}

	//Ordenação
	sort ( N, population);

	for (  i = 0 ; i<N ; i++)
	{
		printf( "%f , \n", population[80][i] );
	}


	//Piorar solução*

	int g,r;
	//Loop das gerações
	for (g=0; g<gerac ; g++)
	{
		//Loop da reprodução
		for (r=0; r<n; r++)
		{
			//Seleção por torneio
			//
			//Crossover
			//
			//Correção*
			//
			//Mutação
			//
			//Realoca os números infimos*
		}

		//Avaliar novas soluções
		//
		//Inserção das novas soluções na população
	}






	//
	//Armazenamento das info*
	//
	//Troca de mutação*
	//
	//Condição de parada
	//
	//Save*

	//Fim Loop das gerações
	//
	//Plotagem da população



	//-------------------Test area---------------------

	/*
    double test[81][N];
    memcpy(test, population, sizeof(population));
    for (  i = 0 ; i<40 ; i++)
    	{
    		printf( "%d  - test  %f ,  \n", i , test[i][1]);
    		//printf("%d",1);
    	}
	*/

	return 0;
}
