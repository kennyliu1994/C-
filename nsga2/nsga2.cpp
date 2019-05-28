#include "iostream"
#include <stdlib.h>

#include "global.h"

int popsize;
int ngen;
int nobj;
int dimension;
double lowerbound;
double upperbound;
double pcross_real;
double pmut_real;
double eta_c;
double eta_m;
int nrealcross;
int nrealmut;

int main(int argc, char **argv)
{
    srand(time(NULL));
    fstream fs1;
    fstream fs2;
    fstream fs3;
    fstream fs4;
    fstream fs5;
    FILE *gp;
    string s = argv[1];
    fs1.open("initial_pop.out", ios::out); //write
    fs2.open("final_pop.out", ios::out);   //write
    fs3.open("best_pop.out", ios::out);    //write
    fs4.open("all_pop.out", ios::out);     //write
    fs5.open("params.out", ios::out);      //write
    cin >> popsize >> ngen >> nobj >> dimension >> lowerbound >> upperbound >> pcross_real >> pmut_real >> eta_c >> eta_m;
    gp = popen("gnuplot -persist", "w");
    nrealcross = 0;
    nrealmut = 0;
    chromosome parent_pop[popsize];
    chromosome child_pop[popsize];
    chromosome mixed_pop[2 * popsize];
    allocate_memory(parent_pop, popsize);
    allocate_memory(child_pop, popsize);
    allocate_memory(mixed_pop, 2 * popsize);
    initialize_pop(parent_pop);
    evaluate_pop(parent_pop, s);
    assign_rank_and_crowding_distance(parent_pop);
    report_pop(parent_pop, fs1);
    fs4 << "# gen = 1" << endl;
    report_pop(parent_pop, fs4);
    display(parent_pop, gp, 1);
    for (int i = 2; i <= ngen; i++)
    {
        selection(parent_pop, child_pop);
        mutation_pop(child_pop);
        evaluate_pop(child_pop, s);
        merge(parent_pop, child_pop, mixed_pop);
        fill_nondominated_sort(mixed_pop, parent_pop);
        fs4 << "# gen = " << i << endl;
        report_pop(parent_pop, fs4);
        display(parent_pop, gp, i);
    }
    for (int i = 0; i < popsize; i++)
    {
        fs2 << parent_pop[i].fitness[0] << " " << parent_pop[i].fitness[1] << endl;
    }
    report_feasible(parent_pop, fs3);
    if (dimension != 0)
    {
        fs5 << endl
            << "Number of crossover of real variable = " << nrealcross;
        fs5 << endl
            << "Number of mutation of real variable = " << nrealmut;
    }
    fs1.close();
    fs2.close();
    fs3.close();
    fs4.close();
    fs5.close();
    pclose(gp);
}