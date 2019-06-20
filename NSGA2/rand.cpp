#include "rand.h"

double rand_double(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX + 1.0) + lower;
}

int rand_int(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}