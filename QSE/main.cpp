#include "global.h"
#include <time.h>
#include <stdlib.h> /* srand, rand , atoi*/
#include <fstream>

int popsize;
int item;
int max_gen;
double ff_x;
double ff_omega;
double ff_c1;
double ff_c2;
int e_count; //evaluation count

int main(int argc, char **argv)
{
    fstream fs_plot;
    fs_plot.open("./gnuplot/QSE.txt", ios::out);
    srand((unsigned)time(NULL));
    int t;
    double start, end;
    load_parameter(argv);
    individual Q[popsize];
    individual B[popsize];
    individual b;
    start = clock();
    t = 0;
    e_count = 0;
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
        update(Q, B, b);
        store(Q, B, b);
        migration(B, b, t);
        output(b, fs_plot);
        cout << t << endl;
    }
    output(B, b);
    end = clock();
    fstream fs;
    fs.open("./output/output.out", ios::app);
    // cout << "共 " << (end - start) / CLOCKS_PER_SEC << " 秒" << endl;
    fs << " 共 " << (end - start) / CLOCKS_PER_SEC << " 秒 ";
    fs << e_count;
    fs.close();
}