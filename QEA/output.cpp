#include "global.h"
#include "algorithm"
#include <fstream>

void best(individual b, double &Best)
{
    Best = b.fitness;
    // cout << "Best = " << Best << endl;
}

bool cmp_worst(const double &a, const double &b)
{
    return a < b;
};

void worst(individual B[], double &Worst)
{
    vector<double> tmp;
    for (int i = 0; i < popsize; i++)
    {
        tmp.push_back(B[i].fitness);
    }
    sort(tmp.begin(), tmp.end(), cmp_worst);
    Worst = tmp[0];
    // cout << "Worst = " << Worst << endl;
}

void average(individual B[], double &Ave)
{
    double tmp;
    tmp = 0;
    for (int i = 0; i < popsize; i++)
    {
        tmp += B[i].fitness;
    }
    Ave = tmp / popsize;
    // cout << "Ave = " << Ave << endl;
}

void standard(individual B[], double &Ave)
{
}

void output(individual B[], individual b)
{
    double Best, Worst, Ave;
    // for (int i = 0; i < popsize; i++)
    // {
    //     cout << B[i].fitness << endl;
    // }
    best(b, Best);
    worst(B, Worst);
    average(B, Ave);
    fstream fs;
    fs.open("./output/output.out", ios::app);
    fs << endl
       << popsize << " " << item << " " << max_gen << " " << Best << " " << Worst << " " << Ave;
    fs.close();
}