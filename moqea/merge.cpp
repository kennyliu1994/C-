#include "iostream" //was not declared in this scope

#include "global.h"

void merge(chromosome pop1[], chromosome pop2[], chromosome pop3[])
{
    int i, k;
    for (i = 0; i < popsize; i++)
    {
        copy_ind(pop1[i], pop3[i]);
    }
    for (i = 0, k = popsize; i < popsize; i++, k++)
    {
        copy_ind(pop2[i], pop3[k]);
    }
}
void copy_ind(chromosome ind1, chromosome &ind2)
{
    int i, j;
    ind2.rank = ind1.rank;
    ind2.crowd_dist = ind1.crowd_dist;
    if (dimension != 0)
    {
        for (i = 0; i < dimension; i++)
        {
            ind2.value[i] = ind1.value[i];
            for (j = 0; j < nbit; j++)
            {
                ind2.alpha[i][j] = ind1.alpha[i][j];
                ind2.beta[i][j] = ind1.beta[i][j];
                ind2.gene[i][j] = ind1.gene[i][j];
            }
        }
    }
    for (i = 0; i < nobj; i++)
    {
        ind2.fitness[i] = ind1.fitness[i];
    }
}