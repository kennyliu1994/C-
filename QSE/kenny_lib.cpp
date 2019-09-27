#include "kenny_lib.h"
#include <stdlib.h> /* srand, rand */

int kenny_rand::int11(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}
double kenny_rand::double10(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX + 1.0) + lower;
}
double kenny_rand::double11(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX) + lower;
}