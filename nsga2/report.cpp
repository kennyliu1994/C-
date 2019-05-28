#include "iostream" //was not declared in this scope

#include "global.h"

void report_pop(chromosome pop[], fstream &fs)
{
    for (int i = 0; i < popsize; i++)
    {
        fs << "# value = " << endl;
        for (int j = 0; j < dimension; j++)
        {
            fs << pop[i].value[j] << " ";
        }
        fs << endl;
        fs << "# fitness = " << endl;
        for (int j = 0; j < nobj; j++)
        {
            fs << pop[i].fitness[j] << " ";
        }
        fs << endl;
        fs << "# rank = " << endl;
        fs << pop[i].rank << endl;
        fs << "# crowd_dist = " << endl;
        fs << pop[i].crowd_dist << endl;
        fs << "------------------------------------------------" << endl;
    }
}
void report_feasible(chromosome pop[], fstream &fs)
{
    for (int i = 0; i < popsize; i++)
    {
        if (pop[i].rank == 1)
        {
            fs << "# value = " << endl;
            for (int j = 0; j < dimension; j++)
            {
                fs << pop[i].value[j] << " ";
            }
            fs << endl;
            fs << "# fitness = " << endl;
            for (int j = 0; j < nobj; j++)
            {
                fs << pop[i].fitness[j] << " ";
            }
            fs << endl;
            fs << "# rank = " << endl;
            fs << pop[i].rank << endl;
            fs << "# crowd_dist = " << endl;
            fs << pop[i].crowd_dist << endl;
        }
        fs << "------------------------------------------------" << endl;
    }
}