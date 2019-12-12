#include "Kenny.h"

#include <iostream> // cout, endl
#include <math.h>
#include <algorithm> // shuffle
#include <iomanip>   //setw
using namespace std;

class particles
{
private:
public:
    double fitness;
    vector<double> velocity;
    vector<double> x;
};

bool cmp_best(const particles &a, const particles &b)
{
    return a.fitness < b.fitness;
}

int main()
{
    srand((unsigned)time(NULL));
    Kenny_rand rd;
    int iter = 1000;
    int popsize = 50;
    int dim = 10;
    double ub = 5.12;
    double lb = -5.12;
    double v_max = rd.double11(0, 1) * (ub - lb);
    double w;
    double w_max = 0.9;
    double w_min = 0.2;
    double c1 = 2;
    double c2 = 2;
    particles p[popsize];
    particles pbest[popsize];
    particles gbest;
    //initialization
    for (int i = 0; i < popsize; i++)
    {
        p[i].x.assign(dim, 0);
        p[i].velocity.assign(dim, 0);
        for (int j = 0; j < dim; j++)
        {
            p[i].x[j] = rd.double11(lb, ub);
        }
    }
    //fitness
    for (int i = 0; i < popsize; i++)
    {
        p[i].fitness = 0;
        for (int j = 0; j < dim; j++)
        {
            // p[i].fitness += 10 + pow(p[i].x[j], 2) - 10 * cos(2 * M_PI * p[i].x[j]); //RASTRIGIN FUNCTION
            p[i].fitness += pow(p[i].x[j], 2); //SPHERE FUNCTION
        }
    }
    //first_store
    vector<particles> tmp;
    for (int i = 0; i < popsize; i++)
    {
        pbest[i] = p[i]; //first time
        tmp.push_back(pbest[i]);
    }
    sort(tmp.begin(), tmp.end(), cmp_best);
    gbest = tmp[0];
    //update
    for (int l = 0; l < iter; l++)
    {
        w = w_max - l * ((w_max - w_min) / iter);
        for (int i = 0; i < popsize; i++)
        {
            p[i].fitness = 0;
            for (int j = 0; j < dim; j++)
            {
                p[i].velocity[j] = w * p[i].velocity[j] + c1 * rd.double11(0, 1) * (pbest[i].x[j] - p[i].x[j]) + c2 * rd.double11(0, 1) * (gbest.x[j] - p[i].x[j]);
                if (p[i].velocity[j] > v_max)
                    p[i].velocity[j] = v_max;
                else if (p[i].velocity[j] < -v_max)
                    p[i].velocity[j] = -v_max;
                p[i].x[j] += p[i].velocity[j];
                //fitness
                // p[i].fitness += 10 + pow(p[i].x[j], 2) - 10 * cos(2 * M_PI * p[i].x[j]); //RASTRIGIN FUNCTION
                p[i].fitness += pow(p[i].x[j], 2); //SPHERE FUNCTION
            }
            if (pbest[i].fitness > p[i].fitness)
                pbest[i] = p[i];
            if (gbest.fitness > p[i].fitness)
                gbest = p[i];
        }
    }
    cout << gbest.fitness << endl;
    return 0;
}