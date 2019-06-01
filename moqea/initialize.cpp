#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"

void initialize_pop(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                pop[i].alpha[j].assign(nbit, 1 / sqrt(2));
                pop[i].beta[j].assign(nbit, 1 / sqrt(2));                
            }
        }
    }
}