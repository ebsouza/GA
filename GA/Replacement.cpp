#include<iostream>

#include "Replacement.h"
#include "../util/util.h"

//It prefers to replace worst solutions
void replaceAll( Solution &solution)
{
  if ( totalpop < totalnewpop )
  {
     std::cout << "The new population is larger than original" << std::endl;
     return;
  }
  else
  {
     unsigned int npIndex = totalnewpop ;
     for(unsigned int i = ( totalpop - 1 ) ; i > ( totalpop - totalnewpop - 1) ; i--)
     {
       npIndex --;
       for(unsigned int j = 0 ; j<length ; j++)
       {
          solution.population[i][j] = solution.newpopulation[npIndex][j];
          solution.populationFit[i] = solution.newpopulationFit[npIndex];
       }
     }    
  }

  //calling sort population method
  sortPopulation(solution);
}
