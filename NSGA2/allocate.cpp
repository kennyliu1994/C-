#include "iostream" //was not declared in this scope

#include "global.h"

void allocate_memory(chromosome pop[], int size)
{
    for (int i = 0; i < size; i++)
    {
        pop[i].value.assign(dimension, 0);
        pop[i].fitness.assign(nobj, 0);
    }
}