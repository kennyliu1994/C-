#include "global.h"
#include "algorithm"

void global_migration(individual B[], individual b)
{
    for (int i = 0; i < popsize; i++)
    {
        B[i] = b;
    }
}

void local_migration(individual B[], individual b)
{
    vector<individual> tmp;
    for (int i = 0; i < popsize; i++)
    {
        tmp.push_back(B[i]);
    }
    sort(tmp.begin(), tmp.end(), cmp_best);
    for (int i = 0; i < popsize; i++)
    {
        B[i] = tmp[0];
    }
}

void migration(individual B[], individual b, int t)
{
    if (t % 10 == 0)
    {
        global_migration(B, b);
    }
    else
    {
        local_migration(B, b);
    }
}