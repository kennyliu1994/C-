#include "global.h"
#include <stdlib.h> /* atoi */

void load_parameter(char **argv)
{
    popsize = atoi(argv[1]);
    item = atoi(argv[2]);
    max_gen = atoi(argv[3]);
    // cout << "popsize = " << popsize << " item = " << item << " max_gen = " << max_gen << endl;
}