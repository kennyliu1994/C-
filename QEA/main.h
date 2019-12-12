#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream> // cout
#include <vector>
using namespace std;

class individual //Q
{
private:
public:
    double c; //capacity
    double fitness;
    vector<int> x; // binary
    vector<int> w; //weight
    vector<int> p; //profit
    vector<double> alpha;
    vector<double> beta;
};

class quantum_evolutionary_algorithm
{
private:
    double theta = 0;
public:
    void initialize(individual Q[]);
    void make(individual Q[]);
    void repair(individual Q[]);
    void store(individual Q[], individual pbest[], individual &gbest, const int run);
    void make(individual Q[], const int i);
    void repair(individual Q[], const int i);
    void update(individual Q[], individual pbest[], const int i);
    void evaluate(individual Q[], const int i, const int run);
    void store(individual Q[], individual pbest[], individual &gbest, const int i, const int run);
    void migration(individual pbest[], individual gbest, const int t);
};

class run30
{
private:
    double best;
    double worst;
    double average = 0;

public:
    vector<double> gbest; //每 run 的 gbest
    void output(clock_t start, clock_t end);
};

class gnuplot
{
private:
public:
    vector<int> eva_count; //每次 evaluate 的 evaulate count
    vector<double> gbest;  //每次 evaluate 的 gbest
    void output();
};

void run();

#endif
