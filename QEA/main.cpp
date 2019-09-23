#include "global.h"
#include <time.h>
#include <stdlib.h> /* srand, rand , atoi*/

int popsize = 1;
int item = 100;
int max_gen = 1;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    individual Q[popsize];
    individual B[popsize];
    individual b;
    int t;
    t = 0;
    initialize(Q);
    make(Q);
    repair(Q);
    evaluate(Q);
    first_store(Q, B, b);
    while (t < max_gen)
    {
        t++;
        make(Q);
        repair(Q);
        evaluate(Q);
        // update;
        store(Q, B, b);
        //migration
    }
}