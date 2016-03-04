/*
 * GA.h
 *
 *  Created on: Mar 4, 2016
 *      Author: ebsouza
 */

#ifndef GA_H_
#define GA_H_

  int N=256;

  //Geração da população inicial
  void generatePop( int N, double population[81][N] );

  //Avaliação
  void evaluation( int N, double population[81][N]) ;


  //Ordenação
  void sort ( int N, double population[81][N] );


  //Piorar solução*


  //Seleção por torneio


  //Crossover


  //Correção*


  //Mutação


  //Realoca os números infimos*



  //Inserção das novas soluções na população


  //Save*



  //Plotagem da população









#endif /* GA_H_ */
