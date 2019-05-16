#include "nsga2.h"
#include <math.h>    /* sqrt, pow */
#include <algorithm> // min sort
#include <limits>    // numeric_limits<double>::max()
//#define debug
#ifndef debug
#define trace(x) \
    do           \
    {            \
    } while (0)
#else
#define trace(x) cerr << x
#endif

double randDouble(const double lowerBound, const double upperBound) //[low,upper)
{
    return (double)(upperBound - lowerBound) * rand() / (RAND_MAX + 1.0) + lowerBound;
}
nsga2::nsga2(const string testFunName, const unsigned int run, const unsigned int iteration)
{
    this->testFunName = testFunName;
    this->run = run;
    this->iteration = iteration;
}
void nsga2::testFunInit()
{
    if (testFunName == "SCH")
    {
        dim = 1;
        lowerbound = -1000;
        upperbound = 1000;
    }
    else if (testFunName == "FON")
    {
        dim = 3;
        lowerbound = -4;
        upperbound = 4;
    }
    else if (testFunName == "POL")
    {
        dim = 2;
        lowerbound = -M_PI;
        upperbound = M_PI;
    }
    else if (testFunName == "KUR")
    {
        dim = 3;
        lowerbound = -5;
        upperbound = 5;
    }
    else if (testFunName == "ZDT1")
    {
        dim = 30;
        lowerbound = 0;
        upperbound = 1;
    }
    else if (testFunName == "ZDT2")
    {
        dim = 30;
        lowerbound = 0;
        upperbound = 1;
    }
    else if (testFunName == "ZDT3")
    {
        dim = 30;
        lowerbound = 0;
        upperbound = 1;
    }
    trace("==========================================" << endl);
    trace("Load Data" << endl);
    trace("==========================================" << endl);
    trace("Test DataSet = " << testFunName << endl);
    trace("dim = " << dim << endl);
    trace("Upperbound = " << upperbound << endl);
    trace("lowerbound = " << lowerbound << endl);
    trace("==========================================" << endl);
}
void nsga2::main()
{
    tournament.assign(popSize, 0);      
    bestFit.resize(popSize, 0); 
    chromosome parent[popSize];
    chromosome child[popSize];
    trace("Initialization" << endl);
    trace("==========================================" << endl);
    for (unsigned int i = 0; i < popSize; i++)
    {
        parent[i].np = 0;
        parent[i].d = 0.0;
        parent[i].Sp.clear();
        parent[i].value.assign(dim, 0);
        parent[i].fitness1 = 0.0;
        parent[i].fitness2 = 0.0;
        trace("Parent[" << i << "] : " << endl);
        trace("np = " << parent[i].np << endl);
        trace("d = " << parent[i].d << endl);
    }
    trace("------------------------------------------" << endl);
    for (unsigned int i = 0; i < popSize; i++)
    {
        child[i].np = 0;
        child[i].d = 0.0;
        child[i].Sp.clear();
        child[i].value.assign(dim, 0);
        child[i].fitness1 = 0.0;
        child[i].fitness2 = 0.0;
        trace("child[" << i << "] : " << endl);
        trace("np = " << child[i].np << endl);
        trace("d = " << child[i].d << endl);
    }
    trace("==========================================" << endl);
    for (unsigned int i = 0; i < popSize; i++)
    {
        trace("Parent[" << i << "][j] : " << endl
                        << "value = ");
        for (unsigned int j = 0; j < dim - 1; j++)
        {
            parent[i].value.push_back(randDouble(lowerbound, upperbound));
            trace(parent[i].value[j] << ",");
        }
        parent[i].value.push_back(randDouble(lowerbound, upperbound));
        trace(parent[i].value[dim - 1] << endl);
    }
    trace("==========================================" << endl);
    evaluate(parent);
    tourSelection(parent, child);
    mutation(child);
    evaluate(child);
    unsigned int t = 0;
    while (t < iteration)
    {
        t++;
        for (unsigned int i = 0; i < popSize; i++) //小孩變成父母
        {
            parent[i] = child[i];
        }
        evaluate(parent);
        tourSelection(parent, child);
        mutation(child);
        evaluate(child);
        fastNondomSort();
    }
}
void nsga2::evaluate(chromosome ch[])
{
    if (testFunName == "SCH")
    {
        SCH(ch);
    }
    else if (testFunName == "FON")
    {
        FON(ch);
    }
    else if (testFunName == "POL")
    {
        POL(ch);
    }
    else if (testFunName == "KUR")
    {
        KUR(ch);
    }
    else if (testFunName == "ZDT1")
    {
        ZDT1(ch);
    }
    else if (testFunName == "ZDT2")
    {
        ZDT2(ch);
    }
    else if (testFunName == "ZDT3")
    {
        ZDT3(ch);
    }
    else if (testFunName == "ZDT4")
    {
        ZDT4(ch);
    }
    else if (testFunName == "ZDT6")
    {
        ZDT6(ch);
    }
    trace("Calculate fitness" << endl);
    trace("==========================================" << endl);
    for (unsigned int i = 0; i < popSize; i++)
    {
        trace("Parent[" << i << "][j] : " << endl);
        trace("fitness1 = " << ch[i].fitness1 << endl);
        trace("fitness2 = " << ch[i].fitness2 << endl);
    }
    trace("==========================================" << endl);
}
void nsga2::tourSelection(chromosome pa[], chromosome ch[])
{
    int ran1;
    int ran2;
    for (unsigned int i = 0; i < popSize; i++)
    {
        ran1 = rand() % popSize;
        ran2 = rand() % popSize;
        if (bestFit[ran1] < bestFit[ran2])
        {
            tournament[i] = ran1;
        }
        else if (bestFit[ran1] > bestFit[ran2])
        {
            tournament[i] = ran2;
        }
    }

    double rdm;
    unsigned int crossptr; //crossover pointer
    int randc1;
    int randc2;
    for (unsigned int i = 0; i < popSize / 2; i++)
    {
        rdm = random();
        crossptr = rand() % dim;
        randc1 = tournament[rand() % popSize];
        randc2 = tournament[rand() % popSize];
        if (rdm < crossRate)
        {
            for (unsigned int j = 0; j < crossptr; j++)
            {
                ch[i * 2].value[j] = pa[randc1].value[j];
                ch[i * 2 + 1].value[j] = pa[randc2].value[j];
            }
            for (unsigned int j = crossptr; j < dim; j++)
            {
                ch[i * 2].value[j] = pa[randc2].value[j];
                ch[i * 2 + 1].value[j] = pa[randc1].value[j];
            }
        }
    }
}
void nsga2::mutation(chromosome ch[])
{
    unsigned int ptr;
    double rd;
    for (unsigned int i = 0; i < popSize; i++)
    {
        rd = randDouble(0, 1);
        ptr = rand() % dim;
        if (rd < mutRate)
        {
            ch[i].value[ptr] = randDouble(lowerbound, upperbound);
        }
    }
}
int dominate(double x1, double x2, double y1, double y2)
{
    if (x1 < y1)
    {
        if (x2 > y2)
            return 2; //none
        else
            return 0; //dominate
    }
    else if (x1 > y1)
    {
        if (x2 < y2)
            return 2;
        else
            return 1; //is dominated
    }
    else
    {
        if (x2 < y2)
            return 0;
        else if (x2 == y2)
            return 2;
        else
            return 1;
    }
}
void nsga2::fastNondomSort()
{
    Rt.clear();
    for (unsigned int i = 0; i < popSize; i++)
    {
        Rt.push_back(parent[i]);
    }
    for (unsigned int i = 0; i < popSize; i++)
    {
        Rt.push_back(child[i]);
    }
    for (unsigned int i = 0; i < 2 * popSize; i++)
    {
        Rt[i].index = i + 1;
    }
    for (unsigned int i = 0; i < 2 * popSize - 1; i++)
    {
        for (unsigned int j = i + 1; j < 2 * popSize; j++)
        {
            //cout << "show fitness : " << endl;
            //cout << Rt[i].fitness1 << " , " << Rt[i].fitness2 << " , " << Rt[j].fitness1 << " , " << Rt[j].fitness2 << endl;
            //cout << "show dominate status : " << endl;
            //cout << dominate(Rt[i].fitness1, Rt[i].fitness2, Rt[j].fitness1, Rt[j].fitness2) << endl;
            if (dominate(Rt[i].fitness1, Rt[i].fitness2, Rt[j].fitness1, Rt[j].fitness2) == 0)
            {
                Rt[i].Sp.push_back(j + 1);
                Rt[j].np++;
            }
            else if (dominate(Rt[i].fitness1, Rt[i].fitness2, Rt[j].fitness1, Rt[j].fitness2) == 1)
            {
                Rt[j].Sp.push_back(i + 1);
                Rt[i].np++;
            }
        }
    }
    for (unsigned int i = 0; i < 2 * popSize; i++)
    {
        if (Rt[i].np == 0)
            F[0].push_back(i + 1);
    }
    for (unsigned int i = 0; i < 2 * popSize; i++)
    {
        if (F[i].size() != 0)
        {
            for (unsigned int j = 0; j < F[i].size(); j++)
            {
                for (unsigned int k = 0; k < Rt[F[i][j] - 1].Sp.size(); k++)
                {
                    Rt[Rt[F[i][j] - 1].Sp[k] - 1].np--;
                    if (Rt[Rt[F[i][j] - 1].Sp[k] - 1].np == 0)
                        F[i + 1].push_back(Rt[F[i][j] - 1].Sp[k]);
                }
            }
        }
    }
    unsigned int needed_n = popSize; //需要 popSize 個傳回 child
    unsigned int th = 0;             //目前存到第幾個 child
    for (unsigned int i = 0; i < 2 * popSize; i++)
    {
        if (F[i].size() > 2)
        {
            calCrowdDis(F[i]);
        }
    }
    for (unsigned int i = 0; i < 2 * popSize; i++)
    {
        if (F[i].size() == needed_n)
        {
            for (unsigned int j = 0; j < needed_n; j++)
            {
                child[th] = Rt[F[i][j] - 1];
                th++;
            }
            //cout << "==" << endl;
            break;
        }
        else if (F[i].size() > needed_n)
        {
            for (unsigned int j = 0; j < needed_n; j++)
            {
                child[th] = Rt[F[i][j] - 1];
                th++;
            }
            //cout << ">" << endl;
            break;
        }
        else
        {
            for (unsigned int j = 0; j < F[i].size(); j++)
            {
                child[th] = Rt[F[i][j] - 1];
                th++;
            }
            needed_n -= F[i].size();
            //cout << "<" << endl;
        }
    }
}
bool cmpByFit1(chromosome const &a, chromosome const &b)
{
    return a.fitness1 < b.fitness1;
};
bool cmpByFit2(chromosome const &a, chromosome const &b)
{
    return a.fitness2 < b.fitness2;
};
bool cmpByd(chromosome const &a, chromosome const &b)
{
    return a.d > b.d;
};
void nsga2::calCrowdDis(vector<int> &F)
{
    sortF.clear();
    for (unsigned int i = 0; i < F.size(); i++)
    {
        sortF.push_back(Rt[F[i] - 1]);
    }
    //依照fit1排序一次
    sort(sortF.begin(), sortF.end(), cmpByFit1); //對整個class的某項參數作為依據排序
    //清空d
    for (unsigned int i = 0; i < sortF.size(); i++)
    {
        sortF[i].d = 0;
    }
    //設頭尾的d為無限大
    sortF.front().d = numeric_limits<double>::max();
    sortF.back().d = numeric_limits<double>::max();
    //算中間的d
    for (unsigned int i = 1; i < sortF.size() - 1; i++)
    {
        sortF[i].d += (sortF[i + 1].fitness1 - sortF[i - 1].fitness1) / (sortF.back().fitness1 - sortF.front().fitness1);
    }
    //依照fit2排序一次
    sort(sortF.begin(), sortF.end(), cmpByFit2); //對整個class的某項參數作為依據排序
    //算中間的d
    for (unsigned int i = 1; i < sortF.size() - 1; i++)
    {
        sortF[i].d += (sortF[i + 1].fitness2 - sortF[i - 1].fitness2) / (sortF.back().fitness2 - sortF.front().fitness2);
    }
    //依照d排序
    sort(sortF.begin(), sortF.end(), cmpByd);
    //改變F裡的順序
    F.clear();
    for (unsigned int i = 0; i < sortF.size(); i++)
    {
        F.push_back(sortF[i].index);
    }
}
void nsga2::SCH(chromosome ch[])
{ //popSize = 1 [-10^3, 10^3]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        sum1 = pow(ch[i].value[0], 2);
        ch[i].fitness1 = sum1;
        sum2 = pow((ch[i].value[0] - 2), 2);
        ch[i].fitness2 = sum2;
    }
}

