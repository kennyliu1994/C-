#include "iostream" //was not declared in this scope

#include "global.h"

void allocate_memory(chromosome pop[], int size)
{
    for (int i = 0; i < size; i++)
    {
        pop[i].alpha.resize(dimension);
        pop[i].beta.resize(dimension);
        pop[i].gene.resize(dimension);
        for (int j = 0; j < dimension; j++)
        {
            pop[i].alpha[j].assign(nbit, 0);
            pop[i].beta[j].assign(nbit, 0);
            pop[i].gene[j].assign(nbit, 0);
        }
        pop[i].value.assign(dimension, 0);
        pop[i].fitness.assign(nobj, 0);
        pop[i].crowd_dist = 0;
    }
}