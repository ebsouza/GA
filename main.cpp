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

int main() {

	Solution solution = Solution();

	randomGeneration( solution );

	printSolution( solution, 0);

	return 0;
}
