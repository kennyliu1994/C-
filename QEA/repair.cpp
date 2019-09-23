#include "global.h"
#include "kenny_lib.h"

double w;

double current_weight(individual Q)
{
    w = 0;
    for (int j = 0; j < item; j++)
    {
        w += Q.w[j] * Q.x[j];
    }
    return w;
}

void repair(individual Q[])
{
    bool overfilled;
    overfilled = false;
    kenny_rand rd;
    int index;
    for (int i = 0; i < popsize; i++)
    {
        if (current_weight(Q[i]) > Q[i].C)
        {
            overfilled = true;
        }
        while (overfilled)
        {
            Q[i].x[rd.int11(0, item - 1)] = 0;
            if (current_weight(Q[i]) <= Q[i].C)
            {
                overfilled = false;
            }
        }
        while (!overfilled)
        {
            index = rd.int11(0, item - 1);
            Q[i].x[index] = 1;
            if (current_weight(Q[i]) > Q[i].C)
            {
                overfilled = true;
            }
        }
        Q[i].x[index] = 0;
    }
}