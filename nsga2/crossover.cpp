#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void crossover(chromosome parent1, chromosome parent2, chromosome &child1, chromosome &child2)
{
    int i;
    double rand;
    double y1, y2, yl, yu;
    double c1, c2;
    double alpha, beta, betaq;
    if (rand_double(0, 1) <= pcross_real)
    {
        nrealcross++;
        for (i = 0; i < dimension; i++)
        {
            if (rand_double(0, 1) <= 0.5)
            {
                if (fabs(parent1.value[i] - parent2.value[i]) > EPS)
                {
                    if (parent1.value[i] < parent2.value[i])
                    {
                        y1 = parent1.value[i];
                        y2 = parent2.value[i];
                    }
                    else
                    {
                        y1 = parent2.value[i];
                        y2 = parent1.value[i];
                    }
                    yl = lowerbound[i];
                    yu = upperbound[i];
                    rand = rand_double(0, 1);
                    beta = 1.0 + (2.0 * (y1 - yl) / (y2 - y1));
                    alpha = 2.0 - pow(beta, -(eta_c + 1.0));
                    if (rand <= (1.0 / alpha))
                    {
                        betaq = pow((rand * alpha), (1.0 / (eta_c + 1.0)));
                    }
                    else
                    {
                        betaq = pow((1.0 / (2.0 - rand * alpha)), (1.0 / (eta_c + 1.0)));
                    }
                    c1 = 0.5 * ((y1 + y2) - betaq * (y2 - y1));
                    beta = 1.0 + (2.0 * (yu - y2) / (y2 - y1));
                    alpha = 2.0 - pow(beta, -(eta_c + 1.0));
                    if (rand <= (1.0 / alpha))
                    {
                        betaq = pow((rand * alpha), (1.0 / (eta_c + 1.0)));
                    }
                    else
                    {
                        betaq = pow((1.0 / (2.0 - rand * alpha)), (1.0 / (eta_c + 1.0)));
                    }
                    c2 = 0.5 * ((y1 + y2) + betaq * (y2 - y1));
                    if (c1 < yl)
                        c1 = yl;
                    if (c2 < yl)
                        c2 = yl;
                    if (c1 > yu)
                        c1 = yu;
                    if (c2 > yu)
                        c2 = yu;
                    if (rand_double(0, 1) <= 0.5)
                    {
                        child1.value[i] = c2;
                        child2.value[i] = c1;
                    }
                    else
                    {
                        child1.value[i] = c1;
                        child2.value[i] = c2;
                    }
                }
                else
                {
                    child1.value[i] = parent1.value[i];
                    child2.value[i] = parent2.value[i];
                }
            }
            else
            {
                child1.value[i] = parent1.value[i];
                child2.value[i] = parent2.value[i];
            }
        }
    }
    else
    {
        for (i = 0; i < dimension; i++)
        {
            child1.value[i] = parent1.value[i];
            child2.value[i] = parent2.value[i];
        }
    }
}