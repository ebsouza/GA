#include "../GA/Solution.h"

/*
* Print the chosen solution
* @param[in] solution
* @param[in] solutionIndex
*/
void printSolution( Solution &solution, unsigned int solutionIndex );

/*
* Print all population fitness
* @param[in] solution
*/
void printPopulationFitness( Solution &solution );

/*
* Population sort by fitness in ascending order (Insertion Sort)
* @param[in] solution
*/
void sortPopulation( Solution &solution );

/*
* Export population in a csv file
* @param[in] solution
*/
void exportPopulation( Solution &solution );
