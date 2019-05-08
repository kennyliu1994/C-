#include "nsga2.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    string dataName = argv[1];
    unsigned int run = atoi(argv[2]);
    unsigned int iter = atoi(argv[3]);
    //show dataset info.
    nsga2 nsga2(dataName, run, iter);
    nsga2.exe();
    return 0;
}