#include "iostream" //was not declared in this scope

#include "global.h"
#include "rand.h"

void initialize_pop(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            pop[i].value[j] = rand_double(lowerbound, upperbound);
        }
    }
}