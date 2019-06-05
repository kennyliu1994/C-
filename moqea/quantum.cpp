#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void make(chromosome pop[], chromosome new_pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        new_pop[i].alpha = pop[i].alpha;
        new_pop[i].beta = pop[i].beta;
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

void update(chromosome pop[], chromosome archived[])
{
    double theta;
    for (int i = 0; i < popsize; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                theta = lookup(pop[i].gene[j][k], archived[i].gene[j][k], check_dominance(pop[i], archived[i]));
                if (pop[i].alpha[j][k] * pop[i].beta[j][k] < 0)
                    theta = -theta;
                pop[i].alpha[j][k] = cos(theta) * pop[i].alpha[j][k] - sin(theta) * pop[i].beta[j][k];
                pop[i].beta[j][k] = sin(theta) * pop[i].alpha[j][k] + cos(theta) * pop[i].beta[j][k];
                //cerr<<pop[i].alpha[j][k]<<endl;
                //cerr<<pop[i].gene[j][k]<<" "<<archived[i].gene[j][k]<<endl;
            }
        }
    }
}

double lookup(int x, int b, int domi)
{
    //cerr << x << b << domi <<endl;
    if (x == 0)
    {
        if (b == 0)
        {
            if (domi == -1) //theta1
            {
                //cerr << "theta 1" << endl;
                return 0 * M_PI;
            }
            else //theta2
            {
                //cerr << "theta 2" << endl;
                return 0 * M_PI;
            }
        }
        else
        {
            if (domi == -1) //theta3
            {
                //cerr << "theta 3" << endl;
                return 0 * M_PI;
            }
            else //theta4
            {
                //cerr << "theta 4" << endl;
                return 0.01 * M_PI;
            }
        }
    }
    else
    {
        if (b == 0)
        {
            if (domi == -1) //theta5
            {
                //cerr << "theta 5" << endl;
                return 0 * M_PI;
            }
            else //theta6
            {
                //cerr << "theta 6" << endl;
                return -0.01 * M_PI;
            }
        }
        else
        {
            if (domi == -1) //theta7
            {
                //cerr << "theta 7" << endl;
                return 0 * M_PI;
            }
            else //theta8
            {
                //cerr << "theta 8" << endl;
                return 0 * M_PI;
            }
        }
    }
}