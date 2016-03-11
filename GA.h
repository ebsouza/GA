/*
 * GA.h
 *
 *  Created on: Mar 4, 2016
 *      Author: ebsouza
 */

#ifndef GA_H_
#define GA_H_

  int N=256;
  int n=10;

  //----------------Generation of the initial population----------------
  void generatePop( int N, double population[81][N] );



  //----------------Evaluation----------------
  void evaluation( int N, double population[81][N]) ;

  void evaluation1( int N, double population[81][N]) ;



  //----------------Sort the population structure----------------
  void sort( int N, double population[81][N] );



  //----------------Get the wrost evaluation from the best solutions----------------
  void popwrost( int N, int value , double population[81][N] );



  //------------------------Selection--------------------------------
  void selector( int N, double population[81][N], int G, double I1[81], double I2[81] );



  //----------------------Crossover--------------------------------
  void crossover( int N, double I1[81], double I2[81], double I3[81] );



  //--------------Fix solution - This need to continue be feasible-----------
  void repair( double I[81] );


  //------------------Mutation--------------------------
  void mutation( double I[81] );


  //------------------Realocation--------------------------------
  void realocn( double I[81] );



  //--------------------Insertion of new solution in population-------------------
  void reposition( int N, int n, double population[81][N], double sons[81][n]) ;


  //Save*



  //Population plotting









#endif /* GA_H_ */
