#include "Solution.h"

/*
* This crossover attempt to average the elements of the parents
* @param[in] solution
* @param[in] newSolutionIndex
*/
void intermediateCrossover( Solution &solution, unsigned int newSolutionIndex);

/*
* Mutation operator: small changes in new solution 
* @param[in] solution
* @param[in] newSolutionIndex
* @param[in] mutationRate
*/
void mutation( Solution &solution, unsigned int newSolutionIndex, double mutationRate );