void nsga2::FON(chromosome ch[])
{ //popSize = 3 [-4, 4]
    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned int j = 0; j < dim; j++)
        {
            sum1 += pow(ch[i].value[j] - 1 / sqrt(3), 2);
            sum2 += pow(ch[i].value[j] + 1 / sqrt(3), 2);
        }

        sum1 *= -1;
        sum1 = 1 - exp(sum1);
        ch[i].fitness1 = sum1;
        sum2 *= -1;
        sum2 = 1 - exp(sum2);
        ch[i].fitness2 = sum2;
    }
}

void nsga2::POL(chromosome ch[])
{ //popSize = 2 [-M_PI, M_PI]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double A1 = 0.5 * sin(1) - 2 * cos(1) + sin(2) - 1.5 * cos(2);
        double A2 = 1.5 * sin(1) - cos(1) + 2 * sin(2) - 0.5 * cos(2);
        double B1 = 0.5 * sin(ch[i].value[0]) - 2 * cos(ch[i].value[0]) + sin(ch[i].value[1]) - 1.5 * cos(ch[i].value[1]);
        double B2 = 1.5 * sin(ch[i].value[0]) - cos(ch[i].value[0]) + 2 * sin(ch[i].value[1]) - 0.5 * cos(ch[i].value[1]);

        sum1 = 1 + pow((A1 - B1), 2) + pow((A2 - B2), 2);
        ch[i].fitness1 = sum1;
        sum2 = pow((ch[i].value[0] + 3), 2) + pow((ch[i].value[1] + 1), 2);
        ch[i].fitness2 = sum2;
    }
}

