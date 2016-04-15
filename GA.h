/*
 * GA.h
 *
 *  Created on: Mar 4, 2016
 *      Author: ebsouza
 */

#ifndef GA_H_
#define GA_H_

  //----------------Generation of the initial population----------------
  void generatePop( int N, double population[81][N] );


  //----------------Evaluation----------------
  void evaluation( int N, double population[81][N]) ;

  void evaluation1( int N, double population[81][N]) ;

  void eval1( double individual[81]) ; // Just for only one solution

  //------------------------Selection--------------------------------
  void selector( int N, double population[81][N], int G, double I1[81], double I2[81] );


  //----------------------Crossover--------------------------------
  void crossover( int N, double I1[81], double I2[81], double I3[81] );


  //------------------Mutation--------------------------
  void mutation( double I[81] );


  //--------------------Insertion of new solution in population-------------------
  void reposition( int N, int n, double population[81][N], double sons[81][n]) ;





#endif /* GA_H_ */
