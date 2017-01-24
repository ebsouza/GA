/* Classe que representa o conjunto de soluções */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <vector>


#ifndef SOLUTION_H_
#define SOLUTION_H_

#define totalpop 100 //Population size
#define totalnewpop 20 //New population(created every generation) size
#define length 5 //Chromosome length
#define MAX_PROBLEM 1 // 0 - Minimization problem ; 1 - Maximization problem


class Solution {

  public:

  Solution();

  virtual ~Solution();

  //Population data
  double population[totalpop][length];
  double newpopulation[totalnewpop][length];

  //Fitness data
  double populationFit[totalpop];
  double newpopulationFit[totalnewpop];

  //Selected solutions indexes
  std::vector<unsigned int> selected;

  //Current generated solution index;
  unsigned generatedSolution;

};

#endif /* SOLUTION_H_ */
