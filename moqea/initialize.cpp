#include "iostream" //was not declared in this scope

#include "global.h"
#include "rand.h"

void initialize_pop(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbin; k++)
            {
                if (rand_double(0, 1) <= 0.5)
                {
                    pop[i].gene[j][k] = 0;
                }
                else
                {
                    pop[i].gene[j][k] = 1;
                }
            }
        }
    }
}