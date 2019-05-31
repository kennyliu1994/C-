#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdlib.h>
#include <stdio.h> /* printf, scanf, NULL */
#include <vector>
#include <fstream>
using namespace std;

class chromosome
{
public:
    vector<int> gene[];
    vector<double> value;
    vector<double> Sp;
    vector<double> fitness;
    double crowd_dist;
    int np;
    int index;
    int rank;
};

extern int popsize;
extern int dimension;
extern int nbin;
extern int nobj;
extern int ngen;
extern int nrealcross;
extern int nrealmut;

extern vector<double> lowerbound;
extern vector<double> upperbound;
extern double pcross_real;
extern double pmut_real;
extern double eta_c;
extern double eta_m;

extern string s;

void allocate_memory(chromosome pop[], int size);

void initialize_pop(chromosome pop[]);

#endif
