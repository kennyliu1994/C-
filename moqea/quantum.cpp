#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

//use left pop alpha and beta to calculate gene stored in right pop
void make(chromosome pop[], chromosome new_pop[])
{
    for (int i = 0; i < popsize; i++)
    {
        new_pop[i].alpha = pop[i].alpha;
        new_pop[i].beta = pop[i].beta;
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

void update(chromosome pop[], chromosome best[], int generation)
{
    int sch = 1;                  //rotation scheme
    string ampl = "MSAA"; //rotation angle amplitude
    for (int i = 0; i < popsize; i++)
    {
        lookup(pop[i], best[i], check_dominance(pop[i], best[i]), sch, ampl, generation);
    }
}

void lookup(chromosome &x, chromosome b, int domi, int sch, string ampl, int g)
{
    if (sch == 1 && ampl == "SSAA")
        SSAA_sch1(x, b, domi);
    if (sch == 1 && ampl == "MSAA")
        MSAA_sch1(x, b, domi);
    if (sch == 1 && ampl == "GDAA_Xu_Wang")
        GDAA_sch1_Xu_Wang(x, b, domi, g);
    if (sch == 2 && ampl == "GDAA_Xu_Wang")
        GDAA_sch2_Xu_Wang(x, b, domi, g);
    if (sch == 2 && ampl == "GDAA_Ji")
        GDAA_sch2_Ji(x, b, domi, g);
}