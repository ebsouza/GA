#include "Generation.h"


void randomGeneration(Solution&solution)
{
   //seed
   srand(time(NULL));

   for(unsigned int i = 0; i < totalpop; i++){
       for(unsigned int j = 0; j < length; j++){
           solution.population[i][j] = double (rand() % 1000);
           }
       }
}
