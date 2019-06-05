#include <time.h>
#include "iostream"
#include <fstream>

#include "global.h"

int popsize;
int ngen;
int nobj;
int dimension;
int nbit = 10;
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
    gp = popen("gnuplot -persist", "w");
    chromosome parent_pop[popsize];
    chromosome child_pop[popsize];
    chromosome archived_pop[popsize];
    chromosome mixed_pop[2 * popsize];
    allocate_memory(parent_pop, popsize);
    allocate_memory(child_pop, popsize);
    allocate_memory(archived_pop, popsize);
    allocate_memory(mixed_pop, 2 * popsize);
    initialize_pop(parent_pop);
    make(parent_pop, parent_pop);
    decode_pop(parent_pop);
    cout << "Initialization done, now performing first generation" << endl;
    evaluate_pop(parent_pop, s);
    assign_rank_and_crowding_distance(parent_pop);
    //report_pop(parent_pop, fs1);
    //fs4 << "# gen = 1" << endl
    //<< "------------------------------------------------" << endl;
    //report_pop(parent_pop, fs4);
    //cout << " gen = 1" << endl;
    //display(parent_pop, gp, 1);
    for (int i = 2; i <= ngen; i++)
    {
        make(parent_pop, child_pop);
        fs1<<"make"<<endl;
        /*report_pop(parent_pop, fs1);
        report_pop(child_pop, fs1);*/
        decode_pop(child_pop);
        /*report_pop(parent_pop, fs1);
        report_pop(child_pop, fs1);*/
        //selection(parent_pop, child_pop);//nsga2
        //mutation_pop(child_pop);//nsga2
        evaluate_pop(child_pop, s);
        //report_pop(child_pop, fs1);
        /*report_pop(parent_pop, fs1);
        report_pop(child_pop, fs1);*/
        merge(parent_pop, child_pop, mixed_pop);
        /*report_pop(parent_pop, fs1);
        report_pop(child_pop, fs1);*/
        fill_nondominated_sort(mixed_pop, parent_pop);
        /*report_pop(parent_pop, fs1);
        report_pop(child_pop, fs1);*/
        if (i == 2)
        {
            for (int j = 0; j < popsize; j++)
            {
                archived_pop[j] = parent_pop[j];
            }
            //report_pop(parent_pop, fs1);
        }
        update(parent_pop, archived_pop);
        if (i != 2)
        {
            for (int j = 0; j < popsize; j++)
            {
                archived_pop[j] = parent_pop[j];
            }
            //report_pop(parent_pop, fs1);
        }
        //fs4 << "# gen = " << i << endl;
        //report_pop(parent_pop, fs4);
        cout << " gen = " << i << endl;
        //display(parent_pop, gp, i);
        /*for (int i = 0; i < popsize; i++)
        {
            fs2 << parent_pop[i].fitness[0] << " " << parent_pop[i].fitness[1] << endl;
        }*/
    }
    cout << " Generations finished, now reporting solutions " << endl;
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
    pclose(gp);
    cout << " Routine successfully exited " << endl;
}