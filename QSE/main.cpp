#include "main.h"
#include "Kenny.h"

#include <time.h>
#include "algorithm"
#include <math.h>
#include <fstream>

int max_run;
int max_iter;
int max_pop;
int max_item;
int eva_count;
string output_path = "./output/result.txt";
string gnuplot_path;
quantum_swarm_evolutionary_algorithm QSE;
run30 RUN30;
gnuplot GNUPLOT[30];

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    Kenny_convert ct;

    max_run = atoi(argv[1]);
    max_iter = atoi(argv[2]);
    max_pop = atoi(argv[3]);
    max_item = atoi(argv[4]);

    gnuplot_path = "./gnuplot/" + ct.char2str(argv[1]) + "_" + ct.char2str(argv[2]) + "_" + ct.char2str(argv[3]) + "_" + ct.char2str(argv[4]) + ".txt";

    clock_t start = clock();
    run();
    clock_t end = clock();
    RUN30.output(start, end);
    GNUPLOT[0].output();
}

void run()
{
    for (int run = 0; run < max_run; run++)
    {
        cout << "run " << run << endl;

        individual Q[max_pop];
        individual pbest[max_pop];
        individual gbest;
        eva_count = 0;

        QSE.initialize(Q);
        QSE.make(Q);
        QSE.repair(Q);
        QSE.store(Q, pbest, gbest, run);
        for (int t = 0; t < max_iter; t++)
        {
            // cout << t << endl;
            for (int i = 0; i < max_pop; i++)
            {
                QSE.make(Q, i);
                QSE.repair(Q, i);
                QSE.update(Q, pbest, gbest, i);
                QSE.evaluate(Q, i, run);
                QSE.store(Q, pbest, gbest, i, run);
                QSE.migration(pbest, gbest, t);
            }
        }
        RUN30.gbest.push_back(gbest.fitness);
    }
}

void quantum_swarm_evolutionary_algorithm::initialize(individual Q[])
{
    for (int i = 0; i < max_pop; i++)
    {
        Q[i].angle.assign(max_item, M_PI / 4);
        Q[i].x.assign(max_item, 0);
        Q[i].w.assign(max_item, 0);
        Q[i].p.assign(max_item, 0);
        Q[i].c = 0;
    }
    Kenny_rand rd;
    for (int i = 0; i < max_pop; i++)
    {
        for (int j = 0; j < max_item; j++)
        {
            Q[i].w[j] = rd.int11(1, 10);
            Q[i].p[j] = Q[i].w[j] + 5;
            Q[i].c += ((double)Q[i].w[j] / 2);
        }
    }
}

void quantum_swarm_evolutionary_algorithm::make(individual Q[])
{
    Kenny_rand rd;
    for (int i = 0; i < max_pop; i++)
    {
        for (int j = 0; j < max_item; j++)
        {
            if (rd.double10(0, 1) > pow(cos(Q[i].angle[j]), 2))
                Q[i].x[j] = 1;
            else
                Q[i].x[j] = 0;
        }
    }
}

double current_weight(individual Q)
{
    double sum_w = 0;
    for (int i = 0; i < max_item; i++)
        sum_w += Q.w[i] * Q.x[i];
    return sum_w;
}

void quantum_swarm_evolutionary_algorithm::repair(individual Q[])
{
    Kenny_rand rd;
    bool overfilled;
    overfilled = false;
    for (int i = 0; i < max_pop; i++)
    {
        int index;
        if (current_weight(Q[i]) > Q[i].c)
            overfilled = true;
        while (overfilled)
        {
            Q[i].x[rd.int11(0, max_item - 1)] = 0;
            if (current_weight(Q[i]) <= Q[i].c)
                overfilled = false;
        }
        while (!overfilled)
        {
            index = rd.int11(0, max_item - 1);
            Q[i].x[index] = 1;
            if (current_weight(Q[i]) > Q[i].c)
                overfilled = true;
        }
        Q[i].x[index] = 0;
    }
}

void quantum_swarm_evolutionary_algorithm::store(individual Q[], individual pbest[], individual &gbest, const int run)
{
    gbest = Q[0];
    for (int i = 0; i < max_pop; i++)
    {
        Q[i].fitness = 0;
        for (int j = 0; j < max_item; j++)
            Q[i].fitness += Q[i].p[j] * Q[i].x[j];
        eva_count++;
        pbest[i] = Q[i];
        if (gbest.fitness < Q[i].fitness)
            gbest = Q[i];
        GNUPLOT[run].eva_count.push_back(eva_count);
        GNUPLOT[run].gbest.push_back(gbest.fitness);
    }
}

