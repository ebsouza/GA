#include "Solution.h"

Solution::Solution() :
   generatedSolution(0)
{
//Initialize Population
   for(unsigned int i = 0; i < totalpop; i++){
       for(unsigned int j = 0; j < length; j++){
           population[i][j] = 0.0;
           }
       }

//Initialize newPopulation
   for(unsigned int i = 0; i < totalnewpop; i++){
       for(unsigned int j = 0; j < length; j++){
           newpopulation[i][j] = 0.0;
           }
       }

//Initialize PopulationFit
   for(unsigned int i = 0; i < totalpop; i++){
       populationFit[i] = 0.0;
       }

//Initialize newPopulationFit
   for(unsigned int i = 0; i < totalnewpop; i++){
       newpopulationFit[i] = 0.0;
       }
}

Solution::~Solution()
{
}
