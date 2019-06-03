#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void initialize_pop(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            //pop[i].value[j] = rand_double(lowerbound[j], upperbound[j]);//nsga2
            for (int k = 0; k < nbit; k++)
            {
                pop[i].alpha[j].assign(nbit, 1 / sqrt(2));
                pop[i].beta[j].assign(nbit, 1 / sqrt(2));                
            }
        }
    }
}
