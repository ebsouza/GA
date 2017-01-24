#include "Evaluation.h"

void dummyPopEval(Solution &solution)
{
  for(unsigned int i = 0; i<totalpop ; i++)
  {
    for(unsigned int j = 0 ; j<length ; j++)
    {
       //Fit = f(solution)
       solution.populationFit[i] += solution.population[i][j];
    }
  }
}


void dummyNewpopEval(Solution &solution)
{
  for(unsigned int i = 0; i<totalnewpop ; i++)
  {
    for(unsigned int j = 0 ; j<length ; j++)
    {
       //Fit = f(solution)
       solution.newpopulationFit[i] += solution.newpopulation[i][j];
    }
  }
}
