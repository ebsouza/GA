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

	for ( i=0 ; i<N/2 ; i++  )
	{
		population[80][i] = ( (N/2) - i ) + 100;
	}
	for ( i=N/2 ; i<N ; i++  )
	{
		population[80][i] = i + 100;
	}
}

//Função avaliação 1
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


//Piorar solução
 void popwrost( int N, int value , double population[81][N] )
 {
	 int i,j,k;
	 int i1;//Indivíduo com avaliação igual a value
	 int m=(N-1);//Controle do indivíduo de sofrerá mutação
	 int c1=1;//Controle do indivíduo de sofrerá modificação


	 for ( i=0 ; i<N ; i++ )
	 {
		 if ( population[80]>value )
		 {
			 i1=i;
			 break;
		 }
	 }

	 while ( c1<i1 )
	 {
		 //Mutação


	 }
 }

 void selector( int N, double population[81][N], int G, double I1[81], double I2[81] )
 {
	 int i=0;

	 //Variáveis
	 int random1;
	 int random2;
	 int choose;
	 int g=G/2;
	 double percentage;
	 double total;

	 //Estrutura
	 double AUX[2][g];
	 double T[2][G];

	 //Construção da estrutura composta por indivíduos do torneio
	 for ( i=0 ; i<G ; i++)
	 {
		 choose = rand() % N + 1;
		 T[0][i] = choose; //índice do indivíduo escolhido
		 T[1][i] = population[80][choose]; //raio do respectivo indivíduo
	 }


	 //Seleção por torneio
	 while ( G>2 )
	 {
		 //Torneio
		 for ( i = 0 ; i < g ; i++)
		 {

			 //Gerações de 2 números aleatórios
			 random1 = rand() % G + 1;
			 random2 = rand() % G + 1;
			 while ( random1 == random2 )
			 {
				 random2 = rand() % G + 1;
			 }

			 //Probabilidade de escolha
			 percentage = (rand() % 100 )/100 ;

			 //Promoção do torneio
			 total = population[80][random1] + population[80][random2];
			 if ( percentage < ( total - population[80][random1] )/total  )
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

		 //Substituição dos indivíduos no conjunto T
		 for ( i=0; i<g ; i++)
		 {
			 T[0][i] = AUX[0][i] ;
			 T[1][i] = AUX[1][i] ;
		 }

		 G=G/2;
		 g=g/2;

	 }

	 //Indivíduos selecionados
	 for ( i=0 ; i<81 ; i++)
	 {
		 I1[i] = population[i][ (int)T[0][0] ];
		 I2[i] = population[i][ (int)T[0][1] ];
	 }



 }
