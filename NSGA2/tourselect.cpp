#include "iostream" //was not declared in this scope

#include "global.h"
#include "rand.h"

void selection(chromosome old_pop[], chromosome new_pop[])
{
    vector<int> a1;
    vector<int> a2;
    int temp;
    int rand;
    int i;
    chromosome parent1;
    chromosome parent2;
    a1.assign(popsize, 0);
    a2.assign(popsize, 0);
    for (i = 0; i < popsize; i++)
    {
        a1[i] = a2[i] = i;
    }
    for (i = 0; i < popsize; i++)
    {
        rand = rand_int(i, popsize - 1);
        temp = a1[rand];
        a1[rand] = a1[i];
        a1[i] = temp;
        rand = rand_int(i, popsize - 1);
        temp = a2[rand];
        a2[rand] = a2[i];
        a2[i] = temp;
    }
    for (i = 0; i < popsize; i += 4)
    {
        parent1 = tournament(old_pop[a1[i]], old_pop[a1[i + 1]]);
        parent2 = tournament(old_pop[a1[i + 2]], old_pop[a1[i + 3]]);
        crossover(parent1, parent2, new_pop[i], new_pop[i + 1]);
        parent1 = tournament(old_pop[a2[i]], old_pop[a2[i + 1]]);
        parent2 = tournament(old_pop[a2[i + 2]], old_pop[a2[i + 3]]);
        crossover(parent1, parent2, new_pop[i + 2], new_pop[i + 3]);
    }
    return;
}
chromosome tournament(chromosome ind1, chromosome ind2)
{
    int flag;
    flag = check_dominance(ind1, ind2);
    if (flag == 1)
    {
        return (ind1);
    }
    if (flag == -1)
    {
        return (ind2);
    }
    if (ind1.crowd_dist > ind2.crowd_dist)
    {
        return (ind1);
    }
    if (ind2.crowd_dist > ind1.crowd_dist)
    {
        return (ind2);
    }
    if (rand_double(0, 1) <= 0.5)
    {
        return (ind1);
    }
    else
    {
        return (ind2);
    }
}
