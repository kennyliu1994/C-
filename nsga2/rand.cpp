#include "rand.h"

double randDouble(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX + 1.0) + lower;
}