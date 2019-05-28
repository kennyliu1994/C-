#include <fstream>

#include "global.h"

void display(chromosome pop[], FILE *gp, int generation)
{
    fstream fs;
    fs.open("plot.out", ios::out); //write
    for (int i = 0; i < popsize; i++)
    {
        fs << pop[i].fitness[0] << " " << pop[i].fitness[1] << endl;
    }
    fprintf(gp, "reset\n"
                "set title 'Generation #%d'\n"
                "set xlabel 'f1'\n"
                "set ylabel 'f2'\n"
                "plot 'plot.out'\n",
            generation);
    fs.close();
}