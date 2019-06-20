#include <time.h>
#include "iostream"
#include <fstream>

#include "global.h"

int popsize;
int ngen;
int nobj;
int dimension;
int nbit = 15;
int nrealcross;
int nrealmut;
double pcross_real;
double pmut_real;
double eta_c;
double eta_m;
string s;
vector<double> lowerbound;
vector<double> upperbound;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    fstream fs1; //初使 parent
    fstream fs2; //最終 parent
    fstream fs3; //best
    fstream fs4; //all
    fstream fs5; //parameters
    s = argv[1];
    fs1.open("initial_pop.out", ios::out);
    fs2.open("final_pop.out", ios::out);
    fs3.open("best_pop.out", ios::out);
    fs4.open("all_pop.out", ios::out);
    fs5.open("params.out", ios::out);
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
    chromosome parent_pop[popsize];
    chromosome child_pop[popsize];
    chromosome best_pop[popsize];
    chromosome mixed_pop[2 * popsize]; //mix for non-domi sort
    allocate_memory(parent_pop, popsize);
    allocate_memory(child_pop, popsize);
    allocate_memory(best_pop, popsize);
    allocate_memory(mixed_pop, 2 * popsize);
    initialize_pop(parent_pop);   //initialize Q(0)
    make(parent_pop, parent_pop); //make P(0)
    decode_pop(parent_pop);
    //cout << "Initialization done, now performing first generation" << endl;
    evaluate_pop(parent_pop, s);
    //cout << "Initialization done, now performing first generation" << endl;
    assign_rank_and_crowding_distance(parent_pop);
    for (int j = 0; j < popsize; j++)
    {
        best_pop[j] = parent_pop[j];
    }
    //report_pop(parent_pop, fs1);
    //fs4 << "# gen = 1" << endl
    //<< "------------------------------------------------" << endl;
    //report_pop(parent_pop, fs4);
    //cout << " gen = 1" << endl;
    for (int i = 2; i <= ngen; i++)
    {
        make(parent_pop, child_pop); //make P(1)
        decode_pop(child_pop);
        evaluate_pop(child_pop, s);
        merge(best_pop, child_pop, mixed_pop);
        fill_nondominated_sort(mixed_pop, parent_pop);
        if (i == 2)
        {
            for (int j = 0; j < popsize; j++)
            {
                best_pop[j] = parent_pop[j];
            }
        }
        update(parent_pop, best_pop, i);
        if (i != 2)
        {
            for (int j = 0; j < popsize; j++)
            {
                best_pop[j] = parent_pop[j];
            }
        }
        //report_pop(parent_pop, fs1);
        //report_pop(parent_pop, fs1);
        //fs4 << "# gen = " << i << endl;
        cout << " gen = " << i << endl;
    }
    //cout << " Generations finished, now reporting solutions " << endl;
    for (int i = 0; i < popsize; i++)
    {
        fs2 << parent_pop[i].fitness[0] << " " << parent_pop[i].fitness[1] << endl;
    }
    report_feasible(parent_pop, fs3);
    if (dimension != 0)
    {
        fs5 << "Number of crossover of real variable = " << nrealcross << endl;
        fs5 << "Number of mutation of real variable = " << nrealmut << endl;
    }
    fs1.close();
    fs2.close();
    fs3.close();
    fs4.close();
    fs5.close();
    //cout << " Routine successfully exited " << endl;
}