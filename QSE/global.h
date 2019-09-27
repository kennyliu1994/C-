#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream> // cout
#include <vector>
using namespace std;

class individual //Q
{
private:
public:
    vector<double> angle;
    vector<int> x; // binary
    vector<int> w; //weight
    vector<int> p; //profit
    double C;      //capacity
    double fitness;
};

extern int popsize;
extern int item;
extern int max_gen;
extern double ff_x;
extern double ff_omega;
extern double ff_c1;
extern double ff_c2;
extern int count; //evaluation count

void load_parameter(char **argv);
void initialize(individual[]);
void make(individual[]);
void repair(individual[]);
void evaluate(individual[]);
void first_store(individual[], individual[], individual &);
void update(individual[], individual[], individual &);
void store(individual[], individual[], individual &);
void output(individual[], individual);

#endif