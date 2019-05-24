#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <fstream>
#include <vector>
using namespace std;

class chromosome
{
public:
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
extern double lowerbound;
extern double upperbound;

void init_parent(chromosome[]);

void display(fstream &gp, int generation);

#endif
