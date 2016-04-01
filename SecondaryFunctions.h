/*
 * SecondaryFunctions.h
 *
 *  Created on: Apr 1, 2016
 *      Author: rngd1
 */

//#include "GA.h"

#ifndef SECONDARYFUNCTIONS_H_
#define SECONDARYFUNCTIONS_H_

//#include "GA.h"

  //int N=256;
  //int n=10;

  //----------------Sort the population structure----------------
  void sort( int N, double population[81][N] );

  //----------------Get the wrost evaluation from the best solutions----------------
  void popwrost( int N, int value , double population[81][N] );

  //--------------Fix solution - This need to continue be feasible-----------
  void repair( double I[81] );

  //------------------Realocation--------------------------------
  void realocn( double I[81] );

  //------------------Cataclysm-----------------------------------
  void cataclysm( int N, int n, double population[81][N], double newpopulation[81][n]);

  //Save*

  //Population plotting


#endif /* SECONDARYFUNCTIONS_H_ */
