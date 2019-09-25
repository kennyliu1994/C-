#include "global.h"
#include <math.h>

void lookup(individual Q, individual B, const int j, double &theta)
{
    if ((Q.x[j] == 0) && (B.x[j] == 1) && (Q.fitness < B.fitness))
    {
        theta = 0.01 * M_PI;
    }
    else if ((Q.x[j] == 1) && (B.x[j] == 0) && (Q.fitness < B.fitness))
    {
        theta = -0.01 * M_PI;
    }
}

void update(individual Q[], individual B[])
{
    double theta;
    for (int i = 0; i < popsize; i++)
    {
        theta = 0;
        for (int j = 0; j < item; j++)
        {
            lookup(Q[i], B[i], j, theta);
            if (Q[i].alpha[j] * Q[i].beta[j] > 0)
            {
                theta = -theta;
            }
            Q[i].alpha[j] = cos(theta) * Q[i].alpha[j] - sin(theta) * Q[i].beta[j];
            Q[i].beta[j] = sin(theta) * Q[i].alpha[j] + cos(theta) * Q[i].beta[j];
        }
    }
}