#include "global.h"
#include <time.h>
#include <stdlib.h> /* srand, rand , atoi*/
#include <fstream>

int popsize;
int item;
int max_gen;
int count; //evaluation count

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    int t;
    double start, end;
    load_parameter(argv);
    individual Q[popsize];
    individual B[popsize];
    individual b;
    start = clock();
    t = 0;
    count = 0;
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
        cout << t << endl;
    }
    output(B, b);
    end = clock();
    fstream fs;
    fs.open("./output/output.out", ios::app);
    // cout << "共 " << (end - start) / CLOCKS_PER_SEC << " 秒" << endl;
    fs << " 共 " << (end - start) / CLOCKS_PER_SEC << " 秒 ";
    fs << count;
    fs.close();
}