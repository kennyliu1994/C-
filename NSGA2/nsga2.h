#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

#define crossRate 0.9 //crossover rate
#define mutRate 0.3   //mutation rate
#define popSize 100   //number of population
#define objNum 2      //number of multiobective function

class chromosome
{
public:
    vector<double> value;
    vector<double> Sp;
    double fitness1;
    double fitness2;
    double d; //crowding distance
    unsigned int np;
    unsigned int index;
};
class nsga2
{
private:
    string testFunName;
    unsigned int run;
    unsigned int iteration;
    unsigned int dim;
    double upperbound;
    double lowerbound;
    double best_fitness;
    vector<int> F[2 * popSize];
    vector<double> tournament;
    vector<double> final_cofitness;
    vector<double> final_fitness; //each population's temp fitness
    vector<double> best_value;    //the best value
    vector<chromosome> Rt;
    vector<chromosome> sortF;
    chromosome parent[popSize];
    chromosome child[popSize];
    void testFunInit();
    void init();
    void evaluate(chromosome ch[]);
    void tourSelection(chromosome parent[], chromosome child[]);
    void mutation(chromosome ch[]);
    void main();
    void fastNondomSort();
    void calCrowdDis(vector<int> &F);
    void SCH(chromosome ch[]);
    void FON(chromosome ch[]);
    void POL(chromosome ch[]);
    void KUR(chromosome ch[]);
    void ZDT1(chromosome ch[]);
    void ZDT2(chromosome ch[]);
    void ZDT3(chromosome ch[]);
    void ZDT4(chromosome ch[]);
    void ZDT6(chromosome ch[]);

public:
    nsga2(const string, const unsigned int run, const unsigned int iteration);
    void exe();
};
