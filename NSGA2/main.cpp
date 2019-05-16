#include "nsga2.h"

int main(int argc, char *argv[])
{
    string testFunName = argv[1];
    unsigned int run = atoi(argv[2]);
    unsigned int iter = atoi(argv[3]);
    nsga2 nsga2(testFunName, run, iter);
    nsga2.exe();
    return 0;
}