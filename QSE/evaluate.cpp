#include "global.h"

void evaluate(individual Q[])
{
    for (int i = 0; i < popsize; i++)
    {
        Q[i].fitness = 0;
        for (int j = 0; j < item; j++)
        {
            Q[i].fitness += Q[i].p[j] * Q[i].x[j];
        }
    }
    count++;
}