#include "util.h"
#include <stdio.h>

void printSolution(Solution&solution, unsigned int solutionIndex)
{
   for(unsigned int i = 0; i < length; i++){
       std::cout << solution.population[0][i] << std::endl;
       }
}

void printPopulationFitness(Solution&solution)
{
   for(unsigned int i = 0; i < totalpop; i++){
       std::cout << solution.populationFit[i] << std::endl;
       }
}

void sortPopulation(Solution&solution)
{
   for(unsigned int i = 0; i < totalpop; i++){
       //electedSolution copy
       double electedSolution[length];
       for(unsigned int j = 0; j < length; j++){
           electedSolution[j] = solution.population[i][j];
           }

       double elected = solution.populationFit[i];

       //Current first solution index
       int z = i - 1;

       while(z >= 0 && elected < solution.populationFit[z]){
             //#if length > something
             //#pragma openmp parallel for
             //#endif
             for(unsigned int j = 0; j < length; j++){
                 solution.population[z + 1][j] = solution.population[z][j];
                 solution.populationFit[z + 1] = solution.populationFit[z];
                 }
             z = z - 1;
             }

       //It's not necessary this code if above while didn't run
       if(z != i - 1){
          for(unsigned int j = 0; j < length; j++){
              solution.population[z + 1][j] = electedSolution[j];
              }
          solution.populationFit[z + 1] = elected;
          }
       }
}

void exportPopulation(Solution&solution)
{
   FILE *file;

   file = fopen("/home/rngd1/population.csv", "w");
   for(unsigned int i = 0; i < length; i++){
       for(unsigned int j = 0; j < totalpop; j++){
           fprintf(file, "%f  ", solution.population[j][i]);
           }
       fprintf(file, "\n");
       }
   fclose(file);
   file = 0;
}
