#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream> // cout
#include <vector>
using namespace std;

class individual //Q
{
private:
public:
    vector<double> alpha;
    vector<double> beta;
    vector<int> x; // binary
    vector<int> w; //weight
    vector<int> p; //profit
    double C;      //capacity
    double fitness;
};

extern int popsize;
extern int item;
extern int max_gen;
// extern vector<vector<double> > d;
// extern double ff_alpha;
// extern double ff_beta0;
// extern double ff_beta;
// extern double ff_gamma;
// extern double ff_omega;
// extern double ff_c1;
// extern double ff_c2;

// void load_parameter(char **argv);
void initialize(individual[]);
void make(individual[]);
void repair(individual[]);
void evaluate(individual[]);
void first_store(individual[], individual[], individual &);
// void ff_distance(individual, individual, int, int);
// void Q_update(individual[], int, int);
// void PSO_update(individual[], individual[], individual, int, int);
void store(individual[], individual[], individual &);
// void output(individual[], individual);

#endif