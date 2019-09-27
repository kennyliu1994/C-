#include "global.h"
#include <math.h>
#include "kenny_lib.h"

void initialize(individual Q[])
{
    for (int i = 0; i < popsize; i++)
    {
        Q[i].angle.assign(item, M_PI / 4);
        Q[i].w.assign(item, 0);
        Q[i].p.assign(item, 0);
        Q[i].C = 0;
    }
    //simple knapsack
    kenny_rand rd;
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < item; j++)
        {
            Q[i].w[j] = rd.int11(1, 10);
            Q[i].p[j] = Q[i].w[j] + 5;
            // Q[i].p[j] = Q[i].w[j] + rd.int11(0, 5);
            Q[i].C += ((double)Q[i].w[j] / 2);
        }
    }
}