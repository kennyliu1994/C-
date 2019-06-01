#include "iostream" //was not declared in this scope
#include "fstream"

#include "global.h"

void report_pop(chromosome pop[], fstream &fs)
{
    for (int i = 0; i < popsize; i++)
    {
        fs << "# population = " << i << endl;
        fs << "# alpha = " << endl;
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                fs << pop[i].alpha[j][k];
            }
            fs << " ";
        }
        fs << endl;
        fs << "# beta = " << endl;
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                fs << pop[i].beta[j][k];
            }
            fs << " ";
        }
        fs << endl;
        fs << "# gene = " << endl;
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < nbit; k++)
            {
                fs << pop[i].gene[j][k];
            }
            fs << " ";
        }
        fs << endl;
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
            fs << "# population = " << i << endl;
            fs << "# alpha = " << endl;
            for (int j = 0; j < dimension; j++)
            {
                for (int k = 0; k < nbit; k++)
                {
                    fs << pop[i].alpha[j][k];
                }
                fs << " ";
            }
            fs << endl;
            fs << "# beta = " << endl;
            for (int j = 0; j < dimension; j++)
            {
                for (int k = 0; k < nbit; k++)
                {
                    fs << pop[i].beta[j][k];
                }
                fs << " ";
            }
            fs << endl;
            fs << "# gene = " << endl;
            for (int j = 0; j < dimension; j++)
            {
                for (int k = 0; k < nbit; k++)
                {
                    fs << pop[i].gene[j][k];
                }
                fs << " ";
            }
            fs << endl;
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