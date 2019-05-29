#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void mutation_pop(chromosome pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        int j;
        double rnd, delta1, delta2, mut_pow, deltaq;
        double y, yl, yu, val, xy;
        for (j = 0; j < dimension; j++)
        {
            if (rand_double(0, 1) <= pmut_real)
            {
                y = pop[i].value[j];
                yl = lowerbound[j];
                yu = upperbound[j];
                delta1 = (y - yl) / (yu - yl);
                delta2 = (yu - y) / (yu - yl);
                rnd = rand_double(0, 1);
                mut_pow = 1.0 / (eta_m + 1.0);
                if (rnd <= 0.5)
                {
                    xy = 1.0 - delta1;
                    val = 2.0 * rnd + (1.0 - 2.0 * rnd) * (pow(xy, (eta_m + 1.0)));
                    deltaq = pow(val, mut_pow) - 1.0;
                }
                else
                {
                    xy = 1.0 - delta2;
                    val = 2.0 * (1.0 - rnd) + 2.0 * (rnd - 0.5) * (pow(xy, (eta_m + 1.0)));
                    deltaq = 1.0 - (pow(val, mut_pow));
                }
                y = y + deltaq * (yu - yl);
                if (y < yl)
                    y = yl;
                if (y > yu)
                    y = yu;
                pop[i].value[j] = y;
                nrealmut += 1;
            }
        }
    }
}