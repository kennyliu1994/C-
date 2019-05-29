#include <time.h>
#include "iostream"

#include "global.h"

int popsize;
int ngen;
int nobj;
int dimension;
int nbin = 1;
vector<double> lowerbound;
vector<double> upperbound;
double pcross_real;
double pmut_real;
double eta_c;
double eta_m;
int nrealcross;
int nrealmut;
string s;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    fstream fs1;
    fstream fs2;
    fstream fs3;
    fstream fs4;
    fstream fs5;
    FILE *gp;
    s = argv[1];
    fs1.open("initial_pop.out", ios::out); //write
    fs2.open("final_pop.out", ios::out);   //write
    fs3.open("best_pop.out", ios::out);    //write
    fs4.open("all_pop.out", ios::out);     //write
    fs5.open("params.out", ios::out);      //write
    cin >> popsize >> ngen >> nobj >> dimension;
    fs5 << "Number of population size = " << popsize << endl;
    fs5 << "Number of generations = " << ngen << endl;
    fs5 << "Number of objectives = " << nobj << endl;
    fs5 << "Number of dimensions = " << dimension << endl;
    for (int i = 0; i < dimension; i++)
    {
        lowerbound.assign(dimension, 0);
        upperbound.assign(dimension, 0);
    }
    for (int i = 0; i < dimension; i++)
    {
        cin >> lowerbound[i] >> upperbound[i];
        fs5 << "min and max bounds = " << lowerbound[i] << " " << upperbound[i] << endl;
    }
    cin >> pcross_real >> pmut_real >> eta_c >> eta_m;
    fs5 << "Probability of crossover = " << pcross_real << endl;
    fs5 << "Probability of mutation = " << pmut_real << endl;
    fs5 << "Value of distribution index for crossover = " << eta_c << endl;
    fs5 << "Value of distribution index for mutation = " << eta_m << endl;
    fs5 << "Number of binary variables = " << eta_m << endl;
    gp = popen("gnuplot -persist", "w");
    chromosome parent_pop[popsize];
    chromosome child_pop[popsize];
    chromosome mixed_pop[2 * popsize];
    allocate_memory(parent_pop, popsize);
    allocate_memory(child_pop, popsize);
    allocate_memory(mixed_pop, 2 * popsize);
    initialize_pop(parent_pop);

    fs1.close();
    fs2.close();
    fs3.close();
    fs4.close();
    fs5.close();
    pclose(gp);
}