void quantum_swarm_evolutionary_algorithm::make(individual Q[], const int i)
{
    Kenny_rand rd;
    for (int j = 0; j < max_item; j++)
    {
        if (rd.double10(0, 1) > pow(cos(Q[i].angle[j]), 2))
            Q[i].x[j] = 1;
        else
            Q[i].x[j] = 0;
    }
}

void quantum_swarm_evolutionary_algorithm::repair(individual Q[], const int i)
{
    Kenny_rand rd;
    bool overfilled;
    overfilled = false;
    int index;
    if (current_weight(Q[i]) > Q[i].c)
        overfilled = true;
    while (overfilled)
    {
        Q[i].x[rd.int11(0, max_item - 1)] = 0;
        if (current_weight(Q[i]) <= Q[i].c)
            overfilled = false;
    }
    while (!overfilled)
    {
        index = rd.int11(0, max_item - 1);
        Q[i].x[index] = 1;
        if (current_weight(Q[i]) > Q[i].c)
            overfilled = true;
    }
    Q[i].x[index] = 0;
}

void quantum_swarm_evolutionary_algorithm::update(individual Q[], individual pbest[], individual gbest, const int i)
{
    Kenny_rand rd;
    for (int k = 0; k < max_item; k++)
    {
        delta = x * (omega * Q[i].angle[k] + c1 * rd.double11(0, 1) * (pbest[i].angle[k] - Q[i].angle[k]) + c2 * rd.double11(0, 1) * (gbest.angle[k] - Q[i].angle[k]));
        if ((Q[i].x[k] != pbest[i].x[k]) || (Q[i].x[k] != gbest.x[k]))
            Q[i].angle[k] += delta;
    }
}

void quantum_swarm_evolutionary_algorithm::evaluate(individual Q[], const int i, const int run)
{
    Q[i].fitness = 0;
    for (int j = 0; j < max_item; j++)
        Q[i].fitness += Q[i].p[j] * Q[i].x[j];
    eva_count++;
    GNUPLOT[run].eva_count.push_back(eva_count);
}

void quantum_swarm_evolutionary_algorithm::store(individual Q[], individual pbest[], individual &gbest, const int i, const int run)
{
    if (pbest[i].fitness < Q[i].fitness)
        pbest[i] = Q[i];
    if (gbest.fitness < Q[i].fitness)
        gbest = Q[i];
    GNUPLOT[run].gbest.push_back(gbest.fitness);
}

bool cmp_best(const individual &a, const individual &b)
{
    return a.fitness > b.fitness;
};

void quantum_swarm_evolutionary_algorithm::migration(individual pbest[], individual gbest, const int t)
{
    if (t % 10 == 0)
    {
        for (int i = 0; i < max_pop; i++)
            pbest[i] = gbest;
    }
    else
    {
        vector<individual> tmp;
        for (int i = 0; i < max_pop; i++)
            tmp.push_back(pbest[i]);
        sort(tmp.begin(), tmp.end(), cmp_best);
        for (int i = 0; i < max_pop; i++)
        {
            pbest[i] = tmp[0];
        }
    }
}

void run30::output(clock_t t1, clock_t t2)
{
    best = *max_element(begin(gbest), end(gbest));
    worst = *min_element(begin(gbest), end(gbest));
    for (int i = 0; i < max_run; i++)
    {
        average += gbest[i];
    }
    average /= max_run;
    fstream fs_result;
    fs_result.open(output_path.c_str(), ios::app);
    fs_result << endl
              << max_run << " "
              << max_iter << " " << max_pop << " " << max_item << " "
              << best << " " << worst << " " << average << " " << eva_count << " "
              << double(t2 - t1) / CLOCKS_PER_SEC << " sec";
    ;
    fs_result.close();
}

void gnuplot::output()
{
    for (int i = 1; i < max_run; i++)
    {
        for (unsigned int j = 0; j < GNUPLOT[0].eva_count.size(); j++)
            GNUPLOT[0].gbest[j] += GNUPLOT[i].gbest[j];
    }
    fstream fs_gnuplot;
    fs_gnuplot.open(gnuplot_path.c_str(), ios::out);
    for (unsigned int i = 0; i < GNUPLOT[0].eva_count.size(); i++)
    {
        fs_gnuplot << eva_count[i] << " "
                   << GNUPLOT[0].gbest[i] / max_run << endl;
    }
    fs_gnuplot.close();
}
