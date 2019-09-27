#include "global.h"
#include "algorithm"

bool cmp_best(const individual &a, const individual &b)
{
    return a.fitness > b.fitness;
};

void first_store(individual Q[], individual B[], individual &b)
{
    vector<individual> tmp;
    for (int i = 0; i < popsize; i++)
    {
        B[i] = Q[i];
        tmp.push_back(B[i]);
    }
    sort(tmp.begin(), tmp.end(), cmp_best);
    b = tmp[0];
}

void store(individual Q[], individual B[], individual &b)
{
    for (int i = 0; i < popsize; i++)
    {
        if (B[i].fitness < Q[i].fitness)
        {
            B[i] = Q[i];
        }
        if (b.fitness < Q[i].fitness)
        {
            b = Q[i];
        }
    }
}