void nsga2::KUR(chromosome ch[])
{ //popSize = 3 [-5, 5]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned int j = 0; j < dim - 1; j++)
        {
            sum1 += -10 * exp(-0.2 * sqrt(pow(ch[i].value[j], 2) + pow(ch[i].value[j + 1], 2)));
        }
        for (unsigned int j = 0; j < dim; j++)
        {
            sum2 += pow(fabs(ch[i].value[j]), 0.8) + 5 * sin(pow(ch[i].value[j], 3));
        }
        ch[i].fitness1 = sum1;
        ch[i].fitness2 = sum2;
    }
}

void nsga2::ZDT1(chromosome ch[])
{ //popSize = 30 [0, 1]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double g = 0;

        for (unsigned int j = 1; j < dim; j++)
        {
            g += ch[i].value[j];
        }
        g = 1 + 9 * g / (dim - 1);

        sum1 = ch[i].value[0];
        ch[i].fitness1 = sum1;
        sum2 = g * (1 - sqrt(ch[i].value[0] / g));
        ch[i].fitness2 = sum2;
    }
}

void nsga2::ZDT2(chromosome ch[])
{ //popSize = 30 [0, 1]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double g = 0;

        for (unsigned int j = 1; j < dim; j++)
        {
            g += ch[i].value[j];
        }
        g = 1 + 9 * g / (dim - 1);

        sum1 = ch[i].value[0];
        ch[i].fitness1 = sum1;
        sum2 = g * (1 - pow(ch[i].value[0] / g, 2));
        ch[i].fitness2 = sum2;
    }
}

