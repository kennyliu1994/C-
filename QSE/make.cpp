#include "global.h"
#include "kenny_lib.h"
#include <math.h>

void make(individual Q[])
{
    kenny_rand rd;
    for (int i = 0; i < popsize; i++)
    {
        Q[i].x.assign(item, 0);
        for (int j = 0; j < item; j++)
        {
            if (rd.double10(0, 1) > pow(cos(Q[i].angle[j]), 2))
                Q[i].x[j] = 1;
        }
    }
}