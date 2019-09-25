#include "global.h"
#include <time.h>
#include <stdlib.h> /* srand, rand , atoi*/
#include <fstream>

int popsize;
int item;
int max_gen;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    load_parameter(argv);
    individual Q[popsize];
    individual B[popsize];
    individual b;
    int t;
    double start, end;
    start = clock();
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
        update(Q, B);
        store(Q, B, b);
        //migration
    }
    output(B, b);
    end = clock();
    // cout << "共 " << (end - start) / CLOCKS_PER_SEC << " 秒" << endl;
    fstream fs;
    fs.open("./output/output.out", ios::app);
    fs << " 共 " << (end - start) / CLOCKS_PER_SEC << " 秒";
    fs.close();
}