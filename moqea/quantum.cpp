#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void make(chromosome pop[], chromosome new_pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        new_pop[i] = pop[i];
    }
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                if (rand_double(0, 1) < pow(pop[i].beta[j][k], 2))
                {
                    new_pop[i].gene[j][k] = 1;
                }
                else
                {
                    new_pop[i].gene[j][k] = 0;
                }
            }
        }
    }
}

void update(chromosome pop[])
{
    double theta;
    chromosome best;
    for (int i = 0; i < popsize; i++)
    {
        if (pop[i].rank == 1)
        {
            if (pop[i].crowd_dist == INF)
            {
                best = pop[i];
                break;
            }
        }
    }
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                theta = lookup(pop[i].gene[j][k], best.gene[j][k], check_dominance(pop[i], best));
                if (pop[i].alpha[j][k] * pop[i].beta[j][k] < 0)
                    theta = -theta;
                pop[i].alpha[j][k] = cos(theta) * pop[i].alpha[j][k] - sin(theta) * pop[i].beta[j][k];
                pop[i].beta[j][k] = sin(theta) * pop[i].alpha[j][k] + cos(theta) * pop[i].beta[j][k];
            }
        }
    }
}

double lookup(int x, int b, int domi)
{
    if (x == 0)
    {
        if (b == 0)
        {
            if (domi == -1) //theta1
            {
                return 0;
            }
            else //theta2
            {
                return 0;
            }
        }
        else
        {
            if (domi == -1) //theta3
            {
                return 0.005 * M_PI;
            }
            else //theta4
            {
                return 0;
            }
        }
    }
    else
    {
        if (b == 0)
        {
            if (domi == -1) //theta5
            {
                return -0.005 * M_PI;
            }
            else //theta6
            {
                return 0;
            }
        }
        else
        {
            if (domi == -1) //theta7
            {
                return 0;
            }
            else //theta8
            {
                return 0;
            }
        }
    }
}