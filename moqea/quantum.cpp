#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void make(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                if (rand_double(0, 1) < pow(pop[i].beta[j][k], 2))
                {
                    pop[i].gene[j][k] = 1;
                }
                else
                {
                    pop[i].gene[j][k] = 0;
                }
            }
        }
    }
}

void update(chromosome pop[])
{
    double theta;
    chromosome best;
    for (int i = 0; i < popsize; i++)
    {
        if (pop[i].rank == 1)
        {
            best = pop[i];
        }
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                theta = lookup(pop[i].gene[j][k], best.gene[j][k], check_dominance(pop[i], best));
                if (pop[i].alpha[m] * pop[i].beta[m] > 0)
                    theta = -theta;
                pop[i].alpha[j][k] = cos(theta) * pop[i].alpha[j][k] - sin(theta) * pop[i].beta[j][k];
                pop[i].beta[j][k] = sin(theta) * pop[i].alpha[j][k] + cos(theta) * pop[i].beta[j][k];
            }
        }
    }
}
