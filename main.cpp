//============================================================================
// Name        : Genetic Algorithm
// Author      : ebsouza
// Version     :
// Copyright   :
// Description : Genetic Algorithm
//============================================================================

#include "util/util.h"
#include "GA/Solution.h"
#include "GA/Generation.h"
#include "GA/Evaluation.h"
#include "GA/Selection.h"
#include "GA/Reproduction.h"
#include "GA/Replacement.h"

int main()
{
   Solution solution = Solution();

   randomGeneration(solution);

   sortPopulation(solution);

   dummyPopEval(solution);

   int generations = 20;

   for(unsigned int i = 0; i < generations; i++){
       for(unsigned int j = 0; j < totalnewpop; j++){
           tournmentSelection(solution, 40, 2);

           intermediateCrossover(solution, j);

           mutation(solution, j, 0.15);
           }

       dummyNewpopEval(solution);


       for(unsigned int j = 0; j < totalnewpop; j++){
           std::cout << i << " Solution: " << solution.newpopulationFit[j] << std::endl;
           }



       replaceAll(solution);

       //std::cout << " Best solution: " << solution.populationFit[98] << " - " << solution.populationFit[totalpop] << std::endl ;
       }

   return(0);
}
