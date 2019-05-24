#include "iostream"
#include <stdlib.h>

#include "global.h"

int popsize = 10;
int dimension = 3;
double lowerbound = -5;
double upperbound = 5;

int main(int argc, char **argv)
{
    srand(time(NULL));
    fstream fs1; //
    fstream gp;
    fs1.open("initial_pop.out", ios::out); //write
    gp.open("plot.gp", ios::out);          //write
    if (gp.fail())
    {
        cout << "Can't open file!" << endl;
        exit(1);
    }
    chromosome parent[popsize];
    chromosome child[popsize];
    chromosome mixed[2 * popsize];

    init_parent(parent);
    for (int i = 0; i < popsize; i++)
    {
        fs1 << "Parent[" << i << "][j] : " << endl;
        for (int j = 0; j < dimension - 1; j++)
        {
            fs1 << parent[i].value[j] << "," ;
        }
        fs1 << parent[i].value[dimension - 1] << endl;
    }

    display(gp, 1);
    fs1.close();
    gp.close();
    return 0;
}