#include "iostream" //was not declared in this scope

#include "global.h"

//evaluate value to fitness
void evaluate_pop(chromosome pop[], string s)
{
    for (int i = 0; i < popsize; i++)
    {
        if (s == "sch1")
            sch1(pop[i].value, pop[i].fitness);
        if (s == "sch2")
            sch2(pop[i].value, pop[i].fitness);
        if (s == "fon")
            fon(pop[i].value, pop[i].fitness);
        if (s == "kur")
            kur(pop[i].value, pop[i].fitness);
        if (s == "pol")
            pol(pop[i].value, pop[i].fitness);
        if (s == "vnt")
            vnt(pop[i].value, pop[i].fitness);
        if (s == "zdt1")
            zdt1(pop[i].value, pop[i].fitness);
        if (s == "zdt2")
            zdt2(pop[i].value, pop[i].fitness);
        if (s == "zdt3")
            zdt3(pop[i].value, pop[i].fitness);
        if (s == "zdt4")
            zdt4(pop[i].value, pop[i].fitness);
        if (s == "zdt6")
            zdt6(pop[i].value, pop[i].fitness);
    }
}