void nsga2::ZDT3(chromosome ch[])
{ //popSize = 30 [0, 1]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double g = 0;

        for (unsigned int j = 1; j < dim; j++)
        {
            g += ch[i].value[j];
        }
        g = 1 + 9 * g / (dim - 1);

        sum1 = ch[i].value[0];
        ch[i].fitness1 = sum1;
        sum2 = g * (1 - sqrt(ch[i].value[0] / g) - (ch[i].value[0] / g) * sin(10 * M_PI * ch[i].value[0]));
        ch[i].fitness2 = sum2;
    }
}

void nsga2::ZDT4(chromosome ch[])
{ //popSize = 10 X1[0, 1] Xi[-5, 5]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double g = 0;

        for (unsigned int j = 1; j < dim; j++)
        {
            g += pow(ch[i].value[j], 2) - 10 * cos(4 * M_PI * ch[i].value[j]);
        }
        g = 1 + 10 * (dim - 1) + g;

        sum1 = ch[i].value[0];
        ch[i].fitness1 = sum1;
        sum2 = g * (1 - sqrt(ch[i].value[0] / g));
        ch[i].fitness2 = sum2;
    }
}

void nsga2::ZDT6(chromosome ch[])
{ //popSize = 10 [0, 1]

    for (unsigned int i = 0; i < popSize; i++)
    {
        double sum1 = 0;
        double sum2 = 0;
        double g = 0;

        for (unsigned int j = 1; j < dim; j++)
        {
            g += ch[i].value[j];
        }
        g = 1 + 9 * pow(g / (dim - 1), 0.25);

        sum1 = 1 - exp(-4 * ch[i].value[0]) * pow(sin(6 * M_PI * ch[i].value[0]), 6);
        ch[i].fitness1 = sum1;
        sum2 = g * (1 - pow(sum1 / g, 2));
        ch[i].fitness2 = sum2;
    }
}
void nsga2::exe()
{
    srand((unsigned)time(NULL));
    testFunInit();
    main();
}