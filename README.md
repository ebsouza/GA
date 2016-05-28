## **Genetic Algorithms**

Genetic Algorithms(GA) are a very popular class of Evolutionary Algorithms. They have become popular due their use in solving hard combinatorial optimization problems. Above there are a basic Genetic Algorithm template:

Choose an initial population of chromosomes
**while** termination condition not satisfied **do**
	**repeat**
		**if** crossover condition satisfied **then**
			select parent chromosomes
			choose crossover parameters
			perform crossover
		**if** mutation condition satisfied **then**
			choose mutation points
			perform mutation
			evaluate fitness of offspring
	**until** sufficient offspring created
select new population
**end while**



## **About this project**

This is a implementation of a algorithm that I developed to solve a radiotherapy optimization problem in my master thesis. So this is a Genetic Algorithm for a specific problem, but I think it is useful to share this code because another researchers can adapt this to solve their problems.

My intention is share a code that everybody can read without difficult. A basic knowledge in arrays, functions and loop/conditional structures is enough to understand this code.

I hope this code can help you to solve your problem. 


