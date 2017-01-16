# **About**

I'm developing this Genetic Algorithm(GA) template to help professionals and students to start using this metaheuristic. Due the operators and algorithms diversity in GA, my intention is do some basic codes to bring forward further implementations. To increase your knowledge in Genetic Algorithms, I recommend "Metaheuristics - From Design To Implementation, El-Ghazali Talbi".

## **Project Status**

**DEVELOPMENT** | TESTS | CONCLUDED 


# **Genetic Algorithms**

Genetic Algorithms(GA) are a very popular class of Evolutionary Algorithms. They have become popular due their use in solving hard combinatorial optimization problems. The Algorithm 1 show a Evolutionary Algorithm template.

```
Initialize a population of K individuals;
Evaluate the k individuals;
Repeat
	Generate K' offsprings from K parents;
	Evaluate the K' offsprings;
	Replate the population with K individuals from parents and offprings;
Until Stopping criteria
Output Best individual or population found;

(Algorithm 1)
```

## **Common concepts for Evolutionary Algorithms(EA)**

The main search components for designing an evolutionary algorithm are as follows:

**1. Representation:** This is a common search component for all metaheuristics. In the EA community, the encoded solution is referred as chromosome while the decision variables within a solution(chromosome) are genes. The possible values of variables (genes) are the alleles and the position of an element (gene) within a chromosome is named locus.

**2. Population initialization:** This is a common search component for all population based metaheuristics.

**3. Objective Function:** This is a common search component for all metaheuristics. In the EA community, the term fitness refers to the objective function.

**4. Selection strategy:** The selection strategy addresses the following question:“Which parents for the next generation are chosen with a bias toward better fitness?”

**5. Reproduction strategy:** The reproduction strategy consists in designing suitable mutation and crossover operator(s) to generate new individuals(offsprings).

**6. Replacement strategy:** The new offsprings compete with old individuals for their place in the next generation (survival of the fittest).

**7. Stopping criteria:** This is a common search component for all metaheuristics. Some stopping criteria are specific to P-metaheuristics.

**Bibliography**
- TALBI, E.-G. Metaheuristics: from design to implementation. John Wiley & Sons, Honoken, New Jersey, 2009.


# **How to use**

To build this project: 

```
# In CMakeLists.txt directory
# 1) First option
$ cmake .

# 2) Second option
$ mkdir build
$ cd build
$ cmake ..

# Both options will create the executable file named GAlgorithm
```

To use Gprof Tool

```
# Run executable file GAlgorithm at least once
$ ./GAlgorithm
# Execute gprofile command
$ gprof GAlgorithm gmon.out > analysis.txt

# The new text file named analysis.txt will contain the profiling information  
```


