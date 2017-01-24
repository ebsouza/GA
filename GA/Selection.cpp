#include<vector>

#include "Selection.h"

void tournmentSelection(Solution &solution, unsigned int groupSize, unsigned int nSelecteds)
{
  bool Condition_one = groupSize > nSelecteds ;
  bool Condition_two = groupSize < totalpop ;
  //Check nSelecteds value
  if( !Condition_one && !Condition_two  )
  { 
    std::cout << "It wasn't possible run tournmentSelection. Please, see constraints" << std::endl;
  }

  unsigned int firstGroupSize = groupSize;
  unsigned int nextGroupSize = 1;
  std::vector<unsigned int> firstGroup;
  std::vector<unsigned int> nextGroup;

  while ( 2*nextGroupSize < groupSize )
  {
   nextGroupSize *= 2;
  }

  //selecting solutions randomly
  for ( unsigned int i = 0 ; i < groupSize ; i++ )
  {
    firstGroup.push_back( rand() % totalpop  );
  }

    
  //Tournment
  do
  {
    //Loop to construct nextGroup
    for ( unsigned int i = 0 ; i < nextGroupSize ; i++ )
    {
     //1)Select two solutions from firstGroup
     unsigned int firstIndex = rand() % firstGroupSize ;
     unsigned int secondIndex = rand() % firstGroupSize ;
     
     //2)Certify both isn't same index
     int sameIndexControl = 0;
     while( firstIndex == secondIndex )
     {
       secondIndex = rand() % firstGroupSize;
       sameIndexControl++;

       if ( sameIndexControl == 30 )
       {
         break;
       }   
     }

     //3)Choose one between two (using fit value)
     unsigned int selectedIndex = 0;
     double randomNumber = ((double) rand() / (RAND_MAX) ); //Seed must be changed


     //Probability to select the firstIndex
     double maxProbability = solution.populationFit[firstIndex] / ( solution.populationFit[firstIndex] + solution.populationFit[secondIndex] );
     double minProbability = solution.populationFit[secondIndex] / ( solution.populationFit[firstIndex] + solution.populationFit[secondIndex]  );    
     double probability = 0;
     

     MAX_PROBLEM ? probability = maxProbability : probability = minProbability ;

     randomNumber <= probability ? selectedIndex = firstIndex : selectedIndex = secondIndex ;

     //4)Insert into nextGroup
     nextGroup.push_back(selectedIndex);
    }   
    
    //firstGroup = nextGroup
    firstGroup.clear();
    for ( unsigned int i = 0 ; i < nextGroupSize ; i++  )
    {
      unsigned int index = nextGroup[i];
      firstGroup.push_back(index);
    }

    nextGroup.clear();

    //Updating index
    firstGroupSize = nextGroupSize;
    nextGroupSize /= 2;
    
  }while( nextGroupSize > nSelecteds );


  //fill solution.selected vector
  for ( unsigned int i = 0; i< nSelecteds ; i++ )
  {
    //Same selection process here, but inserting in selected vector
    unsigned int index = nextGroup[i];
    solution.selected.push_back(index);
  }

}
