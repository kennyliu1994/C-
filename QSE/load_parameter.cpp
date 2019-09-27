#include "global.h"
#include <stdlib.h> /* atoi */

void load_parameter(char **argv)
{
    popsize = atoi(argv[1]);
    item = atoi(argv[2]);
    max_gen = atoi(argv[3]);
    ff_x = strtod(argv[4], NULL);
    ff_omega = strtod(argv[5], NULL);
    ff_c1 = strtod(argv[6], NULL);
    ff_c2 = strtod(argv[7], NULL);
}