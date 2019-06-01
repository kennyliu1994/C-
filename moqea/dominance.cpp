#include "iostream" //was not declared in this scope

#include "global.h"

int check_dominance(chromosome a, chromosome b)
{
    if (a.fitness[0] < b.fitness[0])
    {
        if (a.fitness[1] > b.fitness[1])
            return 0;
        else
            return 1;
    }
    else if (a.fitness[0] == b.fitness[0])
    {
        if (a.fitness[1] < b.fitness[1])
            return 1;
        else if (a.fitness[1] == b.fitness[1])
            return 0;
        else
            return -1;
    }
    else
    {
        if (a.fitness[1] < b.fitness[1])
            return 0;
        else
            return -1;
    }
}
