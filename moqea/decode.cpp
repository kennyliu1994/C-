#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"

void decode_pop(chromosome pop[])
{
    int sum;
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            sum = 0;
            for (int k = 0; k < nbit; k++)
            {
                if (pop[i].gene[j][k] == 1)
                {
                    sum += pow(2, nbit - 1 - k);
                }
            }
            pop[i].value[j] = lowerbound[j] + (double)sum * (upperbound[j] - lowerbound[j]) / double(pow(2, nbit) - 1);
        }
    }
}