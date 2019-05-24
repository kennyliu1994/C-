#include "iostream"

#include "global.h"
#include "rand.h"

void init_parent(chromosome ch[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            ch[i].value.assign(dimension, 0);
            ch[i].value[j] = randDouble(lowerbound, upperbound);
        }
    }
}