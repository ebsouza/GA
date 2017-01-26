#include "Reproduction.h"
#include <time.h>       /* time */

void intermediateCrossover(Solution&solution, unsigned int newSolutionIndex)
{
   unsigned int size   = solution.selected.size();
   double       weight = 1.0 / size;

   for(unsigned int i = 0; i < length; i++){
       double value = 0.0;

       for(unsigned int j = 0; j < size; j++){
           unsigned int selectedIndex = solution.selected[j];
           value += weight * solution.population[selectedIndex][i];
           }

       solution.newpopulation[newSolutionIndex][i] = value;
       }
}

void mutation(Solution&solution, unsigned int newSolutionIndex, double mutationRate)
{
   //seed
   srand(time(NULL));

   //random number
   double random = (double)(rand() % 101) / 100;

   //random vector position
   unsigned int position = (unsigned int)(rand() % length);

   if(random <= mutationRate){
      solution.newpopulation[newSolutionIndex][position] = 0.0;
      }
}
